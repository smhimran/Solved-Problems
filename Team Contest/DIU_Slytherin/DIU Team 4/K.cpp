#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
#define eps 1e-9
#define unq(c)          (sort(c.begin(), c.end()), c.resize(distance(c.begin(),unique(c.begin(), c.end()))))

int main() {
	#ifdef HOME
     clock_t Start=clock();
     freopen("in.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
    #endif
     
	long long t, ca=1;
	scanf("%lld", &t);
	while (t--) {
		long long a, b, n;
		scanf("%lld %lld %lld", &a, &b, &n);

		long long points[10];
		for (long long i=0; i<=9; i++) 
			points[i] = 0;

		map<long long, bool> taken;
		long long cnt = 0;

		for (long long i=1; i * i <=n; i++) {
			long long now = a * i *i + b * i;

			if (now <= n) {
				if (taken[now])
					continue;

				taken[now] = 1;
				cnt++;

				long long mx = 0;
				long long freq[10];
				for (int i=0; i<=9; i++)
					freq[i] = 0;

				while (now) {
					long long d = now % 10LL;
					now /= 10LL;

					freq[d]++;
					mx = max(mx, freq[d]);
				}

				for (int i=0; i<=9; i++) {
					if (freq[i] == mx)
						points[i]++;
				}
			}
			else 
				break;
		}

		if (!cnt) {
			printf("-1\n");
			continue;
		}

		long long mx = 0, ans = 0;

		for (long long i=0; i<=9; i++) {
			if (points[i] > mx) {
				mx = points[i];
				ans = i;
			}
		}

		printf("%lld\n", ans);
	}

	#ifdef HOME
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif

	return 0;
}