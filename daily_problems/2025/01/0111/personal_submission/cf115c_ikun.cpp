#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m;
void solve()
{
    cin >> n >> m;
    vector<vector<char>> a(n+5, vector<char>(m+5));    
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> a[i][j];
    int num = 0;
    auto check = [&](int x, int y)->bool{
        if(x >= 0 && x <= 1 && y >= 2 && y <= 3) return 1;
        if(x >= 2 && x <= 3 && y >= 0 && y <= 1) return 1;
        return 0;
    };
    auto check1 = [&](int x, int y)->bool{
        if(x >= 1 && x <= 2 && (y < 1 || y > 2)) return 1;
        if(y >= 1 && y <= 2 && (x < 1 || x > 2)) return 1;
        return 0;
    };
    for(int i = 1; i <= n; i++) {
        int index = 0, sign;
        for(int j = 1; j <= m; j++) {
            if(a[i][j] != '.') {
                index = j;
                break;
            }
        }
        if(!index) {
            num++;
            continue;
        }
        int l = index - 1, r = index + 1;
        vector<int> tem(m+5, 0);
        tem[index] = a[i][index] - '0' - 1;
        while(l >= 1 || r <= m) {
            if(l >= 1 && l + 1 <= m) {
                if(a[i][l] = '.') tem[l] = (tem[l + 1] + 2) % 4;
                else {
                    tem[l] = a[i][l] - '0' - 1;
                    int pre = tem[l], now = tem[l+1];
                    if(!check(pre, now)) {
                        cout << 0;
                        return;
                    }
                    
                }                
            }
            if(r <= m && r - 1 >= 1) {
                if(a[i][r] == '.') tem[r] = (tem[r-1] + 2) % 4;    
                else {
                    tem[r] = a[i][r] - '0' - 1;
                    if(!check(tem[r], tem[r-1])) {
                        cout << 0;
                        return;
                    }
                }
            }
            l--, r++;
        }
    }
    for(int i = 1; i <= m; i++) {
        int index = 0, sign;
        for(int j = 1; j <= n; j++) {
            if(a[j][i] != '.') {
                index = j;
                break;
            }
        }
        if(!index) {
            num++;
            continue;
        }
        vector<int> tem(n+5, 0);
        int l = index - 1, r = index + 1;
        tem[index] = a[index][i] - '0'-1;
        while(l >= 1 || r <= n) {
            if(l >= 1 && l + 1 <= n) {
                if(a[l][i] = '.') tem[l] = (tem[l + 1] + 2) % 4;
                else {
                    tem[l] = a[l][i] - '0' - 1;
                    int pre = tem[l], now = tem[l+1];
                    if(!check1(pre, now)) {
                        cout << 0;
                        return;
                    }
                }                
            }
            if(r <= n && r - 1 >= 1) {
                if(a[r][i] == '.') tem[r] = (tem[r-1] + 2) % 4;    
                else {
                    tem[r] = a[r][i] - '0' - 1;
                    if(!check1(tem[r], tem[r-1])) {
                        cout  << 0;
                        return;
                    }
                }
            }
            l--, r++;
        }
    }
    ll ret = 1;
    for(int i = 1; i <= num; i++) {
        ret = ret * 2 % 1000003;
    }
    cout << ret;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
//     cin >> _;
    while(_--) solve();
}
