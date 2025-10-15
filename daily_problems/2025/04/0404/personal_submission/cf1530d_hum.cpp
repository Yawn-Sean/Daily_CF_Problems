#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), cnt(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      a[i]--;
      cnt[a[i]]++;
    }
    set<int> st;
    for (int i = 0; i < n; ++i) {
      if (cnt[i] == 0) {
        st.insert(i);
      }
    }
    cout << n - st.size() << endl;
    for (int i = 0; i < n; ++i) {
      if (cnt[a[i]] > 1) {
        int x = -1;
        for (auto y: st) {
          if (y != i) {
            x = y;
            break;
          }
        }
        if (x != -1) {
          cnt[a[i]]--;
          a[i] = x;
          cnt[x]++;
          st.erase(x);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << a[i] + 1 << " ";
    }
  }
}
