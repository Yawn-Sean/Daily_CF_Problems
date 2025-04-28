#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
using i64 = long long;
void solve(){
    string s;
    cin >> s;
    int n = s.length(), subzero = 0, prezero = 0;
    bool prenum = false, subnum = false;
    int pos = -1, pre = 0, sub = 0;
    for(int i = 0; i < n; i++){
        if(s[i] > '0' && s[i] <= '9')prenum = true;
        if(s[i] == '0' && pos == -1 && !prenum)pre++;
        if(s[i] == '.'){
            pos = i;
            continue;
        }
        if(pos != -1 && s[i] > '0' && s[i] <= '9')subnum = true;
        if(pos != -1 && !subnum)subzero++;
    }
    for(int i = n - 1; i >= pos; i--){
        if(s[i] == '0')sub++;
        else break;
    }
    for(int i = pos - 1; i >= pre; i--){
        if(s[i] == '0')prezero++;
        else break;
    }
    if(pos == -1 && pre + sub == n || pos != -1 && pre + sub + 1 == n){
        cout << 0 << '\n';
        return;
    }
    if(pos == -1 || subzero == sub && pos + sub == n - 1){
        // cout << "1: \n";
        if(subzero == sub && pos != -1){
            n -= sub + 1;
            sub = prezero;
        }
        int exp = n - pre - 1;
        cout << s[pre];
        if(pre + 1 < n - sub){
            cout << ".";
            for(int i = pre + 1; i < n - sub; i++){
                if(s[i] != '.')cout << s[i];
            }
        }
        if(exp != 0)cout << "E" << exp << '\n';
    }else if(pos == pre){
        // cout << "2: \n";
        int exp = subzero + 1;
        cout << s[pos + subzero + 1];
        if(pos + subzero + 2 < n - sub){
            cout << '.';
            for(int i = pos + subzero + 2; i < n - sub; i++)cout << s[i];
        }
        if(exp != 0)cout << "E" << -exp << '\n';
    }else{
        // cout << "3: " << '\n';
        int exp = pos - pre - 1;
        // cout << pos << " " << pre << '\n';
        cout << s[pre] << ".";
        for(int i = pre + 1; i < n - sub; i++){
            if(i != pos)cout << s[i];
        }
        if(exp != 0)cout << "E" << exp << '\n';
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
