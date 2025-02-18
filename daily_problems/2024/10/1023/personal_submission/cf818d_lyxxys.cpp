#include <bits/stdc++.h>
using namespace std;
void fmax(int &x, int y){
    if (y > x) x = y;
}
void fmin(int &x, int y){
    if (y < x) x = y;
}

void solve(){
    const int N = 1e6+1;
    vector <int> cnt(N);

    int n;
    cin >> n;
    int c1;
    cin >> c1;
    vector <int> A(n+1), Ps(1, 0);
    set <int> st;
    for (int i = 1; i <= n; ++ i){
        cin >> A[i];
        if (A[i] == c1) Ps.push_back(i);
        else st.insert(A[i]);
    }

    int len = Ps.size();
    for (int i = 1; i < len; ++ i){
        for (int j = Ps[i-1]+1; j < Ps[i]; ++ j){
            if (cnt[A[j]] == -1) continue;
            cnt[A[j]] += 1;
        }
        vector <int> deles;
        for (auto &x : st){
            if (cnt[x] < i){
                deles.push_back(x);
            }
        }
        for (auto &x : deles){
            cnt[x] = -1;
            st.erase(x);
        }
        if (st.empty()) break;
    }

    if (st.size()){
        cout << *st.begin() << "\n";
    } else cout << -1 << "\n";
}
