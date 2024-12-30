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
    int n, l, tar1, tar2;
    cin >> n >> l >> tar1 >> tar2;
    vector <int> A(n);
    for (auto &x : A){
        cin >> x;
    }

    unordered_set <int> st;
    bool jg1 = 0, jg2 = 0;
    for (auto &x : A){
        if (st.count(x-tar1)) jg1 = 1;
        if (st.count(x-tar2)) jg2 = 1;
        st.insert(x);
    }

    if (jg1 && jg2){
        cout << 0 << "\n";
    } else if (jg1 || jg2){
        cout << 1 << "\n";
        int ans = jg1 ? tar2 : tar1;
        cout << ans << "\n";
    } else {

        vector <int> ans;
        for (auto &x : A){
            if (x > tar1){
                // cout << x-tar1+tar2 << "\n";
                if (st.count(x-tar1+tar2) || st.count(x-tar1-tar2)){
                    ans.push_back(x-tar1);
                    break;
                }
            }
            if (x+tar1 <= l){
                if (st.count(x+tar1+tar2) || st.count(x+tar1-tar2)){
                    ans.push_back(x+tar1);
                    break;
                }
            }
        }
        if (ans.empty()) ans = {tar1, tar2};

        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); ++ i){
            if (i) cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }
}
