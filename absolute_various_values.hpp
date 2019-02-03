#pragma once

#include <iterator>
#include <algorithm>

template<class InputIt>
size_t absolute_various_values(
	InputIt first,
	InputIt last
)
{
	int dst = std::distance(first, last);
	size_t result = std::abs(dst);
	if (dst < 0)
		std::swap(first, last);
	int sum = 0;

	for (auto i = first, j = std::prev(last); i != j;)
	{
		for (; i != j && *i == *std::next(i); result--, i++) ;
		for (; i != j && *j == *std::prev(j); result--, j--) ;

		if (i != j)
		{
			sum = *i + *j;
			if (0 == sum)
				result--, i++, j--;
			else if (sum < 0)
				i++;
			else
				j--;
		}
	}

	return result;
}
