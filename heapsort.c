
#include <stdio.h>

#define nelem(a) (sizeof(a)/sizeof(a[0]))
#define PARENT(_i) ((_i))/2)

#define LEFT(_i) (2*(_i))

#define RIGHT(_i) (2*(_i)+1)

void
swap(int *a, int *b)
{
	int t;

	t  = *a;
	*a = *b;
	*b = t;
}

int
max_heapify(int *A, int i, int heapsize)
{
	int l = LEFT(i);
	int r = RIGHT(i);
	int largest;

	largest = i;
	if (l < heapsize && A[l] > A[i])
		largest = l;
	if (r < heapsize && A[r] > A[largest])
		largest = r;
	if (largest != i) {
		swap(&A[i], &A[largest]);
		max_heapify(A, largest, heapsize);
	}

	return 0;
}

int build_max_heap(int *A, int heapsize)
{
	int i;

	for(i = heapsize/2; i >= 0; i--) {
		max_heapify(A, i, heapsize);
	}

	return 0;
}

int heapsort(int *A, int sz)
{
	int i, j;

	build_max_heap(A, sz);
	j = sz;

	for(i = sz; i >= 0; i--) {
		sz--;
		max_heapify(A, i, j);
	}

	return 0;
}

int
main(int argc, char* argv[])
{
	int i;
	int A[] = {20, 3, 42, 8, 9, 90, 10, 33, 9000, 10, -1, 89};

	heapsort(A, nelem(A));

	for(i = 0; i < nelem(A); i++) {
		printf("%d ", A[i]);
	}
	
	printf("\n");
	return 0;
}
