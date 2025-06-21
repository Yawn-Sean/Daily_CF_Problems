#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
#define int long long
void solve(){
	int n;cin>>n;
    int v[n+1];
    for(int i=1;i<=n;i++){cin>>v[i];}
    int gap[n+1]={0};
    sort(v+1,v+1+n);int x=1,cnt=0;
    for(int i=1;i<=n;i++){
        if(pow((int)(sqrt(v[i])),2)==v[i]){
            cnt++;
            gap[i]=0;
        }
        else{
            gap[i]=min(abs(v[i]-pow((int)(sqrt(v[i])),2)),abs(v[i]-pow((int)(sqrt(v[i])+1),2)));
            
        }
        // cout<<gap[i]<<" ";
        
    }
    cout<<endl;
    sort(gap+1,gap+1+n);int ans=0;
    if(cnt<n/2){
        for(int i=1;i<=n&&cnt<n/2;i++){
            if(gap[i]!=0){
                cnt++;
                ans+=gap[i];
            }
        }
        cout<<ans<<endl;
    }
    else if(cnt==n/2)cout<<0<<endl;
    else{
        for(int i=n;i>=1&&cnt>n/2;i--){
            if(gap[i]==0){
                if(v[i]==0){
                    ans+=2;
                }
                else{
                    ans++;
                }
                cnt--;
            }
        }
        cout<<ans<<endl;
    }
    
}
signed main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
