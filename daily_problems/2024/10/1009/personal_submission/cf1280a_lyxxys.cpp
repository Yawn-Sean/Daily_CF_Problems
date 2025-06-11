#include bitsstdc++.h
using namespace std;
const long long inf = 1e18;

void solve(){
    const int mod = 1e9 + 7;
    int ends;
    string s;
    cin  ends  s;
    int all = s.size(), pas = 0;

    for (int i = 0; i  ends; ++ i){
        int x = s[i] - '0';
        string t;
        if (s.size()  ends) t = s.substr(i+1);
        for (int j = 0; j  x-1; ++ j){
            if (s.size()  ends){
                s += t;
            }
        }
        pas = ((all - i - 1) % mod + mod) % mod;
        all += 1ll  pas  (x - 1) % mod;
        all %= mod;
    }

    cout  << all  << "\n";
}
