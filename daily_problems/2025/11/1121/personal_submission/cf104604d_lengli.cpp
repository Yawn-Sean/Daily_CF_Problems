#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    vector<string> outs;
    outs.reserve(T);

    while (T--) {
        long long a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);

        if (b > 2 * a) {
            outs.push_back("NO");
        } else if (a == b) {
            if (a % 2 == 0) outs.push_back("SI");
            else outs.push_back("NO");
        } else {
            long long diff = b - a; // > 0 here
            if (a % diff != 0) {
                outs.push_back("NO");
            } else {
                bool flg = false;
                for (int i = 2; i <= 4; ++i) {
                    if (b % i == 0) {
                        long long x = a - b / i;
                        if (x > 0 && b % x == 0) {
                            flg = true;
                            break;
                        }
                    }
                }
                outs.push_back(flg ? "SI" : "NO");
            }
        }
    }

    for (auto &s : outs) cout << s << '\n';
    return 0;
}
