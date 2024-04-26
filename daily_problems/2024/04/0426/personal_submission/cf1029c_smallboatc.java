package cf20240426_1029c;

import java.util.*;

public class Main {
	static final int N = 300010;
	static int[] l = new int[N], r = new int[N];
	static int[] preL = new int[N], sufL = new int[N];
	static int[] preR = new int[N], sufR = new int[N];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		for (int i = 0; i < n; i ++) {
			l[i] = sc.nextInt();
			r[i] = sc.nextInt();
		}

		int minv = Integer.MAX_VALUE, maxv = Integer.MIN_VALUE;
		for (int i = 0; i < n; i ++) {
			preL[i] = maxv;
			preR[i] = minv;
			maxv = Math.max(maxv, l[i]);
			minv = Math.min(minv, r[i]);
		}

		minv = Integer.MAX_VALUE; maxv = Integer.MIN_VALUE;
		for (int i = n - 1; i >= 0; i --) {
			sufL[i] = maxv;
			sufR[i] = minv;
			maxv = Math.max(maxv, l[i]);
			minv = Math.min(minv, r[i]);
		}

		int res = 0;
		// 画图就好理解
		for (int i = 0; i < n; i ++) {
			res = Math.max(res, Math.min(preR[i], sufR[i]) - Math.max(preL[i], sufL[i]));
		}

		System.out.println(res);
	}
}
