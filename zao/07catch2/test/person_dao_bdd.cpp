/*
    Example tests
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
#include <fakeit.hpp>

#include <person_dao.hpp>
#include <db_memory.hpp>
#include <iostream>
#include <string>

using json = nlohmann::json;
using namespace fakeit;
using namespace Catch::Matchers;

using namespace db;
using namespace crud;



SCENARIO("working on filled database", "[crud][bdd]") {
  
	Database_in_memory datasource;
	Person_dao dao ( &datasource, "Person_" );
  
  GIVEN("the database is empty") {
    REQUIRE(dao.get().size() == 0);

    WHEN("there is added one person") {
    	Person p = {.id = 1, .name = "Janusz", .yob = 1955};
      dao.put(p);

      THEN("there is one item in database") {
        CAPTURE(dao.get());
        REQUIRE(dao.get().size() == 1);
      }

      THEN("the item is the same as added") {
        REQUIRE(dao.get(1) == p);
      }

      THEN("it is impossible to get element that has not been added") {
        CAPTURE(dao.get());
        REQUIRE_THROWS_WITH( dao.get(3), Contains( "not found" ) && Contains( "3" ) );
      }
    }
  }
}



