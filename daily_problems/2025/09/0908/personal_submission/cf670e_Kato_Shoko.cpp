#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e6 + 5, mod = 998244353, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    ll n,m,p;
    cin>>n>>m>>p;
    string s,op;
    cin>>s>>op;
    s="!"+s;
    vector<ll>L(n+2),R(n+2),match(n+2);
    for(int i=0;i<=n+1;i++){
        L[i]=i-1;
        R[i]=i+1;
    }
    stack<int>st;
    for(int i=1;i<=n;i++){
        if(s[i]=='(')st.push(i);
        else{
            int j=st.top();
            st.pop();
            match[i]=j;
            match[j]=i;
        }
    }
    int cur=p;
    for(auto c:op){
        if(c=='L'){
            cur=L[cur];
        }else if(c=='R'){
            cur=R[cur];
        }else{
            int a=cur,b=match[cur];
            if(a>b)swap(a,b);
            int l=L[a],r=R[b];
            R[l]=r;
            L[r]=l;
            if(r!=n+1)cur=r;
            else cur=l;
        }
    }
    for(int i=R[0];i<=n;i=R[i]){
        cout<<s[i];
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    //cin >> t;

    while (t--) {

        solve();

    }

    return 0;
}
