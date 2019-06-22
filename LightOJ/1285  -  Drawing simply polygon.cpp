#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2005;

struct point{
    ll x, y;
    int id;
};

point P[maxn], C[maxn], P0;
vector<point> lastEdge, vertices;

inline ll triArea(const point &a, const point &b, const point &c) {
    return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}

inline ll sqDist(const point &a, const point &b) {
    return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

inline bool comp(const point &a, const point &b) {
    ll d = triArea(P0, a, b);
    if(d < 0) return false;
    if(!d && sqDist(P0, a) > sqDist(P0, b)) return false;
    return true;
}

void print(){
    for(int i = 0; i<vertices.size(); i++) {
        if(i) printf(" ");
        printf("%d", vertices[i].id);
    }
    puts("");
}

void convexHull(int &np) {

    int i, j, pos = 0;
    for(i = 1; i < np; i++)
        if(P[i].y<P[pos].y || (P[i].y==P[pos].y && P[i].x<P[pos].x))
            pos = i;
    swap(P[0], P[pos]);
    P0 = P[0];
    sort(&P[1], &P[np], comp);

    bool ok = false;

    for(int i = 0; i<np; i++){
        if(triArea(P[0], P[1], P[i]) != 0){
            ok = true;
            break;
        }
    }

    if(!ok) {
        puts("Impossible");
        return;
    }



    lastEdge.clear();
    vertices.clear();

    for(int i = 0; i<np; i++){
        if(triArea(P[0], P[np-1], P[i]) == 0){
            lastEdge.push_back(P[i]);
        } else vertices.push_back(P[i]);
    }

    for(int i = lastEdge.size()-1; i>=0; i--) vertices.push_back(lastEdge[i]);

    print();

}


int main(){
#ifdef local
    freopen("in.txt", "r", stdin);
 //   freopen("out.txt", "w", stdout);
#endif

        int test, cs = 0;

        scanf("%d", &test);

        while(test--){

            int n, d;

            scanf("%d", &n);

            for(int i = 0; i<n; i++){
                scanf("%lld %lld", &P[i].x, &P[i].y);
                P[i].id = i;
            }

            printf("Case %d:\n", ++cs);

            convexHull(n);



          //  printf("Case %d: %.6lf\n", ++cs, tot);
        }

   #ifdef local
    cerr<<"\n\n__time elapsed = "<<(double)clock()*1000/CLOCKS_PER_SEC<<" ms__"<<endl;
#endif

}

