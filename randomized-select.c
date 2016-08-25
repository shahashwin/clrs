#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Fixes: 
 * pass elements: num_elem -1
 * set p to p+1 in random_partition
 */
void
print_array(int *a, int num_elem)
{
	int i;

	for(i = 0; i < num_elem; i++) {
		printf("a[%d] = %d ", i, a[i]);
	}
	printf("\n");
}

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
	       j++;
	}
	swap(&A[++i], &A[r]);
	printf("%d\n", i);
	return i;
}

int
random_partition(int A[], int p, int r)
{
	int i;

	printf("here\n");
	i = (rand() | p) % r;
	printf("%d %d %d\n", i, p, r);
	swap(&A[i], &A[r]);
	print_array(A, r-p+1);
	return partition(A, p, r);
}

int
random_select(int A[], int p, int r, int i)
{
	int k, q;

	printf("p=%d r=%d\n", p, r);
	if(p >= r)
		return A[p];

	q = random_partition(A, p, r);
	k = q - p + 1;

	printf("i = %d k: %d p: %d q = %d\n", i, k, p, q);

	if(i < k)
		random_select(A, p, q-1, i);
	else if(i > k)
		random_select(A, q+1, r, i);

	return A[q];
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


	i = random_select(a, 0, num_elem-1, 1);
	printf("The output of random_selec is : %d\n", i);

	return 0;
}
