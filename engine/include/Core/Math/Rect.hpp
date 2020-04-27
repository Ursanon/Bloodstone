#ifndef RECT_HPP
#define RECT_HPP

namespace bs
{
	template <typename T>
	struct Rect
	{
		T X;
		T Y;
		T Width;
		T Height;
		
		Rect();
		Rect(const T& x, const T& y, const T& w, const T& h);
	};

	template<typename T>
	bs::Rect<T>::Rect()
		: X(0)
		, Y(0)
		, Width(0)
		, Height(0)
	{
	}

	template <typename T>
	Rect<T>::Rect(const T& x, const T& y, const T& w, const T& h)
		: X(x)
		, Y(y)
		, Width(w)
		, Height(h)
	{
	}
	
	typedef Rect<float> Rectf;
	typedef Rect<int> Recti;
}

#endif // !RECT_HPP