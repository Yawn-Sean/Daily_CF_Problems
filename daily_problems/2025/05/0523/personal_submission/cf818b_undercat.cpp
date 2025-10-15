#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;cin>>n>>m;
    vector<int>l(m),a(n);for(auto&i:l){cin>>i;i--;}
    set<int>st;
    for(int i=1;i<=n;i++)st.insert(i);
    for(int i=0;i<m-1;i++){
        if(a[l[i]]){
            for(int j=i;j<m-1;j++){
                if(a[l[j]]&&a[l[j+1]]&&(l[j]+a[l[j]])%n==l[j+1])continue;
                cout<<"-1";return;
            }
            break;
        }
        if((l[i+1]+n-l[i])%n==0)a[l[i]]=n;
        else a[l[i]]=(l[i+1]+n-l[i])%n;
        if(st.count(a[l[i]])==0){
            cout<<"-1\n";return;
        }
        st.erase(a[l[i]]);
    }
    for(int i=0;i<n;i++)if(!a[i]){
        a[i]=*st.begin();
        st.erase(*st.begin());
    }
    for(auto&i:a)cout<<i<<' ';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}