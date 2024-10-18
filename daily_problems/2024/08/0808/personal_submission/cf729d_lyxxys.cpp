#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 2e5, mod = 1e9+7, inf = 1e9;

void solve(){
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    vector <int> loc;
    for (int i = 0, cnt = 0; i < n; ++ i){
        if (s[i] == '0'){
            ++ cnt;
            if (cnt == b) loc.push_back(i), cnt = 0;
        } else cnt = 0;
    }

    -- a;
    while (!loc.empty() && a--) loc.pop_back();
    cout << loc.size() << "\n";
    for (auto &x : loc) cout << x+1 << " ";
    cout << "\n";
}
