//相切--半径之和等于距离的平方根
//+r -r 看成连通图的二分着色问题
import java.util.*;

public class i1949 {
    static final int MAXN = 1005;
    static int n;
    static int[] x = new int[MAXN];
    static int[] y = new int[MAXN];
    static int[] r = new int[MAXN];
    static List<Integer>[] e = new ArrayList[MAXN];
    //注意这里的语法 List<int[]>[] e  常用于邻接表的实现 List<int[]> e
    static int f;
    static int[] cnt = new int[2];
    static int[] vis = new int[MAXN];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
            r[i] = sc.nextInt();
        }
        for (int i = 1; i <= n; i++) {
            e[i] = new ArrayList<>();
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (sq(x[i] - x[j]) + sq(y[i] - y[j]) <= sq(r[i] + r[j])) {
                    e[i].add(j);
                    e[j].add(i);
                }
            }
        }
        Arrays.fill(vis, -1);
        //遍历从 1 到 n 的所有节点
        for (int i = 1; i <= n; i++) {
            //vis[i] 数组用于记录每个节点的访问状态
            if (vis[i] == -1) {
                f = 1;//f 是一个标志变量，用于判断当前子图是否满足条件
                cnt[0] = cnt[1] = 0;//cnt 是一个计数数组，cnt[0] 和 cnt[1] 分别记录两种颜色的节点数
                dfs(i, 0);
                //如果 f 仍然为 1，表示当前子图满足条件。
                //如果 cnt[0] 不等于 cnt[1]，表示两种颜色的节点数不相等，则输出 "YES" 并终止程序。
                if (f == 1 && cnt[0] != cnt[1]) {
                    System.out.println("YES");
                    return;
                }
            }
        }
        System.out.println("NO");
    }

    static long sq(long x) {
        return x * x;
    }

    static void dfs(int p, int w) {
        /*如果 vis[p] 等于 w，表示当前节点的颜色与预期一致，f 保持不变。
        如果 vis[p] 不等于 w，表示颜色冲突，f 被置为 0。
        然后返回，不再继续递归。*/
        if (vis[p] != -1) {
            f &= (vis[p] == w ? 1 : 0);
            return;
        }
        //将节点 p 标记为颜色 w。
        //增加颜色 w 的节点计数。
        vis[p] = w;
        cnt[w]++;
        //对于节点 p 的每个相邻节点 x，递归调用 dfs 函数，并将颜色设为 1 - w（即与当前节点颜色相反）
        for (int x : e[p]) {
            dfs(x, 1 - w);
        }
    }
}
