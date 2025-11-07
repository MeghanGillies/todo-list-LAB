#include <sstream>

#include "todo_list.hpp"

void Todo_List::add(std::string const task) {
    if (task == "") {
        throw std::invalid_argument("Can't add empty task.");
    }else if (!list.contains(task)) {
        list.insert({task, false});
    } else {
        throw std::invalid_argument("You've already added this task.");
    }
}

void Todo_List::complete(std::string const task) {
    if (list.contains(task)) {
        list.at(task) = true;
    } else {
        throw std::out_of_range("That item is not in the list.");
    }
}

void Todo_List::clear() {
    list.clear();
}

std::string Todo_List::pp_all() {
    if (list.empty()) {
        return "The list is empty.";
    } else {
        std::stringstream ss;

        ss << "To-Do List:" << std::endl;

        for (const auto& [task, complete] : list) {
            if (complete) {
                ss << "☑";
            } else {
                ss << "☐";
            }

            ss << "\t" << task << std::endl;
        }

        return ss.str();
    }
}

std::string Todo_List::pp_complete() {
    if (list.empty()) {
        return "The list is empty.";
    } else {
        std::stringstream ss;

        ss << "Completed:" << std::endl;

        for (const auto& [task, complete] : list) {
            if (complete) {
                ss << "☑" << "\t" << task << std::endl;
            }
        }

        return ss.str();
    }
}

std::string Todo_List::pp_incomplete() {
    if (list.empty()) {
        return "The list is empty.";
    } else {
        std::stringstream ss;

        ss << "Incomplete:" << std::endl;

        for (const auto& [task, complete] : list) {
            if (!complete) {
                ss << "☐" << "\t" << task << std::endl;
            }
        }

        return ss.str();
    }
}