// https://codeforces.com/problemset/problem/281/B

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 100010;
typedef long long ll;

struct Node {
	ll i,j,k,p;
};

Node arr[N];
ll x,y,n,idx = 0;

int gcd(int a,int b) {
	if (b == 0) {
		return a;
	}
	
	return gcd(b,a % b);
}

bool cmp(const Node& v1,const Node& v2) {
	if (v1.i * v2.j == v1.j * v2.i) {
		if (v1.k != v2.k) {
			return v1.k < v2.k;
		}
		
		return v1.p <= v2.p;
	}
	
	return v1.i * v2.j < v1.j * v2.i;
}

void solve() {
	cin >> x >> y >> n;
	
	if (y <= n) {
		int temp = gcd(x,y);
		
		printf("%lld/%lld",x / temp,y / temp);
		return;
	}
	
	for (int b = 1; b <= n; b++) {
		ll a,t1,t2;
		t1 = b * x / y; t2 = (b * x - 1)  / y + 1;
		
		if (abs(t1 * y - x * b) <= abs(t2 * y - x * b)) {
			a = t1;
		} else {
			a = t2;
		}
		
		arr[idx++] = Node{abs(a * y - x * b),b * y,b,a};
	}
	
	sort(arr,arr + idx,cmp);
	
	printf("%lld/%lld",arr[0].p,arr[0].k);
	
}

int main() {
	solve();
	
	return 0;
}
