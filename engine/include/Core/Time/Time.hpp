#ifndef TIME_HPP
#define TIME_HPP

#include <chrono>

typedef std::chrono::high_resolution_clock::time_point TimePoint;
typedef std::chrono::high_resolution_clock::duration TimeDuration;

template<typename TPeriod>
using ElapsedDouble = std::chrono::duration<double, TPeriod>;

namespace bs
{
	class Time sealed
	{
	public:
		static TimePoint Now();

		template <typename TPeriod>
		static double ElapsedFrom(const TimePoint& point);
	};

	template<typename TPeriod>
	inline double Time::ElapsedFrom(const TimePoint& point)
	{
		return ElapsedDouble<TPeriod>(Now() - point).count();
	}
}

#endif // !TIME_HPP