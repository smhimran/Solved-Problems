#include<bits/stdc++.h>
using namespace std;
const char *day[]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const char *months[]={"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int dm[]={0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isleap(int n)
{
    if (n<1752) return (n%4)? 0:1;
    if (n%400==0 ||(n%4==0 && n%100!=0))
        return 1;
    return 0;
}

int isold(int m, int d, int y)
{
    if (y<1752)
        return 1;
    else if (y==1752 && m<9)
        return 1;
    else if (y==1752 && m==9 && d<=2)
        return 1;
    return 0;
}

int check(int y, int m, int d)
{
    if (y<=0 || m<=0 || m>12 || d<=0 || d>dm[m])
        return 0;
    if (y==1752 && m==9 && d>=3 && d<=13)
        return 0;
    return 1;
}

int main()
{
    int d, m, y;
    while (scanf("%d %d %d", &m, &d, &y) && (m||d||y)) {
        dm[2]=28+isleap(y);
        if (check(y, m,d)) {
            int days=d;
            for (int i=1; i<m; i++)
                days+=dm[i];
            for (int i=1; i<y; i++)
                days+=365+isleap(i);
            printf("%s %d, %d is a %s\n", months[m], d, y, day[(days+(isold(m, d, y)? 12: 1))%7]);
        }
        else
            printf("%d/%d/%d is an invalid date.\n", m, d, y);
    }
    return 0;
}
