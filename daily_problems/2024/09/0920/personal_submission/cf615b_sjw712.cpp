const int N = 100010, M = 200010 * 2;
int h[N], ne[M], e[M], idx;
bool vis[N];
int tail[N],cnt[N];
void add(int a, int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void dfs(int u, int fa){
	if(vis[u]) return;
	vis[u] = true;
	int c = 0;
	tail[u] = 1;
	for(int i = h[u]; ~i; i = ne[i]){
		int j = e[i];
		c ++;
		if(j == fa){
			if(j < u) tail[u] = max(tail[u], tail[j] + 1);
			continue;
		}
		if(j > u) continue;
		dfs(j, u);
		if(j < u) tail[u] = max(tail[u], tail[j] + 1);
	}
	cnt[u] = c;
}
