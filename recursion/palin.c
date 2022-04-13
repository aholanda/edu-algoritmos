#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

static int palin(char *str, int first, int last) {
	/* integrity constraints or preconditions */
	if (str == NULL || strlen(str) == 0) {
		fprintf(stderr, "Error: empty string!\n");
		exit(-1);
	}

	/* only one character */
	if (strlen(str) == 1)
		return TRUE;

	/* compare symmetrical characters */
	if (str[first] != str[last])
		return FALSE;

	/* check boundaries */
	if (first < last + 1)
		palin(str, ++first, --last);

	return TRUE;
}

int palindrome(char *str) {
	int is_palin = palin(str, 0, strlen(str) - 1);
	char *ans;
	
	if (is_palin == TRUE)
		ans = "is";
	else
		ans = "is not";

	printf("The word '%s' %s palindrome\n", str, ans);
}

int main(int argc, char*argv) {
	char *str = "ababa";

	palindrome(str);
}
