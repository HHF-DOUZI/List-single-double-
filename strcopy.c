#include "stdio.h"
#include "stdlib.h"
#include <assert.h>

char* Mystrcpy(char* dest, const char* src)
{
	assert(dest && src);
	char* tmp = dest;
	while (*dest++ = *src++)
	{
		printf("hhf\n");
	}
	return tmp;
}
int main()
{
	char arr1[10] = "";
	char arr2[] = "123456789109876541111111111111";
	char*p=Mystrcpy(arr1,arr2);
	printf("%s\n", p);
	return 0;
}
