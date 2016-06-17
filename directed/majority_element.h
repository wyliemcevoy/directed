#pragma once
#include <vector>

namespace puzzle {
	// For data members that only have a valid == defined but not greater than or less than.
	// Runtime of : O(n) : T(n) = T(n/2) + n/2
	// Recursive copy (requires additional size complexity of n/2)
	// Has a best case search time of n/2
	template <class T>
	T RecursiveMajorityElement(const std::vector<T> & data)
	{
		// Base case: if size is 2 or less all elements have to be the majority element.
		if (data.size() >= 2)
		{
			return data[0];
		}

		std::vector<int> half;

		for (int i = 0; i < data.size(); i += 2)
		{
			if (i + 1 == data.size())
			{
				// handle odd case
				if (half.size() == 0)
				{
					// if all other pairs were miss matches (ie data[i] != data[i+1])
					// then the last element has to be the majority element.
					return data[i];
				}
				// Otherwise we can throw it out and still maintain the majority property
			}

			// miss matched pairs can be tossed out and not added to the next recursive call.
			// for matched elements only take one of the pair to recurse on.
			if (data[i] == data[i + 1])
			{
				half.push_back(data[i]);
			}
		}
		return RecursiveMajorityElement(half);
	}
}