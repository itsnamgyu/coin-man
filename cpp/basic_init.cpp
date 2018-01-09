#include <cstdio>
#include <string>

namespace ho {
	class member {
		public:
			member() {
				printf("member default contructed\n");
			}

			member(member& origin) {
				printf("member copy-constructed\n");
			}
	};

	class man {
		public:
			man() {
			//man() : ho() { // WORKS - same
				printf("man default constructed\n");
				//ho(); ERROR - doy
				//ho = member(); // WORKS - extra construct
			}

			man(man& origin) {
			//man(man& origin) : ho(origin.ho) { // WORKS - same
				printf("man copy-constructed\n");
				// ho(origin.ho); ERROR - doy
				// ho = member(origin.ho); // WORKS - extra copy
				// ho = origin.ho; // WORKS - raw copy (assignment)
			}
		private:
			member ho;
	};
}

int main(void) {
	printf("\n");

	printf("Q. Why does copy constructor need a ref-qualifier?\n");
	printf("A. If it doesn't (i.e. man(man origin)), then calling the\n");
	printf("   copy constructor would internally do origin_param = origin_arg\n");
	printf("   which would call the copy constructor again -> recursive man!\n");

	printf("\n");

	printf("ho::member member_a;\n");
	printf("------------------------------\n");
	ho::member member_a;
	printf("------------------------------\n");
	
	printf("\n");

	printf("ho::member member_b();\n");
	printf("------------------------------\n");
	ho::member member_b();
	printf("------------------------------\n");
	printf("Dafuq this is just a function declaration... smh\n");
	
	printf("\n");

	printf("ho::member member_c;\n");
	printf("member_c = ho::member();\n");
	printf("------------------------------\n");
	ho::member member_c;
	member_c = ho::member();
	printf("------------------------------\n");
	printf("Q. Why doesn't this copy-construct?\n");
	printf("A. Why would it - since it's the exact same type, you just\n");
	printf("   need to raw-copy the data\n");
	printf("Q. What if it's not the same type - but it is a child type?\n");
	printf("A. Let's do that in oop.cpp\n"); // TODO

	printf("\n");

	printf("ho::man man;\n");
	printf("------------------------------\n");
	ho::man man;
	printf("------------------------------\n");
	printf("Note that the user-defined default constructor for ho may or may\n");
	printf("not have an initializer list [ man() : ho() ]; it's the same\n");
	printf("However, calling ho() within constructor definition\n");
	printf("doesn't work - like ho::man man() vs ho::man man; man();\n");
	printf("Also note that explicitly calling man = ho::man() does not\n");
	printf("disable the implicit initilization of man, thus calls the\n");
	printf("ho::man() constructor for the second time\n");
	printf("Terminology! A non-user-defined default constructor is\n");
	printf("called an implicit default constrcutor\n");

	printf("\n");

	printf("ho::man nan = man;\n");
	printf("------------------------------\n");
	ho::man nan = man;
	printf("------------------------------\n");
	printf("Same as default constructor\n");

	printf("\n");
	

	return 0;
}
