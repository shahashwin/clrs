#include <stdio.h>

#define nelem(A) (sizeof(A)/sizeof(A[0]))

void
swap(int *v1, int *v2)
{
	int t;
	
	t = *v1;
	*v1 = *v2;
	*v2 = t;
}

void
printArray(int A[], int r)
{
	int i;

	for(i = 0; i < r; i++) {
		printf("%d ", A[i]);
	}

	printf("\n");
}

int
partition(int A[], int p, int r)
{
	int j;
	int x = A[r];
	int i = p - 1;
	
	for(j = p; j < r; j++) {
		if(A[j] <= x) 
			swap(&A[++i], &A[j]);
	}
	
	swap(&A[++i], &A[r]);

	return i;
}

void
quicksort(int A[], int p, int r)
{
	int q;
	if (p < r) {
		q = partition(A, p, r);
		quicksort(A, p, q-1);
		quicksort(A, q+1, r);
	}
}

int
main(int argc, char *argv[])
{
	int A[] = {100000, 21, 300, -1, 11, 231, 5, 99, 21, 3, 4, 7};

	quicksort(A, 0, nelem(A)-1);
	printArray(A, nelem(A));

	return 0;
}			
