#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int a[N];
int n, cnts[N], cnth[N], cntsh[N];


signed main(){
	//freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	string str;
	for(int i = 0; i < n; i++) {
		cin >> str;
		a[i] = i;
		for(char ch : str) {
			if(ch == 's') cnts[i] ++;
			if(ch == 'h') cnth[i] ++, cntsh[i] += cnts[i]; 
		}
	}
	sort(a, a + n, [](int x, int y){
		if(cnts[x] * cnth[y] != cnts[y] * cnth[x]) return cnts[x] * cnth[y] > cnts[y] * cnth[x];
		return false;
	});
	int tot = 0;
	for(int i = 0, s = 0; i < n; i++)
		tot += cnth[a[i]] * s + cntsh[a[i]], s += cnts[a[i]];
	cout << tot;
	return 0;
}
