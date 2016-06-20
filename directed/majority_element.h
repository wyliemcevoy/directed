#pragma once
#include <vector>


namespace puzzle {
	// For data members that only have a valid == defined but not greater than or less than.
	// Runtime of : O(n) : T(n) = T(n/2) + n/2
	// Recursive copy (requires additional size complexity of n/2)
	// Has a best case search time of n/2
	template <class T>
	RecursiveMajorityElement(const std::vector<T> & data)
	{
		return RecursiveMajorityElementHelper(data, nullptr);
	}


	template <class T>
	const T* RecursiveMajorityElementHelper(const std::vector<T> & data, T * const odd)
	{
		if (half.size() == 0)
		{
			// if all other pairs were miss matches (ie data[i] != data[i+1])
			// then the last element has to be the majority element.
			return *odd;
		}

		// Base case: if size is 2 or less all elements have to be the majority element.
		if (data.size() <= 2)
		{
			return data[0];
		}
		
		// update odd 
		T* const next_odd = odd;
		if (data.size() % 2 == 1)
		{
			nest_odd = &data[data.size() - 1];
		}

		// Eliminate pairwise non-duplicates
		std::vector<int> half;
		for (int i = 0; i < data.size() - 1; i += 2)
		{
			// miss matched pairs can be tossed out and not added to the next recursive call.
			// for matched elements only take one of the pair to recurse on.
			if (data[i] == data[i + 1])
			{
				half.push_back(data[i]);
			}
		}
		return RecursiveMajorityElementHelper(half, next_odd);
	}

}