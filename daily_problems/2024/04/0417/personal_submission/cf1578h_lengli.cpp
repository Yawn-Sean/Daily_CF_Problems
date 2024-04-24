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
    string s;
    cin>>s;
    stack<int> l;
    stack<array<int,2>> nums;
    int n=s.size();
    for(int i=0;i<n;i++){
        char x=s[i];
        if(x=='(') l.push(i);
        else if(x==')'){
            if(l.top()==i-1) {
                nums.push({i-1,0});
                l.pop();
            }else{
                auto [id,v]=nums.top();
                nums.pop();
                while(nums.size() and nums.top()[0]>l.top()){
                    auto [a,b]=nums.top();
                    nums.pop();
                    v=max(v,b+1);
                    id=a;
                }
                nums.push({l.top(),v});
                l.pop();
            }
        }else continue;
    }
    
    auto [id,v]=nums.top();
    nums.pop();
    while(nums.size()){
        auto [a,b]=nums.top();
        nums.pop();
        v=max(v,b+1);
        id=a;
    }
    cout<<v<<endl;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
