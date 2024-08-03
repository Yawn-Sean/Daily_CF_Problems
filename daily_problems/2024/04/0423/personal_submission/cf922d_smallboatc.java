package cf20240423_922d;

// 一定要看是不是需要开long啊！
import java.io.*;
import java.util.*;

public class Main {
	static final int N = 100010;
	static String[] strs = new String[N];
	static int n;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		n = Integer.parseInt(br.readLine());
		for (int i = 0; i < n; i ++) {
			strs[i] = br.readLine();
		}

		Arrays.sort(strs, 0, n, new Comparator<String>() {
			@Override
			public int compare(String s1, String s2) {
				String ss1 = s1 + s2, ss2 = s2 + s1;
				if (getNoise(ss2) - getNoise(ss1) > 0) return 1;
				else if (getNoise(ss2) - getNoise(ss1) < 0) return -1;
				return 0;
			}
		});

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i ++) {
			sb.append(strs[i]);
		}

		bw.write(getNoise(sb.toString()) + "");
		bw.flush();
	}

	public static long getNoise(String s) {
		char[] cs = s.toCharArray();
		int l = cs.length;
		long cnts = 0, res = 0;
		for (int i = 0; i < l; i ++)
			if (cs[i] == 's') cnts ++;
			else if (cs[i] == 'h') res += cnts;

		return res;
	}
}