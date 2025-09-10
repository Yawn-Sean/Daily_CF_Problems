#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 2e5+10; 
const int mod = 1e9 + 7;
vector<int> Next(string s){
	int n = s.size();
	vector<int> res(n+1);
	res[0] = -1;
	res[1] = 0;
	int i = 2, cn = 0;
	while(i <= n){
		if(s[i-1] == s[cn]){
			res[i++] = ++ cn;
		}
		else if(cn > 0){
			cn = res[cn];
		}
		else{
			i ++;
		}
	}
	return res;
}
vector<int> kmp(string s1, string s2){
	vector<int> next = Next(s2), res;
    s2 += '#';
	int n = s1.size(), m = s2.size();
	int i = 0, j = 0;
	while(i < n && j < m){
		if(s1[i] == s2[j]){
			i ++;
			j ++;
            if(j == m-1 && i - m + 1 > 0 && i - m + 1 < m-1)res.push_back(i - m + 1);
		}
		else if(j > 0){
			j = next[j];
		}
		else{
			i ++;
		}
	}
	return res;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<string>> s(n+1, vector<string> (n+1));
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++)cin >> s[i][j];
    }
    vector<string> ss(n+1);
    auto check = [&]()->bool{
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
            	if(i == j)continue;
                if(s[i][j] != ss[i] + ss[j]){
                    return false;
                }
            }
        }
        return true;
    };
    
    if(n >= 3){
        int x = (s[1][2].size() + s[1][3].size() - s[2][3].size())/2;
        ss[1] = s[1][2].substr(0, x);
        if(x <= 0){
            cout << "NONE" << '\n';
            return;
        }
        for(int i = 2; i <= n; i++){
            ss[i] = s[i][1].substr(0, s[i][1].size()-x);
            if(ss[i].size() <= 0){
                cout << "NONE" << '\n';
                return;
            }
        }
        if(check()){
            cout << "UNIQUE" << '\n';
            for(int i = 1; i <= n; i++)cout << ss[i] << '\n';
        }
        else cout << "NONE" << '\n';
    }
    else{
        string S1 = s[1][2], S2 = s[2][1];
        if(S1.size() != S2.size()){
            cout << "NONE" << '\n';
            return;
        }
        vector<int> ans = kmp(S1 + S1, S2);
        if(ans.empty())cout << "NONE" << '\n';
        else if(ans.size() == 1){
            int x = ans[0];
            cout << "UNIQUE" << '\n';
            cout << S1.substr(0, x) << '\n';
            cout << S2.substr(0, (int)S1.size()-x) << '\n';
        }
        else cout << "MANY" << '\n';

    }
}
signed cute_prov0nce()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int t;
     //cin >> t;
     t = 1;
     while (t--)
     {
          solve();
     }

     return 0;
}
