#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e6 + 5, mod = 998244353, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

struct Node{
    int type;
    string bits;
    int op,a,b;
    Node():type(0),bits(""),op(0),a(-1),b(-1){}
};

il void solve(){
    int n,m;
    cin>>n>>m;
    vector<Node>a(n);
    map<string,int>id;
    for(int i=0;i<n;i++){
        string v,s,t;
        cin>>v>>s>>t;
        id[v]=i;
        if(t[0]=='0'||t[0]=='1'){
            a[i].type=0;
            a[i].bits=t;
        }else{
            a[i].type=1;
            if(t=="?")a[i].a=-1;
            else a[i].a=id[t];
            string op,t2;
            cin>>op>>t2;
            if(op=="AND")a[i].op=0;
            else if(op=="OR")a[i].op=1;
            else a[i].op=2;
            if(t2=="?")a[i].b=-1;
            else a[i].b=id[t2];
        }
    }
    string min_ans(m,'0'),max_ans(m,'0');
    for(int k=0;k<m;k++){
        vector<int>v0(n,0),v1(n,0);
        for(int i=0;i<n;i++){
            if(a[i].type==0){
                int bit=a[i].bits[k]-'0';
                v0[i]=v1[i]=bit;
            }else{
                int a0=(a[i].a==-1?0:v0[a[i].a]);
                int b0=(a[i].b==-1?0:v0[a[i].b]);
                int res;
                if(a[i].op==0)res=a0&b0;
                else if(a[i].op==1)res=a0|b0;
                else res=a0^b0;
                v0[i]=res;

                int a1=(a[i].a==-1?1:v1[a[i].a]);
                int b1=(a[i].b==-1?1:v1[a[i].b]);
                int res1;
                if(a[i].op==0)res1=a1&b1;
                else if(a[i].op==1)res1=a1|b1;
                else res1=a1^b1;
                v1[i]=res1;
            }
        }

        int cnt0=0,cnt1=0;
        for(int i=0;i<n;i++){
            cnt0+=v0[i];
            cnt1+=v1[i];
        }
        if(cnt0<=cnt1)min_ans[k]='0';
        else min_ans[k]='1';

        if(cnt1>cnt0)max_ans[k]='1';
        else max_ans[k]='0';
    }
    cout<<min_ans<<"\n"<<max_ans;
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
