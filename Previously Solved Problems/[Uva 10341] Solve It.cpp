#include<bits/stdc++.h>
using namespace std;
#define eps 1e-7

double p, q, r, s, t, u;
double eqn(double x)
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main()
{

    while (scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u)!=EOF) {
        double low=0.0, high=1.0;
        if (eqn(low)*eqn(high)>0) printf("No solution\n");
        else {
            double mid;
            while (high-low>eps) {
                mid=(low+high)/2;
                if (eqn(low)*eqn(mid)<=0)
                    high=mid;
                else low=mid;
            }
            printf("%.4lf\n", mid);
        }
    }
    return 0;
}
