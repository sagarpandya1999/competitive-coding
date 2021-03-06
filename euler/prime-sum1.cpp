#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

const int LIMIT  = 10000005;  //size of integers array
const int PRIMES = 5000000;
//linear time sieve.
int prime[PRIMES];
int prime_count=0;
bool is_composite[LIMIT+1];
int largest_prime_factor[LIMIT+1];


void sieve(int n)
{
	std::fill (is_composite, is_composite + n, false);
	largest_prime_factor[1] = 1;
	for(int i=2; i<n; i++)
	{
		if(is_composite[i])
			continue;
		prime[prime_count] = i;
		prime_count++;
		for(int j=i; j<n; j+=i)
		{	largest_prime_factor[j] = i;
			is_composite[j]= true;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	sieve(LIMIT);
	long long sum=0, mod = 1e9+7;
	for(int i=1; i<=n; i++)
	{
		long long p1 = largest_prime_factor[i];
		//cout << p1<<endl;
		sum = (sum + p1)%mod;
	}
	cout << sum;
}
