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

		static Vec2<T> Up();
		static Vec2<T> Right();

		static Vec2<T> One();
		static Vec2<T> Zero();

		static Vec2<T> Lerp(const Vec2<T>& a, const Vec2<T>& b, const float& t);

		bool operator!= (const Vec2<T>& rhs) const;
		bool operator== (const Vec2<T>& rhs) const;
		Vec2<T> operator+ (const Vec2<T>& rhs) const;
		Vec2<T> operator* (const T& scalar) const;

		Vec2<T>& operator*= (const T& scalar);
		Vec2<T>& operator+= (const Vec2<T>& rhs);
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

	template <typename T>
	Vec2<T> Vec2<T>::Up()
	{
		return Vec2<T>(0, 1);
	}

	template <typename T>
	Vec2<T> Vec2<T>::Right()
	{
		return Vec2<T>(1, 0);
	}


	template <typename T>
	Vec2<T> Vec2<T>::One()
	{
		return Vec2<T>(1, 1);
	}

	template <typename T>
	Vec2<T> Vec2<T>::Zero()
	{
		return Vec2<T>();
	}

	template<typename T>
	Vec2<T> Vec2<T>::Lerp(const Vec2<T>& a, const Vec2<T>& b, const float& t)
	{
		return a * (1 - t) + b * t;
	}

	template <typename T>
	bool Vec2<T>::operator!= (const Vec2<T>& rhs) const
	{
		return this->X != rhs.X
			|| this->Y != rhs.Y;
	}

	template <typename T>
	bool Vec2<T>::operator== (const Vec2<T>& rhs) const
	{
		return this->X == rhs.X
			&& this->Y == rhs.Y;
	}

	template <typename T>
	Vec2<T> Vec2<T>::operator+ (const Vec2<T>& rhs) const
	{
		return Vec2<T>(this->X + rhs.X, this->Y + rhs.Y);
	}

	template <typename T>
	Vec2<T> Vec2<T>::operator* (const T& scalar) const
	{
		return Vec2<T>(this->X * scalar, this->Y * scalar);
	}

	template <typename T>
	Vec2<T>& Vec2<T>::operator*= (const T& scalar)
	{
		X *= scalar;
		Y *= scalar;

		return *this;
	}

	template <typename T>
	Vec2<T>& Vec2<T>::operator+= (const Vec2<T>& rhs)
	{
		X += rhs.X;
		Y += rhs.Y;

		return *this;
	}

	typedef Vec2<int> Vec2i;
	typedef Vec2<float> Vec2f;
	typedef Vec2<unsigned int> Resolution;
}

#endif