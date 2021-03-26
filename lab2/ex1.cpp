#include <iostream>

auto main() -> int {

	int* pointer = reinterpret_cast<int*> (0xdeadbeef);
	
	std::cout << *pointer;
	
	return 0;
}
