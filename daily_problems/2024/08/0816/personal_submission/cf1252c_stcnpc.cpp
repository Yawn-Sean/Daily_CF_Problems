//https://codeforces.com/problemset/problem/1252/C
#include <bits/stdc++.h>
using namespace std;

//以下是一个并查集的写法但是TLE。。。

void solve()
{
    int n,q;
    cin>>n>>q;
    n++;
    vector<int> rv(n),cv(n);
    for(int i=1;i<n;i++) cin>>rv[i];
    for(int i=1;i<n;i++) cin>>cv[i];
    vector<int> fa(n*n); //build Disjoint-set
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            fa[i*n+j]=i*n+j; //init Disjoint-set
    //define Uinon-Find behavior
    function<int(int)> find;
    find=[&](int i)->int{
        if(fa[i]==i) return i;
        fa[i]=find(fa[i]);
        return fa[i];
    };

    auto uni=[&](int x, int y){
        int xrt=find(x);
        int yrt=find(y);
        fa[xrt]=yrt;
    };
    //union all even blocks 
    int dir[5]{0,1,0};
    for(int i=0; i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<2;k++){
                int ansi=i+dir[k],ansj=j+dir[k+1];
                if(j==0&&i==0) continue;
                if(ansi==0&&ansj==0)continue;
                if((rv[i]+cv[j])&1) continue;
                if(ansi>=0 && ansj>=0 && ansi<n && ansj<n && ((rv[ansi]+cv[ansj])%2==0))
                    uni(ansi*n+ansj, i*n+j);
            }   
    int ra,ca,rb,cb;
    while(q--){
        cin>>ra>>ca>>rb>>cb;
        int start=ra*n+ca,end=rb*n+cb;
        if(find(start)==find(end))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
