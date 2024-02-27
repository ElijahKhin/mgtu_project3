#include <iostream>

int main(int argc, char** argv) {
	int test = 10;
	unsigned long long ll = -1;
	unsigned long l = -1;
	unsigned int i = -1;

	std::cout << "long long: " << (int)ll++ << " | " << "long: " << l++ << " | " << "u_int: " << i++ << std::endl;
}
