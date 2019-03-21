#include <bits/stdc++.h>
using namespace std;

string multiplyBy2(string s){

	string ret = "";

	int carry = 0;

	for(int i = s.size()-1; i>=0; i--){
		int p = s[i] - '0';
		int r = (p + p + carry)%10;
		int ex = (p+p+carry)/10;
		carry = ex;
		ret.push_back('0'+r);
	}

	if(carry != 0) ret.push_back('0'+carry);

	reverse(ret.begin(), ret.end());

	return ret;
}

string minus2(string s){
	int carry = 2;
	string ret = "";

	for(int i = s.size()-1; i>=0; i--){
		int p = s[i] - '0';
		if(carry>p) {
			int r = 10 + p - carry;
			carry = 1;
			ret.push_back('0' + r);
		}
		else{
			int r = p - carry;
			carry = 0;
			ret.push_back('0' + r);
		}
	}

	while(ret[ret.size()-1]=='0') ret.pop_back();

	if(ret=="") ret = "0";

	reverse(ret.begin(), ret.end());

	return ret;
}

int main()
{	
		#ifdef local
			freopen("in.txt", "r", stdin);
		#endif

		string s;

		while(cin>>s){
			
			if(s=="1") cout<<1<<endl;
			else{
				s = multiplyBy2(s);
				cout<<minus2(s)<<endl;
			}
		}

		return 0;

}

