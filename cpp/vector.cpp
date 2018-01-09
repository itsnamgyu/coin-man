#include <vector>
#include <cstdio>

namespace ho {
	class man {
		public:
			man() {
				printf("man constructed\n");
			}
	};
}

int main(void) {
	{
		std::vector<int> vector = { 0, 1, 2, 3 };

		printf("\n");
		printf("Basic Operations\n");

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


		printf("\n");
		printf("\n");
		printf("Guessing The Internals...\n");
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
	} printf("\n"); {
		printf("auto vector = std::vector<ho::man>(2);\n");
		printf("----------------------------------------------\n");
		auto vector = std::vector<ho::man>(2);
		printf("----------------------------------------------\n");
	} printf("\n\n"); {
		auto vector = std::vector<std::pair<int, int>>();
		vector.push_back(std::make_pair(17, 23));
		printf("----------------------------------------------\n");
		printf("First pair is %d, %d\n", vector[0].first, vector[0].second);
		printf("Second pair is %d, %d\n", vector[1].first, vector[1].second);
		printf("Size is %d\n", vector.size());
		printf("----------------------------------------------\n");
		printf("Accessing a vector element out-of-bounds will not\n");
		printf("do anything to the vector -> the [] operator for vector\n");
		printf("probably just does [] on the internal data\n");
	}

	return 0;
}
