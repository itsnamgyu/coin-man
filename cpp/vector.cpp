#include <vector>
#include <cstdio>

int main(void) {
	std::vector<int> vector = { 0, 1, 2, 3 };

	printf("\n");
	printf("\n");
	printf("Basic Operations\n");
	printf("\n");

	for (auto i : vector)
		printf("%d", i);
	printf("\n");
	
	printf("Popped: %d\n", vector.back());
	vector.pop_back();

	for (auto i : vector)
		printf("%d", i);
	printf("\n");

	printf("Pushed 4\n");
	vector.push_back(4);
	
	for (auto i : vector)
		printf("%d", i);
	printf("\n");

	printf("Address of vector:        %p\n", &vector);
	//printf("Vector as pointer: %p\n", vector);
	printf("Vector as pointer:        n/a\n");
	printf("Vector data as pointer:   %p\n", vector.data());

	printf("Address of first:         %p\n", &vector.front());
	printf("Address of back:          %p\n", &vector.back());

	printf("\n");
	printf("\n");
	printf("Misc\n");
	printf("\n");

	printf("Max size:                 %lu\n", vector.max_size());
	printf("\tApparently max_size is %%lu for clang900\n");
	printf("\tThis is the theortical max size (n_element) of vector\n");
	printf("\tdue to implementation details, not memory.\n");
	printf("\tMemory may be smaller\n");
	printf("\tMax size for clang900 is 2^62 or 2^64/sizeof(int)\n");




	return 0;
}
