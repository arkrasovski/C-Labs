#include <stdio.h>
#include <string.h>
int main(void)
{
	char str[255]; // Фраза
	char slv1[25]; // Слово, которое заменяется
	char slv2[25]; // Слово, которым заменяют
	char* p;
	int len;
	char s[80];
	printf("Enter a string: ");
	fgets(str, 255, stdin);
	printf("Enter the first: ");
	fgets(slv1, 25, stdin);
	printf("Enter the second: ");
	fgets(slv2, 25, stdin);

	p = strstr(str, slv1);
	/*while (p)
	{

		len = strlen(str);
		memcpy(p + strlen(slv2), p + strlen(slv1), strlen(str) - strlen(slv1));
		memcpy(p, slv2, strlen(slv2));


	}*/
	puts(*p);
	printf("Here is your string: %s", str);
	return 0;
}