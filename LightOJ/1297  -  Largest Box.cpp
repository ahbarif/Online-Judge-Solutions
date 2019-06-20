# include<bits/stdc++.h>
using namespace std;
 
void solve(int cs)
{
        double l, w, x1, x2, x;
 
        scanf("%lf %lf", &l, &w);
 
        x1 = ((l+w) + sqrt(l*l - w*l + w*w))/6.0;
        x2 = ((l+w) - sqrt(l*l - w*l + w*w))/6.0;
 
        x = min(x1, x2);
 
        double v = x*(l-2*x)*((double)w-2*x);
 
        cout<<"Case "<<cs<<": "<<std::fixed<<std::setprecision(8)<<v<<endl;
}
 
 
int main(){
 
    int test, cs = 1;
 
    scanf("%d", &test);
 
    while(test--)
    {
        solve(cs++);
    }
    return 0;
}