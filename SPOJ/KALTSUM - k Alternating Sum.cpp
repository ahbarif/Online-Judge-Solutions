#include<bits/stdc++.h>
using namespace std;
 
const int maxn = 100005;
 
long long a[maxn], cum[maxn], pref[318][maxn];
 
int main(){
 
 
	#ifdef local
	freopen("in.txt", "r", stdin);
	#endif
 
	int n, q, root;
 
	scanf("%d %d", &n, &q);
 
	root = sqrt(n);
 
	for(int i = 1; i<=n; i++){
		scanf("%lld", &a[i]);
		cum[i] = a[i] + cum[i-1];
	}
 
	for(int i=1; i<=root; i++)
	{
		long long ret=0, ex=0;
 
		for(int j=n; j>=1; j--)
		{
			ret += a[j];
			if(j+i>n)   ex=0;
			else  ex=a[j+i];
 
			ret-=ex;
 
			if(j+i-1>n)
				pref[i][j]=0;
			else
				pref[i][j]=ret-pref[i][j+i];
		}
	}
 
	while(q--){
		int l, r, k;
 
		scanf("%d %d %d", &l, &r, &k);
 
		int vagfol = (r-l+1)/k;
 
		long long ans = 0;
 
		if(k>root){
 
			for(int i = l, turn = 0; i<=r; i+=k){
				if(turn&1){
					ans -= (cum[i+k-1] - cum[i-1]);
				}
				else ans += (cum[i+k-1] - cum[i-1]);
 
				turn ^= 1;
			}
		}
 
		else{
 
			if(vagfol & 1){
				ans = pref[k][l] + pref[k][r+1];
			}
			else ans = pref[k][l] - pref[k][r+1];
		}
 
		printf("%lld\n", ans);
	}
 
	return 0;
	
}
