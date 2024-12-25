#include <vector>

namespace VectorUtils {
	template<typename T>
	T shift(std::vector<T>& vector) {
		T element = vector.front();
		vector.erase(vector.begin());

		return element;
	}
};