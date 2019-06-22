#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPalindrome(ll n){
	
	ll rev = 0, nn = n;
	while(n){
		int x = n%10;
		n/=10;
		rev = rev*10 + x;
	}

	return rev == nn;
}

int bruteForce(int i, int j){
	int ret = 0;
	for(int x = i; x<=j; x++){
		ret += isPalindrome(x);
	}

	return ret;
}

ll dp[20][20][2][2][2];
vector<int> v;

ll f(int i, int j, bool isSmall, bool rFlag, bool isStart){

	if(i>j){
		if(isSmall == false && rFlag) return 0;
		else return 1;
	}

	ll &ret = dp[i][j][isSmall][rFlag][isStart];

	if(ret != -1) return ret;

	ret = 0;

	int max_ = (isSmall?9:v[i]);
	int min_ = isStart?0:1;

	for(int k = 0; k<=max_; k++){		


		if(isStart == false && k==0){
			 ret += f(i+1, j, isSmall | k<v[i], rFlag, 0);
		}

		else if(i == j){
			ret += f(i+1, j, isSmall | k<v[i], rFlag, isStart | k>0);
		}
		else if(k == v[j]){
			ret += f(i+1, j-1, isSmall | k<v[i], rFlag, isStart | k>0);
		}

		else {


			ret += f(i+1, j-1, isSmall | k<v[i], k > v[j],isStart | k);
		}
	}


	return ret;


}

ll solve(ll n){

	v.clear();
	while(n){
		v.push_back(n%10);
		n/=10;
	}

	reverse(v.begin(), v.end());
	memset(dp, -1, sizeof(dp));
	return f(0, v.size()-1, false, false, false);

}

int main(){

	//freopen("in.txt", "r", stdin);

	int test, cs= 0;

	scanf("%d", &test);

	while(test--){

		ll a, b;

		scanf("%lld %lld", &a, &b);

		if(a>b) swap(a, b);

		ll ret = solve(b) - solve(a) + isPalindrome(a);

	//	cout<<bruteForce(a, b)<<endl;
		printf("Case %d: %lld\n", ++cs, ret);

	}

}
