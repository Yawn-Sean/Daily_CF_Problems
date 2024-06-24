import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // 读取数组长度

        List<Integer> nums = new ArrayList<>(); // 存储输入数组
        for (int i = 0; i < n; i++) {
            nums.add(scanner.nextInt()); // 读取数组元素
        }

        // 遍历所有可能的最高位
        for (int i = 29; i >= 0; i--) {
            List<Integer> ans = new ArrayList<>(); // 存储满足条件的元素
            int msk = (1 << i) - 1; // 初始化掩码，用来判断所有元素的最高位是否一致
            for (int x : nums) {
                // 如果元素的第 i 位为 1，则添加到 ans 列表中，并将掩码与该元素进行与运算
                if ((x >> i & 1) == 1) { 
                    ans.add(x);
                    msk &= x;
                }
            }
            // 如果掩码为 0，则表示所有元素的最高位都一致，输出结果并结束程序
            if (msk == 0) { 
                System.out.println(ans.size());
                for (int x : ans) {
                    System.out.print(x + " ");
                }
                return;
            }
        }

        // 如果没有找到满足条件的元素，则输出 0
        System.out.println(0);
    }
}
