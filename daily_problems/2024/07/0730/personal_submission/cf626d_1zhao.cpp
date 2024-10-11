#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    const int MAX = 5000;
    long long d = n * (n-1) / 2;
    d = d * d * d;

    vector<int> cnt(MAX);
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            cnt[a[j]-a[i]] ++;
        }
    }

    vector<int> pre(MAX);
    for(int i=1; i<=MAX-1; i++) {
        pre[i] = pre[i-1] + cnt[i];
    }

    long long sum = 0;
    for(int i=1; i<=MAX-1; i++) {
        for(int j=1; i+j<=MAX-2; j++) {
            sum += (long long)cnt[i] * cnt[j] * (pre[MAX-1] - pre[i+j]);
        }
    }
    
    cout << (double) sum / d << endl;
}

int main()
{
	int T = 1;
	// cin >> T;
	while(T --) solve();
	return 0;
}
