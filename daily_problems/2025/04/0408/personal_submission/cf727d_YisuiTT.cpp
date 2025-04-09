#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e5 + 10;
int nums[10], n, a[N];
vector<vector<int>>g;
map<int, string>i2s;
map<string, int>s2i;
void solve(){
    for(int i = 1; i <= 6; i++)scanf("%d", &nums[i]);
    i2s[1] = "S", i2s[2] = "M", i2s[3] = "L";
    i2s[4] = "XL", i2s[5] = "XXL", i2s[6] = "XXXL";
    s2i["S"] = 1, s2i["M"] = 2, s2i["L"] = 3;
    s2i["XL"] = 4, s2i["XXL"] = 5, s2i["XXXL"] = 6;
    scanf("%d\n", &n);
    g.resize(7);
    string s;
    auto fun = [](string s)-> vector<int>{
        vector<int>t;
        int i = 0, len = s.length();
        while(i < len){
            int st = i;
            while(i < len && s[i] != ',')i++;
            t.push_back(s2i[s.substr(st, i - st)]);
            i++;
        }
        return t;
    };
    bool ok = true;
    for(int i = 1; i <= n; i++){
        getline(cin, s);
        vector<int>t = fun(s);
        if(t.size() > 1){
            g[t[0]].push_back(i);
            g[t[1]].push_back(i);
        }else{
            a[i] = t[0], nums[t[0]]--;
            if(nums[t[0]] < 0){
                cout << "NO\n";
                return;
            }
        }
    }
    // for(int i = 1; i <= 6; i++)cout << nums[i] << " ";
    // cout << '\n';
    for(int i = 1; i <= 6; i++){
        while(!g[i].empty()){
            if(a[g[i].back()] != 0){
                g[i].pop_back();
                continue;
            }
            if(nums[i] > 0){
                a[g[i].back()] = i;
                g[i].pop_back();
                nums[i]--;
            }else if(nums[i + 1] > 0){
                a[g[i].back()] = i + 1;
                g[i].pop_back();
                nums[i + 1]--;
            }else{
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++)cout << i2s[a[i]] << '\n';
}
int main()
{
    // ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
