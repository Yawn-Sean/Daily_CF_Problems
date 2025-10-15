#pragma Gcc optimize(3)
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<char> change(const vector<char> &cur){
    vector<char>ans;
    for(auto i : cur){
        if (i == '*'){
            ans.push_back('+');
        }
        else{
            ans.push_back('*');
        }
    }
    return ans;
}

vector<vector<char>> dfs(int i){
    vector<vector<char>>ans;
    if(i == 0){
        ans.push_back({'+'});
        return ans;
    }
    vector<vector<char>> last = dfs(i - 1);
    for(auto j : last){
        vector<char>mid = j;
        mid.insert(mid.end(), j.begin(), j.end());
        ans.push_back(mid);
    }
    for(auto j : last){
        vector<char>mid = j;
        j = change(j);
        mid.insert(mid.end(), j.begin(), j.end());
        ans.push_back(mid);
    }
    return ans;
}
void solve() {
    int n;
    cin >> n;
    vector<vector<char>>ans;
    ans = dfs(n);
    for(auto i : ans){
        for(auto j : i){
            cout << j;
        }
        cout << endl;
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
