import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class NumberConcatenation {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // 读取数字个数

        List<Integer> nums = new ArrayList<>();
        List<Integer> cnt = new ArrayList<>();
        for (int i = 0; i <= 10; i++) {
            cnt.add(0); // 初始化 cnt 列表，用于存储不同位数数字的个数
        }
        for (int i = 0; i < n; i++) {
            nums.add(sc.nextInt()); // 读取每个数字
            int len = String.valueOf(nums.get(i)).length(); // 计算数字的位数
            cnt.set(len, cnt.get(len) + 1); // 更新对应位数数字的个数
        }

        int ans = 0;
        int mod = 998244353;

        for (int x : nums) {
            long a = x; // 使用 long 类型防止溢出
            long b = 0;
            long power = 1;

            // 从个位开始遍历数字 x 的每一位
            for (int i = 1; i < 11; i++) {
                b = (b + a % 10 * power) % mod;
                a /= 10;
                // x 在前面的贡献
                ans = (int) ((ans + (a * 10 * power + b) % mod * cnt.get(i) * 10 % mod) % mod);
                // x 在后面的贡献
                ans = (int) ((ans + (a * 100 * power + b) % mod * cnt.get(i) % mod) % mod);
                power = power * 100 % mod;
            }
        }

        System.out.println(ans); // 输出最终结果
    }
}
