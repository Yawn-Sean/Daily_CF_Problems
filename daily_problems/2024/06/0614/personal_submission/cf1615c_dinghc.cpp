#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int p = 0, q = 0;
        array<int, 4> cnts{};
        for (int i = 0; i < n; i++) {
            if (a[i] == '1') p++;
            if (b[i] == '1') q++;
            int st = ((a[i] - '0') << 1) | (b[i] - '0');
            cnts[st]++;
        }
        if (p != q && p != n - q + 1) {
            cout << "-1\n";
        } else {
            int k = INT_MAX;
            if (p == q) {
                k = min(k, cnts[1] + cnts[2]);
            }
            int m = INT_MAX;
            if (p == n - q + 1) {
                array<int, 4> cnts_bk = cnts;
                if (cnts[3]) {
                    cnts[3]--;
                    //c00=cnts[2]
                    //c11=cnts[1]
                    //c10=cnts[0]
                    //c01=cnts[3]
                    m = min(m, cnts[0] + cnts[3] + 1);
                }
                cnts = cnts_bk;
                if (cnts[2]) {
                    cnts[2]--;
                    //c00=cnts[2]
                    //c11=cnts[1]
                    //c10=cnts[0]
                    //c01=cnts[3]
                    m = min(m, cnts[0] + cnts[3] + 1);
                }
            }
            cout << min(k, m) << "\n";
        }
    }
    return 0;
}

