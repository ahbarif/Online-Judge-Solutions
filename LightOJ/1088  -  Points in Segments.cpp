#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int a[N];

int main() {

    int n, query, test, i, caseno=0, left, rigth, maxP, minP, ans;

    scanf("%d", &test);

    while(test--)
    {
        scanf("%d %d", &n, &query);

        for(i=0; i<n; i++)  scanf("%d", &a[i]);

        printf("Case %d:\n", ++caseno);

        while(query--)
        {

                scanf("%d %d", &left, &rigth);

                minP = lower_bound(a, a + n, left) - a;

                maxP = upper_bound(a, a+n, rigth)- a;

                ans=maxP-minP;

                printf("%d\n", ans);
        }


    }

  return 0;
}
