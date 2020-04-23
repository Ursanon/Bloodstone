#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP

#include "Core/Time/Time.hpp"

namespace bs
{
	class Stopwatch
	{
	public:
		Stopwatch();

		void Stop();

		void Restart();

		template <typename TPeriod>
		double GetElapsedTime();

	private:
		TimePoint endPoint_;
		TimePoint startPoint_;
	};

	template<typename TPeriod>
	inline double Stopwatch::GetElapsedTime()
	{
		return std::chrono::duration<double, TPeriod>(endPoint_ - startPoint_).count();
	}
}

#endif // !STOPWATCH_HPP