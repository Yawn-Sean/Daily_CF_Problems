#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> a(6);
  for (int i = 0; i < 6; i++) {
    cin >> a[i];
  }
  vector<string> as{"S", "M", "L", "XL", "XXL", "XXXL"};
  vector<string> cmp{"S,M", "M,L", "L,XL", "XL,XXL", "XXL,XXXL"};

  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < 6; j++) {
      if (s[i] == as[j]) {
        a[j]--;
      }
    }
  }
  for (int i = 0; i < 6; i++) {
    if (a[i] < 0) {
      cout << "NO\n";
      return 0;
    }
  }
  for (int t = 0; t < 5; t++) {
    for (int i = 0; i < n; i++) {
      if (s[i] == cmp[t]) {
        if (a[t] > 0) {
          a[t]--, s[i] = as[t];
        } else if (a[t + 1] > 0) {
          a[t + 1]--, s[i] = as[t + 1];
        } else {
          cout << "NO\n";
          return 0;
        }
      }
    }
  }


  cout << "YES\n";
  for (int i = 0; i < n; i++)
    cout << s[i] << '\n';
}
