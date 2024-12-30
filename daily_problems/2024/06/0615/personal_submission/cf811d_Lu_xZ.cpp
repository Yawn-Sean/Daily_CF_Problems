#include<bits/stdc++.h>
#define eb emplace_back
#define e emplace
#define mkp make_pair
using namespace std;

using ll = long long;

int x, y, n, m, px[100][100], py[100][100], tx, ty;
string g[100];

char a[] = {'U', 'D'}, b[] = {'L', 'R'};

void print(char c) {
	cout << c << endl;
	cin >> x >> y;
	-- x, -- y;
}
#define _end if(g[x][y] == 'F') {return;}

void solve() {
	cin >> n >> m;
	for(int i = 0; i < n; ++ i) {
		cin >> g[i];
	} 
	x = 0, y = 0;
	auto ck = [&](int i, int j) {
		return i >= 0 && i < n && j >= 0 && j < m && g[i][j] != '*';
	};
	if(ck(x + 1, y) && ck(x, y + 1)) {
		print('U');
		_end;
		if(x) {
			swap(a[0], a[1]);
			print(a[0]);
		}
		print('L');
		_end;
		if(y) {
			swap(b[0], b[1]);
			print(b[0]);
		}	
	}
	else if(ck(x + 1, y)){
		print('U');
		_end;
		vector<char> path;
		if(x) {
			swap(a[0], a[1]);
			path.eb(a[0]);
		}
		while(1) {
			if(ck(x, y + 1)) {
				print('L');
				_end;
				if(y) {
					swap(b[0], b[1]);
					path.eb(b[0]);
				}
				break;
			}
			print(a[1]), path.eb(a[0]);
			_end;
		}
		ranges::reverse(path);
		for(auto c : path) {
			print(c);
		}
	}
	else {
		print('L');
		_end;
		vector<char> path;
		if(y) {
			swap(b[0], b[1]);
			path.eb(b[0]);
		}
		while(1) {
			if(ck(x + 1, y)) {
				print('U');
				_end;
				if(x) {
					swap(a[0], a[1]);
					path.eb(a[0]);
				}
				break;
			}
			print(b[1]), path.eb(b[0]);
			_end;
		}
		ranges::reverse(path);
		for(auto c : path) {
			print(c);
		}
	}
	// strart with (0, 0)
	typedef pair<int, int> pii;
	queue<pii> q;
	q.e(0, 0);
	
	for(int i = 0; i < n; ++ i) {
		for(int j = 0; j < m; ++ j) {
			px[i][j] = py[i][j] = -1;
		}
	}
	
	while(!q.empty()) {
		auto [u, v] = q.front();
		q.pop();
		if(g[u][v] == 'F') {
			tx = u, ty = v;
			break;
		}
		for(auto [nu, nv] : {mkp(u + 1, v), mkp(u, v + 1), mkp(u - 1, v), mkp(u, v - 1)}) {
			if(ck(nu, nv) && px[nu][nv] == -1) {
				px[nu][nv] = u;
				py[nu][nv] = v;
				q.e(nu, nv);
			}
		}
	}
	
	stack<char> path;
	while(tx || ty) {
		if(tx == px[tx][ty] + 1) {
			path.e(a[1]);
		}		
		if(tx == px[tx][ty] - 1) {
			path.e(a[0]);
		}
		if(ty == py[tx][ty] + 1) {
			path.e(b[1]);
		}		
		if(ty == py[tx][ty] - 1) {
			path.e(b[0]);
		}
		tie(tx, ty) = mkp(px[tx][ty], py[tx][ty]);
	}
	while(!path.empty()) {
		print(path.top());
		path.pop();
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int T = 1;
//	cin >> T;
	
	while(T --) {
		solve();
	}
	return 0;
}
