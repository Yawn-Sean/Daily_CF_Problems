#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
//#define x first
//#define y second

using namespace std;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void solve() {
    string s;
    cin>>s;
    string a="",b="";
    bool st=0,fg=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!='0') st=1;
        if(s[i]=='.') {
            fg=1;
            break;
        }
        if(st) a+=s[i];
    }
    if(fg){
        st=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!='0') st=1;
            if(s[i]=='.') break;
            if(st) b+=s[i];
        }
    }
    reverse(all(b));
    // cout<<a<<' '<<b<<endl;
    if(a.size()){
            cout<<a[0];
            string t;
            st=0;
            for(int i=a.size()-1;i>=1;i--){
                if(a[i]!='0') st=1;
                if(st) t+=a[i];
            } 
            reverse(all(t));
            if(b.size()){
                cout<<'.';
                for(int i=1;i<a.size();i++) cout<<a[i];
                cout<<b;
            }
            else if(t.size()) cout<<'.'<<t;

            if(a.size()-1>=1) cout<<'E'<<a.size()-1;
    }
    else{
        int k=0;
        string t;
        st=0;
        for(int i=0;i<b.size();i++){
            if(st) t+=b[i];
            if(b[i]!='0'&&!st){
                k=i;
                st=1;
            }
        }
        // cout<<k<<endl;
        cout<<b[k];
        if(t.size()) cout<<'.'<<t;
        cout<<'E'<<'-'<<(k+1);
    }
    
}
signed main() {
    fastio;
    int T;
 T = 1;
    // cin>>T;
    while (T--) solve();

    return 0;
}
