#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(3));
    map<pair<int,int>, int> mx;
    int ans2 = 0;
    int idx1 = -1, idx2 = -1;
    bool two = false;

    for (int i = 0; i < n; i++) {
        cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
        sort(vec[i].begin(), vec[i].end());
    }

    for (int i = 0; i < n; i++) {
        int a = vec[i][0], b = vec[i][1], c = vec[i][2];
        int tmp1 = a; // 只选1个
        if (tmp1 > ans2) {
            ans2 = tmp1;
            idx1 = i;
            two = false;
        }

        // 选2个 则能变大只有a被扩大的情况
        if (mx.find({b, c}) != mx.end()) {
            int newa = vec[mx[{b, c}]][0] + a; // (b,c)
            int tmp2 = min({newa, b, c});
            if (tmp2 > ans2) {
                ans2 = tmp2;
                idx1 = i;
                idx2 = mx[{b, c}];
                two = true;
            }
        }
        
        if (mx.find({b, c}) == mx.end() || vec[mx[{b, c}]][0] < a) {
            mx[{b, c}] = i; // 选最大的
        }
    }

    cout << (two ? 2 : 1) << endl;
    if (two) {
        cout << idx1 + 1 << ' ' << idx2 + 1 << endl;
    } else {
        cout << idx1 + 1 << endl;
    }
    // cout << ans2 << endl;
    return 0;
}
