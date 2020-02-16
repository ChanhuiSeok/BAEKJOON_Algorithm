#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int n, temp=0, idx = 1, count = 0;
	int tempB=0;
	int main = 666;
	int cycle = 666;
	scanf("%d", &n);

	while (1) {
		
		if (n == 1)
		{
			printf("%d", main);
			break;
		}
		else {
			cycle = cycle + 1;
			main = cycle;

			while (main > 0) {
				tempB = main % 10;
				if (tempB == 6) {
					count++;
					main = main / 10;
				}
				else if (count < 3){
					main = main / 10;
					count = 0;
				}
				else if (count >= 3) {
					main = main / 10;
				}
			}

			if (count >= 3) 
				idx = idx + 1;
			
			count = 0;
			
			if (idx == n) {
				printf("%d", cycle);
				break;
			}
		}

	}

}