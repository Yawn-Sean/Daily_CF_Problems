import java.util.*;
import java.io.*;
 //直接写就超时，给AI，说超时了，然后改的这版就过了。。。
public class Main {
    static final int INF = 2_000_000_000;

    static int[] head, next, to, weight;
    static int edgeCount;
 
    static void addEdge(int u, int v, int w) {
        to[edgeCount] = v;
        weight[edgeCount] = w;
        next[edgeCount] = head[u];
        head[u] = edgeCount++;
    }
 
    public static void main(String[] args) throws IOException {
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);
 
        int n = sc.nextInt();
        int m = sc.nextInt();
        head = new int[n];
        Arrays.fill(head, -1);
        next = new int[m * 2];
        to = new int[m * 2];
        weight = new int[m * 2];
        edgeCount = 0;
 
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            int w = sc.nextInt();
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        int[] dis = new int[n];
        Arrays.fill(dis, INF);
        dis[0] = 0;
        PriorityQueue<Long> pq = new PriorityQueue<>();
        pq.add(0L); // (0 << 32) | 0
 
        while (!pq.isEmpty()) {
            long curr = pq.poll();
            int d = (int) (curr >> 32);
            int u = (int) (curr & 0xFFFFFFFFL);
 
            if (d > dis[u]) continue;
 
            for (int i = head[u]; i != -1; i = next[i]) {
                int v = to[i];
                int w = weight[i];
                int maxW = Math.max(d, w);
                if (dis[v] > maxW) {
                    dis[v] = maxW;
                    pq.add(((long) dis[v] << 32) | v);
                }
            }
        }
 
        // Greedy matching logic
        int dCount = sc.nextInt();
        int[] v1 = new int[dCount];
        for (int i = 0; i < dCount; i++) {
            v1[i] = dis[sc.nextInt() - 1];
        }
 
        int[] v2 = new int[dCount];
        for (int i = 0; i < dCount; i++) {
            v2[i] = sc.nextInt();
        }
 
        Arrays.sort(v1);
        Arrays.sort(v2);
 
        int ans = 0;
        int p2 = dCount - 1;
        for (int i = dCount - 1; i >= 0; i--) {
            if (p2 >= 0 && v1[i] <= v2[p2]) {
                ans++;
                p2--;
            }
        }
 
        out.println(ans);
        out.flush();
    }
 
    static class FastReader {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try { st = new StringTokenizer(br.readLine()); }
                catch (IOException e) { return null; }
            }
            return st.nextToken();
        }
        int nextInt() { return Integer.parseInt(next()); }
    }
}
