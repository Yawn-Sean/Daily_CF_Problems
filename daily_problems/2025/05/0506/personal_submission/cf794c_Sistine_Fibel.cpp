#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
void solve();
#define endl '\n'
signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int t = 1;
	// cin >> t;  //atc默认关闭，cf按需开启
	while(t --)
		solve();
}

void solve(){ 
    string a, b;
    cin >> a >> b;
    const int N = a.length();
    sort(all(a)); sort(all(b));
    reverse(all(b)); // 翻转取最大
    
    deque<char> as, bs;
    for(int i = 0; i < (N + 1) / 2; i++)
        as.push_back(a[i]);
    for(int i = 0; i < N / 2; i++)
        bs.push_back(b[i]);
    
    string l = "", r = "";//有些情况放后面逼迫对手放前面更优
    for(int i = 0; i < N; i++) {
        if(i % 2) {
            if(!bs.empty()) {
                if(as.empty() || bs.front() > as.front()) {
                    l += bs.front();
                    bs.pop_front();
                } 
                else {
                    r += bs.back();
                    bs.pop_back();
                }
            }
        } 
        else { 
            if(!as.empty()) {
                if(bs.empty() || as.front() < bs.front()) {
                    l += as.front();
                    as.pop_front();
                } 
                else {
                    r += as.back();
                    as.pop_back();
                }
            }
        }
    }
    reverse(all(r));//反向存储
    cout << l + r << endl;
}
