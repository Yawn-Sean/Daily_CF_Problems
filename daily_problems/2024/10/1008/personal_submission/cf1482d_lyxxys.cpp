#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353, inf = 1e9;

void solve(){
    using sit = set<int>::iterator;
    int n;
    cin >> n;
    vector <int> A(n+1);
    for (int i = 1; i <= n; ++ i) cin >> A[i];
    set <int> st;
    for (int i = 1; i <= n; ++ i) st.insert(i);

    vector <int> ans;
    queue <int> Q;
    for (int i = 1; i <= n; ++ i) Q.push(i);

    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        if (st.find(u) == st.end()) continue;
        
        sit it = st.find(u);
        int v = (next(it) == st.end() ? *st.begin() : *next(it));
        if (__gcd(A[u], A[v]) == 1){
            ans.push_back(v);
            Q.push(u);
            st.erase(v);
        }
    }

    cout << ans.size();
    for (auto &x : ans) cout << " " << x;
    cout << "\n";
}
