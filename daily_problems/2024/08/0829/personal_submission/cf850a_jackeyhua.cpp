#include <iostream>
#include <vector>
#include <array>

using namespace std;
using ll = long long;

bool judge(array<int, 5>&& x, array<int, 5>&& y) {
    ll ans = 0;
    for (int i = 0; i < 5; ++i) {
        ans += 1LL * x[i] * y[i];
    }
    return ans <= 0;
}

array<int, 5> vec(array<int, 5>& src, array<int, 5>& dest) {
    array<int, 5> ans;
    for (int i = 0; i < 5; ++i) ans[i] = dest[i] - src[i];
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<array<int, 5>> vc(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> vc[i][j];
        }
    }
    if (n >= 34) {
        cout << 0 << "\n";
        return;
    }
    int cnt = 0;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        bool flag = true;
        for (int j = 0; j < n; ++j) {
            if (!flag) break;
            for (int k = j + 1; k < n; ++k) {
                if (j == i || k == i) continue;
                if (!judge(move(vec(vc[j], vc[i])), move(vec(vc[k], vc[i])))) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            ++cnt;
            ans.push_back(i + 1);
        }
    }
    cout << cnt << "\n";
    for (auto& i : ans) cout << i << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
