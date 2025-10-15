#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
#define int long long
void solve(){
	int n,k;cin>>n>>k;
    if(n>31){cout<<"YES "<<n-1<<endl;return ;}
    int ans=-1;
    vector<int> f(32, 0),f2(32,0);int x=1;
    for(int i=1;i<32;i++)
    {
        f[i]=4*f[i-1]+1;
        x*=2;
        f2[i]=x-1;
        f2[i]+=f2[i-1];//f2为2的i次累加和
    }
    for(int i=0;i<n;i++){
        int s=((int)1<<(n-i+1))-(int)1;//路径长度
        int mini=f2[n-i];
        // int mini = (((int)1 << (n - i + 1)) - 1) * f[i];
        int maxi=f[n]-(s)*f[i];
        if(k>=mini&&k<=maxi){
            ans=i;break;
        }
    }
    if(ans==-1){cout<<"NO"<<endl;return ;}
    else{
        cout<<"YES "<<ans<<endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {solve();}
    return 0;
}
