#include<bits/stdc++.h>
using namespace std;

const int maxn = 100005, inf = 16843009;

int freq[maxn], a[maxn], need[maxn];
bool dp[maxn];

int solve(int n, int m){

	memset(dp, 0, sizeof(dp));
	dp[0] = 1;

	for(int i = 1; i<=n; i++){
		
		for(int j = 0; j<=m; j++){
			if(dp[j] == true) need[j] = 0;
			else need[j] = inf;
		}

		for(int j = 0; j<=m; j++){
			int k = a[i];
			if(j+k <=m && dp[j] == true){
				int lagbe = need[j] + 1;
				if(lagbe<need[j+k] && lagbe<=freq[i]){
					need[j+k] = lagbe;
					dp[j+k] = true;
				}
			}

		}
	}

	int ret = 0;

	for(int i = 1; i<=m; i++){
		ret += (dp[i]==true);
	}
	return ret;
}

int main(){

	// freopen("in.txt", "r", stdin);

	int test, cs= 0;

	scanf("%d", &test);

	while(test--){
			
			int n, m;

			scanf("%d %d", &n, &m);

			for(int i = 1; i<=n; i++) scanf("%d", &a[i]);
			for(int i = 1; i<=n; i++) scanf("%d", &freq[i]);


			int res = solve(n, m);

			printf("Case %d: %d\n", ++cs, res);



	}

}
