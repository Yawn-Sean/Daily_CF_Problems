// https://codeforces.com/problemset/problem/766/C

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010,mod = 1e9 + 7;
typedef long long ll;

ll num[30],n,f[N],f3[N],ans1 = 1;    // f2 是用来求 第三行的答案 
char s[N];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> s + 1;
	for (int i = 0; i < 26; i++) {
		cin >> num[i];
	}
	
	f[0] = 1;f[1] = 1;
//	f2[1][1] = 1;
//	f2[0][0] = 1;
//	
//	pre[0][1] = 1; pre[0][2] = 1;
//	pre[1][1] = 0; pre[1][2] = 1;

	f3[1] = 1;
	
	for (ll i = 2; i <= n; i++) {
		f[i] = (num[s[i] - 'a'] >= 1) ? f[i - 1] : 0;
		f3[i] = min(i,f3[i - 1] + 1);
		
		ll minv = num[s[i] - 'a'],j = i - 1;
		for (j = i - 1; j >= 1; j--) {
			int idx = s[j] - 'a';
			
			minv = min(minv,num[idx]);
			if (minv >= i - j + 1) {
				ans1 = max(ans1,i - j + 1);
				
				f[i] = (f[i] + f[j - 1]) % mod;
				f3[i] = min(f3[i],f3[j - 1] + 1);
			} else {
				break;
			}
		}
		
//		f2[i][0] = 0;
//		pre[0][i + 1] = pre[0][i] + f2[i][0];
//		
//		for (int k = 1; k <= n; k++) {
//			if (i < k) {
//				f2[i][k] = 0;
//			} else {
//				f2[i][k] = pre[k - 1][i] - pre[k - 1][j];
//			}
//			
//			pre[k][i + 1] = pre[k][i] + f2[i][k];
//		}
		
		
	}
	
//	for (int i = 1; i <= n; i++) {
//		cout << f3[i] << " ";
//	}

//	for (int i = 0;i <= n; i++) {
//		for (int k = 0; k <= n; k++) {
//			cout << f2[i][k] << " ";
//		}
//		
//		cout << "\n";
//	}


	cout << f[n] << "\n" << ans1 << "\n" << f3[n] << "\n";
	
	return 0;
}
