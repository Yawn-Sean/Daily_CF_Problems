import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static PrintWriter pr = new PrintWriter(System.out);
	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}

	static int n, k, x, cnt, a[], dp[];
	static List<Integer> adj[];
	static void DFS(int v, int p) {
		dp[v] = a[v];
		for (int u : adj[v]) {
			if (u != p) {
				DFS(u, v);
				if (dp[u] != x) dp[v] ^= dp[u];
			}
		}
		if (dp[v] == x) ++cnt;
	}
	static void solve() throws IOException {
		n = readInt();
		k = readInt();
		x = cnt = 0;
		a = new int[n + 1];
		adj = new List[n + 1];
		for (int i = 1; i <= n; ++i) {
			a[i] = readInt();
			x ^= a[i];
			adj[i] = new ArrayList();
		}
		for (int i = 1; i < n; ++i) {
			int u = readInt(), v = readInt();
			adj[u].add(v);
			adj[v].add(u);
		}
		dp = new int[n + 1];
		DFS(1, 0);
		
		if (x == 0 || (k > 2 && cnt > 1)) pr.println("YES");
		else pr.println("NO");
	}
	public static void main(String[] args) throws IOException {
		
		for (int t = readInt(); t > 0; --t) solve();
		pr.close();
	}
}
