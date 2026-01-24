#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> lens{1}, cnts{0};
    int cur_len = 1, cur_cnt = 0;
    while (lens.size() <= k) {
        if (1LL * cur_len * k + 1 > n) {
            cur_cnt = n / cur_len * cur_cnt;
            int q = n % cur_len;
            while (q) {
                while (lens.back() > q) {
                    lens.pop_back();
                    cnts.pop_back();
                }
                cur_cnt += q / lens.back() * cnts.back();
                q %= lens.back();
            }
            cur_len = n;
            break;
        }
        cur_len = cur_len * k + 1;
        cur_cnt = cur_cnt * k + 1;
        lens.push_back(cur_len);
        cnts.push_back(cur_cnt);
    }
    printf("%d\n", cur_cnt + n - cur_len);
    return 0;
}

