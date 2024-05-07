#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 200050, p = 998244353, eps = 1e-8;
struct Node {
    ll temp, x;
    bool operator < (const Node &tmp){
        return temp < tmp.temp;
    }
}a[N];
ll n, m;

void solve(){
    cin >> n >> m;
    ll tot = 0; // 此处要定义为整数，避免出现精度问题
    double sum = 0;
    for (int i = 1; i <= n; ++ i){
        cin >> a[i].x;
        sum += a[i].x;
    }
    for (int i = 1; i <= n; ++ i){
        cin >> a[i].temp;
        a[i].temp -= m;
        tot += a[i].temp*a[i].x;
    }
    sort(a+1, a+1+n);
    if (tot < 0){ //remove cold
        for (int i = 1; i <= n; ++ i){
            if (tot - a[i].temp*a[i].x >= 0){
                sum -= 1.0*tot/a[i].temp, tot = 0;
                break;
            }
            tot -= a[i].temp*a[i].x, sum -= a[i].x;
        }
    }
    if (tot > 0){  //remove hot
        for (int i = n; i >= 1; -- i){
            if (tot - a[i].temp*a[i].x <= 0){
                sum -= 1.0*tot/a[i].temp, tot = 0;
                break;
            }
            tot -= a[i].temp*a[i].x, sum -= a[i].x; 
        }
    }
    cout << fixed << setprecision(10) << sum << "\n";
}
