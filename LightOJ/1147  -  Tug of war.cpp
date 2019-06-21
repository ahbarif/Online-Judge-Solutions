#include<bits/stdc++.h>
using namespace std;

const int maxn = 100005, inf = 16843009;

long long int w[maxn], dp[maxn];

void solve(int n, int sum)
{
	int hn = n/2;
	int hn1 = (n+1)/2;

	memset(dp, 0, sizeof(dp));
	dp[0] = 1LL;

	for(int i = 1; i<=n; i++){
		for(int j = sum/2; j>=w[i]; j--){
			
				dp[j] |= (dp[j-w[i]]<<1);
			
		}
	}


	if(n&1){
		for(int i = sum/2; i>=0; i--){
			long long flag1 = dp[i]&(1LL<<hn);
			long long flag2 = dp[i]&(1LL<<hn1);
			if(flag1 || flag2){
				cout<<i<<" "<<sum-i<<endl;
				return;
			}
		}
	}
	else{

		for(int i = sum/2; i>=0; i--){
			long long flag = (dp[i] & (1LL<<(n/2)));
			if(flag){
				cout<<i<<" "<<sum-i<<endl;
				return;
			}
		}
	}
}



int main()
{

#ifdef local
  	freopen("in.txt", "r", stdin);
#endif
  	
    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {

            int n, sum = 0;

            scanf("%d", &n);

            for(int i = 1; i<=n; i++)
            {
                scanf("%lld", &w[i]);
                sum += w[i];
            }

            printf("Case %d: ", ++cs);

            solve(n, sum);

    }

    return 0;	

}
