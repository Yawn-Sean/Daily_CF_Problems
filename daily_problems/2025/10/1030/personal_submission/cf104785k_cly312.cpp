#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> f,b;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        if(x<y) f.push_back(i);
        else b.push_back(i);
    }
    long long k=(m+1)/2;
    vector<int> *a;
    if((long long)f.size()>=k) a=&f;
    else a=&b;
    cout<<"YES\n"<<a->size()<<"\n";
    for(int i=0;i<a->size();i++) cout<<(*a)[i]<<' ';
    cout<<"\n";
}
