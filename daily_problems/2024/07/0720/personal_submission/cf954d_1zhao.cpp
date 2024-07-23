#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void dijkstra(vector<vector<int>>& graph, int start, vector<int>& distances) {
    int n = graph.size();
    distances.resize(n, INF);
    distances[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v : graph[u]) {
            if (distances[u] + 1 < distances[v]) {
                distances[v] = distances[u] + 1;
                pq.push({distances[v], v});
            }
        }
    }
}

int main()
{
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	s--; t--;
	vector<vector<int>> g(n);
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		g[a-1].push_back(b-1);
		g[b-1].push_back(a-1);
	}
	
	vector<int> sd, td;
	dijkstra(g, s, sd);
	dijkstra(g, t, td);
	
	int res = 0;
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			res += sd[i] + 1 + td[j] >= sd[t] && sd[j] + 1 + td[i] >= sd[t];
		}
	}
	res -= m;
	
	cout << res << endl;
	
	return 0;
}
