#include <unistd.h>
#include <string>
#include <vector>

auto execute(std::vector<std::string> vect) -> int {
	auto argv = std::vector<char*>{};

	for(auto const& each : vect){
		argv.push_back(const_cast<char*> (each.c_str()));
	}
	argv.push_back(nullptr);

	auto env = std::vector<char*>{};
	env.push_back(nullptr);

	execve(argv[0], argv.data(), env.data());
	exit(EXIT_FAILURE);
	return 0;
}

auto main(int argc, char* argv[]) -> int {
	
	auto vec = std::vector<std::string>{};
	
	for (auto i = 1; i < argc; ++i){
			vec.push_back(argv[i]);
	}
	execute(vec);
	return 0;
}
