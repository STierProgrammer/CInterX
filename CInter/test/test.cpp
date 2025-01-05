#include <iostream>
#include <vector>
#include "../src/utils/vectors.cpp"

void static run() {
	std::vector<char> chars = { 'a', 'b', 'c' };

	char ch = VectorUtils::shift(chars);

	std::cout << "Character: " << ch << std::endl;

	std::cout << "\n";

	std::cout << "Characters inside chars vector: ";

	for (char ch : chars) {
		std::cout << ch << " ";
	}

	std::cout << std::endl;
}