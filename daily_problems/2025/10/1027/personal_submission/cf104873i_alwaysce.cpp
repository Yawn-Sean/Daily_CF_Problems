#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  auto ask = [&](vector<int>& idxs) {
    cout << "? " << idxs.size();
    for (auto i : idxs) {
      cout << " " << i;
    }
    cout << endl;

    int tot;
    cin >> tot;
    vector<int> res(tot);
    for (auto& x : res) {
      cin >> x;
    }
    return res;
  };

  auto answer = [&](vector<vector<int>>& res) {
    cout << "! ";
    for (auto x : res) {
      cout << x.size() << ' ';
      for (auto y : x) {
        cout << y << ' ';
      }
    }
    cout << endl;
  };

  vector<vector<int>> ans(n);  
  if (n == 1) {
    vector<int> idxs = {1};
    vector<int> res = ask(idxs);
    ans[0] = res;
    answer(ans);
    return 0;
  } else {
    for (int i = 1; i <= n; i += n / 2) {
      vector<int> idxs;

      for (int j = i; j < n / 2 + i && j <= n; j++) {
        idxs.push_back(j);
        idxs.push_back(j);
      }

      vector<int> tmp = ask(idxs);
    
      int k = idxs.size() / 2;
      int pt = 0;
      for (int j = i; j < i + k; j++) {
        int npt = pt + 1;
        while (tmp[npt] != tmp[pt]) {
          npt++;
        }

        for (int k = pt; k < npt; k++) {
          ans[j - 1].emplace_back(tmp[k]);
        }
        pt = npt + (npt - pt);
      }
    }
    // cout << "Exiting normally" << endl;
    answer(ans);
  }
  return 0;
}
