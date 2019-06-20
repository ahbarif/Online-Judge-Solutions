#include<bits/stdc++.h>
using namespace std;

string s, ans;
int dp[55][55][55];

bool isVowel(char p)
{
    string s = "AEIOU";
    for(int i = 0; i<s.size(); i++)
    {
        if(s[i]==p) return true;
    }
    return false;
}

int fun(int i, int cons, int vow){

    if(i>=s.size()) return 2;

    if(dp[i][cons][vow] != -1) return dp[i][cons][vow];

    int &res = dp[i][cons][vow];

    res = 0;

    if(s[i]=='?'){
        int x, y;
        if(cons>=4) x = 1;
        else x = fun(i+1, cons+1, 0);

        if(vow>=2) y = 1;
        else y = fun(i+1, 0, vow+1);
        res = x|y;
    }

    else if(isVowel(s[i])){
        if(vow>=2) res = 1;
        else res = fun(i+1, 0, vow+1);
    }
    else{
        if(cons>=4) res = 1;
        else res = fun(i+1, cons+1, 0);
    }

    return res;

}

void solve(int cs)
{


    cin>>s;

    memset(dp, -1, sizeof(dp));

    int res = fun(0, 0, 0);

    if(res == 1) ans = "BAD";
    if(res == 2) ans = "GOOD";
    if(res == 3) ans = "MIXED";

    cout<<"Case "<<cs<<": "<<ans<<endl;

    // can be made bad
    // try korbo good banaite


}
int main()
{

    int test, cs = 0;

    cin>>test;

    while(test--){
        solve(++cs);
    }
}

