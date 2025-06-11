#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
        
    */
    map<char, pair<int,int>> mp;
    mp['L'] = {-1, 0};
    mp['R'] = {1, 0};
    mp['U'] = {0, 1};
    mp['D'] = {0, -1};

    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;

        int n = s.size();
        int x = 0, y = 0, cx = 0, cy = 0;
        for (auto&c: s) {
            auto&[dx, dy] = mp[c];
            cx += dx;   cy += dy;

            if (cx || cy) {
                int vx = 0, vy = 0;
                // 暴力模拟 n<=5000
                for (auto&nc: s) {
                    auto&[ndx, ndy] = mp[nc];
                    if (vx + ndx != cx || vy + ndy != cy) {
                        vx += ndx;  vy += ndy;
                    }
                }

                if (vx == 0 && vy == 0) {
                    x = cx;
                    y = cy;
                    break;
                }
            }
        }        
        cout << x << ' ' << y << '\n';
    }
    return 0;
}
