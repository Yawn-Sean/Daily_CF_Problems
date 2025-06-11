#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
//#define x first
//#define y second

using namespace std;
typedef pair<string, string> PII;

const int N = 1e5 + 10;

/* S ， M ， L ， XXL ， XXL ， XXXL*/
void solve() {
    vector<int>a(7);
    for(int i=1;i<=6;i++) cin>>a[i];
    int n;
    cin>>n;
    vector<string>s(n+1);
    vector<array<int,3>>q;
    vector<PII>qq(n+1);
    map<string,int>p;
    p["S"]=1;
    p["M"]=2;
    p["L"]=3;
    p["XL"]=4;
    p["XXL"]=5;
    p["XXXL"]=6;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        if(s[i]=="S") a[1]--;
        else if(s[i]=="M") a[2]--;
        else if(s[i]=="L") a[3]--;
        else if(s[i]=="XL") a[4]--;
        else if(s[i]=="XXL") a[5]--;
        else if(s[i]=="XXXL") a[6]--;
        else{
            for(int j=0;j<s[i].size();j++){
                if(s[i][j]==','){
                    string ss=s[i].substr(0,j);
                    string tt=s[i].substr(j+1,s[i].size());
                    qq[i]={ss,tt};
                    // cout<<ss<<' '<<tt<<endl;
                    q.push_back({p[ss],p[tt],i});
                    break;
                }
            }
        }
    }

    for(int i=1;i<=6;i++){
        if(a[i]<0){
            cout<<"NO"<<endl;
            return;
        }
    }
    sort(all(q));

    for(int i=0;i<q.size();i++){
        auto [x,y,u]=q[i];
        int l=0,r=0;
        if(a[x]&&a[y]) l=1;
        else if(a[x]) l=1;
        else if(a[y]) r=1;
        else{
            cout<<"NO"<<endl;
            return;
        }
        if(l){
            a[x]--;
            s[u]=qq[u].first;
        }
        else{
            a[y]--;
            s[u]=qq[u].second;
        }
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++) cout<<s[i]<<endl;
}
signed main() {
    fastio;
    int T;
 T = 1;
    // cin>>T;
    while (T--) solve();

    return 0;
}
