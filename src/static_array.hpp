#include <cstdint>
#include <format>
#include <random>
#include <string>

#include "optional.hpp"

template<typename T, std::size_t N>
class StaticArray {
public:
	using value_type = T;
	static constexpr std::size_t size = N;

	value_type _array[size]{};

	[[nodiscard]] value_type& operator[](std::size_t index) const
	{
		return _array[index];
	}

	/** -- Algorithm: Sequential Search --
	 * Time Complexity:
	 * - Worst Case: O(n)
	 * - Best Case:  O(1)
	 * Space Complexity: O(1)
	 */
	[[nodiscard]] auto sequential_search(value_type target, std::size_t target_iteration = 0) const
		-> Optional<std::size_t>
	{
		std::size_t index = 0;
		std::size_t iteration = 0;
		for (const auto elem : _array) {
			if (elem == target) {
				if (iteration == target_iteration) {
					return index;
				}
				iteration++;
			}
			index++;
		}

		return {};
	}

	/** -- Algorithm: Binary Search --
	 * Special Requirements: Ordered
	 * Time Complexity:
	 * - Worst Case: O(log(n))
	 * - Best Case:  O(1)
	 * Space Complexity: O(1)
	 */
	[[nodiscard]] auto binary_search(value_type target) const
		-> Optional<std::size_t>
	{
		std::size_t lower_bound = 0;
		std::size_t upper_bound = size;
		
		while (lower_bound < upper_bound) {
			std::size_t middle = lower_bound + (upper_bound - lower_bound) / 2;
			value_type current_value = _array[middle];
			if (current_value > target) {
				upper_bound = middle;
			} else if (current_value < target) {
				lower_bound = middle + 1;
			} else {
				return middle;
			}
		}

		return {};
	}

	/** -- Algorithm: Bogo Search --
	 * Time Complexity:
	 * - Worst Case: O(∞)
	 * - Best Case:  O(1)
	 * Space Complexity: O(1)
	 */
	[[nodiscard]] std::size_t bogo_search(value_type target) const
	{
		static std::mt19937 rng{std::random_device{}()};
		std::uniform_int_distribution<std::size_t> dist{0, size - 1};
		
		while (true) {
			std::size_t index = dist(rng);
			if (_array[index] == target) {
				return index;
			}
		}
	}
};

template<typename T, std::size_t N>
struct std::formatter<StaticArray<T, N>> {
	constexpr auto parse(std::format_parse_context& ctx) {
		return ctx.begin();
	}

	auto format(const StaticArray<T, N>& obj, std::format_context& ctx) const {
		std::string str = "";
		
		std::size_t i = 0;
		for (auto elem : obj._array) {
			str += std::format("{}", elem);
			if (i != N - 1) { 
				str += ", ";
			}
			i++;
		}
		return std::format_to(ctx.out(), "[{}]", str);
	}
};
