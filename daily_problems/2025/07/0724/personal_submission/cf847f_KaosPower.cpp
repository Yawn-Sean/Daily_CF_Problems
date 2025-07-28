#include<bits/stdc++.h>


using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, m, a;
    cin >> n >> k >> m >> a;

    vector<int> nums(a);
    for (auto &v: nums) cin >> v;

    for (int i = 1; i <= n; i ++) {
        {
            vector<int> cnt(n + 1, 0), last_vote(n + 1, -1);

            for (int j = 0; j < a; j ++) {
                cnt[nums[j]] ++;
                last_vote[nums[j]] = j;
            }

            for (int j = a; j < m; j ++) {
                cnt[i] ++;
                last_vote[i] = j;
            }

            if (cnt[i] == 0) {
                cout << 3 << ' ';
                continue;
            }
            else {
                int total = 1;
                for (int j = 1; j <= n; j ++) {
                    if (cnt[j] > cnt[i] || (cnt[j] == cnt[i] && last_vote[j] < last_vote[i])) {
                        total ++;
                    }
                }

                if (total > k) {
                    cout << 3 << ' ';
                    continue;
                }
            }
        }
        {
            vector<int> cnt(n + 1, 0), last_vote(n + 1, -1);

            for (int j = 0; j < a; j ++) {
                cnt[nums[j]] ++;
                last_vote[nums[j]] = j;
            }

            for (int tmstamp = a; tmstamp < m; tmstamp ++) {
                int cur_cnt = -1, idx = 0;
                for (int j = 1; j <= n; j ++) {
                    if (cnt[j] < cnt[i] || (cnt[j] == cnt[i] && last_vote[j] > last_vote[i])) {
                        if (cnt[j] > cur_cnt) {
                            cur_cnt = cnt[j];
                            idx = j;
                        }
                    }
                }
                cnt[idx] ++;
                last_vote[idx] = tmstamp;
            }

            if (cnt[i]) {
                int total = 1;
                for (int j = 1; j <= n; j ++) {
                    if (cnt[j] > cnt[i] || (cnt[j] == cnt[i] && last_vote[j] < last_vote[i])) {
                        total ++;
                    }
                }

                if (total <= k) {
                    cout << 1 << ' ';
                    continue;
                }
            }
        }
        cout << 2 << ' ';
    }

    return 0;
}
