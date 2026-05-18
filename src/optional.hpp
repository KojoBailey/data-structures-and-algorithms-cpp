#ifndef ALGO_DATA_OPTIONAL
#define ALGO_DATA_OPTIONAL

#include <format>
#include <stdexcept>
#include <string>
#include <string_view>

class EmptyOptionalAccess : public std::runtime_error {
public:
	EmptyOptionalAccess()
		: std::runtime_error("Tried to access optional value when object was empty.")
	{}
};

template<typename T>
class Optional {
public:
	using value_type = T;

	Optional() {}

	Optional(value_type value) : _value(value)
	{
		_has_value = true;
	}

	[[nodiscard]] bool is_empty() const
	{
		return !_has_value;
	}

	[[nodiscard]] value_type& value()
	{
		if (!_has_value) {
			throw EmptyOptionalAccess{};
		}
		return _value;
	}

	[[nodiscard]] value_type value_copy() const
	{
		if (!_has_value) {
			throw EmptyOptionalAccess{};
		}
		return _value;
	}

private:
	value_type _value{};
	bool _has_value{false};
};

template<typename T>
struct std::formatter<Optional<T>> {
	constexpr auto parse(std::format_parse_context& ctx) {
		return ctx.begin();
	}

	auto format(const Optional<T>& obj, std::format_context& ctx) const {
		if (obj.is_empty()) {
			return std::format_to(ctx.out(), "Optional::Empty");
		}
		return std::format_to(ctx.out(), "Optional::{{{}}}", obj.value_copy());
	}
};

#endif
