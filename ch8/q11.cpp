#include <cstdio>

int main(void) {
	int target;
	scanf("%d", &target);

	int sum25 = 0;
	for (int n25 = 0; sum25 < target; n25++, sum25 += 25) {
		int sum10 = sum25;
		for (int n10 = 0; sum10 < target; n10++, sum10 += 10) {
			int sum5 = sum10;
			for (int n5 = 0; sum5 < target; n5++, sum5 += 5) {
				int n1 = target - sum5;
				printf("25 * %-3d + 10 * %-3d + 5 * %-3d + %-3d   (%d, %d, %d, %d)\n",
						n25, n10, n5, n1, n25 * 25, n10 * 10, n5 * 5, n1);
			}
		}
	}

	return 0;
}
