#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll bigmod(ll a, ll b, ll mod)
{
    ll ans = 1;
    while(b){
        if(b&1) ans = (ans*a)%mod;
        a = (a*a)%mod;        
    b = b>>1;
    }
    return ans%mod;
}

char str[100005];

int main () {
    #ifdef local
        freopen("in.txt", "r", stdin);
    #endif

    int t;

    scanf("%d", &t);

    while(t--){
        scanf("%s", str);
        ll b;
        scanf("%lld", &b);


        char c = str[strlen(str)-1];
        ll a = c - '0'; 
        ll ret = bigmod(a, b, 10LL);
        printf("%lld\n", ret);
    }

}
