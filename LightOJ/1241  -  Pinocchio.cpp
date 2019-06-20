#include<iostream>
using namespace std;
int main(){

	int test, x = 0, ans, a[105], i, n;
	
	cin >> test;
	
	while (test--){
		
		cin >> n;	
		ans = 0;
		
		for (i = 0; i < n; i++)	cin >> a[i];
		
		if (a[0]>2)	ans += (a[0] -2 + 4) / 5;
		
		for (i = 1; i < n; i++){
			if (a[i - 1] < a[i])	{
				ans += (a[i] - a[i - 1] + 4) / 5;
			}
		}
		cout << "Case " << ++x << ": " << ans << endl;
	}

	return 0;
}