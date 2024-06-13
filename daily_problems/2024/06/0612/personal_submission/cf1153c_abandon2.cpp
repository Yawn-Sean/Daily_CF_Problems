#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    s=' '+s;
    int c=0;
    for(int i=1;i<=n;i++){
        c+=s[i]==')';
    }
    if(c>n/2){
        cout<<":(\n";return;
    }
    for(int i=n;i>=1;i--){
        if(c==n/2)break;
        if(s[i]=='?')s[i]=')',c++;
        if(c==n/2)break;
    }
    if(c>n/2){cout<<":(\n";return;}

    for(int i=1;i<=n;i++){
        if(s[i]=='?')s[i]='(';
    }
    
    c=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='(')c++;
        else c--;
        if(c<=0&&i!=n){
            cout<<":(\n";return;
        }
        if(i==n&&c!=0){
            cout<<":(\n";return;
        }
        if(c>n/2){
            cout<<":(\n";return;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<s[i];
    }
    cout<<"\n";

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
