#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int stn(char *s)
{
    int i;
    int num = 0;
    for (i = 0; i < strlen(s); i++)
    {
        num *= 4;
        if (s[i] == 'U')
        {
            num++;
        }
        else if (s[i] == 'C')
        {
            num += 2;
        }
        else if (s[i] == 'D')
        {
            num += 3;
        }
    }
    return num;
}

int main()
{
    int n;
    char s[1024];
    scanf("%d", &n);
    printf("COWCULATIONS OUTPUT\n");
    while (n--) {
        scanf(" %s", s);
        int n1, n2;
        n1=stn(s);
        scanf(" %s", s);
        n2=stn(s);
        int j=3;
        while (j--) {
            char c;
            scanf(" %c", &c);
            if (c=='A')
                n2+=n1;
            else if (c=='R')
                n2/=4;
            else if (c=='L')
                n2*=4;
        }
        scanf(" %s", s);
        n1=stn(s);
        printf("%s\n", (n1==n2)? "YES":"NO");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
