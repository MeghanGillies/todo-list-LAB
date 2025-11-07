#pragma once
#include <map>
#include <string>

class Todo_List {
private:
    std::map<std::string, bool> list;
public:
    void add(std::string task);
    void complete(std::string task);
    void clear();

    // Return formatted strings for printing
    std::string pp_all();
    std::string pp_complete();
    std::string pp_incomplete();
};
