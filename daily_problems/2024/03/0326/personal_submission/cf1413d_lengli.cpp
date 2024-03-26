/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

void solve(){
    int n;
    cin>>n;
    vector<pair<char,int>> q(n*2);
    for(int i=0;i<n*2;i++){
        cin>>q[i].first;
        if(q[i].first=='-') cin>>q[i].second;
        else q[i].second=-1;
    }
    reverse(all(q));
    vector<int> que,res;
    bool flag=1;
    for(auto it:q){
        char op=it.first;
        if(que.empty() and op=='+'){
            flag=0;
            break;
        }
        if(op=='+'){
            res.pb(que.back());
            que.pop_back();
        }else{
            int x=it.second;
            if(que.size() and x>que.back()){
                flag=0;
                break;
            }
            else que.pb(x);
        }
    }
    if(!flag) cout<<"NO";
    else{
        cout<<"YES"<<endl;
        reverse(all(res));
        for(auto x:res) cout<<x<<" ";
    }
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
