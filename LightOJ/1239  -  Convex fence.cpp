#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100005;


struct point{

    ll x, y;

};

point P[maxn], C[maxn], P0;

inline ll triArea(const point &a, const point &b, const point &c) {
    return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}
 
inline ll sqDist(const point &a, const point &b) {
    return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

inline bool issame(const point &a, const point &b) {
    return (a.x == b.x && a.y == b.y);
}

inline bool comp(const point &a, const point &b) {
    ll d = triArea(P0, a, b);
    if(d < 0) return false;
    if(!d && sqDist(P0, a) > sqDist(P0, b)) return false;
    return true;
}
 
void convexHull(int &np, int &nc) {
    int i, j, pos = 0;
    for(i = 1; i < np; i++)
        if(P[i].y<P[pos].y || (P[i].y==P[pos].y && P[i].x<P[pos].x))
            pos = i;
    swap(P[0], P[pos]);
    P0 = P[0];
    sort(&P[1], &P[np], comp);
    for(i = 0; i < 3; i++) C[i] = P[i];
    for(i = j = 3; i < np; i++) {
        while(triArea(C[j-2], C[j-1], P[i]) < 0) j--;
        C[j++] = P[i];
    }
    nc = j;
}   // C contains the points on the hull


int main(){

      //  freopen("in.txt", "r", stdin);

        int test, cs = 0;

        scanf("%d", &test);

        while(test--){

            int n, d;

            scanf("%d %d", &n, &d);

            for(int i = 0; i<n; i++){
                scanf("%lld %lld", &P[i].x, &P[i].y);
            }

            int nc = 0;
            
            convexHull(n, nc);

            double tot = 0;

            for(int i = 0; i<nc; i++){
                tot += sqrt(sqDist(C[i], C[(i+1)%nc]));
            }

            tot += (2.0*acos(-1.0)*d);

            printf("Case %d: %.6lf\n", ++cs, tot);
        }

   

}
