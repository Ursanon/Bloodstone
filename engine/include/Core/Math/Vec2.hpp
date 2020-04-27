#ifndef VEC2_HPP
#define VEC2_HPP

namespace bs
{
	template <typename T>
	struct Vec2
	{
		T X;
		T Y;

		Vec2();
		Vec2(const T& x, const T& y);
	};

	template <typename T>
	Vec2<T>::Vec2()
		: X(0)
		, Y(0)
	{
	}

	template <typename T>
	Vec2<T>::Vec2(const T& x, const T& y)
		: X(x)
		, Y(y)
	{
	}

	typedef Vec2<int> Vec2i;
	typedef Vec2<float> Vec2f;
	typedef Vec2<unsigned int> Resolution;
}

#endif