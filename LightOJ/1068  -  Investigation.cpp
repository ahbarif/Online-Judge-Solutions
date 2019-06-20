#include<bits/stdc++.h>
using namespace std;
 
int dp[10][2][100][100], k;
 
string val;
 
string toString(int n)
{
    stringstream ss;
    ss << n;
    return ss.str();
}
 
int f(int id, bool isEqual, int sumMod, int valMod)
{
 
        if(id==val.length())
        {
            return (sumMod==0 && valMod == 0);
        }
 
        if(dp[id][isEqual][sumMod][valMod] != -1)   return dp[id][isEqual][sumMod][valMod];
 
        int res = 0;
 
        int top = (isEqual? val[id]-'0':9);
 
        for(int j = 0; j<=top; j++)
        {
             res += f(id + 1, isEqual && (j == top), (sumMod + j) % k, (((valMod * 10) % k) + j) % k);
        }
 
        return dp[id][isEqual][sumMod][valMod] = res;
}
 
int main()
{
 
        int test, cs = 0;
 
        scanf("%d", &test);
 
        while(test--)
        {
 
                int a, b, res1, res2;
 
                scanf("%d %d %d", &a, &b, &k);
 
 
                    memset(dp, -1, sizeof(dp));
 
                    val = toString(b);
 
                    res1 = f(0, 1, 0, 0);
 
                    memset(dp, -1, sizeof(dp));
 
                    val = toString(a-1);
 
                    res2 = f(0, 1, 0, 0);
 
                    printf("Case %d: %d\n", ++cs, res1-res2);
               
 
 
        }
 
        return 0;
 
 
    return 0;
}
 
