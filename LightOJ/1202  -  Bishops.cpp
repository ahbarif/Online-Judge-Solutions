#include <bits/stdc++.h>
using namespace std;
long long myabs(long long a, long long b){
    if(a>b) return a-b;
    return b-a;
}
int main(){

	ios_base::sync_with_stdio(false);
	long long test, i = 0, a, b, c, d;
	cin >> test;
	while (test--){
		cin >> a >> b >> c >> d;
		if (myabs(a,c) == myabs(b,d))	cout << "Case " << ++i << ": 1\n";
		else if (myabs(a,c) % 2 == myabs(b,d) % 2) cout << "Case " << ++i << ": 2\n";
		else cout << "Case " << ++i << ": impossible\n";
	}
	return 0;
}
