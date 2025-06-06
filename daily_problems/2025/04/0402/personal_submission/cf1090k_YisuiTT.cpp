#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
using i64 = long long;
void solve(){
    int n;
    cin >> n;
    map<pair<string, int>, vector<int>>mp;
    for(int i = 1; i <= n; i++){
        string s, t;
        cin >> s >> t;
        int sub = 0, pre = 0;
        for(int j = 0; j < s.length(); j++){
            pre |= 1 << (s[j] - 'a');
        }
        for(int j = 0; j < t.length(); j++){
            sub |= 1 << (t[j] - 'a');
        }
        if((pre | sub) == sub)mp[{"", sub}].push_back(i);
        else{
            int j = s.length() - 1;
            while(j >= 0 && sub >> (s[j] - 'a') & 1)j--;
            mp[{s.substr(0, j + 1), sub}].push_back(i);
        }
    }
    cout << mp.size() << '\n';
    for(auto &tmp: mp){
        cout << tmp.second.size() << " ";
        for(auto tt: tmp.second)cout << tt << " ";
        cout << '\n';
    }
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
