#include<bits/stdc++.h>
using namespace std;

const int maxn = 102;
int n, dp[maxn][maxn][maxn], a[maxn];

int frodo(int pos, int baam, int daan){

		if(pos>n) return 0;

		if(dp[pos][baam][daan] != -1) return dp[pos][baam][daan];

		int ret = 0;

		ret = max(ret, frodo(pos+1, baam, daan));

		if(a[pos]>=a[baam] && a[pos]<=a[daan]){
			ret = max(ret, 1+frodo(pos+1, pos, daan));
		}

		if(a[pos]<=a[daan] && a[pos]>=a[baam]){
			ret = max(ret, 1+frodo(pos+1, baam, pos));
		}


		return dp[pos][baam][daan] = ret;

}


int foo(){

	a[0] = 0;
	a[n+1] = INT_MAX;
	memset(dp, -1, sizeof(dp));
	int res = frodo(1, 0, n+1);
	return res;

}
int main(){

//	freopen("in.txt", "r", stdin);

	int test, cs= 0;

	scanf("%d", &test);

	while(test--){
			
			scanf("%d", &n);

			for(int i = 1; i<=n; i++) scanf("%d", &a[i]);

			memset(dp, -1, sizeof(dp));

			int res = foo();

			printf("Case %d: %d\n", ++cs, res);



	}

}
