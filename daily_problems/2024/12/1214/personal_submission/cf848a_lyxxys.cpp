#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}

void solve(){
    using ary2 = array<int,2>;
    vector <int> ws(1001);
    for (int i = 2; i <= 1000; ++ i){
        ws[i] = i*(i-1)/2;
    }

    int k, j = -1;
    cin >> k;
    if (!k){
        cout << 'a' << "\n";
        return;
    }
    vector <ary2> ans;
    for (int i = 1000; i >= 2; -- i){
        while (k >= ws[i]){
            ans.push_back({i, ++ j});
            k -= ws[i];
        }
        if (k == 0) break;
    }
    assert(j <= 26);

    for (auto &it : ans){
        int cnt = it[0];
        char c = char(it[1]+'a');
        while (cnt--) cout << c;
    }
    cout << "\n";
}
