#include<bits/stdc++.h>
using namespace std;
const int N=500;
std::vector<int> v[N];
int n,k;

void solve(){
    cin>>n>>k;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<=k;j++){
            v[j].push_back(a[i]*j);
        }
    }
    for(int i=1;i<=k;i++)
        sort(v[i].begin(),v[i].end());
    int q;cin>>q;
    while(q--){
        int x;cin>>x;
        int ans=1e9;
        for(int i=1;i<=k;i++){//枚举使用几张
            for(int t:v[i]){
                int now=x-t;
                if(now<=0){
                    if(now==0){
                        ans=min(ans,i);
                    }
                    break;
                }
                for(int j=1;j<=k-i;j++){
                    int c=*lower_bound(v[j].begin(),v[j].end(),now);
                    if(now-c==0){
                        ans=min(ans,i+j);
                    }
                }
            }
        }
        if(ans==1e9){
            cout<<"-1\n";continue;
        }
        cout<<ans<<"\n";
    }

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
