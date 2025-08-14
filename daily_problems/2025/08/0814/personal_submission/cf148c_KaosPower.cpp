#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    if (a && a == n - 1) cout << -1;
    else if (n == 1) cout << 1;
    else {
        if (b) b --, cout << "1 2 ";
        else cout << "2 1 ";

        int cur = 3, val = 2;
        for (int i = 2; i < n; i ++) {
            if (b) b --, val = cur + 1, cur += val;
            else if (a) a --, val = max(val + 1, 3);
            else val = 1;
            cout << val << ' ';
        }

    }

    return 0;
}
