#include<bits/stdc++.h>
using namespace std;
 
const int mx = 1000000000;
 
int pal[1002][1002];
int dp[1002];
 
string s;
 
bool isPalindrome(int i, int j)
{
    if(i>=j)    return true;
 
    if(pal[i][j] !=-1) return pal[i][j];
 
    bool flag = ((s[i] == s[j]) && isPalindrome(i + 1, j - 1));
 
    return pal[i][j] = flag;
}
 
int f(int i)
{
        if(i>=s.size()) return 0;
 
        if(dp[i]!=-1)   return dp[i];
 
        int res = INT_MAX;
 
        for(int j = i; j<s.size(); j++)
        {
            if(isPalindrome(i, j))
            {
                int tmp = 1 + f(j+1);
 
                res = min(res, tmp);
            }
        }
 
        return dp[i] = res;
 
 
}
 
int main()
{
 
       int test, cs = 0;
 
       scanf("%d", &test);
 
       while(test--)
       {
            cin>>s;
 
            memset(dp, -1, sizeof(dp));
            memset(pal, -1, sizeof(pal));
 
            printf("Case %d: %d\n", ++cs, f(0));
 
 
       }
 
    return 0;
}
