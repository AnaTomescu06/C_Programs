#include <stdio.h>
#include <math.h>

int main(void)
{
unsigned long long a, b;
double N, i, a_max = -1, b_max = -1, a_first = -1, b_first = -1;
double n_a = 0, n_b = 0, ps = 0;

scanf("%lf", &N);

for (i = 0; i < N; i++) {
	scanf("%llo %llo", &a, &b);

		//Produsul scalar
		ps += a * b;

		//Gasirea celui de al doilea maxim
		if (a > a_first) {
			a_max = a_first;
			a_first = a;
		} else if (a < a_first && a > a_max) {
			a_max = a;
		}
		if (b > b_first) {
			b_max = b_first;
			b_first = b;
		} else if (b < b_first && b > b_max) {
			b_max = b;
		}

		//Suma de patrate pentru norma 2
		n_a += pow(a, 2);
		n_b += pow(b, 2);
	}

	//Radicalul pentru norma 2
	n_a = sqrt(n_a);
	n_b = sqrt(n_b);

	printf("%.lf\n%.lf %.lf\n%.7lf %.7lf\n", ps, a_max, b_max, n_a, n_b);

	return 0;
}
