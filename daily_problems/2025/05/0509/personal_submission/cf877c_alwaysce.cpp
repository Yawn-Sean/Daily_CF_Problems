#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> ans;
    int odd = n / 2 + (n % 2);
    int even = n / 2;
    for (int i = 1; i <= even; i++) {
        ans.push_back(2 * i);
    }
    for (int i = 1; i <= odd; i++) {
        ans.push_back(2 * i - 1);
    }
    for (int i = 1; i <= even; i++) {
        ans.push_back(2 * i);
    }
    cout << ans.size() << '\n';
    for (auto&x: ans) { cout << x << ' '; }
    cout << '\n';
    return 0;
}
