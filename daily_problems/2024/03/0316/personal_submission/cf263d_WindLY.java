import java.util.*;
import java.io.*;
public class cf263d_WindLY {
    static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    static int idx = 0; // 路径数组下标&长度
    public static void main(String[] args) throws IOException {
        int[] in = na();
        int n = in[0], m = in[1], k = in[2];
        // 建邻接表
        List<Integer>[] nexts = new List[n + 1];
        Arrays.setAll(nexts, e -> new ArrayList<>());
        for (int i = 0; i < m; i++) {
            in = na();
            nexts[in[0]].add(in[1]);
            nexts[in[1]].add(in[0]);
        }

        int[] dis = new int[n + 1]; // 存走过的长度
        Arrays.fill(dis, 2, n + 1, -1); // 初始化
        int[] ls = new int[n + 1]; // 用于记录路径
        StringBuilder sb = new StringBuilder();
        f(1, nexts, ls, k, dis, sb); // 1开始dfs

        out.println(idx);
        out.println(sb);
        out.flush();
    }
    static void f(int node, List<Integer>[] nexts, int[] ls, int k, int[] dis, StringBuilder sb) {
        ls[idx++] = node;
        for (int next: nexts[node]) {
            if (dis[next] > -1) {
                if (dis[node] - dis[next] >= k) { // 遇到遍历过的邻居，且可以构成大于k+1长度的环，直接记录答案返回
                    int l = dis[next];
                    for (int i = l; i < idx; i++) { // 答案为遍历过的邻居开始 到 当前节点
                        sb.append(ls[i]);
                        sb.append(" ");
                    }
                    idx = idx - l; // 更新答案长度，而后直接返回
                    return;
                } else continue;
            }
            dis[next] = dis[node] + 1;
            f(next, nexts, ls, k, dis, sb);
            if (sb.length() > 0) return; // 答案已经计算，结束递归
        }
        // 由于每个点有k个邻居，所以回溯前 答案一定已经计算，最坏为遍历所有点，无需回溯
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
