#include <stdio.h>


int main()
{
	int i = 7;
	int* ip = &i;
	printf("Address %p contains %d\n", ip, *ip);
	*ip = 8;
	printf("Address %p contains %d\n", ip, *ip);
	printf("Value of i %d\n", i);
	int *j = &i;   // j is address and *j is contains at this address which is *j == 8
	printf("Address of j %d\n", *j);
	return 0;
};
