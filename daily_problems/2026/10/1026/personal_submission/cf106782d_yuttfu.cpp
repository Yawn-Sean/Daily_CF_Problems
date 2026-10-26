#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 21;

vector<int> a[N];

void dfs(int u){
    for(auto v : a[u]){
        dfs(v);
    }
    cout << u << ' ';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int ans = (1<<(n+1))-2;
    cout << ans << '\n';
    for(int i = 1;i < n;i++){
        a[i].push_back(i+1);
        a[i].push_back(i+1);
    }
    dfs(1);
    dfs(1);
    cout << '\n';
    return 0;
}