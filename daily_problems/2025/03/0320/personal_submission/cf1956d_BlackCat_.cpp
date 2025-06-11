/*
 * @Author: BlaCat
 */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i64=long long;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    i64 maxn=0;
    vector<pair<int,int>> op;
    for(int i=0;i<(1<<n);i++){
        i64 sum=0;
        vector<pair<int,int>> tmp;
        for(int j=0;j<n;){
            if(((i&(1<<j)))){
                int l=j;
                int r=j;
                r++;
                while(r<n&&((i&(1<<r)))){
                   r++; 
                }
                tmp.emplace_back(make_pair(l,r-1));
                sum+=(r-l)*(r-l);
                j=r;
            }
            else{
                sum+=a[j];
                j++;
            }

        }
        if(sum>maxn){
            maxn=sum;
            op=tmp;
        }
    }
    vector<pair<int,int>>ans;
    auto dfs=[&](this auto && self,int l,int r){
        if(l==r){
            ans.push_back(make_pair(l+1,r+1));
            return ;
        }
        for(int i=r-1;i>=l;i--){
            self(l,i);
            if(l!=i){
                ans.push_back({l+1,i});
            }
        }
        ans.push_back(make_pair(l+1,r+1));
    };
    for(auto &x:op){
    
        for(int i=x.first;i<=x.second;i++){
            if(a[i]!=0){
                ans.emplace_back(make_pair(i+1,i+1));
            }
        }
        dfs(x.first,x.second);
    }
    cout<<maxn<<" "<<ans.size()<<endl;
    for(auto &x:ans){
        cout<<x.first<<" "<<x.second<<endl;
    }
    
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
