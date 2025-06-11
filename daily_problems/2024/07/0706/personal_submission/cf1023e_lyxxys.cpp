#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 1e5+5, inf = (1u<<31)-1, mod = 998244353;

void solve(){
    int n;
    cin >> n;
    auto ops = [&](int x1, int y1, int x2, int y2)->bool{
        cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        string s;
        cin >> s;
        return s == "YES";
    };
    string ans1, ans2;
    int x = 1, y = 1;
    for (int i = 0; i < n-1; ++ i){
        if (ops(x+1, y, n, n)) ans1 += 'D', ++ x;
        else ans1 += 'R', ++ y;
    }
    x = n, y = n;
    for (int i = 0; i < n-1; ++ i){
        if (ops(1,1,x,y-1)) ans2 += 'R', -- y;
        else ans2 += 'D', -- x;
    }
    reverse(ans2.begin(), ans2.end());
    cout << "! " << (ans1+ans2);
}
