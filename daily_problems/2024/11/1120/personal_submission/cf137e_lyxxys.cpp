#include <bits/stdc++.h>
using namespace std;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}
template <class T> struct fenwick {
    vector <T> info;
    int n;
    fenwick(){}
    fenwick(int n): info(n+1, 1000000000), n(n){}
    void add(int x, T c){
        while (x <= n) fmin(info[x], c), x += x&-x;
    }
    T query(int x) {
        T res = 1000000000;
        while (x) fmin(res, info[x]), x -= x & -x;
        return res;
    }
};
void solve(){
    using Yint = fenwick<int>;

    set <char> st = {'a','e','i','o','u','A','E','I', 'O', 'U'};
    string s;
    cin >> s;
    int n = s.size();
    vector <int> Pr(n+1);
    for (int i = 0; i < n; ++ i){
        Pr[i+1] = Pr[i] + (st.find(s[i]) != st.end());
    }

    Yint Y(7*n);
    const int inf = 1e9, det = 3*n;
    Y.add(2*1 - 3*Pr[1-1] + det, 1);

    int Max = 0, ans = 0;
    for (int i = 1; i <= n; ++ i){
        int j1 = 2*i + 2 - 3*Pr[i];

        int y = Y.query(j1+det);
        if (y != inf){
            if (i-y+1 > Max){
                Max = i-y+1;
                ans = 1;
            } else if (i-y+1 == Max) ans += 1;
        }

        int j2 = 2*i - 3*Pr[i-1];
        Y.add(j2+det, i);
    }

    if (Max == 0){
        cout << "No solution\n";
    } else {
        cout << Max << " " << ans << "\n";
    }
}
