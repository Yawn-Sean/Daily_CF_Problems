#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
using u64 = unsigned long long;
const f64 eps = 1e-12;
const i64 inf_i64 = 4e18;
const int inf_int = 2e9;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}
template <class T> void print(vector <T> &A){
    int n = A.size();
    for (int i = 0; i < n; ++ i){
        if (i) cout << " ";
        cout << A[i];
    }
    cout << "\n";
}
int jgs(f64 x){
    return x < -eps ? -1 : x > eps;
}

void solve(){
    string s, t;
    cin >> s >> t;

    int n = s.size();
    int u = 0, v = 0, pos = n-1;
    for (int i = n-2; i >= 0; -- i){
        if (s[i] < s[pos]) pos = i;
        else if (s[i] > s[pos]) u = i, v = pos;
    }
    swap(s[u], s[v]);
    cout << (s < t ? s : "---") << "\n";
}

int main(){
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
#else
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}
