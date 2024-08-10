#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

bool query(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    string ans;
    cin >> ans;
    return ans == "YES";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int x, y;

    x = 1, y = 1;
    vector<char> tmp1;

    for (int i = 0; i < n - 1; i ++)
        if (query(x, y + 1, n, n))
            y ++, tmp1.push_back('R');
        else
            x ++, tmp1.push_back('D');

    x = n, y = n;
    vector<char> tmp2;

    for (int i = 0; i < n - 1; i ++)
        if (query(1, 1, x - 1, y))
            x --, tmp2.push_back('D');
        else
            y --, tmp2.push_back('R');
    
    reverse(tmp2.begin(), tmp2.end());
    cout << "! ";
    for (auto &c: tmp1) cout << c;
    for (auto &c: tmp2) cout << c;

    return 0;
}