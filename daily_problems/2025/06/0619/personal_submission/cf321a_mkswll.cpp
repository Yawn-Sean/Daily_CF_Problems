#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int n = s.size();
    vector<pair<int, int>> pos(n);
    int x = 0, y = 0;
    for(int i = 0; i < n; ++i) {
        pos[i] = {x, y};
        if(s[i] == 'U') ++y;
        else if(s[i] == 'D') --y;
        else if(s[i] == 'L') --x;
        else ++x;
    }
    for(int i = 0; i < n; ++i) {
        int tx = a - pos[i].first, ty = b - pos[i].second;
        if(!x && !y) {
            if(!tx && !ty) {
                cout << "Yes\n";
                return 0;
            }
            continue;
        }
        if(!x) {
            if(!tx && ty % y == 0 && ty / y >= 0) {
                cout << "Yes\n";
                return 0;
            }
            continue;
        }
        if(!y) {
            if(!ty && tx % x == 0 && tx / x >= 0) {
                cout << "Yes\n";
                return 0;
            }
            continue;
        }
        if(tx % x == 0 && ty % y == 0 && tx / x == ty / y && tx / x >= 0) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}
