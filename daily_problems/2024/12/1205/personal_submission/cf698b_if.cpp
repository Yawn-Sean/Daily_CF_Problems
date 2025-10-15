#pragma GCC optimize("O3")
#include <bits/stdc++.h>  
typedef long long ll;  
using namespace std;  

int find(int i, vector<int> &g){
    if(g[i] == i){
        return i;
    }
    return g[i] = find(g[i], g);
}

void solve(){
    int n;
    cin >> n;
    int ans = 0;
    vector<int>a(n);
    bool f = false;
    int root = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == i + 1){
            if(f){
                a[i] = root;
                ans += 1;
            }
            else{
                f = true;
                root = i + 1;
            }
        }
    }
    vector<int>g(n + 1);
    for(int i = 0; i < n + 1; i++){
        g[i] = i;
    }
    for(int i = 0; i < n; i++){

        if(i + 1 == root) continue;
        int x = find(i + 1, g);
        int y = find(a[i], g);
        if(x == y){
            if(!f){
                a[i] = i + 1;
                root = i + 1;
                ans++;
                f = true;
            }
            else{
                ans += 1;
                a[i] = root;
            }
        }
        x = find(i + 1, g);
        y = find(a[i], g);
        if(x < y){
            g[y] = x;
        }
        if (x > y){
            g[x] = y; 
        }
    }
    cout << ans << endl;
    for(int i : a){
        cout << i << ' ';
    }
    cout << endl;
    return;
}  
int main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(0);  
    cout.tie(0);  
    int t = 1;  
    while (t--) {  
        solve();  
    }  
    return 0;  
}
