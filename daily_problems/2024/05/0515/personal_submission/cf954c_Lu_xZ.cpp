#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 2e5 + 5, X = 1e9;

int n, m, a[N], flag, mx, mi = 1e9;

struct Node {
	int x, y;
	Node(int x = 0) : x((x % m == 0) ? x / m : x / m + 1), y((x % m == 0) ? m : x % m) {}
	friend bool check(Node a, Node b) {
		if(a.x == b.x) {
			if(abs(a.y - b.y) != 1) return 0;
			return 1;
		}
		else if(a.y == b.y) {
			if(abs(a.x - b.x) != 1) return 0;
			return 1;
		}
		return 0;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
		if(flag) {
			if(check(Node(a[i]), Node(a[i - 1])) == 0) {
				cout << "NO";
				exit(0);
			}
		}
		else {
			if(i > 1 && abs(a[i] - a[i - 1]) != 1) {
				if(a[i] == a[i - 1]) {
					cout << "NO";
					exit(0);
				}
				flag = 1;
				m = abs(a[i] - a[i - 1]);
				if(Node(mx).x != Node(mi).x) {
					cout << "NO";
					exit(0);
				}
			}
		}
		mi = min(mi, a[i]), mx = max(mx, a[i]);
	}
	if(flag == 0) {
		cout << "YES\n" << X << ' ' << X; 
	}
	else {
		cout << "YES\n" << X << ' ' << m;
	}
	return 0;
}
