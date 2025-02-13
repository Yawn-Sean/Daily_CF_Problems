#include <bits/stdc++.h>
using namespace std;

template<class T>

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int target = s.size();
  vector cnt(26, 0);
  for (char c: s) {
    cnt[c - 'a']++;
  }

  int n;
  cin >> n;
  MinCostFlow<int> mcf(n + 28);
  int S{n + 26}, T{n + 27};

  for (int i = 0; i < 26; i++) {
    if (cnt[i]) {
      mcf.addEdge(n + i, T, cnt[i], 0);
    }
  }

  for (int i = 0; i < n; i++) {
    string ss;
    int a;
    cin >> ss >> a;
    mcf.addEdge(S, i, a, i + 1);

    cnt.assign(26, 0);
    for (char c: ss) {
      cnt[c - 'a']++;
    }

    for (int j = 0; j < 26; j++) {
      if (cnt[j]) {
        mcf.addEdge(i, n + j, cnt[j], 0);
      }
    }
  }

  auto res = mcf.flow(S, T);
  cout << (res.first == target ? res.second : -1) << endl;
}
