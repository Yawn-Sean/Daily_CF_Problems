#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
typedef long long ll;
void solve(){
    int grp[55][55],n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char x;cin>>x;
            grp[i][j]=(x=='W'?0:1);
        }
    }
    for(int i=1;i<=n;i++){
        bool  flag=1;int cnt=0;
        for(int j=1;j<=m;j++){
            if(grp[i][j]==flag){
                flag=!flag;cnt++;
            }
        }
        if(cnt>=3){cout<<"NO"<<endl;return;}

    }
    for(int i=1;i<=m;i++){
        bool  flag=1;int cnt=0;
        for(int j=1;j<=n;j++){
            if(grp[j][i]==flag){
                flag=!flag;cnt++;
            }
        }
        if(cnt>=3){cout<<"NO"<<endl;return;}
    }
    for(int a=1;a<=n;a++){
        for(int b=1;b<=m;b++){
            for(int c=1;c<=n;c++){
                for(int d=1;d<=m;d++){
                    if(a==c&&b==d)continue;
                    if(grp[a][b]&&grp[c][d]&&(grp[a][d]||grp[c][b])){
                        continue;
                    }
                    else if(grp[a][b]&&grp[c][d]){
                        // cout<<a<<b<<c<<d;
                        cout<<"NO"<<endl;return ;
                    }
                }
            }
        }
    }
    cout<<"YES"<<endl;

}   
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
