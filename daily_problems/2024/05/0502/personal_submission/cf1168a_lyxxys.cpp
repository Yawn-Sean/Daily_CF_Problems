#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using Pli = pair<ll, int>;
const int N = 300050, p = 998244353;
vector <int> a(N);
int n, m;

bool check(int mid){
    vector <int> b = a;
    for (int i = 1; i <= n; ++ i){
        if (b[i] < b[i-1]){
            if (-b[i-1]+b[i] < -mid) return false;
            b[i] = b[i-1];
        }
        else
            if (m-b[i]+b[i-1] <= mid) // 根据贪心，如果可以变得更小的话，则变得更小
                b[i] = b[i-1];
    }
    return true;
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    int l = 0, r = m;
    while (l < r){
        int mid = l+r >> 1;
        if (check(mid)) r = mid;
        else l = mid+1;
    }

    cout << l << "\n";
}
