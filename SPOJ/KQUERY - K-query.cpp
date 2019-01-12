#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

struct query{
	int i, j, k, id;
	query(){}
	bool operator<(const query &p)const{
		return k>p.k;
	}
}q[N];

int a[N], res[N], tree[N];
vector<pair<int, int> > v;

void update(int pos, int limit, int x){
 
    while(pos<=limit)
    {
        tree[pos]+=x;
        pos+=(pos)&(-pos);
    }
}

int query(int pos){
 
    int sum = 0;

    while(pos>0)
    {
        sum+=tree[pos];
        pos-=(pos)&(-pos);
    }
    return sum;
}


int main(){
	
	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif	

	int n, m;

	scanf("%d", &n);

	for(int i = 1; i<=n; i++) {
		scanf("%d", &a[i]);
		v.push_back(make_pair(a[i], i));
	}

	sort(v.begin(), v.end());

	scanf("%d", &m);

	for(int i = 0; i<m; i++){
		scanf("%d %d %d", &q[i].i, &q[i].j, &q[i].k);
		q[i].id = i;
	}

	sort(q, q+m);

	for(int i = 0; i<m; i++){
		
		int pk = q[i].k;

		while(v.size()!=0){
			pair<int, int> top = v.back();
			if(top.first>pk){
				v.pop_back();
				update(top.second, n, 1);
			}
			else break;
		}

		int ans = query(q[i].j) - query(q[i].i - 1);

		res[q[i].id] = ans;
	}

	for(int i = 0; i<m; i++) printf("%d\n", res[i]);

	return 0;

}
