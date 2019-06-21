#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sod(ll n){

    ll res = 0;

    for(int i = 2; i<n; i++){
        if(n%i == 0) res += i;
    }

    return res;

}

ll csod(ll n){

    ll res = 0;
    for(int i = 1; i<=n; i++) res += sod(i);
    return res;
}

ll myfunc(ll n){

    ll res = 0;

    for(ll i = 2; i*i<=n; i++){

        ll j = n/i;

        ll tmp1 = (i+j)*(j-i+1)/2;
        ll tmp2 = i*(j-i);
        res += tmp1;
        res += tmp2;

    }

    return res;
}

int main()
{

   int test, cs = 0;

   scanf("%d", &test);

   while(test--){

    ll n;
    scanf("%lld", &n);

    printf("Case %d: %lld\n", ++cs, myfunc(n));
   }

   return 0;


}

/*
1 -
2 -
3 -
4 -  2
5 -
6 -  2 3
7 -
8 -  2   4
9 -    3
10-  2     5
*/

