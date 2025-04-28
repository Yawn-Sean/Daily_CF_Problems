#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
using i64 = long long;
const int N = 5e5 + 10, S = 1e6;
int n, x[N];
void solve(){
    cin >> n;
    unordered_map<int, int>ump;
    for(int i = 1; i <= n; i++){
        cin >> x[i];
        ump[x[i]] = 1;
    }
    int circle = 0;
    vector<int>res;
    for(int i = 1; i <= n; i++){
        if(ump.count(S - x[i] + 1))circle ++;
        else res.push_back(S - x[i] + 1);
    }
    for(int i = 1; i <= S / 2 && circle > 0; i++){
        if(!ump.count(i) && !ump.count(S - i + 1)){
            res.push_back(i);
            res.push_back(S - i + 1);
            circle -= 2;
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for(auto &t : res)cout << t << " ";
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
