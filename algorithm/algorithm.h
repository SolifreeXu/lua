#pragma once

namespace forever
{
	//template <class T>
	//inline void swap(T &x, T &y)
	//{
	//	x ^= y;
	//	y ^= x;
	//	x ^= y;
	//}

	// STL‘¥¬Î–Œ Ω

	template <class T>
	inline void swap(T &left, T &right)
	{
		int temp = left;
		left = right;
		right = temp;
	}

	template <class T>
	inline const T& max(const T& left, const T& right)
	{
		return left < right ? right : left;
	}

	template <class T>
	inline const T& min(const T& left, const T& right)
	{
		return right < left ? right : left;
	}
}