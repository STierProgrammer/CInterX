#include "../../include/utils/vectors.h"

template<typename T>
T VectorUtils::shift(std::vector<T>& vector) {
	T element = vector.front();
	vector.erase(vector.begin());

	return element;
}