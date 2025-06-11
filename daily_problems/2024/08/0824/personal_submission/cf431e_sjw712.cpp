const int N = 2e5 + 10;
struct Q{
	int op;
	int x, y;
}query[N];
struct Node{
	int l, r;
	int cnt, sum;
}tr[N * 4];
int h[N], n, q;
vector<int> alls;
int find(int x){
	return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;
}
void build(int u, int l, int r){
	tr[u] = {l, r, 0, 0};
	if(l == r){
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
}
void pushup(int u){
	tr[u].cnt = tr[u << 1].cnt + tr[u << 1 | 1].cnt;
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
void modify(int u, int x, int k){
	if(tr[u].l == tr[u].r){
		tr[u].cnt += k;
		tr[u].sum += k * alls[x - 1];
		return;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if(x <= mid) modify(u << 1, x, k);
	else modify(u << 1 | 1, x, k);
	pushup(u);
}
int query_cnt(int u, int l, int r){
	if(tr[u].l >= l && tr[u].r <= r) return tr[u].cnt;
	int res = 0;
	int mid = tr[u].l + tr[u].r >> 1;
	if(l <= mid) res += query_cnt(u << 1, l, r);
	if(r > mid) res += query_cnt(u << 1 | 1, l, r);
	return res;
}
int query_sum(int u, int l, int r){
	if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
	int res = 0;
	int mid = tr[u].l + tr[u].r >> 1;
	if(l <= mid) res += query_sum(u << 1, l, r);
	if(r > mid) res += query_sum(u << 1 | 1, l, r);
	return res;
}

void solve(){
	cin >> n >> q;
	for(int i = 1; i <= n; i ++){
		cin >> h[i];
		alls.push_back(h[i]);
	}
	for(int i = 1; i <= q; i ++){
		int op;
		cin >> op;
		if(op == 1){
			int p, x;
			cin >> p >> x;
			query[i] = {op, p, x};
			alls.push_back(x);
		}
		else{
			int v;
			cin >> v;
			query[i] = {op, 0, v};
		}
	}
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());
	alls.push_back(1e15);
	build(1, 1, alls.size());
	for(int i = 1; i <= n; i ++){
		modify(1, find(h[i]), 1);
	}
	for(int i = 1; i <= q; i ++){
		if(query[i].op == 1){
			modify(1, find(h[query[i].x]), -1);
			h[query[i].x] = query[i].y;
			modify(1, find(h[query[i].x]), 1);
		}
		else{
			double l = 0, r = 1e15;
			while(r - l >= 1e-4){
				double mid = (l + r) / 2;
				int p = upper_bound(alls.begin(), alls.end(), mid) - alls.begin();
				if(query_cnt(1, 1, p) * mid >= query_sum(1, 1, p) * 1. + query[i].y) r = mid;
				else l = mid;
			}
			cout << fixed << setprecision(10) << l << "\n";
		}
	}
}
