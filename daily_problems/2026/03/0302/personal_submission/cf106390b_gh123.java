import java.io.*;
import java.util.*;
//java就超时，问了AI，改成链式前向星才过了。。。
public class Main {
    static int[] head, to, next, weight, dis0;
    static long[] dis1, minDis;
    static int edgeCount;
    static final long INF = (long) 1e18;

    static void addEdge(int u, int v, int w) {
        to[edgeCount] = v;
        weight[edgeCount] = w;
        next[edgeCount] = head[u];
        head[u] = edgeCount++;
    }

    public static void main(String[] args) throws IOException {
        FastReader fr = new FastReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int t = fr.nextInt();
        while (t-- > 0) {
            int n = fr.nextInt();
            head = new int[n];
            Arrays.fill(head, -1);
            to = new int[2 * n];
            next = new int[2 * n];
            weight = new int[2 * n];
            edgeCount = 0;

            for (int i = 0; i < n - 1; i++) {
                int u = fr.nextInt() - 1;
                int v = fr.nextInt() - 1;
                int w = fr.nextInt();
                addEdge(u, v, w);
                addEdge(v, u, w);
            }

            dis0 = new int[n];
            dis1 = new long[n];
            minDis = new long[n];
            Arrays.fill(minDis, INF);

            iterativeDFS1(n);
            iterativeDFS2(n);

            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                sb.append(dis1[i]).append(i == n - 1 ? "" : " ");
            }
            out.println(sb);
        }
        out.flush();
        out.close();
    }

    static void iterativeDFS1(int n) {
        Stack<Integer> stack = new Stack<>();
        Stack<Integer> parent = new Stack<>();
        stack.push(0);
        parent.push(-1);
        dis0[0] = 0;
        dis1[0] = 0;

        while (!stack.isEmpty()) {
            int u = stack.pop();
            int p = parent.pop();
            minDis[dis0[u]] = Math.min(minDis[dis0[u]], dis1[u]);

            for (int i = head[u]; i != -1; i = next[i]) {
                int v = to[i];
                if (v != p) {
                    dis0[v] = dis0[u] + 1;
                    dis1[v] = dis1[u] + weight[i];
                    stack.push(v);
                    parent.push(u);
                }
            }
        }
    }

    static void iterativeDFS2(int n) {
        Stack<Integer> stack = new Stack<>();
        Stack<Integer> parent = new Stack<>();
        stack.push(0);
        parent.push(-1);

        while (!stack.isEmpty()) {
            int u = stack.pop();
            int p = parent.pop();
            dis1[u] = Math.min(dis1[u], minDis[dis0[u]]);

            for (int i = head[u]; i != -1; i = next[i]) {
                int v = to[i];
                if (v != p) {
                    dis1[v] = dis1[u] + weight[i];
                    stack.push(v);
                    parent.push(u);
                }
            }
        }
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
        public FastReader(InputStream in) { br = new BufferedReader(new InputStreamReader(in)); }
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try { st = new StringTokenizer(br.readLine()); } catch (IOException e) {}
            }
            return st.nextToken();
        }
        int nextInt() { return Integer.parseInt(next()); }
    }
}
