#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(A) sizeof(A)/sizeof(A[0])

void
printarray(int A[], int n)
{
	int i;

	for(i = 0; i < n; i++) {
		printf("A[%d] = %d ", i, A[i]);
	}
	printf("\n");
}

int
merge(int A[], int p, int q, int r)
{
	int i, j, k, n1, n2;
	int *L, *R;

	n1 = q - p + 1;
	n2 = r - q;
	
	L = calloc(n1, sizeof(int));
	if(L == NULL) {
		printf("%s:%d malloc failure\n", __FILE__, __LINE__);
		return -1;
	}

	R = calloc(n2, sizeof(int));
	if(R == NULL) {
		printf("%s:%d malloc failure\n", __FILE__, __LINE__);
		return -1;
	}

	memcpy(L, &A[p], n1*sizeof(int));
	memcpy(R, &A[p+n1], n2*sizeof(int));

	i = 0;
	j = 0;	

	for(k = p; k < r; k++) {
		if(L[i] < R[j]) {
			A[k] = L[i++];
		}
		else {
			A[k] = R[j++];
		}

		if(i == n1) {
			memcpy(&A[++k], &R[j], (n2 - j)*sizeof(int));
			k = r;
			break;
		}

		if(j == n2) {
			memcpy(&A[++k], &L[i], (n1 - i)*sizeof(int));
			k = r;
			break;
		}
	}

	free(L);
	free(R);

	return 0;
}

int
my_mergesort(int A[], int p, int r)
{
	int q;

	if (p < r) {
		q = (p + r)/2;
		my_mergesort(A, p, q);
		my_mergesort(A, q+1, r);
	       	merge(A, p, q, r);
	}

	return 0;
}

int
main(int argc, char*argv[])
{
	int A[] = {10, 40, 1, 3, 4, 200, 90, 5, 2};

	printf("Unsorted Array:\n");
	printarray(A, nelem(A));
	printf("\n");

	my_mergesort(A, 0, nelem(A)-1);

	printf("Sorted Array:\n");
	printarray(A, nelem(A));
	printf("\n");

	return 0;
}
