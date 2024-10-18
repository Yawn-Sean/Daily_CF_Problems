#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 100050, mod = 1e9 + 7;
const double inf = 1e9;
double eps = 1e-10;

int mos(int a, int m){
    return (a%m + m)%m;
}
void solve(){
    int d, m;
    vector <vector<int>> f(50, vector<int>(50));
    vector <ll> cnt(50);
    cin >> d >> m;

    {
        int sum = 0, p = 0;
        while (sum+(1<<p) <= d){
            sum += 1<<p;
            cnt[p] = 1<<p;
            ++ p;
        }
        cnt[p] = d - sum;
    }
    /*
        动态维护所有的两个数之间的积，三个数之间的积，四个数之间的积, ····
    */
    int res = 0;
    vector <int> Sum(50);
    for (int i = 1; i <= 30; ++ i){
        for (int j = 0; j <= 30-i; ++ j){
            if (i==1) f[i][j] = cnt[j];
            else {
                f[i][j] = mos(1ll*cnt[j]*Sum[j+1]%m, m);
            }
            res = mos(res+f[i][j], m);
        }
        for (int j = 29; j >= 0; -- j){
            Sum[j] = mos(Sum[j+1]+f[i][j], m);
        }
    }

    cout << res << "\n";
}
