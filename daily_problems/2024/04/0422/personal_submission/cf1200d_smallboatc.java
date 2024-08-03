package cf20240422_1200d;

import java.io.*;

public class Main {
	static final int N = 2010;
	static char[][] g = new char[N][N];
	static int[][] a = new int[N][N];
	static int n, k;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String[] s1 = br.readLine().split(" ");
		n = Integer.parseInt(s1[0]); k = Integer.parseInt(s1[1]);
		for (int i = 1; i <= n; i ++) {
			g[i] = (" " + br.readLine()).toCharArray();
		}

		int res = 0;

		for (int i = 1; i <= n; i ++) {
			int rowStart = n + 1, rowEnd = 0;
			for (int j = 1; j <= n; j ++) {
				if (g[i][j] == 'B') {
					rowStart = Math.min(rowStart, j);
					rowEnd = Math.max(rowEnd, j);
				}
			}
			if (rowStart > rowEnd) res ++;
			else if (rowStart + k - 1 >= rowEnd) {
				int x1 = Math.max(1, i - k + 1), y1 = Math.max(1, rowEnd - k + 1);
				int x2 = i, y2 = rowStart;
				insert(x1, y1, x2, y2);
			}
		}

		for (int j = 1; j <= n; j ++) {
			int colStart = n + 1, colEnd = 0;
			for (int i = 1; i <= n; i ++) {
				if (g[i][j] == 'B') {
					colStart = Math.min(colStart, i);
					colEnd = Math.max(colEnd, i);
				}
			}
			if (colStart > colEnd) res ++;
			else if (colStart + k - 1 >= colEnd) {
				int x1 = Math.max(1, colEnd - k + 1), y1 = Math.max(1, j - k + 1);
				int x2 = colStart, y2 = j;
				insert(x1, y1, x2, y2);
			}
		}

		int maxv = 0;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
				maxv = Math.max(maxv, a[i][j]);
			}
		}

		bw.write(res + maxv + "");
		bw.flush();
	}

	public static void insert(int x1, int y1, int x2, int y2) {
		a[x1][y1] += 1;
		a[x1][y2 + 1] -= 1;
		a[x2 + 1][y1] -= 1;
		a[x2 + 1][y2 + 1] += 1;
	}
}
