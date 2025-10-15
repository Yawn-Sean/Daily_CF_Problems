#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
using i64 = long long;
void solve(){
    string s;
    cin >> s;
    i64 n = s.length(), ans = 0, i = 0;
    while(i < n){
        i64 st, end, mid;
        bool ok1, ok2, ok3;
        ok1 = ok2 = ok3 = false;
        while(i < n && !(s[i] >= 'a' && s[i] <= 'z'))i++;
        if(s[i] >= 'a' && s[i] <= 'z'){
            st = i;
            int cnt = 0;
            while(i < n && (s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9' || s[i] == '_')){
                if(s[i] >= 'a' && s[i] <= 'z')cnt++;
                i++;
            }
            // cout << s.substr(st, i - st) << " ";
            st = cnt;
            if(st > 0)ok1 = true;
        }
        if(s[i] == '@' && ok1){
            i++;
            mid = i;
            while(i < n && (s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')){
                i++;
            }
            if(i - mid > 0)ok2 = true;
            // cout << s.substr(mid, i - mid) << " ";
        }
        if(s[i] == '.' && ok2){
            i++;
            end = i;
            while(i < n && (s[i] >= 'a' && s[i] <= 'z')){
                i++;
            }
            // cout << s.substr(end, i - end) << " ";
            end = i - end;
            if(end > 0)ok3 = true;
        }
        if(ok3)ans += st * end;
        if(ok2)i = mid;
        // cout << "\n";
    }
    cout << ans << '\n';
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
