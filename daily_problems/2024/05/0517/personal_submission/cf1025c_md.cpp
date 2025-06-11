// 0517
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;
    const int siz_s = size(s);

    s += s;
    
    int ret = 0;
    int len = 1;
    for (int i = 1; i < size(s); ++i) {
        if (s[i] != s[i-1]) {
            len++;
        } else {
            len = 1;
        }
        ret = max(ret, min(siz_s, len));
    }

    cout << ret << endl;
    return 0;
}