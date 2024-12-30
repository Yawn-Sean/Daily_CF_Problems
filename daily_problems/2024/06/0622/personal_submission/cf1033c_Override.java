import java.util.*;

public class c1033 {
    static final int MAXN = 100001;
    static int[] arr = new int[MAXN]; // 格子中的值
    static int[] pos = new int[MAXN]; // 值为i的格子编号为pos[i]
    static int[] status = new int[MAXN]; // 格子是必胜(1)还是必败(0)

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // 读取格子的数量

        // 读取每个格子的值
        for (int i = 1; i <= n; i++) {
            arr[i] = scanner.nextInt();
        }

        // 初始化pos数组，记录值为i的格子编号
        for (int i = 1; i <= n; i++) {
            pos[arr[i]] = i;
        }

        // 从最后一个格子开始，逆序遍历
        for (int i = n; i >= 1; i--) {
            int u = pos[i]; // 当前格子的编号
            status[u] = 0; // 初始化当前格子为必败状态
            int v = u; // 从当前格子开始

            // 只枚举距离是倍数的格子
            while (v - arr[u] > 0) {
                v -= arr[u];
            }

            // 遍历所有能从当前格子到达的格子
            for (; v <= n; v += arr[u]) {
                // 如果当前格子的步长大于目标格子的步长，则跳过
                if (!(arr[u] < arr[v])) {
                    continue;
                }

                // 如果发现能到达必败状态，说明当前状态一定是必胜的
                if (status[v] == 0) {
                    status[u] = 1; // 设置当前状态为必胜
                    break; // 找到必胜状态，跳出循环
                }
            }
        }

        // 输出结果
        for (int i = 1; i <= n; i++) {
            if (status[i] == 1) {
                System.out.print('A');
            } else {
                System.out.print('B');
            }
        }
        System.out.println();
    }
}
