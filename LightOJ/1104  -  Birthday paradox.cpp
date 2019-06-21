#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test, cs = 0;

    scanf("%d", &test);

    while(test--){

        int day, i;

        scanf("%d", &day);

        double prob = 1.0;

        for(i = 1; prob>0.5; i++){

            prob *= (double)(day-i)/day;

        }

        printf("Case %d: %d\n", ++cs, i-1);
    }

    return 0;
}

