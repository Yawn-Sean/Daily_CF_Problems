#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int s[N];
struct node{
    int x,y,id;
    bool operator<(const node&v)const{
        if(x==v.x){
            return y<v.y;
        }
        return x<v.x;
    }
}a[N];


struct cmp{
    int operator()(const node&a,const node&b){
        return a.y<b.y;
    }
};

void solve(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        a[i].id=i;
        s[a[i].x]++;
        s[a[i].y+1]--;
    }
    sort(a+1,a+1+n);  
    priority_queue<node,vector<node>,cmp>q;
    vector<int>v;
    int now=1;
    for(int i=1;i<=N-10;i++){
        while(now<n&&a[now].x<=i)
            q.push(a[now++]);
        //cout<<i<<" "<<now<<"\n";
        s[i]+=s[i-1];
        while(s[i]>k){
            auto [x,y,id]=q.top();q.pop();
            //cout<<x<<" "<<y<<" "<<id<<" cc\n";
            v.push_back(id);
            s[i]--;
            s[y+1]++;
        }
    }
    cout<<(int)v.size()<<"\n";
    sort(v.begin(),v.end());
    for(int x:v){
        cout<<x<<" ";
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
