#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;


struct BIT{
    int n;
    vector<int>c;
    BIT(){};    
    BIT(int n){
        this->n=n;
        c.resize(n+1);
    };

    void add(int k,int x){
        for(int i=k;i<=n;i+=i&(-i)){
            c[i]+=x;
        }
    }

    int ask(int k){
        int res=0;
        for(int i=k;i>=1;i-=i&(-i)){
            res+=c[i];
        }
        return res;
    }

    int sum(int l,int r){
        return ask(r)-ask(l-1);
    }
};

void solve(){
    int n;cin>>n;
    BIT t(n);
    vector<int>a(n+1);

    for(int i=1;i<=n;i++)
        cin>>a[i];

    int ok=1;
    vector<int>c(n+1,0);
    for(int i=1;i<=n;i++){
        if(a[i]<a[i-1]){
            ok=0;
        }   
        if(c[a[i]]){
            cout<<"YES\n";return;
        }
        c[a[i]]++;
    }
    if(ok){
        cout<<"YES\n";return;
    }

    int s=0;
    for(int i=n;i>=1;i--){
        s+=t.ask(a[i]-1);
        t.add(a[i],1);
    }
    
    if(s%2){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;cin>>tt;
    while(tt--)
        solve();
    return 0;
}
