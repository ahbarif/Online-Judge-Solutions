#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100005;
const double pi = acos(-1.0);


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

struct vectorLine{
    ll x, y;

};

vectorLine vec(point a, point b){
    return {b.x-a.x, b.y-a.y};
}

void printVector(vectorLine a){
    cout<<a.x<<"i";
    if(a.y<0) cout<<" - ";
    else cout<<" + ";
    cout<<abs(a.y)<<"j";
    cout<<endl;
}

double magnitude(vectorLine a){
    return sqrt((a.x*a.x) + (a.y*a.y));
}

double dotProduct(vectorLine a, vectorLine b){
   return ((a.x*b.x) + (a.y*b.y));
}

double findAngle(point AA, point BB, point CC){ // angle point ta last e

    vectorLine a = vec(CC, AA);

    vectorLine b = vec(CC, BB);

    double radianAngle = acos(dotProduct(a, b)/(magnitude(a)*magnitude(b)));

    double angle = radianAngle * 180.0/pi;

    return angle;
}

map<pair<ll, ll>, bool> vis;

int main(){


     //   freopen("in.txt", "r", stdin);

        int test, cs = 0;

        scanf("%d", &test);

        while(test--){

            int n, np = 0;
            vis.clear();

            scanf("%d", &n);

            for(int i = 0; i<n; i++){
                ll x, y;
                scanf("%lld %lld", &x, &y);
                if(vis[make_pair(x, y)] == 0){
                    vis[make_pair(x, y)] = 1;
                    P[np].x = x;
                    P[np].y = y;
                    np++;

                }
            }

            double res = 200;

            if(np<=2){
                res = 0.0;
                printf("Case %d: %.10lf\n", ++cs, res);
                continue;
            }

            int nc = 0;
            
            convexHull(np, nc);

        
            for(int i = 0; i<nc; i++){

                double ang = findAngle(C[(i+1)%nc], C[(i-1 + nc)%nc], C[i]);

                res = min(res, ang);
            }


            printf("Case %d: %.10lf\n", ++cs, res);

        }

        
   

}
