#include <cstdint>
#include <format>
#include <string>

#include "optional.hpp"

template<typename T, std::size_t N>
class StaticArray {
public:
	using value_type = T;
	static constexpr std::size_t size = N;

	value_type _array[size]{};

	[[nodiscard]] value_type operator[](std::size_t index) const
	{
		return _array[index];
	}

	[[nodiscard]] auto sequential_search(value_type target, std::size_t target_iteration = 0) const
		-> std::optional<std::size_t>
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
