#include <bits/stdc++.h>

#define DEBUG
#ifndef  DEBUG
#pragma GCC optimize("O3")
#endif
using namespace std;


using i64 = long long;
using pii = pair<int, int>;
//using u32 = unsigned;
constexpr int inf = INT32_MAX >> 1;
//constexpr i64 inf = INT64_MAX >> 1;
using vi = vector<int>;
using vl = vector<i64>;
using vb = vector<bool>;
#define all(x) (x).begin(),(x).end()
constexpr int mod = 1e9 + 7;


void solve(){
    int n;cin>>n;
    string s,t;cin>>s>>t;
    unordered_map<char,int> mp;
    for(auto c:s) mp[c]++;
    for(auto c:t) mp[c]++;
    for(auto [c,ct]:mp)
        if(ct % 2) {
            cout<<"No"<<endl;
            return;
        }
    vector<pii> op;
    for(int i=0;i<n;++i){
        if(s[i]==t[i]) continue;
        for(int j=i+1;j<n;++j) {
            if(s[i]==s[j]) {
                swap(s[j],t[i]);
                op.push_back({j+1,i+1});
                break;
            }
            if(s[i]==t[j]){
                swap(s[j],t[j]);
                op.push_back({j+1,j+1});
                swap(t[i],s[j]);
                op.push_back({j+1,i+1});
                break;
            }
        }
        if(s[i]!=t[i]) {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
    cout<<op.size()<<endl;
    for(auto [x,y]:op)
        cout<<x<<' '<<y<<endl;
}

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}






