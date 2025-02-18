#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m; string s;
    cin >> m >> s;
    int n = s.length();

    for (int i = 0; i < 26; i++) {
        bool flag = true;
        for (int j = 0, cur = -1; j < n && flag; j++) {
            if (s[j] - 'a' <= i) cur = j;
            else if (j - cur >= m) flag = false;
        }
        if (!flag) continue;
        vector<int> cnt(26);
        for (int j = 0, cur = -1, pos = -1; j < n; j++) {
            int c = s[j] - 'a';
            if (c < i)
                cur = j, cnt[c]++;
            else if (c == i)
                pos = j;
            if (j - cur == m)
                cnt[i]++, cur = pos;
        }
        for (int c = 0; c < 26; c++)
            for (int j = 0; j < cnt[c]; j++)
                cout << (char)('a' + c);
        return 0;
    }
    
    return 0;
}