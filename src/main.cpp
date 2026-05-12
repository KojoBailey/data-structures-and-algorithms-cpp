#include <iostream>
#include <print>

#include "static_array.hpp"

int main()
{
	std::println("Enter algorithm to test.");
	std::println("Current options:");
	std::println("- array search sequential");
	std::println("- array search binary");
	std::println("- array search bogo");

	std::string user_input;
	std::print(">>> ");
	std::getline(std::cin, user_input);

	std::println();

	if (user_input == "array search sequential") {
		StaticArray<int, 5> arr = {3, 1, 4, 1, 5};
		std::println("array = {}", arr);
		std::println();

		std::println("index of 3 = {}", arr.sequential_search(3));
		std::println("index of 1st 1 = {}", arr.sequential_search(1));
		std::println("index of 2nd 1 = {}", arr.sequential_search(1, 1));
		std::println("index of 4 = {}", arr.sequential_search(4));
		std::println("index of 5 = {}", arr.sequential_search(5));
		std::println("index of 42 = {}", arr.sequential_search(42));
		std::println("index of 3rd 1 = {}", arr.sequential_search(1, 2));
	} else if (user_input == "array search binary") {
		StaticArray<int, 9> arr = {2, 17, 23, 42, 96, 205, 283, 396, 404};
		std::println("array = {}", arr);
		std::println();

		for (auto elem : arr._array) {
			std::println("index of {} = {}", elem, arr.binary_search(elem));
		}
		std::println("index of -5 = {}", arr.binary_search(-5));
		std::println("index of 500 = {}", arr.binary_search(500));
		std::println("index of 25 = {}", arr.binary_search(25));
	} else if (user_input == "array search bogo") {
		StaticArray<int, 15> arr = {3, 1, 4, 23, 5, 9, 2, 6, 42, 369, 108, 8, 902, 7, 85};
		std::println("array = {}", arr);
		std::println();

		std::println("index of 369 = {}", arr.bogo_search(369));
	}
}
