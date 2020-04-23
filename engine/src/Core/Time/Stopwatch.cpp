#include "Core/Time/Stopwatch.hpp"

bs::Stopwatch::Stopwatch()
	: startPoint_(time::Now())
{
}

void bs::Stopwatch::Stop()
{
	endPoint_ = time::Now();
}

void bs::Stopwatch::Restart()
{
	startPoint_ = time::Now();
	endPoint_ = startPoint_;
}