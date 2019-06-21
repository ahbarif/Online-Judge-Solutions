#include <bits/stdc++.h>
using namespace std;

int a[100005];
int b[100005];

void Query(int i, int j)
{
    int c[1005] = {0};

    for(int x = i; x<=j; x++)   c[a[x]]++;
    int k = 0;

    for(int x = 0; x<=1003; x++)
    {
        while(c[x]--)   b[k++] = x;
    }

    int res = INT_MAX;

    for(int x = 1; x<k; x++)
    {
        int tmp = b[x]-b[x-1];
        res = min(res, tmp);
    }

    printf("%d\n", res);

}

int main()
{

        int test, cs = 0;

        scanf("%d", &test);

        while(test--)
        {
                int n, q, i, j;

                scanf("%d %d", &n, &q);

                for(i=0; i<n; i++)  scanf("%d", &a[i]);

                printf("Case %d:\n", ++cs);

                while(q--)
                {
                    scanf("%d %d", &i, &j);
                    Query(i, j);
                }

        }

     return 0;
}


