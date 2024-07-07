int n;

void solve() {
     cin >> n;
     vector<vector<int>> g(n);
     map<PII, int> E;
     rep(i, 1, n - 1) {
         int x, y;
         cin >> x >> y;
         x --, y --;
         if (x > y) swap(x, y);
         E[make_pair(x, y)] = i;
         g[x].push_back(y);
         g[y].push_back(x);
     }
     E[make_pair(-1, 0)] = 0;
     vector<int> cut;
     // dfs
     function<int(int, int)> dfs = [&](int u, int fa) -> int {
         int res = 1;
         vector<vector<int>> cnt(3);
         for (auto x : g[u]) {
             if (x == fa) continue;
             int t = dfs(x, u);
             if (t == -1) {
                 return -1;
             }
             if (t) cnt[t].push_back(x);
         }
         int s1 = sz(cnt[1]), s2 = sz(cnt[2]);
         if (s2 > 1) res = -1;
         else if (s2 == 1) {
             if (s1 == 0) res = 0, cut.push_back(E[make_pair(min(fa, u), max(fa, u))]);
             else res = -1;
         }
         else {
             // cnt[2] = 0
             if (s1 > 2) res = -1;
             else if (s1 == 2) res = 0, cut.push_back(E[make_pair(min(fa, u), max(fa, u))]);
             else res = s1 + 1;
         }
         return res;
     };
     
     auto res = dfs(0, -1);
     if (res != 0) cout << -1 << endl;
     else {
         cout << sz(cut) - 1 << endl;
         for (auto x : cut) {
             if (x) cout << x << ' ';
         }
         cout << endl;
     }
}