const int N = 3e5 + 10, M = N * 2;
int h[N], ne[M], e[M], w[M], idx = 1;
int n, m, k;
int dist[N];
bool st[N];
struct node{
	int d, v, id;
	bool operator>(const node& t) const{
		if(d != t.d) return d > t.d;
		return v > t.v;
	}
};
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}
void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<node, vector<node>, greater<node>> q;
    q.push({0, 1, 0});
    vector<int> ans;
    int cnt = k;
    while (q.size()){
        auto t = q.top();
        q.pop();
        int ver = t.v, distance = t.d;
        if (st[ver]) continue;
        st[ver] = true;
        if(ver != 1){
        	if(cnt == 0) break;
	        ans.push_back(t.id);
	        cnt --;
        }
        for (int i = h[ver]; ~ i; i = ne[i]){
            int j = e[i];
            if (dist[j] > dist[ver] + w[i]){
                dist[j] = dist[ver] + w[i];
                q.push({dist[j], j, i});
            }
        }
    }
    cout << ans.size() << '\n';
    for(auto i : ans) cout << (i + 1) / 2 << " ";
}

void solve(){
	memset(h, -1, sizeof h);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++){
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
	}
	dijkstra();
}
