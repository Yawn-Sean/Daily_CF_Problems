#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
#define int long long
void solve(){
	int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    map<int,int> cnt;
    int k=0;
    for(int i=1;i<=n/2;i++){
        if(a[i]-k>0)
        cnt[a[i]-k]++;
        // cout<<a[i]-k<<" ";
        k++;
    }
    if(n%2){
        k=0;
        for(int i=n;i>=n/2+1;i--){
            // cout<<a[i]-k<<" ";
            if(a[i]-k>0)
            cnt[a[i]-k]++;
        k++;
        // cnt[a[n/2+1]-k]++;
        }
    }
    else{
        for(int i=n/2+1;i<=n;i++){
            k--;
            if(a[i]-k>0)
            cnt[a[i]-k]++;
            // cout<<a[i]-k<<" ";
            
        }
    }
    int ans=0;
    // cout<<ans;
    for(auto [x,y]:cnt){
        // cout<<x<<" "<<y<<endl;
        ans=max(ans,y);
    }
    cout<<n-ans<<endl;

}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
