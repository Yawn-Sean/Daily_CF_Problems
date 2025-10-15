#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;cin>>n>>m;
    int len1=0,len2=0;
    long long tempn=1,tempm=1;
    while(tempn<n){
        len1++;
        tempn*=7;
    }
    while(tempm<m){
        len2++;
        tempm*=7;
    }
    if(!len1)len1++;
    if(!len2)len2++;
    if((len1+len2)>7){
        cout<<0;return;
    }
    int ans=0;
    for(int i=0;i<m*n;i++){
        int x=i/m;
        int y=i%m;
        vector<int>temp(7);
        for(int j=0;j<len1;j++){
            temp[x%7]++;
            x/=7;
        }
        for(int j=0;j<len2;j++){
            temp[y%7]++;
            y/=7;
        }
        int flag=1;
        for(int j=0;j<7&&flag;j++){
            if(temp[j]>1){
                flag=0;
            }
        }
        ans+=flag;
    }
    cout<<ans;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}