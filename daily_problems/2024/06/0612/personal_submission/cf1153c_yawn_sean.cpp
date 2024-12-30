#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin >> n >> s;
    
    int cnt = 0;
    for (auto &c: s)
        cnt += (c == '(');
    
    int left = n / 2 - cnt, cur = 0;

    for (int i = 0; i < n; i ++) {
        if (s[i] == '(')
            cur ++;
        else if (s[i] == ')')
            cur --;
        else if (left) 
            s[i] = '(', cur ++, left --;
        else
            s[i] = ')', cur --;
        if (cur <= 0 && i != n - 1) {
            cout << ":(\n";
            return 0;
        }
    }
    cout << (cur == 0 ? s : ":(") << '\n';

    return 0;
}