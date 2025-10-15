#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    /*
        hints: 1-5 / colors
        每次提示你会指出数值=1-5/颜色=1-5的卡片有哪些
        确认顺序

        一张卡片的两个属性被知道了就会完全确认下来
    */
    int n;
    cin >> n;
    map<char,int> mp;
    mp['R'] = 0;
    mp['G'] = 1;
    mp['B'] = 2;
    mp['Y'] = 3;
    mp['W'] = 4;

    set<int> nums;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        nums.insert(mp[s[0]] * 10 + (s[1] - '1'));
    }
    
    n = nums.size();
    int ans = 1e9;
    for (int m1 = 0; m1 < 32; m1++) {
        for (int m2 = 0; m2 < 32; m2++) {
            set<int> vis;
            for (auto&x: nums) {
                int cur = 0;
                if ((m1 >> (x / 10)) & 1) {
                    cur += (x / 10 + 1) * 10;
                }
                if ((m2 >> (x % 10)) & 1) {
                    cur += (x % 10 + 1);
                }
                vis.insert(cur);
            }

            if (vis.size() == n) {
                ans = min(ans, __builtin_popcount(m1) + __builtin_popcount(m2));
            }
        }
    }

    cout << ans << endl;

    return 0;
}
