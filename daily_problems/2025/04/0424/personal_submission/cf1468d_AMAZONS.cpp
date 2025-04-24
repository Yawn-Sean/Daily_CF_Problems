#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
#define int long long
bool cmp(int a,int b)
{return a>b;}
void solve(){
	int n,m,a,b;cin>>n>>m>>a>>b;
    int v[m+1];
    for(int i=1;i<=m;i++)cin>>v[i];
    int x=abs(b-a)-1;
    int tm=b>a?b-2:n-b-1;
    // cout<<tm<<" ";
    int pos=0,cnt=0;
    sort(v+1,v+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
        if(v[i]>tm)continue;
        cnt++;
        tm--;
    }
    cout<<min(cnt,x)<<endl;

}
signed main(){
    int t;
    cin>>t;
    while(t--)
    {solve();}
    return 0;
}
