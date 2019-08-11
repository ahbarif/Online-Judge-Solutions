#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;
ll factorial[100005];

ll bigmod(ll a, ll b, ll mod){
  ll ans = 1;
  while(b){
    if(b&1) ans = (ans*a)%mod;        
    a = (a*a)%mod;        
    b = b>>1;
  }
  return ans%mod;
}

ll inverse(ll p){
  return bigmod(p, mod-2, mod);
}

ll ncr(ll n, ll r){
  if(r>n) return 0;
  ll top = factorial[n];
  ll bot = (factorial[r] * factorial[n-r])%mod;
  ll botInverse = inverse(bot);
  ll ret = (top*botInverse)%mod;
  return ret;
}

ll freq[105];
vector<int> vec;

int main()
{
  #ifdef local
    freopen("in.txt", "r", stdin);
  #endif
  factorial[0] = 1LL;

  for(int i = 1; i<=100000; i++){
    factorial[i] = (factorial[i-1]*i);
    if(factorial[i] >= mod) factorial[i] %= mod;
  }

  int test;

  scanf("%d", &test);

  while(test--){
    memset(freq, 0, sizeof(freq));
    vec.clear();
    int m, b;
    scanf("%d %d", &m, &b);
    while(m--){
      int x, t;
      scanf("%d %d", &x, &t);
      if(t) {
        vec.push_back(x);
        freq[x]++;
      }
    }

    int n = vec.size();
    
    if(n<b) {
      printf("0\n");
      continue;
    }

    vec.clear();
    for(int i = 100; i>=1; i--){
      if(freq[i]) vec.push_back(i);
    }

    sort(vec.begin(), vec.end());

    ll available = -1, lagbe = 0, ret = 0;

    for(int i = 100; i>=1; i--){
      if(freq[i] == 0) continue;
      if(freq[i]>=b){
         available = freq[i];
         lagbe = b;
         break;
      }
      b -= freq[i];
    }

    ret = ncr(available, lagbe);

    printf("%lld\n", ret);

  }

  //cout<<ncr(10, 2)<<endl;


}


