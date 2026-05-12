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
		return _has_value;
	}

	[[nodiscard]] bool operator!() const
	{
		return is_empty();
	}

	[[nodiscard]] value_type& value()
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
