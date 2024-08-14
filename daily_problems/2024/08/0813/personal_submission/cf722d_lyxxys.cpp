#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 5e6+7, mod = 1e9+7, inf = 1e9;
ll f[N];

void solve(){
    int n;
    cin >> n;
    vector <int> nums(n);
    for (auto &x : nums) cin >> x;

    set <int> st(nums.begin(), nums.end());
    
    while (true){
        int x = *st.rbegin();
        int y = x;
        while (x && st.find(x) != st.end()) x/=2;
        if (!x) break;
        st.erase(y);
        st.insert(x);
    }

    for (auto &x : st) cout << x << " ";
    cout << "\n";
}
