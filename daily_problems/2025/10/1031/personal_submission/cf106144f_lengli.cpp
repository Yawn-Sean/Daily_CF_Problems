#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<string> outs;

    while (t--) {
        int n;
        cin >> n;
        int c0 = 0, c1 = 0;

        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            if (s.find("xxx") != string::npos) c1 ^= 1;
            else if (s.find("xx") != string::npos) c0 ^= 1;
        }

        if (c0 || c1)
            outs.push_back("Monocarp");
        else
            outs.push_back("Polycarp");
    }

    for (auto &x : outs)
        cout << x << '\n';

    return 0;
}
