#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll getPos(ll h, ll t){
    t %= (h + h);
    if (t > h) {
        return h + h - t;
    }
    return t;
}

ll getDirection(ll h, ll t){  // 0 = down, 1 = up
    t %= (h + h);
    return t < h;
}

ll calc(ll x){
   // assert(x>=0);
    return (x+1)/2LL;
}

ll func(ll h1, ll h2, ll curr){  // h1 <= h2
    ll cur = curr;
    ll p1 = getPos(h1, cur), p2 = getPos(h2, cur);
    ll d1 = getDirection(h1, cur), d2 = getDirection(h2, cur);

    if(p1 >= p2) return cur;

    if(d2 == true){
        cur += ((h2-p2) + (h2 - h1));
        p1 = getPos(h1, cur);
        d1 = getDirection(h1, cur);

        if(p1>=h1) return cur;

        if(d1) cur += calc(h1-p1);
        else{
            cur += p1;
            p2 = getPos(h2, cur);
            cur += calc(p2-0);
        }
    }
    else{   // d2 = down
        if(p2 <= h1){
            if(d1 == false) cur += p1;
            p1 = getPos(h1, cur);
            p2 = getPos(h2, cur);
            cur += calc(p2-p1);
        }
        else{
            cur += (p2-h1);
            p1 = getPos(h1, cur);
            p2 = getPos(h2, cur);
            d1 = getDirection(h1, cur);
            d2 = getDirection(h2, cur);

            if(p1 >= p2) return cur;
            if(d1 == false) cur += p1;
            p1 = getPos(h1, cur);
            p2 = getPos(h2, cur);
            cur += calc(p2-p1);
        }
    }

    return cur;
}

ll gunc(ll h1, ll h2, ll cur){  // h1> h2
    ll p1 = getPos(h1, cur), p2 = getPos(h2, cur);
    ll d1 = getDirection(h1, cur), d2 = getDirection(h2, cur);

    if(p1 >= p2) return cur;

    if(d1 == true && d2 == false){
        cur += calc(p2-p1);
    }
    else if(d1 == true && d2 == true){  // both up
        cur += (h2-p2);
        p2 = getPos(h2, cur);

        assert(p2 == h2);

        p1 = getPos(h1, cur);
        if(p1>=p2) return cur;
        cur += calc(p2-p1);
    }
    else if(d1 == false && d2 == false){ // both down
        cur += p1;
        p1 = getPos(h1, cur);
        p2 = getPos(h2, cur);
        cur += calc(p2-p1);
    }
    else{
        cur += (h2-p2);
        p1 = getPos(h1, cur);
        d1 = getDirection(h1, cur);
        p2 = getPos(h2, cur);

        if(p1>=p2) return cur;

        if(d1 == false) cur += p1;
        p1 = getPos(h1, cur);
        p2 = getPos(h2, cur);
        cur += calc(p2-p1);
    }

    return cur;
}


ll ar[100005];

int main()
{
   // for(int i = 0; i<30; i++) cout<<getPos(5, i)<<"  "<<getDirection(5, i)<<endl;
    int test, cs = 0;

    scanf("%d", &test);


    while(test--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i<=n; i++) scanf("%lld", &ar[i]);
        ll ret = 0, tmp;

        for(int i = 1; i<n; i++){
//         /   cout<<i<<" = "<<ret<<endl;
            tmp = ret;
            if(ar[i]<ar[i+1]) ret = func(ar[i], ar[i+1], tmp);
            else ret = gunc(ar[i], ar[i+1], tmp);
            ++ret;
        }

        printf("Case %d: %lld\n", ++cs, ret);
    }



     return 0;
}

