#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
#define int long long
void solve(){
	int x,y,m;cin>>x>>y>>m;
    if(x>=m||y>=m){cout<<0<<endl;return ;}
    if(x<=0&&y<=0&&x<m&&y<m){cout<<-1<<endl;return ;}
    int nx=min(x,y),ny=max(x,y);
    x=nx;y=ny;
    int cnt=0;
    if(x*y<0){
            cnt+=(-x+y-1)/y;
            x+=cnt*y;
        }
    nx=min(x,y),ny=max(x,y);
    x=nx;y=ny;
    while(y<m)
    {
        x=x+y;
        swap(x,y);
        cnt++;
    }
    
    cout<<cnt<<endl;return ;
}
signed main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
