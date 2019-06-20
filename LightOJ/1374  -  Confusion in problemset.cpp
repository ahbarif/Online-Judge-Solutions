#include<bits/stdc++.h>
using namespace std;

int a[10005], b[10005];

int main()
{
        int test, cs = 0;

        scanf("%d", &test);

        while(test--)
        {
            int n, i, x, f = true;

            memset(a, 0, sizeof(a));
            memset(b, -1, sizeof(b));

            scanf("%d", &n);

            for(int i = 0; i<n; i++)
            {
                scanf("%d", &x);
                if(x<n) a[x]++;
                else f = false;
            }

            if(f==false)
            {
                printf("Case %d: no\n", ++cs);
                continue;
            }

            for(int i = 0; i<n; i++)
            {
                int c = i, d = n - i - 1;

                if(a[c]>0)
                {
                    a[c]--;
                    b[i] = c;
                }
                else if(a[d]>0)
                {
                    a[d]--;
                    b[i] = d;
                }
            }

            for(int i = 0; i<n; i++)
            {
                if(b[i]==-1)
                {
                    f = false;
                    break;
                }
            }

            for(int i = 0; i<n; i++)
            {
                if(a[i]>0)
                {
                    f = false;
                    break;
                }
            }

            printf("Case %d: ", ++cs);

            puts(f?"yes":"no");


        }

}
