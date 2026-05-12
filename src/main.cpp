#include <print>

#include "static_array.hpp"

int main()
{
	StaticArray<int, 5> arr = {3, 1, 4, 1, 5};
	std::println("{}", arr);

	std::println("{}", arr.sequential_search(3));
	std::println("{}", arr.sequential_search(1));
	std::println("{}", arr.sequential_search(1, 1));
	std::println("{}", arr.sequential_search(4));
	std::println("{}", arr.sequential_search(5));
	std::println("{}", arr.sequential_search(42));
	std::println("{}", arr.sequential_search(1, 2));
}
