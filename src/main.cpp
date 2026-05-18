#include <iostream>
#include <print>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <functional>
#include <ranges>

#include "static_array.hpp"
#include "dynamic_array.hpp"

std::unordered_map<std::string,
	std::unordered_map<std::string,
		std::unordered_map<std::string, std::function<void()>>
	>
> functions;

void array_search_sequential()
{
	// StaticArray<int, 5> arr = {3, 1, 4, 1, 5};
	DynamicArray<int> arr{3, 1, 4, 1, 5};
	std::println("array = {}", arr);
	std::println();

	std::println("index of 3 = {}", arr.sequential_search(3));
	std::println("index of 1st 1 = {}", arr.sequential_search(1));
	std::println("index of 2nd 1 = {}", arr.sequential_search(1, 1));
	std::println("index of 4 = {}", arr.sequential_search(4));
	std::println("index of 5 = {}", arr.sequential_search(5));
	std::println("index of 42 = {}", arr.sequential_search(42));
	std::println("index of 3rd 1 = {}", arr.sequential_search(1, 2));
}

void array_search_binary()
{
	StaticArray<int, 9> arr = {2, 17, 23, 42, 96, 205, 283, 396, 404};
	std::println("array = {}", arr);
	std::println();

	for (auto elem : arr._array) {
		std::println("index of {} = {}", elem, arr.binary_search(elem));
	}
	std::println("index of -5 = {}", arr.binary_search(-5));
	std::println("index of 500 = {}", arr.binary_search(500));
	std::println("index of 25 = {}", arr.binary_search(25));
}

void array_search_bogo()
{
	StaticArray<int, 15> arr = {3, 1, 4, 23, 5, 9, 2, 6, 42, 369, 108, 8, 902, 7, 85};
	std::println("array = {}", arr);
	std::println();

	std::println("index of 369 = {}", arr.bogo_search(369));
}

void array_find_min()
{
	StaticArray<int, 5> arr = {92, 54, 23, 87, 42};
	std::println("array = {}", arr);
	std::println();

	std::println("index of minimum value = {}", arr.find_min());
}

void array_find_max()
{
	StaticArray<int, 5> arr = {52, 92, 23, 87, 42};
	std::println("array = {}", arr);
	std::println();

	std::println("index of maximum value = {}", arr.find_max());
}

void array_sort_bubble()
{
	StaticArray<int, 15> arr = {3, 1, 4, 23, 5, 9, 2, 6, 42, 369, 108, 8, 902, 7, 85};
	std::println("array = {}", arr);
	std::println();

	arr.bubble_sort();
	std::println("sorted array: {}", arr);
}

void array_sort_selection()
{
	StaticArray<int, 15> arr = {3, 1, 4, 23, 5, 9, 2, 6, 42, 369, 108, 8, 902, 7, 85};
	std::println("array = {}", arr);
	std::println();

	arr.selection_sort();
	std::println("sorted array: {}", arr);
}

void array_sort_insertion()
{
	StaticArray<int, 15> arr = {3, 1, 4, 23, 5, 9, 2, 6, 42, 369, 108, 8, 902, 7, 85};
	std::println("array = {}", arr);
	std::println();

	arr.insertion_sort();
	std::println("sorted array: {}", arr);
}

int main()
{
	functions["array"]["search"]["sequential"] = array_search_sequential;
	functions["array"]["search"]["binary"] = array_search_binary;
	functions["array"]["search"]["bogo"] = array_search_bogo;
	functions["array"]["find"]["min"] = array_find_min;
	functions["array"]["find"]["max"] = array_find_max;
	functions["array"]["sort"]["bubble"] = array_sort_bubble;
	functions["array"]["sort"]["selection"] = array_sort_selection;
	functions["array"]["sort"]["insertion"] = array_sort_insertion;

	std::println("Enter algorithm to test.");
	std::println("Current options:");

	for (auto& f1 : functions | std::views::keys) {
		for (auto& f2 : functions.at(f1) | std::views::keys) {
			for (auto& f3 : functions.at(f1).at(f2) | std::views::keys) {
				std::println("- {} {} {}", f1, f2, f3);
			}
		}
	}

	std::string user_input;
	std::print(">>> ");
	std::getline(std::cin, user_input);

	std::istringstream iss{user_input};
	struct {
		std::string data_structure;
		std::string algorithm_class;
		std::string algorithm;
	} terms;
	iss >> terms.data_structure;
	iss >> terms.algorithm_class;
	iss >> terms.algorithm;

	std::println();

	functions[terms.data_structure][terms.algorithm_class][terms.algorithm]();
}
