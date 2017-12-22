#define _CRT_SECURE_NO_WARINGS
#define TRUE 1
#define FALSE 0

#include <stdio.h>

int main() {
	int num = 2;

	for (int i = 1; i <= 10; i++) {

		/* Printing Spaces */
		for (int j = 10; j >= i; j--) {
			printf("  ");
		}
		/* End of Printing Spaces */



		/* Printing Numbers */
		for (int j = 1; j <= i; j++) {
			while (isFractional(num) == FALSE) {
				num += 1;
			}
			printf("%4d", num++);
		}
		/* End of Printing Numbers */

		printf("\n");
	}
}

int isFractional(int num) {

	if (num < 2) {
		return FALSE;
	}
	else {
		for (int i = 2; i < num; i++) {
			if (num % i == 0)
				return FALSE;

		}
		return TRUE;

	}


}