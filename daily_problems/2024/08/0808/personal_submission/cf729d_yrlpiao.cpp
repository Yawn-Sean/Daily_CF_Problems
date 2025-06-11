#include <iostream>      
#include <string>        
#include <vector>         
using namespace std;  
   
int n, a, b, k;
string s;

void yrlpSolve() {
	cin >> n >> a >> b >> k >> s;
    vector<int> ans;
    for (int i = 0, j = -1; i < n; i++) {
        if (s[i] == '1') j = i;
        else if (i - j == b) {
            if (a == 1) ans.push_back(i);
            else a--;
            j = i;
        }        
    }
    cout << ans.size() << endl;
    for (int x : ans) cout << x + 1 << " ";
}

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
