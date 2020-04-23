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
		float GetElapsedTime();

	private:
		TimePoint endPoint_;
		TimePoint startPoint_;
	};

	template<typename TPeriod>
	inline float Stopwatch::GetElapsedTime()
	{
		return std::chrono::duration<float, TPeriod>(endPoint_ - startPoint_).count();
	}
}

#endif // !STOPWATCH_HPP