#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	i64 n, b;
	cin >> n >> b;
	queue<i64> q;
	for (int i = 0; i < n; i++) {
		i64 t, d;
		cin >> t >> d;
		// 任务进入的时间为t
		// 实际上它的开始时间 取决于前面排队的1..b-1个任务之后再开始
		// 去掉在当前时刻已经结束的任务之后  
		// 如果在这个任务进去之前，队列已满就直接跳过
		// 否则就把这个任务放入队列里面模拟哦
		while (!q.empty() and q.front() <= t) {
			q.pop();
		}
		if ((i64)q.size() > b) {
			cout << -1 << ' ';
		} else {
			if (!q.empty()) {
				t = q.back();
			}
			cout << t + d << ' ';
			q.push(t + d);
		}
	}
	return 0;
}
