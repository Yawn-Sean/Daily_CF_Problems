#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int N = 4E5 + 10;
ll n, a[N], tree[N], lst[N];
vector<int> pos[N];
int lowbit(int x){
    return x & -x;
}
ll sum(int j){
    ll ret = 0;
    for (int i = j; i; i -= lowbit(i)){
        ret += tree[i];
    }
    return ret;
}
void add(int j, int x){
    for (int i = j; i <= 2 * n; i += lowbit(i)){
        tree[i] += x;
    }
}
void solve(){
    for (int i = 1; i <= n + n; ++i){
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    
    vector<array<int, 2>> seg;
    for (int i = 1; i <= n; ++i){
        if (pos[i].size()){
            int k = pos[i].size();
            for (int j = 0; j < k / 2; ++j){
                seg.push_back({pos[i][j], pos[i][j + k / 2]});
            }
        } 
    }
    
    ll all = n * (n - 1) / 2;
    ll now = 0;
    sort(seg.begin(), seg.end());
    for (auto [l, r]: seg){
       // cout << l << " " << r << endl;
        now += sum(r) - sum(l);
        add(r, 1);
       // cout << now << endl;
    }
    all -= now;
    cout << all << "\n";
    for (int i = 1; i <= n; ++i){
        lst[i] = 0;
        lst[i + n] = 0;
        tree[i] = 0;
        tree[i + n] = 0;
        pos[i].clear();
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin >> n, n){
        solve();
    }
    return 0;
}