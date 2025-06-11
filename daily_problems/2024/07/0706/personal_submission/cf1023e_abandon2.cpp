#include<bits/stdc++.h>
using namespace std;
const int N =1e5+10;

int ask(int x,int y,int u,int v){
    cout<<"? "<<x<<" "<<y<<" "<<u<<" "<<v<<endl;
    string s;cin>>s;
    if(s=="YES")return 1;
    return 0;
}

void solve(){
    string a,b;
    int n;cin>>n;
    int x=1,y=1;
    for(int i=1;i<n;i++){
        if(y<n&&ask(x,y+1,n,n)){
            y++;
            a+='R';
        }
        else{ 
            x++;
            a+='D';
        }
    }
    x=n,y=n;
    for(int i=1;i<n;i++){
        if(x>1&&ask(1,1,x-1,y)){
            b+='D';
            x--;
        }
        else{
            b+='R';
            y--;
        }
    }
    reverse(b.begin(),b.end());
    cout<<"! "<<a<<b<<"\n";

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
