#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define int long long
#define itn int

const int N = 1010;

int n, m;
char grid[N][N];
int component_id[N][N];
int component_size[N * N];
int component_count;
char result[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool read_input() {
  if (!(cin >> n >> m))
    return false;
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }
  return true;
}

void dfs(int x, int y) {
  component_size[component_count]++;
  component_id[x][y] = component_count;

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
      continue;
    if (component_id[nx][ny] != -1 || grid[nx][ny] != '.')
      continue;
    dfs(nx, ny);
  }
}

void solve() {
  component_count = 0;
  memset(component_id, -1, sizeof(component_id));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (component_id[i][j] == -1 && grid[i][j] == '.') {
        component_size[component_count] = 0;
        dfs(i, j);
        component_count++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '.') {
        result[i][j] = '.';
        continue;
      }

      vector<int> neighbors;
      for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x < 0 || x >= n || y < 0 || y >= m)
          continue;
        if (grid[x][y] != '.')
          continue;
        neighbors.push_back(component_id[x][y]);
      }

      sort(neighbors.begin(), neighbors.end());
      neighbors.erase(unique(neighbors.begin(), neighbors.end()),
                      neighbors.end());

      int sum = 1;
      for (int id : neighbors) {
        if (id != -1) {
          sum += component_size[id];
        }
      }
      result[i][j] = '0' + (sum % 10);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << result[i] << '\n';
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tt;
  // cin >> tt;
  tt = 1;
  while (tt--) {
    if (!read_input())
      break;
    solve();
  }
  return 0;
}