#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    set<int> odds, evens;
    for (int i = 1; i <= 2 * n; i++) {
      if (i % 2 == 0) {
        evens.insert(i);
      } else {
        odds.insert(i);
      }
    }

    int numO = 0, numE = 0;
    for (auto& ch : s) {
      if (ch == 'E') {
        numE++;
      } else {
        numO++;
      }
    }

    if (((n - numO) / 2) * 2 < numE) {
      cout << "NO" << endl;
      continue;
    }

    bool flag = true;
    vector<pair<int, int>> ans;
    for (auto& ch : s) {
      if (ch == 'E') {
        if (flag) {
          int x = *odds.begin();
          odds.erase(x);
          int y = *odds.begin();
          odds.erase(y);
          ans.emplace_back(x, y);
        } else {
          int x = *evens.begin();
          evens.erase(x);
          int y = *evens.begin();
          evens.erase(y);
          ans.emplace_back(x, y);
        }
        flag = !flag;
      } else {
        int x = *evens.begin();
        evens.erase(x);
        int y = *odds.begin();
        odds.erase(y);
        ans.emplace_back(x, y);
      }
    }

    cout << "YES" << endl;
    for (auto& p : ans) {
      cout << p.first << " " << p.second << "\n";
    }
  }

  return 0;
}
