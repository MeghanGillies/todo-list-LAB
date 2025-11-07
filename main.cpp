#include <iostream>

#include "cmake-build-debug/_deps/catch2-src/src/catch2/internal/catch_stdstreams.hpp"
#include "src/todo_list.hpp"

int main() {
    Todo_List todo_list;

    // Adding Tasks to the To-Do List
    try {
        todo_list.add("Walk the Dog");
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try { // Will throw an exception if entering a task more than once
        todo_list.add("Walk the Dog");
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try { // Will throw an exception if the task is blank
        todo_list.add("");
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        todo_list.add("Buy Groceries");
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        todo_list.add("Empty Dishwasher");
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        todo_list.add("Do Math Homework");
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // Completing Tasks in the To-Do List
    try {
        todo_list.complete("Walk the Dog");
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        todo_list.complete("Empty Dishwasher");
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try { // Will throw an exception if you try to complete a task that isn't in the list
        todo_list.complete("Buy Eggs");
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // Printing the list with all, complete, and incomplete
    std::cout << std::endl << todo_list.pp_all() << std::endl;
    std::cout << todo_list.pp_complete() << std::endl;
    std::cout << todo_list.pp_incomplete() << std::endl;

    // Clearing list
    todo_list.clear();

    // Will print "the list is empty" when it is empty
    std::cout << todo_list.pp_all() << std::endl;
    std::cout << todo_list.pp_complete() << std::endl;
    std::cout << todo_list.pp_incomplete() << std::endl;

    return 0;
}