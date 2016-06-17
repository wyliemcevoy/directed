#pragma once
#include <vector>

namespace puzzle {
	// data is a SORTED vector
	template <typename T>
	int FindPlateauWithSkipping(const std::vector<T> & data)
	{
		int i = 0;
		int longest_plateau = 1;
		bool on_longest_plateau = true;

		while (i < data.size())
		{
			// these nested if/else blocks exist to be able to skip i ahead
			// by the size of the currently known longest plateau, assuming we
			// are already not on the longest plateau
			if (on_longest_plateau)
			{
				if (data[i] == data[i+1])
				{
					++longest_plateau;
				}
				else
				{
					on_longest_plateau = false;
				}
				++i;
			}
			else {
				if (i + longest_plateau > data.size())
				{
					return longest_plateau;
				}

				if (data[i] == data[i + longest_plateau])
				{
					longest_plateau = true;
					i += longest_plateau;
				}
				else {
					++i;
				}
			}
		}
		return longest_plateau;
	}
}