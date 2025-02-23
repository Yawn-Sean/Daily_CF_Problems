#include <bits/stdc++.h>
using namespace std;


int main() {
  long long b1;
  int q, l, m;
  cin >> b1 >> q >> l >> m;

  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  set<int> st(a.begin(), a.end());

  if (abs(b1) > l) cout << 0;
  else if (b1 == 0) cout << (st.find(b1) != st.end() ? "0" : "inf");
  else if (q == 1) cout << (st.find(b1) != st.end() ? "0" : "inf");
  else if (q == -1) cout << ((st.find(b1) != st.end() && st.find(-b1) != st.end()) ? "0" : "inf");
  else if (q == 0) {
    if (st.find(0) != st.end()) cout << (st.find(b1) != st.end() ? 0 : 1);
    else cout << "inf";
  } else {
    int cnt = 0;
    while (abs(b1) <= l) {
      if (st.find(b1) == st.end())
        cnt++;
      b1 *= q;
    }
    cout << cnt;
  }
}
