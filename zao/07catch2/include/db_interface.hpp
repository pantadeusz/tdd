#ifndef __DB_COMMON_INTERFACE___
#define  __DB_COMMON_INTERFACE___

#include <string>
#include <list>
#include <regex>

namespace db {

/**
 * @brief some simple abstract key-value database interface
 ************/
 
class Database_i {
public:
    /**
     * @brief get method interface. This method should return value for a key.
     ************/
    virtual std::string get(const std::string &key) const = 0;

    /**
     * @brief get_keys method interface. This method should return every key matching given regex.
     ************/
    virtual std::list<std::string> get_keys(const std::regex &matching) const = 0;

    /**
     * @brief put method interface. This method insert value for given key.
     ************/
    virtual int put(const std::string &key, const std::string &value) = 0;

    /**
     * @brief del method interface. This method removes given key from database.
     ************/
    virtual int del(const std::string &key) = 0;
};


}
#endif
