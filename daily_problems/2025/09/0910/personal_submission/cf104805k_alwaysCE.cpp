#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    i64 n, l;
    cin >> n >> l;
    l += 1;
    vector<int> nums(16);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      nums[x]++;
    }

    set<i64> seen = {1};
    auto dfs = [&](auto &&dfs, i64 mul) -> void {
      for (int i = 2; i <= 15; i++) {
        if (nums[i] > 0) {
          i64 new_mul = mul * (i + 1);
          if (new_mul <= l && seen.find(new_mul) == seen.end()) {
            seen.insert(new_mul);
            dfs(dfs, new_mul);
          }
        }
      }
    };

    dfs(dfs, 1ll);
    cout << seen.size() - 1 << "\n";
    return 0;
}
