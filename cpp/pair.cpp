#include <utility>
#include <cstdio>

int main(void) {
	printf("\n");

	printf("Basically...\n");
	printf("A templated struct with two fields; first and second\n");

	std::pair<int, std::pair<int, int>> ho = { 13, { 7, 17 }};
	
	struct man {
		int first = 111;
		int second = 222;
	} man;

	printf("\n");

	printf("ho:                   %d\n", ho);
	printf("ho.first:             %d\n", ho.first);
	printf("ho.second:            %d\n", ho.second);
	printf("ho.second.first:      %d\n", ho.second.first);
	printf("ho.second.second:     %d\n", ho.second.second);
	printf("man:                  %d\n", man);
	printf("man.first:            %d\n", man.first);
	printf("\n");
	printf("Ridiculous C++ implicit conversion stuff goin' on. #ask_ray\n");
	printf("\n");
	printf("Actually printf is just reading the first four bytes of ho...\n");
	printf("\n");
	printf("Q. Doesn't printf doesn't need to know the address of ho to\n");
	printf("access its byte sequence?\n");
	printf("A. Reading a byte sequence doesn't mean having a reference to\n");
	printf("the original byte sequence. You just need a copy of the same\n");
	printf("byte sequence - which is exactly what pass-by-value does\n");
	printf(">> type ho = *((type*) &data)\n");


	
	printf("\n");
	
	printf("ho[0] is invalid\n");
	printf("man[0] is invalid\n");
	printf("\n");
	printf("Why did you think struct is subscriptable? smh\n");

	printf("\n");

	printf("&ho:                  %p\n", &ho);
	printf("&ho.first:            %p\n", &ho.first);
	printf("&man:                 %p\n", &man);
	printf("&man.first:           %p\n", &man.first);
	printf("\n");
	printf("Checks out\n");


	return 0;
}
