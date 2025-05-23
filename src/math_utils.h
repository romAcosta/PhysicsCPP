#pragma once
#include <cstdlib>
#include <algorithm>


inline float randomf() {
	return rand() / (float)RAND_MAX;
}

inline float randomf(float min, float max) {
	if (min > max) {
		std::swap(min, max);
	}
	return min + (max - min) * randomf();
}

inline float randomf(float max) {
	return randomf(0, max);
}