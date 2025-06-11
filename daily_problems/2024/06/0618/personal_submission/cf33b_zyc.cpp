#include <bits/stdc++.h>

#define endl "\n"
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define complete_unique(a) a.erase(unique(a.begin(), a.end()), a.end())

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

void solve() {
    string a, b;
    cin >> a >> b;
    if(a.size() != b.size()) {
      cout << -1 << endl;
      return ;
    }

    vector<vector<int>> g(26, vector<int>(26, INF));
    for(int i = 0; i < 26; i ++) g[i][i] = 0;
    int m;
    cin >> m;
    while(m -- ) {
      char c, d; int w;
      cin >> c >> d >> w;
      g[c - 'a'][d - 'a'] = min(g[c - 'a'][d - 'a'], w);
    }

    for(int k = 0; k < 26; k ++) {
      for(int i = 0; i < 26; i ++) {
        for(int j = 0; j < 26; j ++) {
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }
    vector<vector<int>> res(26, vector<int>(26, INF)), charts(26, vector<int>(26, -1));
    for(int k = 0; k < 26; k ++) {
      for(int i = 0; i < 26; i ++) {
        for(int j = 0; j < 26; j ++) {
          if(res[i][j] > g[i][k] + g[j][k]) {
            res[i][j] = g[i][k] + g[j][k]; charts[i][j] = k;
          }
        }
      }
    }
    int n = a.size();
    int ans = 0;
    string s = "";
    for(int i = 0; i < n; i ++) {
      int x = a[i] - 'a', y = b[i] - 'a';
      if(charts[x][y] == -1) {
        cout << -1 << endl; return ;
      }
      ans += res[x][y]; s += ('a' + charts[x][y]);
    }
    cout << ans << "\n" << s << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
//  cout.tie(nullptr);
  int T = 1;
  // cin >> T;
  while (T--) solve();

  return 0;
}
