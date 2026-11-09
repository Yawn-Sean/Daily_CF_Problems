#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool ask(vector<int> &rem,int l,int r,int v){
    cout << "? " <<  r - l + 1 << ' ' << v << endl;
    cout << rem[l];
    for(int i = l+1;i <= r;i++){
        cout << ' ' << rem[i];
    }
    cout << endl;
    if(v > 0){
        cout << 0;
    }
    for(int i = 1;i < v;i++){
        cout << ' ' << i;
    }
    cout << endl;
    int mex;
    cin >> mex;
    return mex > v;
}

void solve(){
    int n;
    cin >> n;
    vector<int> rem(n,0);
    for(int i = 0;i < n;i++) rem[i] = i+1;
    vector<int> res;
    for(int i = 0;i <= n;i++){
        if(ask(rem,0,n-1,i)) res.push_back(i);
    }
    vector<int> ans(n+1,0);
    for(auto v : res){
        while(!rem.empty() && ask(rem,0,(int)rem.size()-1,v)){
            int l = 0,r = rem.size()-1;
            while(l < r){
                int m = l + r >> 1;
                if(ask(rem,l,m,v)){
                    r = m;
                }else{
                    l = m + 1;
                }
            }
            ans[rem[l]] = v;
            rem.erase(rem.begin()+l);
        }
    }
    cout << "! ";
    cout << ans[1];
    for(int i = 2;i <= n;i++){
        cout << ' ' << ans[i];
    }
    cout << endl;
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T = 1;
    cin >> T;
    while(T --){
        solve();
    }
    return 0;
}
