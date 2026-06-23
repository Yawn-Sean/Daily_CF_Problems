		#include<bits/stdc++.h>
		using namespace std;
		using ll = long long;
		#define pb push_back
		#define pii pair<int,int>
		#define int long long
		#define i128 __int128
    #define ull unsigned long long

    struct Dijkstra {
    const long long INF = 1e18; // 极大值

    struct Edge {
        int to;
        long long weight;
    };

    int n; // 节点数
    vector<vector<Edge>> adj; // 邻接表
    vector<long long> dist;   // 距离数组

    // 构造函数，初始化大小
    Dijkstra(int _n) {
        n = _n;
        adj.resize(n + 1);
        dist.assign(n + 1, INF);
    }

    // 添加无向边
    void add_edge(int u, int v, long long w) {
        adj[u].push_back({v, w});
    }

    // 运行 Dijkstra 算法求解单源最短路
    void run(int start) {
        // 如果对同一个图多次查询，需要每次重置距离数组
        dist.assign(n + 1, INF); 
        dist[start] = 0;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (const auto& edge : adj[u]) {
                int v = edge.to;
                long long weight = edge.weight;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    // 获取起点到目标点的最短距离
    long long get_dist(int target) {
        return dist[target];
    }
};

		void solve()
		{		
			int n,m,k,c;
            cin>>n>>m>>k>>c;
            vector<bool>z(n+1,true);
            for(int i=0;i<k;i++){
                int a;
                cin>>a;
                z[a]=false;
            }
            vector<int>f(n+1,0);
            for(int i=1;i<=n;i++){
                cin>>f[i];
            }
            Dijkstra graph(n);
            for(int i=0;i<m;i++){
                int u,v;
                cin>>u>>v;
                if(z[u]&&z[v]){
                    graph.add_edge(u,v,0);
                    graph.add_edge(v,u,0);
                }
                else if(!z[u]&&z[v]){
                    graph.add_edge(u,v,0);
                    graph.add_edge(v,u,f[u]);
                }
                else if(z[u]&&!z[v]){
                    graph.add_edge(u,v,f[v]);
                    graph.add_edge(v,u,0);
                }
            }
            int st=1;
            graph.run(st);
            int ans=graph.get_dist(n);
            if(ans==graph.INF||ans>c)
            cout<<-1<<"\n";
            else
            cout<<ans<<"\n";
		}
		
		
		int32_t main() {
			cin.tie(0)->sync_with_stdio(0);
			int tc = 1;
			//cin >> tc;
			while (tc--) solve();
			return 0;
			}
