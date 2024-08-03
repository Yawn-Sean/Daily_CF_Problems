import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;
import java.util.InputMismatchException;

public class B {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    //https://codeforces.com/contest/739/submission/254730546
    public static void solve() {
        int n = sc.ni();
        int[] arr = sc.na(n);
        ArrayList<int[]>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        int[] par = new int[n];
        par[0] = n;
        for (int i = 0; i < n-1; i++) {
            int p = sc.ni();
            int w = sc.ni();
            p--;
            g[p].add(new int[]{i+1, w});
            par[i+1] = p;
        }
        int[] ans = new int[n+1];
        long[] depth = new long[n];
        Deque<Integer> stack = new ArrayDeque<>();
        List<Integer> nodes = new ArrayList<>();
        List<Long> curDepth = new ArrayList<>();

        List<Integer> order = new ArrayList<>();
        stack.push(0);
        while (!stack.isEmpty()) {
            int u = stack.pop();
            if (u >= 0) {
                nodes.add(u);
                curDepth.add(depth[u]);
                int p = bisectLeft(curDepth, depth[u] - arr[u]);
                ans[par[u]] += 1;
                ans[par[nodes.get(p)]] -= 1;
                stack.push(~u);
                order.add(u);
                for (int[] child : g[u]) {
                    stack.push(child[0]);
                    depth[child[0]] = depth[u] + child[1];
                }
            } else {
                nodes.remove(nodes.size() - 1);
                curDepth.remove(curDepth.size() - 1);
            }
        }

        for (int i = order.size() - 1; i >= 0; i--) {
            int u = order.get(i);
            if (u != 0) {
                ans[par[u]] += ans[u];
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append(ans[i]).append(" ");
        }
        out.println(sb);

    }
    public static int bisectLeft(List<Long> list, long value) {
        int low = 0;
        int high = list.size();

        while (low < high) {
            int mid = (low + high) / 2;
            if (value <= list.get(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
}
