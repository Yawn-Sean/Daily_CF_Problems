#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
typedef pair<int,int> pii;
const int N = 200010,inf = 1e9 + 9;

int n,a[N],dist[N];

vector<pii> son[N];   // (nxt,d)  
priority_queue<pii> pq;

void dijstra(int src) {
	for (int i = 0;i <= n + 1; i++) {
		dist[i] = inf;
	}
	
	dist[src] = 0;
	pq.emplace(pii{0,src});
	
	while (!pq.empty()) {
		pii node = pq.top(); pq.pop();
		
		int i = node.second, d = -node.first;
		if (d > dist[i]) {
			continue;
		}
		
		for (int j = 0; j < son[i].size(); j++) {
			int y = son[i][j].first, z = son[i][j].second;
			
			if (dist[y] > dist[i] + z) {
				dist[y] = dist[i] + z;
				// cout << "更新 i:" << i << " y: " << y << " " << dist[y] << "\n";
				pq.emplace(pii{-dist[y],y});
			}
		}
		
	}
	
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> n;
	
	for (int i = 1;i <= n; i++) {
		cin >> a[i];
		
		if (i != a[i]) {
			son[i].push_back(pii{a[i],1});
		}
	}
	
	for (int i = 2; i <= n; i++) {
		son[i].push_back(pii{i - 1,1});
		son[i - 1].push_back(pii{i,1});
	}
	
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j < son[i].size(); j++) {
//			cout << son[i][j].first << " " << son[i][j].second << "\n";
//		}
//	}
	
	dijstra(1);
	
	for (int i = 1;i <= n; i++) {
		cout << dist[i] << " ";
	}
	
	return 0;
} 
