import java.util.*;

public class cf1210b_yuxue_r {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 快速输入输出
        int n = scanner.nextInt();

        List<Long> nums1 = new ArrayList<>(n);
        List<Integer> nums2 = new ArrayList<>(n);
        Map<Long, Integer> mp = new HashMap<>();

        for (int i = 0; i < n; i++) {
            long x = scanner.nextLong();
            nums1.add(x);
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }

        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            nums2.add(x);
        }

        int[] used = new int[n];
        long ans = 0;

        for (Map.Entry<Long, Integer> entry : mp.entrySet()) {
            long k = entry.getKey();
            int v = entry.getValue();

            if (v > 1) {
                for (int i = 0; i < n; i++) {
                    if (used[i] == 0 && (nums1.get(i) & k) == nums1.get(i)) {
                        used[i] = 1;
                        ans += nums2.get(i);
                    }
                }
            }
        }

        System.out.println(ans);
    }
}
