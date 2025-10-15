#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int d;
    std::cin>>d;

    const int D = d;
    const int N = D * D;               
    vector<char> vis(N, 0), dig(N, -1);  
    vector<int> par(N, -2);       
    queue<int> q;

    auto id = [&](int r, int s) { return r * D + s; };
    int goal = id(0, 0);

    for (int x = 1; x <= 9; ++x) {
        int r = x % D, s = x % D;
        int u = id(r, s);
        if (!vis[u]) {
            vis[u] = 1;
            par[u] = -1;
            dig[u] = (char)x;
            q.push(u);
        }
    }

    int target = -1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == goal) { target = u; break; }
        int r = u / D, s = u % D;
        for (int x = 0; x <= 9; ++x) {
            int nr = (r * 10 + x) % D;
            int ns = (s + x) % D;
            int v = id(nr, ns);
            if (!vis[v]) {
                vis[v] = 1;
                par[v] = u;
                dig[v] = (char)x;
                q.push(v);
            }
        }
    }

    string ans;
    for (int cur = (target == -1 ? goal : target); cur != -1; cur = par[cur]) {
        ans.push_back(char('0' + dig[cur]));
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    return 0;
}
