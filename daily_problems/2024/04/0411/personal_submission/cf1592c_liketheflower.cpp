// problem link: https://codeforces.com/contest/1592/problem/C
// submission: https://codeforces.com/contest/1592/submission/256142238
#include<iostream>
#include<vector>

using namespace std;
int dfs(int i, int p, vector<vector<int>> &tree, vector<int> &a, int target_xor_sum, int &cnt){
    int xor_sum = a[i];
    for (auto x: tree[i]){
        if (x == p) continue;
        xor_sum ^= dfs(x, i, tree, a, target_xor_sum, cnt);
    }
    if (xor_sum == target_xor_sum){
        cnt++;
        return 0;
    }
    return xor_sum;
}
int solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<vector<int>> tree(n);
    int u, v;
    for (int i = 0; i < n - 1; ++i){
        cin >> u >> v;
        u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int xor_sum = 0;
    for (auto x: a){
        xor_sum ^= x;
    }
    if (xor_sum == 0){
        cout << "YES" << endl;
        return 0;
    } 
    if (k == 2){
        cout << "NO" << endl;
        return 0;
    }
    int cnt = 0;
    auto this_xor_sum = dfs(0, -1, tree, a, xor_sum, cnt);
    if (this_xor_sum == 0 && cnt >= 3){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
