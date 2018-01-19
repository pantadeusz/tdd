#ifndef __DB_IN_MEMORY_KV_DATABASE__
#define  __DB_IN_MEMORY_KV_DATABASE__

#include "db_interface.hpp"

#include <string>
#include <list>
#include <regex>
#include <map>

namespace db {

/**
 * @brief in-memory database. Good for testing. See Databas_i for more details on API.
 ************/

class Database_in_memory : public Database_i {
protected:
	std::map<std::string, std::string> _data;
public:
	virtual std::string get( const std::string &key ) const;
	virtual std::list<std::string> get_keys( const std::regex &matching ) const;
	virtual int put( const std::string &key, const std::string &value );
	virtual int del( const std::string &key );

};


}
#endif
