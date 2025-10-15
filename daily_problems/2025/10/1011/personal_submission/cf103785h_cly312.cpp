#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int &x:a)cin>>x;
    vector<int> q(n);
    for(int l=n;l>=1;--l){
        int p=-1;
        for(int i=0;i<l;++i) if(a[i]==i+1) p=i;
        if(p==-1) return cout<<"NO\n",0; 
        q[l-1]=p+1;
        a.erase(a.begin()+p);
    }
    cout<<"YES\n";
    for(int i=0;i<n;++i) cout<<q[i]<<' ';
    cout<<'\n';
}
