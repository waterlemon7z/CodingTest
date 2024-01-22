#include <stdio.h>

int main()
{
	int A, B, temp;
	scanf("%d %d", &A, &B);
	temp = B;
	printf("%d\n", A * (B % 10));
	B /= 10;
	printf("%d\n", A * (B % 10));
	B /= 10;
	printf("%d\n", A * (B % 10));
	printf("%d\n", A * temp);
}