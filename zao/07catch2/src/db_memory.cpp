
#include "db_memory.hpp"
#include "db_interface.hpp"
#include <stdexcept>


namespace db {


std::string Database_in_memory::get( const std::string &key ) const {
	if ( _data.count( key ) ) {
		return _data.at( key );
	} else {
		throw std::domain_error ( key + " not found." );
	}
}

std::list<std::string> Database_in_memory::get_keys( const std::regex &matching ) const {
	std::list<std::string> keys;
	for ( const auto &kv : _data ) {
		if ( std::regex_match( kv.first, matching ) ) {
			keys.push_back( kv.first );
		}
	}
	return keys;
}

int Database_in_memory::put( const std::string &key, const std::string &value ) {
	_data[key] = value;
}

int Database_in_memory::del( const std::string &key ) {
	_data.erase( key );
}


}
