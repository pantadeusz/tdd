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

#include <filedb.hpp>

#include <json.hpp>

#include <cstdio>
#include <fstream>
#include <iostream>
#include <streambuf>
#include <string>

#include <dirent.h>  // unfortunate -- the need for dirent..

#include <unistd.h>

using json = nlohmann::json;
using std::cout;
using std::endl;

FileDb::FileDb(const std::string &dbname) {
  system(std::string("mkdir -p " + dbname).c_str());
  this->dbname = dbname;
}
nlohmann::json FileDb::get() {
  std::string directory = dbname;
  const std::string matching = ".*[.]json";

  nlohmann::json retj = std::vector<std::string>(0);
  DIR *d;
  if ((d = opendir(directory.c_str())) != NULL) {
    struct dirent *f;
    while ((f = readdir(d)) != NULL) {
      if (f->d_name[0] != '.') {
        std::string fn = f->d_name;
        nlohmann::json e = get(fn.substr(0, fn.find(".json")));
        retj.push_back(e);
      }
    }
    closedir(d);
    return retj;
  } else {
    throw std::bad_exception();  // database not created
  }

  return json::parse("[]");
}

void FileDb::drop() { system((std::string("rm -rf ") + dbname).c_str()); }

nlohmann::json FileDb::get(const nlohmann::json &data) {
  try {
    if (data.count("id") > 0) {
      auto id = data["id"].get<std::string>();
      std::ifstream t((dbname + "/" + id + ".json").c_str());
      std::string str((std::istreambuf_iterator<char>(t)),
                      std::istreambuf_iterator<char>());

      return json::parse(str);
    } else {
      auto id = data.get<std::string>();
      std::ifstream t((dbname + "/" + id + ".json").c_str());
      std::string str((std::istreambuf_iterator<char>(t)),
                      std::istreambuf_iterator<char>());

      return json::parse(str);
    }
  } catch (...) {
    return json::parse("null");
  }
}
int FileDb::put(const nlohmann::json &data) {
  if (data.is_array()) {
    int ret = 0;
    for (auto e : data) {
      ret += put(e);
    }
    return ret;
  } else if (!data["id"].is_null()) {
    std::ofstream outfile(
        (dbname + "/" + data["id"].get<std::string>() + ".json").c_str());
    if (!outfile.is_open()) throw std::bad_exception();
    outfile << data.dump();
    outfile.close();
    return 1;
  }
  throw std::bad_exception();
}

int FileDb::del(const nlohmann::json &data) {
  if (data.is_array()) {
    return std::accumulate(
        data.begin(), data.end(), 0,
        [this](int r, const nlohmann::json &x) { return r + del(x); });
  } else if (data.count("id") > 0) {
    if (remove(
            (dbname + "/" + data["id"].get<std::string>() + ".json").c_str()) ==
        0)
      return 1;
    return 0;
  } else if (data.is_string()) {
    if (remove((dbname + "/" + data.get<std::string>() + ".json").c_str()) == 0)
      return 1;
    return 0;
  } else {
    return 0;
  }
}
