#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--){
		int n, k;
		cin >> n >> k;
		
		string s;
		cin >> s;
		
		vector<int> l(k), r(k);
		for(int i=0; i<k; i++) cin >> l[i];
		for(int i=0; i<k; i++) cin >> r[i];
		
		int q;
		cin >> q;
		
		vector<int> diff(n+5);
		for(int i=0; i<q; i++) {
			int x; cin >> x;
			int le = 0, ri = k-1;
			while(le < ri) {
				int mid = (le + ri + 1) / 2;
				if(l[mid] <= x) le = mid;
				else ri = mid - 1;
			}
			int a = min(x, l[le] + r[le] - x);
			int b = max(x, l[le] + r[le] - x);
			diff[a] ++;
			diff[b+1] --;
		}

    // 差分的前缀和
		vector<int> dd(n+5);
		for(int i=1; i<=n; i++) {
			dd[i] = dd[i-1] + diff[i];
		}
		
		for(int i=0; i<k; i++) {
			for(int le=l[i], ri=r[i]; le < ri; le++, ri--) {
				if(dd[le] & 1) {
					swap(s[le-1], s[ri-1]);
				}
			}
		}
		
		cout << s << endl;
	}
	return 0;
}
