#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  string tmp{s};
  int last = 1;
  for (int i = s.length() - 1; i >= 0; --i) {
    tmp[i] = tmp[i] + last;
    if (tmp[i] > 'z') {
      tmp[i] = 'a';
      last = 1;
    } else {
      last = 0;
    }
  }
  if (tmp < t) {
    cout << tmp << endl;
  } else {
    cout << "No such string" << endl;
  }
}
