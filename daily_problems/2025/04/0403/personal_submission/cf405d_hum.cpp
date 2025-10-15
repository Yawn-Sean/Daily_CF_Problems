#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s = 1e6;
  vector<int> vis(s + 1);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vis[x] = 1;
  }

  cout << n << '\n';

  for (int i = 1; i <= s; i++) {
    if (!vis[i] && vis[s + 1 - i]) {
      n--;
      vis[i] = 1;
      cout << i << ' ';
    }
  }

  for (int i = 1; i <= s; i++) {
    if (!vis[i] && !vis[s + 1 - i] && n) {
      n -= 2;
      vis[i] = 1;
      vis[s + 1 - i] = 1;
      cout << i << ' ';
      cout << s + 1 - i << ' ';
    }
  }
}
