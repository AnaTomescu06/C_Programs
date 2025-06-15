#include <stdio.h>

int main(void)
{
	int n, i, j, board[1000][1000], position[1000][1000] = {0};
	double distance = 0;

	scanf("%d\n", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &board[i][j]);
	i = 0; j = 0;

	while (position[i][j] == 0) {
		position[i][j] = 1;

		if ((i + j) % 2 == 0) {
		//Daca patratul este alb
			if (board[i][j] >= 0 && j + board[i][j] < n) {
			//Daca numarul este pozitiv si piesa nu iese din tabla
				distance += board[i][j];
				j += board[i][j];
			} else if (board[i][j] >= 0 && board[i][j] > n - j - 1) {
			//Daca numarul este pozitiv si piesa iese din tabla
				distance += board[i][j];
				j = (j + board[i][j] - n) % n;
			} else if (board[i][j] < 0 && j + board[i][j] >= 0) {
			//Daca numarul este negativ si piesa nu iese din tabla
				distance -= board[i][j];
				j += board[i][j];
			} else if (board[i][j] < 0 && -board[i][j] > j) {
			//Daca numarul este negativ si piesa iese din tabla
				distance -= board[i][j];
				j = n - 1 - (-board[i][j] - j - 1) % n;
			}

		} else if ((i + j) % 2 != 0) {
		//Daca patratul este negru
			if (board[i][j] >= 0 && i + board[i][j] < n) {
			//Daca numarul este pozitiv si piesa nu iese din tabla
				distance += board[i][j];
				i += board[i][j];
			} else if (board[i][j] >= 0 && board[i][j] > n - i - 1) {
			//Daca numarul este pozitiv si piesa iese din tabla
				distance += board[i][j];
				i = (i + board[i][j] - n) % n;
			} else if (board[i][j] < 0 && i + board[i][j] >= 0) {
			//Daca numarul este negativ si piesa nu iese din tabla
				distance -= board[i][j];
				i += board[i][j];
			} else if (board[i][j] < 0 && -board[i][j] > i) {
			//Daca numarul este negativ si piesa iese din tabla
				distance -= board[i][j];
				i = n - 1 - (-board[i][j] - i - 1) % n;
			}
		}
	}

	printf("%.lf\n%d ", distance, n - i);

	if (j < 26)
		printf("%c\n", 'A' + j);
	else if (j >= 26)
		printf("%c%c\n", 'A' + j / 26 - 1, 'A' + j % 26);

	return 0;
}
