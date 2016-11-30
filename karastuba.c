#include <stdio.h>
#include <stdlib.h>

uint64_t karastuba(uint64_t num1, uint64_t num2)
{
	if(num1 < 10 || num2 < 10)
		return num1 * num2;

	m = max(numdigits(num1), numdigits(num2));
	m2 = m/2;

	high1 = num1/(10^m2);
	low1 = num1 - high1*(10^m2);

	high2 = num2/(10^m2);
	low2 = num2 - high2*(10^m2);

	z0 = karastuba(low1, low2);
	z1 = karastuba((low1 + high1), (low2 + high2));
	z2 = karastuba(high1, high2);

	return(z2*10^(2*m2))+((z1-z2-z0)*10^(m2))+(z0);
}

int main(int argc, char *argv[])
{
	uint64_t num1 = 1234;
	uint64_t num2 = 5678;
	uint64_t product;

	product = karastuba(num1, num2);

	if(product != num1*num2) {
		printf("ERROR: product = %lld Expected value = %lld\n",
			product, (num1*num2));
	}
	else {
		printf("Success\n");
	}

	return 0;
}
