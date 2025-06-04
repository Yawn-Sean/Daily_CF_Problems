#include<bits/stdc++.h>
using namespace std;
#define int long long
int st[40001][33];
int a,b,n;
bool ksm(int x,int y,int res=1){
    while(y){
        if(res*x>=n)return false;
        if(y%2){
            res=res*x;
            if(res>=n)return false;
        }
        x=x*x;y/=2;
    }
    return true;
}
int dfs(int x,int y){
    if(st[x][y]!=-1)return st[x][y];
    if(!ksm(x,y))return st[x][y]=0;
    if(dfs(x+1,y)==0&&dfs(x,y+1)==0){
        st[x][y]=1;
    }else{
        st[x][y]=0;
    }
    return st[x][y];
}
void solve(){
   cin>>a>>b>>n;
   if(a==1&&!ksm(2,b)){
        cout<<"Missing";
        return;
   }
   if(b==1&&!ksm(a,2)){
    if((n-a)%2==0)cout<<"Masha";
    else cout<<"Stas";
    return;
   }
   for(int i=0;i<=40000;i++)for(int j=0;j<=30;j++)st[i][j]=-1;
   dfs(a,b);
//    cout<<st[a][b];
   if(!st[a][b]){
    cout<<"Masha";
   }else{
    cout<<"Stas";
   }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}