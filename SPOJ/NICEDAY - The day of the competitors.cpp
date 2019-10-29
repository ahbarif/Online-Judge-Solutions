#include<bits/stdc++.h>
using namespace std;

#define N 500005
#define inf 1e6

int tree[N*4];

struct data{
	int a, b, c;
	data(){}
	data(int a, int b, int c):a(a), b(b), c(c){}
	bool operator<(const data &p) const{
		return a<p.a;
	}
}ar[N];

int query(int at, int lo, int hi, int i, int j){
	if(i>j) return inf;

	if(i>hi || j<lo) return inf;

	if(i<=lo && j>= hi) return tree[at];

	int mid = (lo+hi)/2;

	int x = query(at*2, lo, mid, i, j);
	int y = query(at*2 + 1, mid+1, hi, i, j);

	return min(x, y);
}

void update(int at, int lo, int hi, int i, int val){
	if(i > hi || i< lo) return;

	if(lo == hi){
		tree[at] = val;
		return;
	}

	int mid = (lo+hi)/2;

	update(at*2, lo, mid, i, val);
	update(at*2 + 1, mid+1, hi, i, val);

	tree[at] = min(tree[at*2], tree[at*2 + 1]);

}


int main() {

	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif

	int test;
	scanf("%d", &test);
	while(test--){
		fill(tree, tree+N, inf);

		int n;
		scanf("%d", &n);
		for(int i = 1; i<=n; i++){
			scanf("%d %d %d", &ar[i].a, &ar[i].b, &ar[i].c);
		}

		sort(ar+1, ar+n+1);

		int exc = 0;

		for(int i = 1; i<=n; i++){
			int place_b = ar[i].b;
			int place_c = ar[i].c;

			int mn = query(1, 1, n, 1, place_b-1);

			// cout<<"mn = "<<mn<<endl;

			if(mn > place_c) exc++;

			int upd = min(place_c, query(1, 1, n, place_b, place_b));
			//cout<<"upd = "<<upd<<" at "<<place_b<<endl;
			update(1, 1, n, place_b, upd);
		}

		printf("%d\n", exc);
	}

	//cout<<"done"<<endl;


}

