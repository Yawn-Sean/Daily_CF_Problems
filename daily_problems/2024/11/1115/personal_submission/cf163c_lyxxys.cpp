#include <bits/stdc++.h>
using namespace std;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n, v1, v2;
    long long l;
    cin >> n >> l >> v1 >> v2;
    long long len = l * v2;
    l *= v1+v2;

    map <long long, int> diff;
    for (int i = 0; i < n; ++ i){
        long long x;
        cin >> x;
        x *= v1+v2;
        if (x+len <= 2*l){
            diff[x] += 1;
            diff[x+len] -= 1;
        } else {
            diff[x] += 1, diff[0] += 1;
            diff[2*l] -= 1, diff[x+len - 2*l] -= 1;
        }
    }
    diff[2*l] += 0;

    vector <long long> ans(n+1, 0);
    long long lst = 0, cur = 0;
    for (auto &it : diff){
        ans[cur] += it.first - lst;
        cur += it.second;
        lst = it.first;
    }

    cout << fixed << setprecision(15);
    for (auto &x : ans){
        cout << (long double)1.0 * x / (2*l) << "\n";
    }
}
