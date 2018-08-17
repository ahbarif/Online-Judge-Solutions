#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;

    scanf("%d", &t);

    for(int i = 1; i<=t; i++) {

            int n, x, mx = 0;

            scanf("%d", &n);

            while(n--){
                scanf("%d", &x);
                mx = max(x, mx);
            }

            printf("Case %d: %d\n", i, mx);

    }


    return 0;
}
