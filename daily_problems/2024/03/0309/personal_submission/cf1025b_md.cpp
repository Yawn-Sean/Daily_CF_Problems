#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i][0] >> nums[i][1];
    }

    auto checkAndPrint = [&](int x) -> bool {
        for (int i = 0; i < n; ++i) {
            auto divisible = any_of(begin(nums[i]), end(nums[i]), [&](int num) {
                return num % x == 0;
            });
            if (!divisible) {
                return false;
            }
        }
        cout << x << endl;
        return true;
    };

    for (int j = 0; j < 2; ++j) {
        int num = nums[0][j];
        for (int divisor = 2; divisor * divisor <= num; ++divisor) {
            if (num % divisor == 0) {
                while (num % divisor == 0) {
                    num /= divisor;
                }

                if (checkAndPrint(divisor)) {
                    return;
                }
            }  
        }

        if (num > 1) {
            if (checkAndPrint(num)) {
                return;
            }
        }
    }
    cout << -1 << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}