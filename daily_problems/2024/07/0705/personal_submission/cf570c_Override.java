import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class StringModification {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // 字符串长度
        int q = sc.nextInt(); // 操作次数
        String s = sc.next(); // 输入字符串

        List<Integer> nums = new ArrayList<>();
        nums.add(0); // 添加哨兵，方便处理边界情况
        for (int i = 0; i < n; i++) {
            nums.add(s.charAt(i) == '.' ? 1 : 0); // 将 '.' 转换为 1，其他字符转换为 0
        }
        nums.add(0); // 添加哨兵

        int ans = 0, cur = 0;
        // 计算初始答案
        for (int x : nums) {
            if (x == 1) {
                cur++;
            } else {
                cur = 0;
            }
            if (cur > 1) {
                ans++;
            }
        }

        // 处理操作
        while (q-- > 0) {
            int i = sc.nextInt();
            char c = sc.next().charAt(0);
            int flg = (c == '.') ? 1 : 0;
            // 如果当前字符与要修改的字符不同
            if (flg != nums.get(i)) {
                if (flg == 1) { // 修改为 '.'
                    ans++;
                    ans += nums.get(i - 1) & nums.get(i + 1);
                    ans -= (nums.get(i - 1) ^ 1) & (nums.get(i + 1) ^ 1);
                } else { // 修改为非 '.' 字符
                    ans--;
                    ans -= nums.get(i - 1) & nums.get(i + 1);
                    ans += (nums.get(i - 1) ^ 1) & (nums.get(i + 1) ^ 1);
                }
            }
            nums.set(i, flg); // 更新 nums 数组
            System.out.println(ans); // 输出答案
        }
    }
}
