/*
 * Date: 17.11.14
 * Author: Jho
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {

	int num;
	int temp;
	int bit;
	int flag;

	printf("정수를 하나 입력하세요 >> ");
	scanf(" %d", &num);
	puts("");

	/* Loop */
	while (num != 0) {

		/* BIN */
		printf("이진수 : ");
		// 이진수 출력
		for (int i = 31; i >= 0; i--) {
			bit = (num & 1 << i ? 1 : 0);
			printf("%d", bit);

		}
		puts("");
		puts("");
		/* End of BIN */

		/* OCT */
		flag = 0;
		printf("팔진수: ");
		for (int i = 0; i < 11; i++)
			printf("  ");

		temp = 0;
		for (int i = 31; i >= 0; i--) {
			bit = num & 1 << i ? 1 : 0;

			if (i % 3 == 0) {

				temp += (bit*pow(2, (i % 3)));
				if (temp == 0 && flag == 0)
					printf(" ");
				else {
					printf("%d", temp);
					flag++;
				}
				temp = 0;

			}
			else {
				temp += (bit*pow(2, (i % 3)));
			}

		}

		printf("%8o", num);
		puts("");
		puts("");
		/* End of OCT */

		/* HEX */
		printf("십육진수: ");
		for (int i = 0; i < 12; i++)
			printf("  ");
		temp = 0;
		for (int i = 31; i >= 0; i--) {
			bit = num & 1 << i ? 1 : 0;

			if ((i % 4) == 0) {

				temp += (bit*pow(2, (i % 4)));
				if (temp == 0 && flag == 0)
					printf(" ");
				else if(temp < 10) {
					printf("%d", temp);
					flag++;
				}
				else {
					printf("%c", temp + 55);
					flag++;
				}
				temp = 0;

			}
			else {
				temp += (bit*pow(2, (i % 4)));
			}
		}

		printf("%8X", num);
		puts("");
		puts("");
		/* End of HEX */

		puts("");

		// 다시 입력
		printf("정수를 하나 입력하세요. >> ");
		scanf(" %d", &num);
		puts("");
	}
	/* End of Loop */

	printf("종료합니다..\n");
}