#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
#define int long long
void solve(){
	int n,m;cin>>n>>m;
    vector<vector<int>> grp(n+1,vector<int> (m+1));
    int pt=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((i+j)%2){
                grp[i][j]=pt++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((i+j)%2==0){
                grp[i][j]=pt++;
            }
        }
    }
    if(n+m<5&&n+m>2)
    {cout<<-1<<endl;return ;}
    else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<grp[i][j]<<" ";
            }
            cout<<'\n';
        }
    }
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
