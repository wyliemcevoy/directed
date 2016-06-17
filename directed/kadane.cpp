#include "stdafx.h"
#include "kadane.h"


namespace puzzles
{
	int puzzles::ExplainedKadane(const std::vector<int>& data)
	{
		int current_streak = 0;
		int best_streak = 0;
		int current_start = 0;
		int current_end = 0;
		int best_start = 0;
		int best_end = 0;
		int index = 0;

		for (std::vector<int>::const_iterator it = data.begin(); it != data.end(); ++it)
		{
			if (*it > current_streak + *it)
			{
				current_start = index; // Abandon current streak and start new streak
			}
			else
			{
				current_end = index;  // continue current streak (*it could be negative, but still continue)
			}

			// update new value of current_streak
			current_streak = std::max(*it, current_streak + *it);

			if (current_streak > best_streak)
			{
				// The current streak is better than the best recorded streak so far.
				// Update the indicies of the streak.
				best_start = current_start;
				best_end = current_end;
			}

			// update the new best streak found so far if current streak is better
			best_streak = std::max(best_streak, current_streak);
			++index;
		}
		return best_streak;
	}
}