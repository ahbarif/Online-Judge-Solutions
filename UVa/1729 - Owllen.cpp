#include<bits/stdc++.h>
using namespace std;

int cnt[200];

int main()
{
    int test, cs = 0;

    cin>>test;
    cin.ignore();

    while(test--){

        char c;
        memset(cnt, 0, sizeof(cnt));
        while(scanf("%c", &c)){
            if(c=='\n') break;
            cnt[c]++;
        }

        int res = 100005;

        for(int i = 'a'; i<='z'; i++) res = min(res, cnt[i]);

        printf("Case %d: %d\n", ++cs, res);
    }
    return 0;
}
