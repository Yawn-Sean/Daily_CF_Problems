#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 2e5 + 5;
const int MAXN = 2e5 + 5;

struct Node {
	int rmx = -INF, lmx = -INF, rmn = -INF, lmn = -INF, ans = -INF;
	
	friend Node operator + (Node& lhs, Node& rhs){
		return {
			.rmx = max(lhs.rmx, rhs.rmx),
			.lmx = max(lhs.lmx, rhs.lmx),
			.rmn = max(lhs.rmn, rhs.rmn),
			.lmn = max(lhs.lmn, rhs.lmn),
			.ans = max({lhs.ans, rhs.ans, rhs.rmx + lhs.lmn, rhs.rmn + lhs.lmx})
		};
	}
} t[MAXN << 2];

int a[MAXN];

void build(int cur, int l, int r){
	if(l == r){
		t[cur] = {a[l] - r, a[l] + l, -a[l] - r, -a[l] + l, 0};
		return;
	}
	int mid = (l + r) >> 1;
	build(cur << 1, l, mid);
	build(cur << 1 | 1, mid + 1, r);
	t[cur] = t[cur << 1] + t[cur << 1 | 1];
}

void update(int cur, int l, int r, int q){
	if(l > q || r < q) return;
	if(l == r){
		t[cur] = {a[l] - r, a[l] + l, -a[l] - r, -a[l] + l, 0};
		return;
	}
	int mid = (l + r) >> 1;
	update(cur << 1, l, mid, q);
	update(cur << 1 | 1, mid + 1, r, q);
	t[cur] = t[cur << 1] + t[cur << 1 | 1];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int _;
	cin >> _;
	while(_--){
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= n; ++i){
			cin >> a[i];
		}
		build(1, 1, n);
		cout << t[1].ans << "\n";
		for(int i = 1; i <= m; ++i){
			int p, v;
			cin >> p >> v;
			a[p] = v;
			update(1, 1, n, p);
			cout << t[1].ans << "\n";
		}
		
	}
	return 0;
}