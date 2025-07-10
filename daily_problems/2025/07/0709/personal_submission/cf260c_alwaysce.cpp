#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    --x;

    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    i64 mn = *min_element(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        a[i] -= mn;
    }

    int pt = x;
    i64 add = 0;
    while (a[pt] > 0) {
        a[pt]--;
        add++;
        pt = (pt - 1 + n) % n;
    }

    a[pt] = mn * n + add;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}
