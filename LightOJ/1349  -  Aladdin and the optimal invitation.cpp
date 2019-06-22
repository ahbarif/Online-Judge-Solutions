#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 50005;
const ll inf = 1000000000000000000;
int x[maxn], y[maxn], a[maxn];

ll fx(int idx){
        ll cost = 0;
        for(int j = 1; j<maxn; j++) {
            ll d = abs(idx - j);
            cost += (d*x[j]);
        }

        return cost;
}

ll fy(int idx){
        ll cost = 0;
        for(int j = 1; j<maxn; j++) {
            ll d = abs(idx - j);
            cost += (d*y[j]);
        }

        return cost;
}

ll ternary_X(){

    ll high = 500000, low = 1, res = inf, pos = 1;
    for(int j = 0; j<64; j++){
            ll left_third = (2 * low + high) / 3;
            ll right_third = left_third+1;

            ll leftRes = fx(left_third);
            ll rightRes = fx(right_third);

            if(leftRes<res){
                res = leftRes;
                pos = left_third;
            }

            if(rightRes<res){
                res = rightRes;
                pos = right_third;
            }

            if(leftRes<rightRes) high = left_third;
            else low = right_third;

    }

    return pos;

}

ll ternary_Y(){
 ll high = 500000, low = 1, res = inf, pos = 1;
    for(int j = 0; j<64; j++){
            ll left_third = (2 * low + high) / 3;
            ll right_third = left_third+1;

            ll leftRes = fy(left_third);
            ll rightRes = fy(right_third);

            if(leftRes<res){
                res = leftRes;
                pos = left_third;
            }

            if(rightRes<res){
                res = rightRes;
                pos = right_third;
            }

            if(leftRes<rightRes) high = left_third;
            else low = right_third;

    }

    return pos;

}


int main()
{

        int test, cs = 0;

        scanf("%d", &test);

        while(test--){

            int n, m, q;

            scanf("%d %d %d", &n, &m, &q);
            memset(x, 0, sizeof(x));
            memset(y, 0, sizeof(y));

            for(int i = 1; i<=q; i++){
                int u, v, w;

                scanf("%d %d %d", &u, &v, &w);

                x[u] += w;
                y[v] += w;
            }

            cout<<"Case "<<++cs<<": "<<ternary_X()<<" "<<ternary_Y()<<endl;

        }

}

