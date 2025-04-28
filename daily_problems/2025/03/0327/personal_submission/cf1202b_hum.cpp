#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();

  vector<int> cnt(10);
  for (int i = 1; i < n; i++)
    cnt[(s[i] - s[i - 1] + 10) % 10]++;

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      vector dis(10, 10);

      dis[i] = 0, dis[j] = 0;
      queue<int> q;
      q.push(i), q.push(j);

      while (!q.empty()) {
        int u = q.front();
        q.pop();

        int nu;
        nu = (u + i) % 10;
        if (dis[nu] == 10) {
          dis[nu] = dis[u] + 1;
          q.push(nu);
        }

        nu = (u + j) % 10;
        if (dis[nu] == 10) {
          dis[nu] = dis[u] + 1;
          q.push(nu);
        }
      }

      int res = 0;
      bool flg = true;
      for (int x = 0; x < 10; x++) {
        if (cnt[x] && dis[x] == 10) flg = false;
        res += cnt[x] * dis[x];
      }

      cout << (flg ? res : -1) << ' ';
    }
    cout << '\n';
  }
}
