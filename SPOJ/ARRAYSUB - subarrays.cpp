#include <bits/stdc++.h>
using namespace std;

int a[1000005];
multiset<pair<int, int> > st;

int main(){
	
	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif	

	int n, k;

	scanf("%d", &n);

	for(int i = 1; i<=n; i++) scanf("%d", &a[i]);

	scanf("%d", &k);

	for(int i = 1; i<=k; i++) {
		st.insert(make_pair(-a[i], i));
	}

	pair<int, int> top = *st.begin();

	printf("%d", -top.first);

	int hi = k, lo = 1;

	while(hi<n){
		hi++;
		st.insert(make_pair(-a[hi], hi));
		st.erase(make_pair(-a[lo], lo));
		lo++;
		top = *st.begin();
		printf(" %d", -top.first);
	}

	cout<<endl;

	return 0;

}

