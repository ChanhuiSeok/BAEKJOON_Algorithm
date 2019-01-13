#include <stdio.h>
#include <string.h>

int main() {

	char input[1000000];
	gets(input);

	int i = 0;
	int cnt = 0;

	while (input[i] != '\0') {
		if (input[i] != ' ' && input[i + 1] == ' ')
			cnt++;
		if (input[i] != ' ' && input[i + 1] == '\0')
			cnt++;
		i++;
	}

	printf("%d", cnt);

	return 0;
}