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

#ifndef __FILEDB_HPP__
#define __FILEDB_HPP__

#include <json.hpp>

#include <string>
#include <iostream>


class FileDb {
	private:
		std::string dbname;
	public:
		FileDb(const std::string &dbname);
		/**
		 returns json with format:
		 [{
		 		"id": 121,
		 		"column1": "value1"
		 	},
		 ....]
		*/
		nlohmann::json get();
		/**
		 returns json with format:
		 {
		 		"id": 121,
		 		"column1": "value1"
		  }
		*/
		nlohmann::json get(const nlohmann::json &data);


		/**
		 save json. Format:
		 [{
		 		"id": 121,
		 		"column1": "value1"
		 }, {
		 		"id": 221,
		 		"column1": "value1"
		 }]

		 OR
		 
		 {
		 		"id": 121,
		 		"column1": "value1"
		 }
		*/
		int put(const nlohmann::json &data);
		
		/**
		 delete json. Format:
		{
		 		"id": 121,
		 		"column1": "value1"
		}

		OR

		"1212"

		// where "1212" is ID
		*/

		int del(const nlohmann::json &data);

		/**
		removes whole database.
			*/
		void drop();
};


#endif