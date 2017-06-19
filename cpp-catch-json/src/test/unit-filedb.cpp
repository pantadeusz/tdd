/*
    test program for micro json database
    Copyright (C) 2017 Tadeusz Puźniakowski

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <catch.hpp>
#include <json.hpp>

#include <filedb.hpp>
#include <iostream>
#include <string>

using json = nlohmann::json;

TEST_CASE("error handling tests", "[filedb][nodb]") {
  FileDb("bdd_db0").drop();
  FileDb db("test_db0");
  SECTION("reading elements from dropped database should throw") {
    db.drop();
    REQUIRE_THROWS(db.get());
  }
  SECTION("reading no existient element by id") {
    REQUIRE(db.get("3").is_null());
  }
  SECTION("reading no existient element by object") {
    REQUIRE(db.get({{"id"}, {"3"}}).is_null());
  }
  SECTION("writing to dropped database should throw") {
    json e = {{"id", "1"}};
    db.put(e);
    REQUIRE(db.get("1") == e);
    db.drop();
    REQUIRE_THROWS(db.put({{"id", "3"}}));
  }
  db.drop();
}

SCENARIO("adding data to database and getting data from database", "[crud]") {
  FileDb("bdd_db0").drop();
  GIVEN("the database is empty") {
    FileDb db("bdd_db0");
    REQUIRE(db.get().size() == 0);

    WHEN("user adds two items as an array") {
      json element = json::array({{{"id", "1"}, {"name", "Janusz"}},
                                  {{"id", "2"}, {"name", "Pinokio"}}});
      db.put(element);

      THEN("there are two items in the database") {
        // INFO("The database contains " << db.get().dump());
        CAPTURE(db.get().dump());
        REQUIRE(db.get().size() == 2);
      }

      THEN("the elements contains the expected data") {
        REQUIRE(db.get("1") == element[0]);
        REQUIRE(db.get({{"id", "2"}}) == element[1]);
      }

      THEN("it is impossible to get element that has not been added") {
        REQUIRE(db.get("3").is_null());
      }
    }

    WHEN("user adds two items as an individual elements") {
      json element1 = {{"id", "1"}, {"name", "Janusz"}};
      json element2 = {{"id", "2"}, {"name", "Pinokio"}};
      db.put(element1);
      db.put(element2);

      THEN("there are two items in the database") {
        REQUIRE(db.get("1") == element1);
        REQUIRE(db.get("2") == element2);
        REQUIRE(db.get("3").is_null());
        REQUIRE(db.get().size() == 2);
      }
    }
  }
}

SCENARIO("removing data from database", "[crud]") {
  FileDb("bdd_db0").drop();
  GIVEN("the database contains 3 elements") {
    json elements = json::array({{{"id", "1"}, {"name", "Janusz"}},
                                 {{"id", "2"}, {"name", "Wiktor"}},
                                 {{"id", "3"}, {"name", "Pinokio"}}});
    FileDb db("bdd_db0");
    REQUIRE(db.get().size() == 0);
    db.put(elements);
    REQUIRE(db.get().size() == 3);

    WHEN("user deletes element with id == \"1\"") {
      db.del(elements[0]);
      THEN("the element cannont be retrieved") {
        REQUIRE(db.get("1").is_null());
      }
      THEN("other elements can be retrieved") {
        REQUIRE(!db.get("2").is_null());
        REQUIRE(!db.get("3").is_null());
      }
    }

    WHEN("user deletes every element by its id") {
      for (auto e : db.get()) db.del(e);
      THEN("the database is empty") { REQUIRE(db.get().size() == 0); }
    }

    WHEN("user deletes every element from array") {
      db.del(db.get());
      THEN("the database is empty") { REQUIRE(db.get().size() == 0); }
    }
  }
  FileDb("bdd_db0").drop();
}
