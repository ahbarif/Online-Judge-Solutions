#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[35];

char str[40];

int main(){
    dp[0] = 1LL;

    for(int i = 1; i<=30; i++){
        dp[i] = dp[i-1] * 2;

    }

    int t;

    cin>>t;

    while(t--){
        ll ret = 1LL, cnt = 1;

        scanf("%s", str);

        for(int i = 0; str[i]; i++){
            if(str[i] == str[i+1]) cnt++;
            else{
            //    cout<<"cnt = "<<cnt<<endl;
                ret *= dp[cnt-1];
                cnt = 1;
            }
        }

        printf("%lld\n", ret);

    }
}
