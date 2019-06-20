#include<bits/stdc++.h>
using namespace std;

const int maxn = 1429431;
int tree[maxn+100];

void update(int pos, int val){
    for(; pos <=maxn; pos += pos&(-pos)){
        tree[pos] += val;
    }
}

int query(int pos){
    int sum = 0;

    for(; pos>=1; pos -= pos&(-pos)){
        sum += tree[pos];
    }

    return sum;
}

int find_kth(int k){
    int lo = 1, hi = maxn, mid;

    while(lo<=hi){
        mid = (lo+hi)/2;
        if(query(mid)>=k) hi = mid-1;
        else lo = mid+1;
    }

    return lo;
}

int find_size(){
    return query(maxn);
}

void preprocess(){

    vector<int> v;
    int i, j, cur = 2, sz;

    for(int i = 1; i<=maxn; i++) update(i, 1);

    for(int i = 2; cur<=(sz = find_size()); i++){
        v.clear();
        for(int j = cur; j<=sz; j+=cur) v.push_back(find_kth(j));

        for(int j = 0; j<v.size(); j++) update(v[j], -1);

        cur = find_kth(i);
    }
}

int main()
{
#ifdef local
  //  freopen("in.txt", "r", stdin);
#endif

    preprocess();

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        int n;

        scanf("%d", &n);

        printf("Case %d: %d\n", ++cs, find_kth(n));
    }

    return 0;
}



