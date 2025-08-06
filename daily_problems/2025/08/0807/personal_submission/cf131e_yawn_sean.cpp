#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pts(m);
    for (auto &[x, y]: pts)
        cin >> x >> y;
    
    vector<int> cnt(m);
    
    {
        map<int, vector<int>> mp;
        for (int i = 0; i < m; i ++)
            mp[pts[i].first].emplace_back(i);
        
        for (auto &[k, v]: mp) {
            sort(v.begin(), v.end(), [&] (int i, int j) {
                return pts[i].second < pts[j].second;
            });

            int l = v.size(); 
            for (int i = 1; i < l; i ++)
                cnt[v[i - 1]] ++, cnt[v[i]] ++; 
        }
    }
    
    {
        map<int, vector<int>> mp;
        for (int i = 0; i < m; i ++)
            mp[pts[i].second].emplace_back(i);
        
        for (auto &[k, v]: mp) {
            sort(v.begin(), v.end(), [&] (int i, int j) {
                return pts[i].first < pts[j].first;
            });

            int l = v.size(); 
            for (int i = 1; i < l; i ++)
                cnt[v[i - 1]] ++, cnt[v[i]] ++; 
        }
    }
    
    {
        map<int, vector<int>> mp;
        for (int i = 0; i < m; i ++)
            mp[pts[i].first + pts[i].second].emplace_back(i);
        
        for (auto &[k, v]: mp) {
            sort(v.begin(), v.end(), [&] (int i, int j) {
                return pts[i].second < pts[j].second;
            });

            int l = v.size(); 
            for (int i = 1; i < l; i ++)
                cnt[v[i - 1]] ++, cnt[v[i]] ++; 
        }
    }
    
    {
        map<int, vector<int>> mp;
        for (int i = 0; i < m; i ++)
            mp[pts[i].first - pts[i].second].emplace_back(i);
        
        for (auto &[k, v]: mp) {
            sort(v.begin(), v.end(), [&] (int i, int j) {
                return pts[i].second < pts[j].second;
            });

            int l = v.size(); 
            for (int i = 1; i < l; i ++)
                cnt[v[i - 1]] ++, cnt[v[i]] ++; 
        }
    }

    vector<int> ans(9, 0);
    for (auto &x: cnt) ans[x] ++;

    for (auto &x: ans) cout << x << ' ';

    return 0;
}