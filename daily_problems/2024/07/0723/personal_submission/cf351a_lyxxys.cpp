#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 4e5+10, mod = 1e9 + 7, inf = 1e9;

void solve(){
    /*
        用上取整时非零数字的个数来枚举，设有cnt个整数
        下界是max(0,cnt-n), 上界是 min(n, cnt)
        设下取整小数和是x，上取整小数和是y, 有i个整数
        det = min{|x - (1*n-y-i)|} = {|x+y - n + i|}
    */
    int n;
    cin >> n;
    double det = 1e9, tot = 0;
    int cnt = 0;
    for (int i = 1; i <= 2*n; ++ i){
        double x;
        cin >> x;
        int y = x;
        tot += x-y;
        if (x==y) ++ cnt;
    }

    for (int i = max(cnt-n, 0); i <= min(n, cnt); ++ i){
        det = min(det, fabs(tot-n+i));
    }
    cout << det << "\n";
}
