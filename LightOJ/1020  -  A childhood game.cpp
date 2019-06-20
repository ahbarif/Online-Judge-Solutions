#include <bits/stdc++.h>
using namespace std;

int main()
{

    int test, cs = 0, n;

    char s[6];

    scanf("%d", &test);

    while(test--)
    {
            scanf("%d %s", &n, &s);

            printf("Case %d: ", ++cs);

            if(s[0]=='B')
            {
                if(n%3==0)  puts("Alice");
                else puts("Bob");
            }

            else
            {
                if(n%3!=1)  puts("Alice");
                else puts("Bob");
            }
    }

    return 0;

}
