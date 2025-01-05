#include <array>
#include <cstddef>
#include <iostream>
#include <optional>

//Usage of std::optional coming from c++17
std::optional<size_t>	binary_search(std::array<int, 11> &array, int number_to_search)
{
	size_t	middle;
	size_t	size;
	size_t	lower_limit;
	size_t	higher_limit;

	size = array.size();
	if (size == 0)
		return (std::nullopt);
	lower_limit = 0;
	higher_limit = size - 1;
	while (lower_limit <= higher_limit)
	{
		middle = (lower_limit + higher_limit) / 2;
		if (array[middle] == number_to_search)
			return (middle);
		if ((middle == 0 && number_to_search < array[middle]) || \
				(middle == (size - 1) && number_to_search > array[middle]))
			return (std::nullopt);
		if (number_to_search < array[middle])
			higher_limit = (middle - 1);
		else
			lower_limit = (middle + 1);
	}
	return (std::nullopt);
}

int	main()
{
	std::array<int, 11>	array = {1, 2, 4, 6, 8, 10, 20, 30, 50, 80, 100};
	std::array<int, 5>	values_to_test = {80, 2, 1, 100, 200};
	std::optional<size_t> result;

	for (int &value : values_to_test)
	{
		result = binary_search(array, value);
		if (result.has_value())
			std::cout << "The element " << value << " was found in index " << result.value() << std::endl;
		else
			std::cout << "Element " << value << " not found" << std::endl;
	}
	return (0);
}
