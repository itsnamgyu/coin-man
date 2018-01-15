#include <cstdio>
#include <vector>
#include <cstdlib>

typedef unsigned int uint;

uint generate (unsigned long long binary);

void print_binary(uint n);

bool get(uint n, int i);

uint set(uint n, int i);

uint clear(uint n, int i);

uint clear_msbs(uint n, int i);

uint clear_lsbs(uint n, int i);

uint update(uint n, int i, bool b);

int main(void) {
	uint n;
	n = generate(1001011010110101010);
	print_binary(n);

	printf("Get 31 - 0\n");
	for (int i = 31; i >= 0; --i)
		printf("%d", get(n, i));
	printf("\n");

	n = generate(1001011010110101010);
	print_binary(n);

	srand(time(NULL));

	int a, b;

	a = rand() % 32;
	printf("Set %d\n", a);
	n = set(n, a);
	print_binary(n);

	a = rand() % 32;
	printf("Clear %d\n", a);
	n = clear(n, a);
	print_binary(n);

	a = rand() % 32;
	b = rand() % 2;

	printf("Update %d, %d\n", a, b);
	n = update(n, a, b);
	print_binary(n);

	a = rand() % 32;
	printf("Clear msbs %d\n", a);
	n = clear_msbs(n, a);
	print_binary(n);

	a = rand() % 32;
	printf("Clear lsbs %d\n", a);
	n = clear_lsbs(n, a);
	print_binary(n);

	return 0;
}

uint generate (unsigned long long binary) {
	uint n = 0;

	for (uint i = 1; binary; binary /= 10, i *= 2)
		if (binary % 10)
			n += i;

	return n;
}

void print_binary(uint n) {
	for (int i = 0; i < 32; ++i)
		printf("%d", (31 - i) % 10);
	printf("\n");

	auto sequence = std::vector<bool>();
	
	for (int i = 0; i < 32; ++i, n /= 2) 
		sequence.push_back(n % 2);

	for (auto i = sequence.rbegin(); i != sequence.rend(); ++i)
		printf("%d", *i ? 1 : 0);
	printf("\n");
}

bool get(uint n, int i) {
	return ((1 << i) & n) != 0;
}

uint set(uint n, int i) {
	return (1 << i) | n;
}

uint clear(uint n, int i) {
	return (~(1 << i) & n);
}

uint clear_msbs(uint n, int i) {
	uint mask = (1 << i) - 1;
	return n & mask;
}

uint clear_lsbs(uint n, int i) {
	int imask = -1;
	uint mask = *((uint*)&imask); // we shouldn't be using unsigned stuff :(
	mask = mask << (i + 1);
	return n & mask;
}

uint update(uint n, int i, bool b) {
	return n | (b << i);
}
