#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r;
    cin >> n >> r;

    vector<int> a(n);
    vector<double> ret(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        ret[i] = r;
        if (i == 0) {    
            continue;
        }

        for (int j = 0; j < i; ++j) {
            int dx = abs(a[i] - a[j]);
            if (dx <= 2 * r) {
                double dy = sqrt(4 * r * r - dx * dx);
                ret[i] = max(ret[i], ret[j] + dy);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << fixed << setprecision(10) << ret[i] << " \n"[i == n - 1];
    }

    return 0;
}