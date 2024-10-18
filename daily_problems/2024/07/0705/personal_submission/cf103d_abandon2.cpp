#include<bits/stdc++.h>
using namespace std;
const int N =1e5+10;
using LL=long long;

void solve(){
    int n;cin>>n;
    int B=sqrt(n);
    std::vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }   
    int m;cin>>m;
    vector<array<int,3>>q(m+1);     
    for(int i=1;i<=m;i++){  
        cin>>q[i][1]>>q[i][0];
        q[i][2]=i;
    }
    sort(q.begin()+1,q.end());

    vector<LL>s(n+1);
    vector<LL>ans(m+1);
    
    for(int i=1;i<=m;i++){
        auto[k,l,id]=q[i];
        if(k>=B){
            LL sum=0;
            for(int j=l;j<=n;j+=k){
                sum+=a[j];
            }
            ans[id]=sum;
        }
        else{
            if(k!=q[i-1][0]){
                s.clear();
                for(int j=n;j>=1;j--){
                    if(j+k<=n){
                        s[j]=s[j+k]+a[j];
                    }
                    else{
                        s[j]=a[j];
                    }
                }
            }
            ans[id]=s[l];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<"\n";
    }


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
