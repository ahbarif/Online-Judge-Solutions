#include<bits/stdc++.h>
using namespace std;
 
double dp[505][505][2];
bool vis[505][505][2];
 
double f(int r, int b, int turn)
{
 
        if(turn)  return (b==0?0.0:f(r, b-1, turn^1));
 
        if(r+b==1) return b==1.0;
 
        if(vis[r][b][turn]) return dp[r][b][turn];
 
        vis[r][b][turn] = 1;
 
        double tot = (r + b)*1.0;
 
        double red = r/tot;
 
        if(r>0) red *= f(r-1, b, turn^1);
 
        double blue = b/tot;
 
        if(b>0) blue *= f(r, b-1, turn^1);
 
        return dp[r][b][turn] = red+blue;
 
}
 
 
 
int main()
{
 
       int test, cs = 0;
 
       scanf("%d", &test);
 
       int r, b;
 
       while(test--)
       {
            scanf("%d %d", &r, &b);
 
            printf("Case %d: %.10lf\n", ++cs, f(r, b,0));
 
 
       }
 
    return 0;
}
 
