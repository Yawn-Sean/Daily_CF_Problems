#include <bits/stdc++.h>
using namespace std;

struct HopcroftKarp {
    int nL, nR;
    vector<vector<int>> adj;  
    vector<int> dist, matchL, matchR;
    HopcroftKarp(int nL=0, int nR=0): nL(nL), nR(nR) {
        adj.assign(nL + 1, {});
        matchL.assign(nL + 1, 0);
        matchR.assign(nR + 1, 0);
        dist.resize(nL + 1);
    }
    void addEdge(int u, int v){ adj[u].push_back(v); }
    bool bfs() {
        queue<int> q;
        for (int u = 1; u <= nL; ++u) {
            if (!matchL[u]) dist[u] = 0, q.push(u);
            else dist[u] = -1;
        }
        bool reachableFreeR = false;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v: adj[u]) {
                int w = matchR[v];
                if (w && dist[w] == -1) {
                    dist[w] = dist[u] + 1;
                    q.push(w);
                }
                if (!w) reachableFreeR = true;
            }
        }
        return reachableFreeR;
    }
    bool dfs(int u){
        for (int v: adj[u]) {
            int w = matchR[v];
            if (!w || (dist[w] == dist[u] + 1 && dfs(w))) {
                matchL[u] = v;
                matchR[v] = u;
                return true;
            }
        }
        dist[u] = -1; 
        return false;
    }
    int maxMatching() {
        int m = 0;
        while (bfs()) {
            for (int u = 1; u <= nL; ++u)
                if (!matchL[u] && dfs(u)) ++m;
        }
        return m;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B, C;
    while ( (cin >> A >> B >> C) ) {
        int K; 
        if (!(cin >> K)) return 0;
        auto enc = [&](int x,int y,int z)->int{
            return (x*(B+1) + y)*(C+1) + z; 
        };
        int SZ = (A+1)*(B+1)*(C+1);
        vector<char> blocked(SZ, 0);
        for (int i = 0; i < K; ++i) {
            int x, y, z; cin >> x >> y >> z;
            blocked[enc(x,y,z)] = 1;
        }

        vector<int> idL(SZ, 0), idR(SZ, 0);
        int nL = 0, nR = 0, usable = 0;
        for (int x = 1; x <= A; ++x)
        for (int y = 1; y <= B; ++y)
        for (int z = 1; z <= C; ++z) {
            int code = enc(x,y,z);
            if (blocked[code]) continue;
            ++usable;
            if ( ( (x + y + z) & 1 ) == 0 ) idL[code] = ++nL;
            else idR[code] = ++nR;
        }

        HopcroftKarp hk(nL, nR);

        vector<array<int,3>> moves;
        for (int a = 0; a < 3; ++a)     
        for (int b = 0; b < 3; ++b) if (b != a) {
            for (int s1 : {-1, 1})
            for (int s2 : {-1, 1}) {
                array<int,3> d{0,0,0};
                d[a] = 2*s1; d[b] = 1*s2;
                moves.push_back(d);
            }
        }

        auto inside = [&](int x,int y,int z){
            return 1<=x && x<=A && 1<=y && y<=B && 1<=z && z<=C;
        };
        for (int x = 1; x <= A; ++x)
        for (int y = 1; y <= B; ++y)
        for (int z = 1; z <= C; ++z) {
            int ucode = enc(x,y,z);
            if (!idL[ucode]) continue; 
            int u = idL[ucode];
            for (auto d: moves) {
                int nx = x + d[0], ny = y + d[1], nz = z + d[2];
                if (!inside(nx,ny,nz)) continue;
                int vcode = enc(nx,ny,nz);
                if (blocked[vcode]) continue;
                int v = idR[vcode];
                if (v) hk.addEdge(u, v);
            }
        }

        int M = hk.maxMatching();
        cout << (usable - M) << "\n";
    }
    return 0;
}
