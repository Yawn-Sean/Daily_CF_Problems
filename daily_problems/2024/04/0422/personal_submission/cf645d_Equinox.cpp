#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10, M = N;
typedef pair<int, int> PII;
struct edge{
	int v, nxt;
}edges[M];

int n, m;
int head[N], idx;
int deg[N], q[N], f, b;
PII g[N];
void addedge(int u, int v){
	edges[idx] = { v, head[u] }, head[u] = idx ++;
}

int main(){
	//freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++) cin >> g[i].first >> g[i].second;
	int l = 1, r = m, ans = -1;
	while(l <= r){
		int mid = l + r >> 1;
		memset(head, -1, sizeof head), memset(deg, 0, sizeof deg), idx = 0, f = b = 0;
		for(int i = 0; i < mid; i ++) addedge(g[i].first, g[i].second), deg[g[i].second] ++;
		for(int i = 1; i <= n; i++) if (!deg[i]) q[b ++ ] = i;
		bool F = 1;
		while(f < b){
			if(b - f > 1) {
				F = 0;
				break;
			}
			int x = q[f ++];
			for(int i = head[x]; ~i; i = edges[i].nxt){
				int y = edges[i].v;
				if(! -- deg[y]) q[b ++] = y;
			}
		}
		if(F) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}
