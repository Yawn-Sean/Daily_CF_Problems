#include <bits/stdc++.h>
using namespace std;
#define FAST cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
#include "Dbg.cpp"
#else
#define dbg(...)
#endif 
#define str string
#define vi vector<int>
#define int long long
void solve() {
    str s;
    cin >> s;
    int x = 11,cnt = 0;
    if(s.size() < 2){
        cout << 0 << endl;
        return;

    }
    while(x>=10){
        x = 0;
        for(int i = 0;i<s.size();i++){
            x+= s[i] - '0';
        }
        cnt++;
        s = to_string(x);
    }
    cout << cnt << endl;

}

signed main() 
{
   
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Err.txt", "w", stderr);
    freopen("Output.txt", "w", stdout);
    #endif
    FAST ;   
    cout<<fixed<<setprecision(14);
    int t = 1 ; 
	// cin >> t ; 
    while ( t-- ){ solve(); } 

}