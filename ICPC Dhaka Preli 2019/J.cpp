#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> vec;

int main()
{
    int test, cs = 0;

    scanf("%d", &test);

    while(test--){

        vec.clear();

        int n;

        scanf("%d", &n);

        while(n--){
            ll x;
            scanf("%lld", &x);
            vec.push_back(x);
        }

        sort(vec.begin(), vec.end());

        if(vec.size()==1) vec.push_back(vec[0]);

        ll ret = vec.front() * vec.back();

        printf("Case %d: %lld\n", ++cs, ret);
    }



     return 0;
}

