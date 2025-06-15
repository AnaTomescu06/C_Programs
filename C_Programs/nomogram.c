#include <stdio.h>

int main(void)
{
	int T, N, M;
	scanf("%d", &T);

	while (T > 0) {
		scanf("%d %d", &N, &M);
		int ln_res[100][100], cl_res[100][100];
		int correct = 1;

		for (int i = 0; i < N; i++) { // Restrictii linii
			int K;
			scanf("%d", &K);
			for (int j = 0; j < K; j++)
				scanf("%d", &ln_res[i][j]);
		}
		for (int i = 0; i < M; i++) { // Restrictii coloane
			int K;
			scanf("%d", &K);
			for (int j = 0; j < K; j++)
				scanf("%d", &cl_res[i][j]);
		}
		int nom[100][100];
		for (int i = 0; i < N; i++) { // Nomograma
			for (int j = 0; j < M; j++)
				scanf("%d", &nom[i][j]);
		}

		correct = 1;
		for (int i = 0; i < N; i++) { // Verific restrictiile liniilor
			int consb = 0, id = 0;
			for (int j = 0; j < M; j++) {
				if (nom[i][j] == 1)
					consb++;
				if (nom[i][j] == 0) {
					if (consb > 0 && consb != ln_res[i][id]) {
						correct = 0;
						break;
					} else if (consb > 0) {
						id++;
					}
					consb = 0;
				}
			}
			if (consb > 0 && consb != ln_res[i][id])
				correct = 0;
		}
		if (correct) {
			for (int j = 0; j < M; j++) { // Verific restrictiile coloanelor
				int consb = 0, id = 0;
				for (int i = 0; i < N; i++) {
					if (nom[i][j] == 1)
						consb++;
					if (nom[i][j] == 0 && consb > 0 && consb != cl_res[j][id]) {
						correct = 0;
						break;
					} else if (nom[i][j] == 0 && consb > 0) {
						id++;
					}
					if (nom[i][j] == 0)
						consb = 0;
				}
				if (consb > 0 && consb != cl_res[j][id])
					correct = 0;
			}
		}
		if (correct == 1)
			printf("Corect\n");
		else
			printf("Eroare\n");
		T--;
	}
	return 0;
}
