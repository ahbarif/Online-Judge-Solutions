#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> a;
	int test, len, query, i, x;
	string command;

	cin >> test;
	for (i = 0; i<test; i++){
		a.clear();
		cin >> len >> query;
		printf("Case %d:\n", i + 1);
		while (query--){
			cin >> command;

			if (command == "pushLeft"){
			    cin>>x;
				if (a.size()<len) {
					a.insert(a.begin() + 0, x);
					printf("Pushed in left: %d\n", x);
				}
				else cout << "The queue is full\n";
			}
			else if (command == "pushRight"){
			    cin>>x;
				if (a.size()<len) {
					a.push_back(x);
					printf("Pushed in right: %d\n", x);
				}
				else cout << "The queue is full\n";
			}
			else if (command == "popLeft"){
				if (a.size() == 0) cout << "The queue is empty\n";
				else{
					printf("Popped from left: %d\n", a.front());
					a.erase(a.begin() + 0);
				}
			}
			else{
				if (a.size() == 0) cout << "The queue is empty\n";
				else{

					printf("Popped from right: %d\n", a.back());
					a.pop_back();
				}
			}


		}
	}


	return 0;
}
