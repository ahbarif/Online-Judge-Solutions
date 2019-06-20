#include <iostream>
#include <math.h>
#include<vector>
using namespace std;
vector<double> logs;
int main(){

	ios_base::sync_with_stdio(false);
	int n, i, j, test;
	double k, s=0;
	logs.push_back(0);
	for (i = 1; i < 1000005; i++){
		k = log(i);
		s += k;
		logs.push_back(s); 
	}
	
	cin >> test;
	for (i = 0; i < test; i++){
		cin >> n >> j;
		s = logs[n];
		s /= log(j);
		s =(int)s + 1;
		cout << "Case " << i + 1 << ": " << (int)s << endl;
	}
	return 0;
}