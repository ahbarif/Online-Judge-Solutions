#include<bits/stdc++.h>
using namespace std;
int main(){

    int t, n, p, q, i, j, s, x, c, r;
    vector<int> a;

    cin >> t;
    for (i = 0; i < t; i++){
        s = 0; c = 0; r=0;
        cin >> n >> p >> q;
        for (j = 0; j < n; j++){
            cin >> x;   a.push_back(x);
        }

        for (j = 0; j < n; j++ && j<p){
            s += a[j];  r++;
            if(r==p+1) break;
            if (s <= q)  c++;
            else break;
        }
        printf("Case %d: %d\n", i + 1, c);
        a.clear();

    }

    return 0;
}
