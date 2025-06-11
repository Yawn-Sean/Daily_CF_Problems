#include <bits/stdc++.h>
using namespace std;

void work() {
    string str; cin >> str;
    str += str;

    int len = 1;
    int cur_len = 1;

    for (int pos = 1; pos < str.size(); pos ++) {
        if (str[pos] != str[pos - 1]) {
            cur_len ++;
            len = max(len, cur_len);
        } else {
            cur_len = 1;
        }
    }
    len = min(len, static_cast<int>(str.size() / 2));

    cout << len << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T {1};
    // cin >> T;

    while (T--) {
        work();
    }
}