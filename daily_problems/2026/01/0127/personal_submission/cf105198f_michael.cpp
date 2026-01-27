#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> num = {6,2,5,5,4,5,6,3,7,6};
vector<int> ans(22,1000);

void solve(){
    int n;
    cin >> n;
    if(n <= 21){
        cout << ans[n] << '\n';
    }else{
        int v = (n - 15) % 7 + 15;
        cout << ans[v] << string((n - v) / 7,'8') << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 0; i < 10; ++i){
        ans[num[i]] = min(ans[num[i]],i);
    }
    for(int i = 1; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            ans[num[i] + num[j]] = min(ans[num[i] + num[j]],i * 10 + j);
        }
    }
    for(int i = 1; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            for(int k = 0; k < 10; ++k){
                ans[num[i] + num[j] + num[k]] = min(ans[num[i] + num[j] + num[k]],i * 100 + j * 10 + k);
            }
        }
    }

    while(t--){
        solve();
    }
    cout << flush;
    return 0;
}