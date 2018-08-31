#include<bits/stdc++.h>
using namespace std;

const int maxn = 300005, maxf = 1000005;

int cnt[maxf], a[maxn], ans[maxn], answer = 0;

int block = 174;

struct node{
	int L, R, i;
}q[maxn];

bool cmp(node x, node y) {
	if(x.L/block != y.L/block) {
		return x.L/block < y.L/block;
	}
	return x.R < y.R;
}

void add(int position) {
	cnt[a[position]]++;
	if(cnt[a[position]] == 1) {
		answer++;
	}
}

void remove(int position) {
	cnt[a[position]]--;
	if(cnt[a[position]] == 0) {
		answer--;
	}
}

int main() {

	int n, m;

	scanf("%d", &n);

	for(int i=0; i<n; i++) scanf("%d", &a[i]);

	scanf("%d", &m);

	for(int i=0; i<m; i++) {
		scanf("%d %d", &q[i].L, &q[i].R);
		q[i].L--; q[i].R--;
		q[i].i = i;
	}

	sort(q, q + m, cmp);

	int currentL = 0, currentR = 0;

	for(int i=0; i<m; i++) {

		int L = q[i].L, R = q[i].R;

		while(currentR <= R) {
			add(currentR);
			currentR++;
		}

		while(currentR > R+1) {
			remove(currentR-1);
			currentR--;
		}

		while(currentL < L) {
			remove(currentL);
			currentL++;
		}

		while(currentL > L) {
			add(currentL-1);
			currentL--;
		}


		ans[q[i].i] = answer;
	}

	for(int i=0; i<m; i++)
		printf("%d\n", ans[i]);

}
