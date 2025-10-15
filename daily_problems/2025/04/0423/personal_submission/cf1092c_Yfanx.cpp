#include <bits/stdc++.h>
using namespace std;
#define ll long long;
#define Debug(x) cout << #x << " = " << x << endl;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int m = 2 * n - 2;
  vector<string> arr(m);
  for (int i = 0; i < m; i++) {
    cin >> arr[i];
  }

  vector<vector<int>> lens(n + 1);
  for (int i = 0; i < m; i++) {
    lens[arr[i].length()].push_back(i);
  }

  auto &maxlen = lens[n - 1];
  int a = maxlen[0], b = maxlen[1];

  for (int t = 0; t < 2; t++) {
    swap(a, b);
    string pstr = arr[a] + arr[b].back();

    vector<char> ans(m, '?');
    bool ok = true;

    for (int k = 1; k < n && ok; k++) {
      string p = pstr.substr(0, k);
      string s = pstr.substr(n - k, k);
      bool usedP = false, usedS = false;

      for (int idx : lens[k]) {
        if (!usedP && arr[idx] == p) {
          ans[idx] = 'P';
          usedP = true;
        } else if (!usedS && arr[idx] == s) {
          ans[idx] = 'S';
          usedS = true;
        } else {
          ok = false;
          break;
        }
      }
    }

    if (ok) {
      for (char c : ans)
        cout << c;
      cout << "\n";
      return 0;
    }
  }

  return 0;
}
