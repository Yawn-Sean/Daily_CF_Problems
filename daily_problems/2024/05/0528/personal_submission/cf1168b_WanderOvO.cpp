/*
[x, x + 2k] 一定是奇数长度的，且 >= 3
先找到最小区间，然后扩大版本的就可以直接统计了？
能否钦定左端点，然后找一个最小的 x + 2k，最后直接把右端点统计上？
暴力：枚举 l，枚举 x + 2k，枚举 k，O(n^3)
只有 0 和 1，会不会符合条件的 [x, x + 2k] 的长度不会很长？可以直接暴力？
*/

int T;
string s;
int n;

void solve1() {
    cin >> s;
    n = s.size();
    s = " " + s;
    LL res = 0;
    for (int l = 1; l <= n; l++) {
        for (int x = l + 2; x <= n; x++) {
            bool ok = false;
            for (int k = 1; x - 2 * k >= l; k++) {
                if (s[x] == s[x - k] && s[x - k] == s[x - 2 * k]) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                res += n - x + 1;
                break;
            }
        }
    }
    cout << res << "\n";
}          