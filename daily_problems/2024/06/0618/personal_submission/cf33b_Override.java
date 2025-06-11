import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s1 = scanner.next(); // 读取第一个字符串
        String s2 = scanner.next(); // 读取第二个字符串

        if (s1.length() != s2.length()) { // 检查字符串长度是否相等
            System.out.println("-1"); // 输出-1表示无法计算
            return;
        }

        int inf = 100000000; // 定义一个无穷大的值
        int n = scanner.nextInt(); // 读取字符之间的距离数量
        int[][] dist = new int[26][26]; // 初始化距离矩阵

        for (int i = 0; i < 26; i++) { // 初始化距离矩阵，对角线为0，其余为无穷大
            Arrays.fill(dist[i], inf);
            dist[i][i] = 0;
        }

        while (n-- > 0) { // 读取字符之间的距离信息并更新距离矩阵
            char c1 = scanner.next().charAt(0);
            char c2 = scanner.next().charAt(0);
            int d = scanner.nextInt();
            int x1 = c1 - 'a';
            int x2 = c2 - 'a';
            dist[x1][x2] = Math.min(dist[x1][x2], d);
        }

        // 使用Floyd-Warshall算法计算任意两个字符之间的最短距离
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {//qidian
                for (int k = 0; k < 26; k++) {//zhongdian
                    dist[j][k] = Math.min(dist[j][k], dist[j][i] + dist[i][k]);
                }
            }
        }

        int[][] ans = new int[26][26]; // 存储最短路径和
        int[][] chars = new int[26][26]; // 存储对应字符

        // 计算每对字符之间的最短路径和对应字符
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                ans[i][j] = inf;
                chars[i][j] = -1;
                for (int k = 0; k < 26; k++) {
                    if (dist[i][k] + dist[j][k] < ans[i][j]) {
                        ans[i][j] = dist[i][k] + dist[j][k];
                        chars[i][j] = k;
                    }
                }
            }
        }

        int len = s1.length(); // 字符串长度
        int res = 0; // 最终的最短路径和
        StringBuilder finalStr = new StringBuilder(); // 生成的最终字符串

        // 遍历输入的两个字符串，根据最短路径矩阵和对应字符矩阵计算最短路径和生成最终的字符串
        for (int i = 0; i < len; i++) {
            int x = s1.charAt(i) - 'a';
            int y = s2.charAt(i) - 'a';
            if (chars[x][y] == -1) {
                System.out.println("-1");
                return;
            }
            res += ans[x][y];
            finalStr.append((char) (chars[x][y] + 'a'));
        }

        System.out.println(res); // 输出最终的最短路径和
        System.out.println(finalStr.toString()); // 输出生成的最终字符串
    }
}
