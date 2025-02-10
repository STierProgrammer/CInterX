#ifndef CINTER_UTILS_VECTOR_UTILS_H
#define CINTER_UTILS_VECTOR_UTILS_H

#include <vector>

namespace VectorUtils {	
	template<typename T>
	T shift(std::vector<T>& vector) {
		T element = vector.front();
		vector.erase(vector.begin());
		return element;
	}
};

#endif // !CINTER_UTILS_VECTOR_UTILS_H
