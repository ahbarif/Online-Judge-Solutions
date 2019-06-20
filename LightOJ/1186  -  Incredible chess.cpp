#include<bits/stdc++.h>
using namespace std;

int main()
{

        int test, cs = 0;

        scanf("%d", &test);

        while(test--)
        {
            int n, i, sum = 0;
            int a[105], b[105];

            scanf("%d", &n);

            for(i=0; i<n; i++)  scanf("%d", &a[i]);
            for(i=0; i<n; i++)  scanf("%d", &b[i]);

            for(i=0; i<n; i++)  sum^= (b[i]-a[i]-1);

            printf("Case %d: ", ++cs);

            puts(!sum?"black wins":"white wins");
        }

        return 0;
}
