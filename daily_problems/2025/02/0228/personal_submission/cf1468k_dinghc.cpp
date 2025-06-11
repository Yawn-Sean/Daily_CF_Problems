#include <bits/stdc++.h>

using namespace std;
constexpr int N = 5000;
char s[N + 1];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int n = strlen(s);
        vector<pair<int, int>> f(n + 1);
        f[0] = make_pair(0, 0);
        for (int i = 1, x = 0, y = 0; i <= n; i++) {
            if (s[i - 1] == 'L') {
                x -= 1;
            } else if (s[i - 1] == 'R') {
                x += 1;
            } else if (s[i - 1] == 'D') {
                y -= 1;
            } else {
                y += 1;
            }
            f[i] = make_pair(x, y);
        }
        pair<int, int> ans {0, 0};
        for (auto&[x, y] : f) {
            if (x != 0 || y != 0) {
                int curr_x = 0, curr_y = 0;
                for (int i = 0; i < n; i++) {
                    int nxt_x = curr_x, nxt_y = curr_y;
                    if (s[i] == 'L') {
                        nxt_x -= 1;
                    } else if (s[i] == 'R') {
                        nxt_x += 1;
                    } else if (s[i] == 'D') {
                        nxt_y -= 1;
                    } else {
                        nxt_y += 1;
                    }
                    if (nxt_x != x || nxt_y != y) {
                        curr_x = nxt_x;
                        curr_y = nxt_y;
                    }
                }
                if (curr_x == 0 && curr_y == 0) {
                    ans = make_pair(x, y);
                    break;
                }
            }
        }
        printf("%d %d\n", ans.first, ans.second);
    }
    return 0;
}

