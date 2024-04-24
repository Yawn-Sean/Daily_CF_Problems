import java.util.*;
import java.io.*;

public class cf1098A {
    static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException {
        int n = ni();
        int[] p = na();
        List<Integer>[] child = new List[n + 1];
        Arrays.setAll(child, e -> new ArrayList<>());
        for (int i = 2; i <= n; i++) {
            child[p[i - 2]].add(i);
        }
        int[] in = na(); // -1 presents delete   1 ~ n
        int[] s = new int[n + 1];
        for (int i = 1; i < n + 1; i++) {
            s[i] = in[i - 1];
        }
        int[] a = new int[n + 1];
        a[1] = s[1];
        for (int node: child[1]) {
            f(node, s[1], child, s, a);
        }
        long sum = 0;
        for (int i = 1; i < n + 1; i++) {
            if (a[i] == -1) {
                out.println(-1);
                out.flush();
                return;
            }
            sum += a[i];
        }
        out.println(sum);
        out.flush();
    }
    static void f(int node, int prev, List<Integer>[] child, int[] s, int[] a) {
        if (s[node] != -1) {
            a[node] = s[node] - prev;
            for (int next: child[node]) {
                f(next, s[node], child, s, a);
            }
            return;
        }
        // need to fill s[node]
        int min = Integer.MAX_VALUE;
        if (child[node].isEmpty()) min = prev;
        for (int next: child[node]) {
            min = Math.min(min, s[next]);
        }
        if (min < prev) {
            a[node] = -1;
            return;
        }
        a[node] = min - prev;
        s[node] = prev + a[node];
        for (int next: child[node]) {
            f(next, s[node], child, s, a);
        }
    }
    static int ni() throws IOException {
        return Integer.parseInt(sc.readLine());
    }
    static int[] na() throws IOException {
        String[] in = sc.readLine().split(" ");
        int n = in.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            ans[i] = Integer.parseInt(in[i]);
        }
        return ans;
    }
}
