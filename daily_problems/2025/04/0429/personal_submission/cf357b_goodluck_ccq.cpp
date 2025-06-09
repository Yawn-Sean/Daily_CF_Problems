#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define ll long long

typedef array<int, 3> node;

const int N = 2e5 + 10;

int n, m, p;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> b_feq;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        b_feq[b[i]]++;
    }

    int cnt = 0;
    vector<int> ans;
    for (int q = 0; q < p; q++) {
        vector<int> curr;
        for (int i = q; i < n; i += p) {
            curr.push_back(a[i]);
        }
        // 小于 m 个直接返回
        if (curr.size() < m) {
            continue;
        }

        int diff = b_feq.size(); // 不一样的数量
        int extra = 0; // 非 b 中数据的数量
        int left = 0;
        // 固定滑动窗口 m
        for (int right = 0; right < curr.size(); right++) {
            if (b_feq.find(curr[right]) == b_feq.end()) {
                extra++;
            } else {
                b_feq[curr[right]]--;
                if (b_feq[curr[right]] == 0) {
                    diff--;
                } else if (b_feq[curr[right]] == -1) {
                    diff++;
                }
            }

            while (right - left + 1 > m) {
                if (b_feq.find(curr[left]) == b_feq.end()) {
                    extra--;
                } else {
                    b_feq[curr[left]]++;
                    if (b_feq[curr[left]] == 0) {
                        diff--;
                    } else if (b_feq[curr[left]] == 1) {
                        diff++;
                    }
                }
                left++;
            }

            if (right - left + 1 == m && diff == 0 && extra == 0) {
                cnt++;
                ans.push_back(q + left * p + 1);
            }
        }
        // 将剩余的数据走完，恢复 b_feq
        while (left < curr.size()) {
            if (b_feq.find(curr[left]) == b_feq.end()) {
                extra--;
            } else {
                b_feq[curr[left]]++;
                if (b_feq[curr[left]] == 0) {
                    diff--;
                } else if (b_feq[curr[left]] == 1) {
                    diff++;
                }
            }
            left++;
        }
    }

    cout << cnt << "\n";
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1) {
            cout << ans[i] << "\n";
        } else {
            cout << ans[i] << " ";
        }
    }

    return 0;
}
