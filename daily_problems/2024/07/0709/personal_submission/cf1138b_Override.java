import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // 读取字符串长度
        String s1 = scanner.next(); // 读取第一个字符串
        String s2 = scanner.next(); // 读取第二个字符串

        List<List<Integer>> tmp = new ArrayList<>(); // 存储三种情况的索引
        for (int i = 0; i < 3; i++) {
            tmp.add(new ArrayList<>());
        }
        int cnt = 0; // 统计 s1 中 '1' 的数量

        // 遍历字符串，将每个字符的索引分类到对应的情况中
        for (int i = 0; i < n; ) {
            if (s1.charAt(i) == '1') {
                cnt++;
            }
            // s1[i] + s2[i] 的值代表了三种情况：0，1，2
            tmp.get(s1.charAt(i) - '0' + s2.charAt(i) - '0').add(++i); 
        }

        // 遍历所有可能的 i2 值
        for (int i2 = 0; i2 <= tmp.get(2).size(); i2++) {
            // 计算 i1 和 i0 的值
            int i1 = cnt - i2 * 2; 
            int i0 = n / 2 - i1 - i2;
            // 判断是否满足条件
            if (i0 >= 0 && i0 <= tmp.get(0).size() && i1 >= 0 && i1 <= tmp.get(1).size()) {
                // 输出结果
                for (int i = i0; i < tmp.get(0).size(); i++) {
                    System.out.print(tmp.get(0).get(i) + " ");
                }
                for (int i = i1; i < tmp.get(1).size(); i++) {
                    System.out.print(tmp.get(1).get(i) + " ");
                }
                for (int i = i2; i < tmp.get(2).size(); i++) {
                    System.out.print(tmp.get(2).get(i) + " ");
                }
                return; // 找到结果，结束程序
            }
        }

        // 如果没有找到满足条件的结果，则输出 -1
        System.out.println(-1);
    }
}
