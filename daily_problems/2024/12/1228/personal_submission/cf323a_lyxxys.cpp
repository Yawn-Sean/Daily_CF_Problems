#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}

void solve(){
    int n;
    cin >> n;
    if (n%2){
        cout << -1 << "\n";
    } else {
        bool jg = 0;
        for (int r = 0; r < n; ++ r){
            for (int i = 0; i < n; ++ i){
                for (int j = 0; j < n; ++ j){
                    cout << (jg ? 'w' : 'b');
                    if (j%2==1) jg = !jg;
                }
                cout << "\n";
                if (i%2!=((n/2)%2)) jg = !jg;
            }
            if (r < n-1) cout << "\n";
            if ((n/2)%2 == 0) jg = !jg;
        }
    }
}

int main(){
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
#else
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int _ = 1;
    while (_--) solve();
    return 0;
}
