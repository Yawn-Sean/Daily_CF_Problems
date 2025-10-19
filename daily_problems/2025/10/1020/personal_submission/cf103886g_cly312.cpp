#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int m=0;
    while((1<<m)<n) m++;
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++){
        int r=0,x=i;
        for(int j=0;j<m;j++){
            r=(r<<1)|(x&1);
            x>>=1;
        }
        a.push_back({r,i+1});
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++) cout<<a[i].second<<' ';
    cout<<'\n';
}
