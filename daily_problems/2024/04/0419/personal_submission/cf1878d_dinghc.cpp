#include <bits/stdc++.h>

using namespace std;

constexpr int MXN = 200000;
char s[MXN+1];
int ls[MXN];
int rs[MXN];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        scanf("%s", s);
        for (int i = 0; i < k; i++) {
            scanf("%d", &ls[i]);
            ls[i]--;
        }
        for (int i = 0; i < k; i++) {
            scanf("%d", &rs[i]);
            rs[i]--;
        }
        int q;
        scanf("%d", &q);
        vector<map<int, int>> queries(k);
        for (int i = 0, x; i < q; i++) {
            scanf("%d", &x);
            x--;
            int j = lower_bound(rs, rs + k, x) - rs;
            int mid_l = (ls[j] + rs[j]) / 2;
            int mid_r = (ls[j] + rs[j] + 1) / 2;
            queries[j][min(abs(x - mid_l), abs(x - mid_r))]++;
        }
        for (int i = 0; i < k; i++) {
            if (queries[i].empty()) continue;
            int mid_l = (ls[i] + rs[i]) / 2;
            int mid_r = (ls[i] + rs[i] + 1) / 2;
            auto& mp = queries[i];
            auto it = mp.rbegin();
            int pre_x = it->first;
            int pre_cnt = it->second;
            int tot = pre_cnt;
            for (it++; it != mp.rend(); it++) {
                auto [curr_x, curr_cnt] = *it;
                if (tot & 1) {
                    for (int j = mid_l - pre_x; j < mid_l - curr_x; j++) {
                        swap(s[j], s[mid_r + mid_l - j]);
                    }
                }
                tot += curr_cnt;
                pre_x = curr_x;
            }
            if (tot & 1) {
                for (int j = mid_l - pre_x; j <= mid_l; j++) {
                    swap(s[j], s[mid_r + mid_l - j]);
                }
            }
        }
        printf("%s\n", s);
    }
    return 0;
}

