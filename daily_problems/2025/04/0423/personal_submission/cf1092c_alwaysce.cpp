#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<vector<int>> lens(n);
    vector<string> strs(2 * n - 2);

    for (int i = 0; i < 2 * n - 2; i++) {
        cin >> strs[i];
        lens[strs[i].size()].push_back(i);
    }

    // 两个n-1的谁是前缀 谁是后缀呢?
    int pre = lens[n - 1][0], suf = lens[n - 1][1];
    vector<char> ans(2 * n - 2, ' ');
    bool ok = true;
    ans[pre] = 'P';
    ans[suf] = 'S';
    for (int i = 1; i < n - 1; i++) {
        int j1 = lens[i][0], j2 = lens[i][1];
        if (strs[pre].substr(0, i) == strs[j1] && strs[suf].substr(n - i - 1) == strs[j2]) {
            ans[j1] = 'P';
            ans[j2] = 'S';
        } else if (strs[pre].substr(0, i) == strs[j2] && strs[suf].substr(n - i - 1) == strs[j1]) {
            ans[j1] = 'S';
            ans[j2] = 'P';
        } else {
            ok = false;
            break;
        }
    }

    if (!ok) {
        swap(pre, suf);
        ans = vector<char>(2 * n - 2, ' ');
        ans[pre] = 'P';
        ans[suf] = 'S';
        for (int i = 1; i < n - 1; i++) {
            int j1 = lens[i][0], j2 = lens[i][1];   
            if (strs[pre].substr(0, i) == strs[j1] && strs[suf].substr(n - i - 1) == strs[j2]) {
                ans[j1] = 'P';
                ans[j2] = 'S';
            } else if (strs[pre].substr(0, i) == strs[j2] && strs[suf].substr(n - i - 1) == strs[j1]) {
                ans[j1] = 'S';
                ans[j2] = 'P';
            }
        }
    }
    
    for (int i = 0; i < 2 * n - 2; i++) {
        cout << ans[i];
    }
    return 0;
}
