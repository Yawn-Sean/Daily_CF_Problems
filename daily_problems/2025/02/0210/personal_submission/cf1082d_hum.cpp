#include<bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> g, g2;
  int sum{};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > 1) {
      g.push_back(i + 1);
    } else {
      g2.push_back(i + 1);
    }
    sum += a[i];
  }

  if (sum < 2 * n - 2) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << " " << g.size() - 1 + min(2, (int) g2.size()) << endl;
  cout << n - 1 << endl;
  for (int i = 1; i < g.size(); i++) {
    cout << g[i - 1] << " " << g[i] << endl;
  }
  if (!g2.empty()) {
    cout << g.front() << " " << g2.back() << endl;
    g2.pop_back();
  }

  if (!g2.empty()) {
    cout << g.back() << " " << g2.back() << endl;
    g2.pop_back();
  }
  for (int x: g) {
    while (!g2.empty() && a[x - 1] > 2) {
      a[x - 1]--;
      cout << x << " " << g2.back() << endl;
      g2.pop_back();
    }
  }
}
