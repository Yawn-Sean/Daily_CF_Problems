
//树形dp 待补
import java.util.*;

public class g1833 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt(); // 读取测试用例数量

        while (t-- > 0) {
            int n = sc.nextInt(); // 读取节点数量

            List<Integer> us = new ArrayList<>();
            List<Integer> vs = new ArrayList<>();
            List<List<Integer>> path = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                path.add(new ArrayList<>());
            }

            // 读取边信息，构建邻接表
            for (int i = 0; i < n - 1; i++) {
                int u = sc.nextInt() - 1;
                int v = sc.nextInt() - 1;
                us.add(u);
                vs.add(v);
                path.get(u).add(i);
                path.get(v).add(i);
            }

            int[] size = new int[n];
            Arrays.fill(size, 1);
            List<Integer> ans = new ArrayList<>();

            // 深度优先搜索，查找需要删除的边
            dfs(0, -1, path, us, vs, size, ans);

            // 判断是否可以分割成大小为 3 的连通块
            if ((ans.size() + 1) * 3 == n) {
                System.out.println(ans.size());
                for (int x : ans) {
                    System.out.print((x + 1) + " ");
                }
                System.out.println();
            } else {
                System.out.println("-1");
            }
        }
    }

    // 深度优先搜索函数
    private static void dfs(int u, int p, List<List<Integer>> path, List<Integer> us, List<Integer> vs, int[] size, List<Integer> ans) {
        for (int i : path.get(u)) {
            if (i == p) {
                continue;
            }
            int v = us.get(i) ^ vs.get(i) ^ u; // 计算邻居节点
            dfs(v, i, path, us, vs, size, ans); // 递归处理子树
            if (size[v] == 0) {
                ans.add(i); // 如果子树大小为 0，则需要删除连接 u 和 v 的边
            }
            size[u] += size[v]; // 更新当前节点子树大小
        }
        if (size[u] == 3) {
            size[u] = 0; // 如果当前节点子树大小为 3，则标记为已分割
        }
    }
}
