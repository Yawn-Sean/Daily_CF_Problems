package cf20240427_573b;

import java.util.*;

public class Main {
	static final int N = 100010;
	static int[] h = new int[N], minTime = new int[N];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for (int i = 1; i <= n; i ++) h[i] = sc.nextInt();

		minTime[1] = 1;
		for (int i = 2; i <= n; i ++) minTime[i] = Math.min(minTime[i - 1] + 1, h[i]);

		minTime[n] = 1;
		int res = 1;
		for (int i = n - 1; i >= 1; i --) {
			minTime[i] = Math.min(minTime[i], minTime[i + 1] + 1);
			res = Math.max(res, minTime[i]);
		}
		System.out.println(res);
	}
}