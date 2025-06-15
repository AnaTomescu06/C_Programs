#include <stdio.h>

int main(void)
{
	int N, P = 0, i, j = 0, xi[100], ci[100];
	int m = 0, p_min, n[100], contor = 0, aux = 0, dif = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d ", &xi[i]);

	for (i = 0; i < N; i++)
		scanf("%d ", &ci[i]);

	scanf("%d\n", &p_min);

	// Calculul punctajului
	for (i = 0; i < N; i++)
		P += xi[i] * ci[i];

	if (P < p_min) {
		// Cu cat ar creste punctajul in cazul fiecarei materii
		for (i = 0; i < N; i++) {
			if (xi[i] < 10) {
				n[j] = (10 - xi[i]) * ci[i];
				j++;
				contor++;
			}
		}

		// Gasirea celor mai mari cresteri prin ordonare descrescatoare
		for (i = 0; i < contor - 1; i++) {
			for (j = i + 1; j < contor; j++) {
				if (n[i] < n[j]) {
					aux = n[i];
					n[i] = n[j];
					n[j] = aux;
				}
			}
		}

		i = 0;
		// Numarul minim de mariri
		while (dif < p_min - P && contor >= 0) {
			m++;
			dif += n[i];
			i++;
			contor--;
		}

		// Daca problema nu are solutie
		if (dif < p_min - P)
			m = -1;
	}

	printf("%d\n", m);

	return 0;
}
