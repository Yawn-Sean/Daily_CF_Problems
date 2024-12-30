import java.util.Arrays;
import java.util.Scanner;

public class MaxLengthSubarray {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // 数组长度
        int k = sc.nextInt(); // 预算值

        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt(); // 读取数组元素
        }

        Arrays.sort(nums); // 对数组进行排序

        int l = 0, r = 1, ans = 0, val = 0;
        long cur = 0; // 注意 cur 使用 long 类型，防止溢出

       
        while (l < n) {
            // 扩展右边界，直到不满足条件
            while (r < n && cur + 1L * (nums[r] - nums[r - 1]) * (r - l) <= k) {
                cur += 1L * (nums[r] - nums[r - 1]) * (r - l);
                r++;
            }
            // 更新最大长度和对应的值
            if (r - l > ans) {
                ans = r - l;
                val = nums[r - 1];
            }
            // 收缩左边界
            cur -= 1L * (nums[r - 1] - nums[l]) ; 
            l++;
        }

        // 输出结果
        System.out.println(ans + " " + val);
    }
}
