/*
    Bonelight * v *
    20241101：重 走 西 游
    千 仇 万 恨 无 归 处， 封 灯 何 须 至 尊 骨
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e18
#define pii pair<int,int>
#define tiii tuple<int,int,int>

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    deque<int> st1,man; // *, P
    for(int i = 0; i < n; i ++) {
        if(s[i] == '*') st1.emplace_back(i);
        if(s[i] == 'P') man.emplace_back(i);
    }

    int l = -1, r = INF;

    auto check = [&](int x){
        deque<int> star = st1;
        for(auto i:man){
            if(star.empty()) return true;
            if(i - *begin(star) > x) return false;
            else {
                int l = max(0ll, i - *begin(star));
                int r = i + max((x - l) / 2, x - l * 2);

                while(star.size() && *begin(star) <= r) star.pop_front();
            }
        }
        return star.empty();
    };
    
    while(l + 1 < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
}

signed main(){
ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    // cerr << "整个程序运行时间: " << double(clock()) << " ms" << endl;
#endif
    int T = 1; 
    while(T --){
        solve();
    }
}
