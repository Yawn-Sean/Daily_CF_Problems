#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

struct ListNode {
	public:
		explicit ListNode(int n) {
			head = 0;
			tail = 1;

			nxt = vector<int>(n + 5, -1);
			prv = vector<int>(n + 5, -1);
			tag = vector<int>(n + 5, 0);

			nxt[0] = 1;
			prv[1] = 0;

			sz = 0, flg = false, pt = 2;
		}

		bool check(int idx) {return pos.find(idx) != pos.end();}

		int size() {return sz;}

		void insert(int idx) {
			if (flg) {
				prv[pt] = head;
				nxt[pt] = nxt[head];
			}
			else {
				prv[pt] = prv[tail];
				nxt[pt] = tail;
			}

			nxt[prv[pt]] = pt;
			prv[nxt[pt]] = pt;

			tag[pt] = idx;
			pos[idx] = pt;

			pt ++, sz ++;
		}

		void remove(int idx) {
			int p = pos[idx];
			pos.erase(idx);

			prv[nxt[p]] = prv[p];
			nxt[prv[p]] = nxt[p];

			sz --;
		}

		int get_head() {return tag[flg ? prv[tail] : nxt[head]];}

		void reverse() {flg = !flg;}

		void output(int rnd) {
			cout << sz << '\n';

			if (flg) {
				int cur = tail;
				while (prv[cur] != head) {
					cur = prv[cur];
					cout << (tag[cur] ^ rnd) << ' ';
				}
			}
			else {
				int cur = head;
				while (nxt[cur] != tail) {
					cur = nxt[cur];
					cout << (tag[cur] ^ rnd) << ' ';
				}
			}

			cout << '\n';
		}

	private:
		int head, tail, sz, pt;
		bool flg;
		vector<int> nxt, prv, tag;
		unordered_map<int, int> pos;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, rnd = rng();
	cin >> t;

	while (t --) {
		int n, m, k;
		cin >> n >> m >> k;

		vector<int> idxs(n), states(n);

		for (int i = 0; i < n; i ++) {
			cin >> idxs[i] >> states[i];
			idxs[i] ^= rnd;
		}

		vector<int> reverses(n, 0);
		while (k --) {
			int idx; cin >> idx;
			reverses[idx - 1] = 1;
		}

		auto total = ListNode(n);
		auto broken = ListNode(n);

		for (int i = 0; i < n; i ++) {
			if (total.check(idxs[i])) {
				total.remove(idxs[i]);
				if (broken.check(idxs[i])) broken.remove(idxs[i]);
				total.insert(idxs[i]);
				if (!states[i]) broken.insert(idxs[i]);
			}
			else if (total.size() < m) {
				total.insert(idxs[i]);
				if (!states[i]) broken.insert(idxs[i]);
			}
			else if (broken.size()) {
				int idx = broken.get_head();
				total.remove(idx);
				broken.remove(idx);
				total.insert(idxs[i]);
				if (!states[i]) broken.insert(idxs[i]);
			}
			else if (states[i]) {
				int idx = total.get_head();
				total.remove(idx);
				total.insert(idxs[i]);
				if (!states[i]) broken.insert(idxs[i]);
			}

			if (reverses[i]) total.reverse(), broken.reverse();
		}

		total.output(rnd);
	}

	return 0;
}