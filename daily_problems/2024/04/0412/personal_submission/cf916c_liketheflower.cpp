// problem link: https://codeforces.com/problemset/problem/916/C
// submission link: https://codeforces.com/contest/916/submission/256184975
#include<iostream>
using namespace std;
bool is_prime(int n){
	if(n==1) return false;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
void solve(){
	int n, m;
	cin >> n >> m;
	int mst_edge_sum = n - 1;
	int delta_sum_to_prime = 0;
	for (int i = mst_edge_sum; i < mst_edge_sum * 2 + 10; ++i){
		if (is_prime(i)){
			delta_sum_to_prime = i - mst_edge_sum;
			break;
		}
	}
	int mst_sum = mst_edge_sum + delta_sum_to_prime;
	// mst and dis from 1 to n are the same
	cout << mst_sum <<" " << mst_sum<<endl;
	for (int i = 0; i < n - 1; ++i){
		if (i == n -2){
			cout << i + 1 << " " << i + 2 << " " << 1  +  delta_sum_to_prime << endl;
		}
		else
		cout << i + 1 << " " << i + 2 << " 1" << endl;
	}
	// add the rest of the edges
	int num_edge = n - 1;
	for (int i = 1; i <= n - 1 && num_edge < m; ++i){
		for (int j = i + 1; j <= n && num_edge < m; ++j){
			if (j == i + 1){
				continue; /*already used*/
			}
			cout << i << " " << j << " " << mst_sum << endl;
			num_edge++;
		}
	}
}
int main(){
	solve();
	return 0;
}
