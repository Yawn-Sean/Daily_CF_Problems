#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;
    cin >> n;
    vector<string> name(n);
    vector<int> perctg(n),adds(n);
    int sum = 0;
    int sum_add = 0;
    for(int i = 0; i < n; ++i){
        cin >> name[i];
        cin >> perctg[i];
        
        if(perctg[i] == 0) adds[i] = 49;
        else if(perctg[i] == 100) perctg[i] = 9950,adds[i] = 50;
        else perctg[i] = perctg[i] * 100 - 50,adds[i] = 99;
        sum += perctg[i];
        sum_add += adds[i];
    }
    if(sum > 10000 || sum + sum_add < 10000){
        cout << "IMPOSSIBLE\n";
        return;
    }
    int supply = 10000 - sum;
    for(int i = 0; i < n; ++i){
        int mx = perctg[i] + min(adds[i],supply);
        int mn = perctg[i] + max(0,supply - (sum_add - adds[i]));

        cout << name[i] << " ";
        cout << mn / 100 << (mn % 100 >= 10 ? "." : ".0") << mn % 100 << " ";
        cout << mx / 100 << (mx % 100 >= 10 ? "." : ".0") << mx % 100 << " ";
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    cout << flush;
    return 0;
}