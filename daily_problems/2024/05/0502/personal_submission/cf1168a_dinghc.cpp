#include <bits/stdc++.h>

using namespace std;

constexpr int MXN = 300000;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto check = [&] (int k) -> bool {
        int mn = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] <= mn) {
                if (mn - a[i] > k) {
                    return true;
                }
            } else {
                if (a[i] + k - m < mn) {
                    mn = a[i];
                }
            }
        }
        return false;
    };
    cout << *ranges::partition_point(views::iota(0, m), check) << "\n";
    return 0;
}

