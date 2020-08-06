#include<bits/stdc++.h>
using namespace std;
int N=20000000;
int primes[20000007];
bool prime[20000000+1];

void Sieve()
{
	// Create a boolean array "prime[0..n]" and initialize
	// all entries it as true. A value in prime[i] will
	// finally be false if i is Not a prime, else true.

	memset(prime, true, sizeof(prime));

	for (int p=2; p*p<=N; p++)
	{
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == true)
		{
			// Update all multiples of p greater than or
			// equal to the square of it
			// numbers which are multiple of p and are
			// less than p^2 are already been marked.
			for (int i=p*p; i<=N; i += p)
				prime[i] = false;
		}
	}
    int j=1;
	// Print all prime numbers
	for (int p=3; p<=N; p++)
	if (prime[p] && prime[p+2])
		primes[j++]=p;
}

int main()
{
    Sieve();
    int n;
    while (cin>>n) {
        printf("(%d, %d)\n", primes[n], primes[n]+2);
    }
    return 0;
}
