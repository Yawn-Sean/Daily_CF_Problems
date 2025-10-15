#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
typedef long long ll;
void solve(){
	int n;cin>>n;
    int v[n+1];
    for(int i=1;i<=n;i++)
    cin>>v[i];
    if(n%2==0){cout<<-1<<endl;return ;}
    int x=n/2,ans=0;
    for(int i=n;i>=3;i-=2)
    {
        ans+=max(v[i],v[i-1]);
        v[i/2]-=max(v[i],v[i-1]);
        v[i/2]=max(0,v[i/2]);
    }
    if(v[1]!=0&&n>=3){ans+=v[1];}
    else if(v[1]==0){}
    else {cout<<-1<<endl;return ;}
    cout<<ans<<endl;
    return ;
}
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
