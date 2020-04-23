#ifndef TIME_HPP
#define TIME_HPP

#include <chrono>

typedef std::chrono::high_resolution_clock::time_point TimePoint;
typedef std::chrono::high_resolution_clock::duration TimeDuration;

template<typename TPeriod>
using ElapsedFloat = std::chrono::duration<float, TPeriod>;

namespace bs
{
	namespace time
	{
		inline TimePoint Now()
		{
			return std::chrono::high_resolution_clock::now();
		}

		template <typename TPeriod>
		inline float ElapsedFrom(const TimePoint& point)
		{
			return ElapsedFloat<TPeriod>(Now() - point).count();
		}
	}
}

#endif // !TIME_HPP