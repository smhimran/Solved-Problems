#include <bits/stdc++.h>
using namespace std;

/// Euclidean GCD

// int GCD(int a, int b) {
// 	if (b == 0)
// 		return a;
	
// 	return GCD(b, a%b);
// }

/// Sieve of Eratosthenes
bool mark[1000006];
vector<int> primes;


void Sieve(int n) {
	mark[0] = 1;
	mark[1] = 1;
	
	for (int i=2; i*i<=n; i++) {
		if (mark[i] == false) {
			for (int j= 2*i; j<=n; j+=i) {
				mark[j] = true;
			}
		}
	}
	
	for (int i=2; i<=n; i++) {
		if (mark[i] == false)
			primes.push_back(i);
	}
	
}

int main() {
	#ifdef HOME
	     freopen("in.txt", "r", stdin);
	     freopen("out.txt", "w", stdout);
	#endif
	    
	// Any base to Decimal    
	// string s; // any other letter will be capital
	// int base;
	// cin>>s>>base;
	
	// int decimal = 0, power = 1;
	
	// reverse(s.begin(), s.end());
	
	// // 11D
	
	// for (int i=0; i<s.length(); i++) {
	// 	int val = 0;
		
	// 	if (s[i]>='0' and s[i]<='9')
	// 		val = s[i] - '0';
	// 	else if (s[i]>='A' and s[i]<='Z')
	// 		val = (s[i] - 'A') + 10;
		
	// 	decimal += (val * power);
	// 	power *= base;
	// }
	
	// cout<<decimal<<endl;
	     
	/// Decimal to any base
	     
	// int n, base;
	// cin>>n>>base;
	
	// string ans = "";
	
	// while (n != 0) {
	// 	int rem = n % base;
	// 	n /= base;
		
	// 	if (rem >= 0 and rem <= 9)
	// 		ans += rem + '0';
	// 	else
	// 		ans += ((rem - 10) + 'A');
	// }
	
	// reverse(ans.begin(), ans.end());
	
	// cout<<ans<<endl;
	     
	// int a, b;     
	// scanf("%d %i", &a, &b);
	// // float %f, double %lf, char %c, int %i
	// // %d means decimal
	// printf("%d %X", a, b);
	
	/// Euclidean GCD:
	     
	// int a, b;
	
	// cin>>a>>b;
	
	// cout<<__gcd(a, b)<<endl; // Complexity: O(log n)
	
	/// Divisor Count
	
	// int n, cnt = 0; // n <= 10^14
	// cin>>n;
	
	// for (int i=1; i*i<=n; i++) {
	// 	if (n % i == 0) {
	// 		cnt++; // cout<<i<<endl;
	// 		if (n / i != i)
	// 			cnt++; // cout<< n/i <<endl;
	// 	}
	// }
	
	// cout<<cnt<<endl;
	     
	/// Primality test
	// int n;
	// cin>>n;
	
	// bool isPrime = true;
	
	// for (int i=2; i*i<=n; i++) {
	// 	if (n % i == 0) {
	// 		isPrime = false;
	// 		break;
	// 	}
	// }
	
	// if (isPrime)
	// 	cout<<"Prime"<<endl;
	// else
	// 	cout<<"Not"<<endl;
	     
	
	/// Prime Factorization
	     // Wheel Factorization
	// int n;
	// cin>>n;
	
	// for (int i=2; i*i<=n; i++) {
	// 	if (n % i == 0) {
	// 		// cout<<i<<' ';
			
	// 		while (n % i == 0) {
	// 			n /= i;
				
	// 			cout<< i << ' ';
	// 		} 
	// 	}
	// }
	
	// if (n > 1) 
	// 	cout<<n<<' ';
	     
	/// Sieve of Eratosthenes
	
	int n;
	cin>>n;
	
	Sieve(n);
	
	if (mark[n] == false)
		cout<<"Prime"<<endl;
	
	for (int i=0; i<primes.size(); i++)
		cout<<primes[i]<<' ';
	cout<<endl;
		
	return 0;
}