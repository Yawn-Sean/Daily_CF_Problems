#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,i,j;
    cin>>n>>m;
    if(n>m*(m-1)){cout<<"NO"<<endl;return 0;}
    cout<<"YES"<<endl;
    for(i=1;i<m;i++){
        for(j=i+1;j<=m;j++){
            cout<<i<<" "<<j<<endl;
            n--;
            if(!n)return 0;
            cout<<j<<" "<<i<<endl;
            n--;
            if(!n)return 0;
        }
    }
}
