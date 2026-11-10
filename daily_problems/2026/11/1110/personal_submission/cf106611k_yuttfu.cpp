#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> a(3*n+1,0);
    vector<int> pos(3*n+1,0);
    int l = 0,r = 0;
    for(int i = 1;i <= 3*n;i++){
        cin >> a[i];
        pos[a[i]] = i;
        if(a[i] != i){
            if(l == 0) l = i;
            r = i;
        }
    }
    if(l == 0 && r == 0){
        cout << 0 << '\n';
        return;
    }
    if(r - l + 1 <= 2*n){
        cout << 1 << '\n';
        cout << l << ' ' << r << '\n';
        return;    
    }
    int le = l + 2*n - 1;
    int rs = r - 2*n + 1;
    int lf = 1,rf = 1;
    for(int x = l;x < rs;x ++){
        if(pos[x] > le) lf = 0; 
    }
    for(int x = le+1;x <= r;x ++){
        if(pos[x] < rs) rf = 0;
    }
    if(lf){
        cout << 2 << '\n';
        cout << l << ' ' << le << '\n';
        cout << rs << ' ' << r << '\n';
        return;
    }else if(rf){
        cout << 2 << '\n';
        cout << rs << ' ' << r << '\n';
        cout << l << ' ' << le << '\n';
        return; 
    }
    cout << 3 << '\n';
    cout << 1 << ' ' << 2*n << '\n';
    cout << n+1 << ' ' << 3*n << '\n';
    cout << 1 << ' ' << 2*n << '\n';  
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T --){
        solve();
    }
    return 0;
}