#include <bits/stdc++.h>
using namespace std;

int main()
{

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){

        int n, a, b, res = 0;

        scanf("%d", &n);

        while(n--){
            scanf("%d %d", &a, &b);
            res ^= (b-a-1);
        }

        printf("Case %d: ", ++cs);

        puts(res?"Alice":"Bob");

    }

    return 0;
}

