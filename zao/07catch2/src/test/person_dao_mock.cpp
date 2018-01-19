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


TEST_CASE( "simple crud test with mocks", "[crud][inmemory][mock]" ) {

	Person p = {.id = 1, .name = "Janusz", .yob = 1955};
	json j = p;

	SECTION( "write and read database record" ) {
    Mock<Database_i> database_mock;
    When( Method( database_mock, put ) ).AlwaysReturn( 1 );
    When( Method( database_mock, get ) ).AlwaysReturn( j.dump() );

    Person_dao dao ( &(database_mock.get()), "Person_" );

		dao.put( p );
		Person v = dao.get( 1 );
    Verify( Method( database_mock, put ) + Method(database_mock, get)).Exactly(1_Times);
		REQUIRE( v == p );
	}

}


