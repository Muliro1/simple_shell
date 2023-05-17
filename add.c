#include <stdio.h>

int main() {
	int sum = 0;
	int i, num;

	printf("Enter ten integers:\n");

	for (i = 0; i < 10; i++) {
	scanf("%d", &num);
	sum += num;
	}

	printf("Sum of ten integers is: %d\n", sum);

	return 0;
}
