#include <iostream>
#include <vector>

#include "include/utils/vectors.hh"

int main() {
	std::vector<int> vec = { 1, 2, 3 };
	
	for (int x : vec) {
		std::cout << x << '\n';
	}

	VectorUtils::shift<int>(vec);

	for (int x : vec) {
		std::cout << x << '\n';
	}

	return 0;
}