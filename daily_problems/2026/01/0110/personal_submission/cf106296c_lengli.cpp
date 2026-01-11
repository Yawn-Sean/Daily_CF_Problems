#include <bits/stdc++.h>
using namespace std;

bool check(int x) {
    cout << 2 << " " << 2 * x - 1 << endl;
    cout.flush();
    long long v1;
    cin >> v1;

    cout << 1 << " " << 2 * x << endl;
    cout.flush();
    long long v2;
    cin >> v2;

    return v1 == v2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        long long v = (n + 1) / 2;

        long long l = 1, r = v - 1;

        while (l <= r) {
            long long mid = (l + r) / 2;

            if (check(mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        cout << 3 << " " << 2 * r - 1 << " " << 2 * r + 1 << endl;
        cout.flush();
    }

    return 0;
}
