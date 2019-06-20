#include<bits/stdc++.h>
using namespace std;

long long M = 10000007;
int fn[10005];

int rec(int n){
	for (int i = 7; i <= n; i++){
		fn[i] = (fn[i - 1] % M + fn[i - 2] % M + fn[i - 3] % M + fn[i - 4] % M + fn[i - 5] % M + fn[i - 6] % M) % M;
	}
	return 0;
}

int main(){

	int test, x=0, i, n;
	cin >> test;
	while (test--){
		cin >> fn[1] >> fn[2] >> fn[3] >> fn[4] >> fn[5] >> fn[6] >> n;
		rec(10010);
		cout<<"Case "<<++x<<": "<<fn[n+1]%M<<endl;
	}
   return 0;
}
