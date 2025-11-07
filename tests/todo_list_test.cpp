#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/todo_list.hpp"

TEST_CASE( "You can add new tasks to the to-do list" ) {
    Todo_List todo_list;
    REQUIRE_NOTHROW( todo_list.add("Buy Eggs") );
    REQUIRE( todo_list.pp_all() == "To-Do List:\n☐\tBuy Eggs\n");
}

TEST_CASE( "Will throw an exception if the task added is blank" ) {
    Todo_List todo_list;
    REQUIRE_THROWS_AS( todo_list.add(""), std::invalid_argument );
}

TEST_CASE( "Will throw an exception if you add a task that is already in the list" ) {
    Todo_List todo_list;
    todo_list.add("Buy Eggs");
    REQUIRE_THROWS_AS( todo_list.add("Buy Eggs"), std::invalid_argument );
}

TEST_CASE( "You can complete tasks on the to-do list" ) {
    Todo_List todo_list;
    REQUIRE_NOTHROW( todo_list.add("Buy Eggs") );
    REQUIRE_NOTHROW( todo_list.complete("Buy Eggs") );
    REQUIRE( todo_list.pp_all() == "To-Do List:\n☑\tBuy Eggs\n");
}

TEST_CASE( "Will throw an exception if you try to complete a task that isn't in the list" ) {
    Todo_List todo_list;
    REQUIRE_THROWS_AS( todo_list.complete("Buy Eggs") , std::out_of_range );
}

TEST_CASE( "pretty prints all tasks in the list" ) {
    Todo_List todo_list;

    // Adding Tasks
    todo_list.add("Buy Eggs");
    todo_list.add("Buy Milk");
    todo_list.add("Wash Dishes");

    // Completing Tasks
    todo_list.complete("Buy Milk");

    REQUIRE( todo_list.pp_all() == "To-Do List:\n☐\tBuy Eggs\n☑\tBuy Milk\n☐\tWash Dishes\n" );
}

TEST_CASE( "pretty prints all completed tasks in the list" ) {
    Todo_List todo_list;

    // Adding Tasks
    todo_list.add("Buy Eggs");
    todo_list.add("Buy Milk");
    todo_list.add("Wash Dishes");

    // Completing Tasks
    todo_list.complete("Buy Milk");

    REQUIRE( todo_list.pp_complete() == "Completed:\n☑\tBuy Milk\n" );
}

TEST_CASE( "pretty prints all incomplete tasks in the list" ) {
    Todo_List todo_list;

    // Adding Tasks
    todo_list.add("Buy Eggs");
    todo_list.add("Buy Milk");
    todo_list.add("Wash Dishes");

    // Completing Tasks
    todo_list.complete("Buy Milk");

    REQUIRE( todo_list.pp_incomplete() == "Incomplete:\n☐\tBuy Eggs\n☐\tWash Dishes\n" );
}

TEST_CASE (" clear() method empties the list") {
    Todo_List todo_list;
    todo_list.add("Buy Eggs");
    todo_list.add("Buy Milk");
    todo_list.add("Wash Dishes");

    // Completing Tasks
    todo_list.complete("Buy Milk");

    // proves tasks have been added to the list
    REQUIRE( todo_list.pp_all() == "To-Do List:\n☐\tBuy Eggs\n☑\tBuy Milk\n☐\tWash Dishes\n" );

    todo_list.clear(); // clearing list

    // Checks all printing methods to prove the list is empty
    REQUIRE( todo_list.pp_all() == "The list is empty." );
    REQUIRE( todo_list.pp_complete() == "The list is empty." );
    REQUIRE( todo_list.pp_incomplete() == "The list is empty." );
}