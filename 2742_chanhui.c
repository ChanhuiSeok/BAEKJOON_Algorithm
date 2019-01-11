#include <stdio.h>

// baekjoon_#2742
// Chanhui Seok (chanhuicom@gmail.com)

int main() {

	int input;
	int print_in;
	scanf("%d", &input);

	print_in = input;

	for (int i = 0; i < input; i++)
		printf("%d\n", print_in--);	

	return 0;
}