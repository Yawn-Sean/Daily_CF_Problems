#include <bits/stdc++.h>
#include <cstdio>
#define REP(i, j) for (int i = 0; i < j; ++i)
using namespace std;
using ll = int64_t;
string res;
int no() {
  cout << "NO";
  return 0;
}
int main() {
  int n;
  string tmp;
  string pre = "0";
  cin >> n;
  getchar();
  while (n--) {
    cin >> tmp;
    if (tmp.size() < pre.size()) {
      return no();
    } else if (tmp.size() == pre.size()) {
      int st = 0;
      vector<int> quotepos;
      auto quoteaddone = [&]() {
        for (int i = quotepos.size() - 1; i >= 0; --i) {
          if (tmp[quotepos[i]] != '9') {
            tmp[quotepos[i]]++;
            st = 1;
            break;
          } else {
            tmp[quotepos[i]] = '0';
          }
        }
      };
      REP(i, tmp.size()) {
        if (tmp[i] == '?') {
          quotepos.push_back(i);
          if (st == 0) {
            tmp[i] = pre[i];
          } else if (st == 1) {
            tmp[i] = '0';
          }
        } else if (tmp[i] < pre[i]) {
          if (st == 0 && quotepos.size() == 0)
            return no();
          else if (st == 0) {
            quoteaddone();
            if (st == 0) {
              return no();
            }
          }
        } else if (tmp[i] > pre[i]) {
          if (st == 0)
            st = 1;
        }
      }
      if (st == -1)
        return no();
      else if (st == 0) {
        quoteaddone();
        if (st == 0) {
          return no();
        }
      }
    } else {
      for (int i = tmp.size() - 1; i > 0; --i) {
        if (tmp[i] == '?')
          tmp[i] = '0';
      }
      if (tmp[0] == '?')
        tmp[0] = '1';
    }
    res += tmp;
    res += '\n';
    // cout << res << endl;
    pre = tmp;
  }
  cout << "YES\n" << res;
}