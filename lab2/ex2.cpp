#include <iostream>
#include <sys/types.h>
#include <unistd.h>

auto main() -> int {
	
	auto a = fork();
	if(a == 0){
		std::cout << "ppid: " << getppid() << "\n";	
	}
	else{
		std::cout << "fork: " << a << "\n";
	}
	
		
	return 0;
}
