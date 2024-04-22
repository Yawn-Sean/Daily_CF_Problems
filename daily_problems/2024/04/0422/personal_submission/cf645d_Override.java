//使用拓扑排序查看是否唯一序列  即入度为0的点
//这里二分遍历方案数  需要花时间消化一下
import java.io.*;
import java.util.*;

public class d645 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }
    static final int N = 200010;
    static int n, m;
    static int[] U = new int[N];
    static int[] V = new int[N];
    static int[] in = new int[N];
    static int[] vis = new int[N];
    static List<Integer>[] e = new List[N];

    static boolean check(int x) {
        Queue<Integer> q = new LinkedList<>();
        Arrays.fill(in, 0);
        Arrays.fill(vis, 0);
        for (int i = 1; i <= n; i++) e[i] = new ArrayList<>();
        for (int i = 1; i <= x; i++) {
            in[V[i]]++;
            e[U[i]].add(V[i]);
        }
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) {
                vis[i] = 1;
                q.add(i);
            }
        }
        while (!q.isEmpty()) {
            if (q.size() > 1) return false;
            int u = q.poll();
            for (int v : e[u]) {
                in[v]--;
                if (in[v] == 0 && vis[v] == 0) {
                    vis[v] = 1;
                    q.add(v);
                }
            }
        }
        return true;
    }

    public static void main(String[] args) throws Exception{
        n = nextInt();
        m = nextInt();
        for (int i = 1; i <= m; i++) {
            U[i] = nextInt();
            V[i] = nextInt();
        }

        int l = 1, r = m, ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (ans == 0) System.out.println(-1);
        else System.out.println(ans);
    }
}
