#include<bits/stdc++.h>
using namespace std;
 
struct point
{
    long long x, y;
 
    point(){}
 
    point(long long x, long long y): x(x), y(y){}
 
    bool operator < (const point &p) const {
        if (x == p.x)
            return y < p.y;
        return x < p.x;
    }
};
 
vector<point> p, ranges;
long long n, s, d, k;
 
 
bool ok(long long mid){
    ranges.clear();
   
    for(int i = 0; i<p.size(); i++){
        long long h = p[i].y - mid;
        if(h>d) return false;
        long long nn = sqrt(d*d - h*h);
        ranges.push_back(point(p[i].x + nn, p[i].x-nn));
    }
 
    sort(ranges.begin(), ranges.end());
 
    int cnt = 0, i = 0;
 
    while(i<p.size()){
 
        long long tmp = ranges[i].x;
 
        while(ranges[i].y <= tmp && i<p.size()) i++;
 
        cnt++;
 
        if(cnt>s) return false;
    }
 
    return cnt<=s;
 
}
 
void solve(){
 
   
    p.clear();
 
    scanf("%lld %lld %lld %lld", &k, &n, &s, &d);
 
    for(int i = 0; i<n; i++)
    {
        point pp;
        scanf("%lld %lld", &pp.x, &pp.y);
        p.push_back(pp);
    }
 
    if(!ok(k))
    {
        puts("impossible");
        return;
    }
 
    long long lo = k-d, hi = k;
 
    while(lo < hi)
    {
        if(lo == hi) break;
       
        if (lo + 1 == hi) {
            if (ok(lo)) hi = lo;
            break;
        }
 
        long long mid = (hi+lo)/2;
 
        if(ok(mid)) hi = mid;
        else lo = mid+1;
    }
 
    cout<<k-hi<<endl;
   
 
}
 
int main()
{
 
//  freopen("in.txt", "r", stdin);
 
    int test, cs = 0;
 
    scanf("%d", &test);
 
    while(test--)
    {
 
 
        printf("Case %d: ", ++cs);
 
        solve();
       
    }
 
    return 0;
 
}
