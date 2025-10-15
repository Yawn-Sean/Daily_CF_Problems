#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> cnt1(m), cnt2(m);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ++cnt1[x];
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ++cnt2[x];
    }

    vector<int> ans, stk;
    for (int i = 0; i < m; i++) {
        while (cnt1[i]--) {
            stk.push_back(i);
        }
        // 神秘贪心
        while (cnt2[m - 1 - i] && !stk.empty()) {
            cnt2[m - 1 - i]--;
            int v = stk.back();
            stk.pop_back();
            ans.push_back(v + m - 1 - i);
        }
    }

    // 剩下超过了m的部分 大的match大的 
    for (int i = m - 1; i >= 0; i--) {
        while (cnt2[i]--) {
            int v = stk.back();
            stk.pop_back();
            ans.push_back(v + i - m);
        }
    }

    sort(ans.rbegin(), ans.rend());
    for (auto& v: ans) {
        cout << v << ' ';
    }
    cout << endl;
    return 0;
}
