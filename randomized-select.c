#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void
swap(int *a, int *b)
{
	int t = *a;

	*a = *b;
	*b = t;
}

int 
partition(int A[], int p, int r)
{
	int i, j;
	int x;

	i = p - 1;
	x = A[r];
	j = p;

	while(j < r -1) {
	       if (A[j] < x) {
			swap(&A[j], &A[++i]);
	 	}
	}
	swap(&A[++i], &A[r]);
	return i;
}

int
random_partition(int A[], int p, int r)
{
	int i;

	i = ((rand() % p) + p) % r;
	swap(&A[i], &A[r]);
	return partition(A, p, r);
}

int
random_select(int A[], int p, int r, int i)
{
	int k, q;

	if (p == r)
		return A[p];

	q = random_partition(A, p , r);
	k = p - q + 1;

	if (i == k)
		return A[q];

	if (i < k)
		random_select(A, p, q-1, i);
	else
		random_select(A, q+1, r, i);

	return -1;
}

int
main(int argc, char *argv[])
{
	int i, num_elem;
	int a[256];

	if (argc < 3) {
		printf("%s: <nelem> <elem1> elem2..\n", argv[0]);
		return 0;
	}

	srand(time(NULL));
	num_elem = strtoul(argv[1], NULL, 0);
	
	for (i = 0; i < num_elem; i++) {
		a[i] = strtoul(argv[i + 2], NULL, 0);
	}

	i = random_select(a, 0, num_elem, 1);
	printf("The output of random_selec is : %d\n", i);

	return 0;
}
