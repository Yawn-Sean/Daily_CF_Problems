#include <bits/stdc++.h>

//#define DEBUG
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
//constexpr int mod = 1e9 + 7;



void solve() {
    int n,q;cin>>n>>q;
    vi a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    stack<int> st;
    unordered_map<int,int> mp;
    int mx = -1;
    for(int i=0;i<n;++i){
        if(a[i] == 0) continue;
        while(!st.empty() && st.top() > a[i]) st.pop();
        if(mp.contains(a[i]) && !st.empty() && st.top()!=a[i]) {
            cout<<"NO"<<endl;
            return ;
        }
        st.push(a[i]);
        mp[a[i]]++;
    }
    mx = *max_element(all(a));
    if(mx == q){
        if(a[0]==0) a[0] = 1;
        for(int i=1;i<n;++i)
            if(a[i]==0) a[i]=a[i-1];
    } else{
        bool f = false;
        for(int i=0;i<n;++i)
            if(a[i]==0) {
                a[i]=q;
                f = true;
                break;
            }
        if(!f){
            cout<<"NO"<<endl;
            return ;
        }
        for(int i=1;i<n;++i)
            if(a[i]==0) a[i]=a[i-1];
    }
    cout << "YES" << endl;
    for(int i=0;i<n;++i)
        cout<<a[i]<<" \n"[i==n-1];
}


int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
//    cin >> t;
    t = 1;
    while (t--) {
        solve();
    }

}






