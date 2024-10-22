#include<bits/stdc++.h>
using namespace std;
int k;
bool vis[505][505];
void del(int u, int v){
    vis[u][v] = 0;
    vis[u + k + 2][v + k + 2] = 0;
}
int main(){
    cin >> k;
    if(k % 2 == 0){
        cout << "NO" << endl;
        return 0; 
    }
    cout << "YES" << endl;
    if(k == 1){
        cout << 2 << " " << 1 << endl;
        cout << 1 << " " << 2 << endl;
        return 0;
    }
    int n = (k + 2) * 2, m = (k + 2) * k;
    memset(vis, 1, sizeof vis);
    cout << n << " " << m << endl;
    del(1, k + 1), del(1, k + 2);
    for(int i = 2; i < k; i += 2) del (i, i + 1);
    for(int i = 1; i <= n; i++){
        if(i <= k + 2){
            for(int j = i + 1; j <= k + 2; j++){
                if(vis[i][j]){
                    cout << i << " " << j << endl;
                }
            }
        }else{
            for(int j = i + 1; j <= n; j++){
                if(vis[i][j]){
                    cout << i << " " << j << endl;
                }
            }
        }
    }
    cout << 1 << " " << 1 + k + 2;
    return 0; 
}