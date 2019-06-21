#include <iostream>
#include <string>
using namespace std;
int main() {

	ios_base::sync_with_stdio(false);
	
	int test, ans, score, i, n;
	string a;
	cin >> test;
	while (test--){
		cin >> a;	ans = 1;	score = 0;	n = a.length();
		for (i = 0; i < n; i++){
			if (a[i] == 'O')	score += ans, ans++;
			else ans = 1;
		}
		cout << score << endl;

	}

	return 0;
}
