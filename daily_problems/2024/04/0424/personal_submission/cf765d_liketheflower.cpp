// https://codeforces.com/contest/765/submission/258045899
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void solve(){
    int n; cin >> n;
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        f[i]--;
    }
    vector<int> fixed_points;
    for (int i = 0; i < n; i++){
        if (f[f[i]] != f[i]){
            cout << "-1" << endl;
            return;
        }
        if (f[i] == i) 
            fixed_points.push_back(i);
    }
    unordered_map<int, int> num_idx;
    const int m = fixed_points.size();
    for (int i = 0; i < m; i++){
        num_idx[fixed_points[i]] = i;
    }
    vector<int> g(n, 0), h(m, 0);
    for (int i = 0; i < n; ++i){
        g[i] = num_idx[f[i]]; 
        if (f[i] ==i){
            h[g[i]] = i;
        }
    }
    cout << m << endl;
    for (int i = 0; i < n; i++){
        cout << g[i] + 1 << " ";
    }
    cout << endl;
    for (int i = 0; i < m; i++){
        cout << h[i] + 1 << " ";
    }
    cout << endl;
}
int main(){
    solve();
    return 0;
}
