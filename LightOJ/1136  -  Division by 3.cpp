#include<bits/stdc++.h>
using namespace std;
int main(){

	long long a, b, test, i, diff, ans, k;


	cin >> test;

	for (i = 1; i <= test; i++){
		cin >> a >> b;
		ans = (b / 3) - ((a - 1) / 3);
		diff = b - a;

       if(a%3==2 && b%3==2) k=(diff/3)+1;
       else if(a%3==2 && b%3!=2)    k=(diff+2)/3;
       else if(b%3==2 && a%3!=2)    k=(diff+2)/3;
       else k=diff/3;
        
        if(a%3==1 && b%3==0)    ans++;
    
        ans+=k;

		cout << "Case " << i << ": " << ans << endl;
	}
	return 0;
}