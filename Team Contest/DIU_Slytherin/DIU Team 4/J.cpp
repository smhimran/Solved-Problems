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
     
	int t, ca=1;
	scanf("%d", &t);
	while (t--) {
		double r, a;
		scanf("%lf %lf", &r, &a);

		pair<double, double> y, x, z;

		y = {0, 0}, x = {r, 0};

		double angle = (a * PI) /180.0;

		z = {r * cos(angle), r * sin(angle)};

		double total = r * r * angle / 2.0;

		double traingle = y.first * (x.second - z.second);
		traingle += x.first * (z.second - y.second);
		traingle += z.first * (y.second - x.second);

		traingle = abs(traingle) / 2.0;

		printf("%.6lf\n", total - traingle + eps);
	}

	return 0;
}