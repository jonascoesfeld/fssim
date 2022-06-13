#ifndef AUTONOMOUS_SYSTEM_UTIL_HPP
#define AUTONOMOUS_SYSTEM_UTIL_HPP

#include <random>
#include <type_traits>

namespace util {

/**
 * generate a random number
 * @tparam T A floating point typename
 * @param min lower boundary (inclusive)
 * @param max upper boundary (exclusive)
 * @return a random double number between min and max
 */
	template<typename T>
	auto rng(T min, T max) -> std::enable_if_t<std::is_floating_point_v<T>, T>
	{
		static std::random_device rd;
		static std::default_random_engine el(rd());
		std::uniform_real_distribution<T> dist(min, max);
		return dist(el);
	}

/**
 * generate a random number
 * @tparam T A integral typename
 * @param min lower boundary (inclusive)
 * @param max upper boundary (inclusive)
 * @return a random integer number between min and max
 */
	template<typename T>
	auto rng(T min, T max) -> std::enable_if_t<std::is_integral_v<T>, T>
	{
		static std::random_device rd;
		static std::default_random_engine el(rd());
		std::uniform_int_distribution<T> dist(min, max);
		return dist(el);
	}
} // namespace util

#endif // AUTONOMOUS_SYSTEM_UTIL_HPP
