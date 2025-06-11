
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
#define SZ(a) ((int)a.size())
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int N = 2e5 + 10;

string update(string a) {
    
    int n = a.size();
    bool flag = false;
    if (a[n-1] != '9') {
        a[n-1] = (char)a[n-1] + 1;
        return a;
    }
    
    string res;
    res += '0';
    flag = true;
    int i = n-2;
    for (; i > 0; i -- ) {
        if (a[i] == '9') {
            res += '0';
        } else {
            res += (char)a[i] + 1;
            break;
        }
    }

    
    if (i == 0) {
        if (a[0] == '9') {
            return "10" + res;
        } else {
            res += a[0];
            res.back() = (char)res.back() + 1;
        }
    }
    reverse(all(res));
    return a.substr(0, i) + res;
}

void solve(int _) 
{
    int n;
    cin >> n;
    string s[n];
    cin >> s[0];
    int len = s[0].size();
    if (s[0][0] == '?') s[0][0] = '1';
    for (int k = 1; k < len; k ++ ) {
        if (s[0][k] == '?') {
            s[0][k] = '0';
        }
    }
    vector<string> ans;
    ans.push_back(s[0]);
    for (int i = 1; i < n; i ++ ) {
        cin >> s[i];
        int pre = SZ(s[i-1]), cur = SZ(s[i]);
        if (pre > cur) {
            cout << "NO" << endl;
            return;
        } else if (pre < cur ) {
            if (cur > 1 && s[i][0] == '?') s[i][0] = '1';
            for (int k = 1; k < cur; k ++ ) {
                if (s[i][k] == '?') s[i][k] = '0';
            }
        } else {
            int j = 0;
            string t;
            for (; j < cur; j ++) {
                if (s[i][j] == '?') t += s[i-1][j];
                else if (s[i][j] != s[i-1][j]) {
                    break;
                } 
                
            }
            if (j == cur || s[i][j] < s[i-1][j]) {
                    string now = update(t);
                    
                    if (SZ(now) != SZ(t)) {
                        cout << "NO" << endl;
                        return;
                    }
                    string res = now;
                    int idx = 0;
                    for (int k = 0; k < j; k ++ ) {
                        if (s[i][k] == '?') {
                            s[i][k] = res[idx ++];
                        }
                    }
                    for (int k = j+1; k < cur; k ++ ) {
                        if (s[i][k] == '?') {
                            s[i][k] = '0';
                        }
                    }
            } else {
                for (int k = 0; k < j; k ++ ) {
                    if (s[i][k] == '?') s[i][k] = s[i-1][k];
                }
                for (int k = j+1; k < cur; k ++ ) {
                    if (s[i][k] == '?') s[i][k] = '0';
                }
            }
        }
        ans.push_back(s[i]);
    }

    cout << "YES" << endl;
    for (auto &t: ans) cout << t << endl;
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}