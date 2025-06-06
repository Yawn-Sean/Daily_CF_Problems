#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), cnt(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] > 0) {
                ans++;
            }
        }
        cout << ans << endl;

        vector<int> ansList(n + 1), mark(n + 1);
        // 出现的第1次全部填上
        for (int i = 1; i <= n; i++) {
            if (cnt[a[i]] > 0) {
                ansList[i] = a[i];
                mark[a[i]] = 1;
                cnt[a[i]] = 0;
            }
        }

        // 剩下先填写
        for (int i = 1, j = 1; i <= n; i++) {
            if (ansList[i] == 0) {
                while (mark[j]) {
                    j++;
                }
                ansList[i] = j++;
            }
        }

        // 记录每个位置的送礼目标(可能出现相同)   
        vector<int> old(n + 1);
        for (int i = 1; i <= n; i++) {
            old[ansList[i]] = i;
        }

        for (int i = 1; i <= n; i++) {
            if (ansList[i] == i) {
                // 送礼目标一样 和后面的进行交换避免送给自己
                swap(ansList[i], ansList[old[a[i]]]);
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << ansList[i] << " ";
        }
        cout << endl;
        /*
            (2,3)
            (3,2)
        
         */
    }

    return 0;
}
