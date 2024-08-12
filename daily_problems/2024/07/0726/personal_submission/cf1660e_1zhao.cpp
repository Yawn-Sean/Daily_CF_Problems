#include <bits/stdc++.h>
using namespace std;
 
void solve() {
	int n;
	cin >> n;
	vector<string> mat(n);
	for(int i=0; i<n; i++) {
		cin >> mat[i];
	}
	int res = n*n;
	vector<int> cnt(n);
    int tot = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(mat[i][j] == '1') {
                tot ++;
                if(i<=j) cnt[j-i] ++;
                else cnt[n-(i-j)] ++;
            }
        }
    }
    for(int i=0; i<n; i++) {
        res = min(res, tot-cnt[i]+n-cnt[i]);
    }
	cout << res << endl;
}
 
int main()
{
    int T = 1;
	cin >> T;
	while(T --) solve();
    return 0;
}
