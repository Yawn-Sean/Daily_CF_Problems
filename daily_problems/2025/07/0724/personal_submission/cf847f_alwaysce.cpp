#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    /*
    m 个人给 n 个候选人投票，票数前 k 的候选人可以被选中，
    
    若票数相同则最后一票的时间早的人在前，无票者不能被选中。

    已知前 a 个人的投票，问 n 个候选人是下面三种情况的哪种。
    */
    int n, k, m, a;
    cin >> n >> k >> m >> a;


    vector<int> vote(a);
    for (int i = 0; i < a; i++) {
        cin >> vote[i];
    }

    for (int i = 1; i <= n; i++) {
        {
            // 最好情况 后面的所有选票都给自己
            vector<int> cnt(n + 1);
            vector<int> last_vote(n + 1, -1);
            for (int j = 0; j < a; j++) {
                cnt[vote[j]]++;
                last_vote[vote[j]] = j;
            }

            for (int j = a; j < m; j++) {
                cnt[i]++;
                last_vote[i] = j;
            }
            // 完全没有得票
            if (cnt[i] == 0) {
                cout << 3 << ' ';
                continue;
            } else {
                int tot = 1;
                for (int j = 1; j <= n; j++) {
                    if (cnt[j] > cnt[i] || (cnt[j] == cnt[i] && last_vote[j] < last_vote[i])) {
                        tot++;
                    }
                }
                // 无论怎么选都无法选中
                if (tot > k) {
                    cout << 3 << ' ';
                    continue;
                }
            }
        }
        {
            vector<int> cnt(n + 1);
            vector<int> last_vote(n + 1, -1);

            for (int j = 0; j < a; j++) {
                cnt[vote[j]]++;
                last_vote[vote[j]] = j;
            }

            for (int t = a; t < m; t++) {
                int cur_cnt = -1, idx = 0;
                for (int j = 1; j <= n; j++) {
                    if (cnt[j] < cnt[i] || (cnt[j] == cnt[i] && last_vote[j] > last_vote[i])) {
                        if (cnt[j] > cur_cnt) {
                            cur_cnt = cnt[j];
                            idx = j;
                        }
                    }
                }

                cnt[idx]++;
                last_vote[idx] = t;
            }

            if (cnt[i] > 0) {
                int tot = 1;
                for (int j = 1; j <= n; j++) {
                    if (cnt[j] > cnt[i] || (cnt[j] == cnt[i] && last_vote[j] < last_vote[i])) {
                        tot++;
                    }
                }
                // 最坏情况都能被选中
                if (tot <= k) {
                    cout << 1 << ' ';
                    continue;
                }
            }

            cout << 2 << ' ';
        }
    }

    return 0;
}
