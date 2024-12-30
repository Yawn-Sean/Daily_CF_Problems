#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, k, q, T;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    T = 1;
    cin >> T;
    remake:;
    while(T--){
    	cin >> n >> k;
    	vector<int> a(n);
    	for(auto& x:a)	cin >> x;
    	if(k == 0)	{
    		cout << a[0] << '\n';
    		goto remake;
    	}
    	int res = INT_MAX;
    	int ans = -1;
    	for(int i = 0; i+k < n; ++i){
    		int mid = a[i]+a[i+k] >> 1;
    		if(res > max(mid-a[i],a[i+k]-mid)){
    			ans = mid;
    			res = max(mid-a[i],a[i+k]-mid);
    		}
    	}	
    	cout << ans << '\n';
    }
    return 0;
}
