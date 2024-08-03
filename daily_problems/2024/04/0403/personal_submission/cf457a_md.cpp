#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    int len = max(size(a), size(b)) + 1;

    auto upgrade = [len](string& s) {
        reverse(begin(s), end(s));
        s.resize(len + 1, '0');
        for (int i = len - 1; i > 0; --i) {
            while (i < len && s[i] == '1' && s[i-1] == '1') {
                s[i] = '0';
                s[i - 1] = '0';
                s[i + 1] = '1';
                i += 2;
            }
        }

        reverse(begin(s), end(s));
    };

    upgrade(a);
    upgrade(b);

    cout << ((a == b) ? '=' : (a < b) ? '<' : '>');
    cout << '\n';
    return 0;
}