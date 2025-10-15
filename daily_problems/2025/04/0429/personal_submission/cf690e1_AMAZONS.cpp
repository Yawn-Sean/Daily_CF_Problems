#include<bits/stdc++.h>
using namespace std;
const int N =605;
const int mod=1e9+7;
typedef long long ll;
int v[N][N];
void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)cin>>v[i][j];
    int ans1=0,ans2=0;
    for(int i=1;i<=m;i++)
    {
        ans1+=abs(v[1][i]-v[n][i]);
    }
    for(int i=1;i<=m;i++)
    {
        ans2+=abs(v[n/2][i]-v[n/2+1][i]);
    }
    cout<<((ans1>ans2)?"No":"Yes")<<endl;
}
int main(){
    int t=1;
    cin>>t;
    while(t--)
    {solve();}
    return 0;
}
