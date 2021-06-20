#include <sys/mman.h>
#include <iostream>

auto main() ->int{
		auto const page = mmap(nullptr, 4096, PROT_WRITE, MAP_ANONYMOUS, -1, 0);
		
		std::cout<< "\n" << munmap(page, 4096) << "\n";
}