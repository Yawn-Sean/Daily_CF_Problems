package cf20240422_645d;

import java.util.*;

public class Main {
	static final int N = 100010;
	static int[][] edges = new int[N][2];
	static int[] h = new int[N], e = new int[N], ne = new int[N], d = new int[N];
	static int n, m, idx;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		n = sc.nextInt(); m = sc.nextInt();
		for (int i = 0; i < m; i ++) {
			int a = sc.nextInt(), b = sc.nextInt();
			edges[i] = new int[] {a, b};
		}

		int l = 0, r = m + 1;
		while (l < r) {
			int mid = l + r >> 1;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		System.out.println(l <= m ? l : -1);
	}
	public static boolean check(int mid) {
		Arrays.fill(h, -1); Arrays.fill(e, 0);
		Arrays.fill(ne, 0); Arrays.fill(d, 0);
		idx = 0;
		HashSet<Integer> set = new HashSet<>();
		for (int i = 0; i < mid; i ++) {
			int a = edges[i][0], b = edges[i][1];
			add(a, b);
			set.add(a); set.add(b);
		}
		if (set.size() != n) return false;
		Deque<Integer> q = new ArrayDeque<>();
		for (int i = 1; i <= n; i ++) {
			if (d[i] == 0) {
				q.addLast(i);
			}
			if (q.size() > 1) return false;
		}

		int cnt = 0;
		while (!q.isEmpty()) {
			int t = q.pollFirst();
			cnt ++;
			for (int i = h[t]; i != -1; i = ne[i]) {
				int j = e[i];
				d[j] --;
				if (d[j] == 0) {
					q.addLast(j);
				}
			}
			if (q.size() > 1) return false;
		}

		return cnt == n;
	}

	public static void add(int a, int b) {
		e[idx] = b;
		d[b] ++;
		ne[idx] = h[a];
		h[a] = idx ++;
	}
}
