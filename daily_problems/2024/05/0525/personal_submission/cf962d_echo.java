import java.io.*;
import java.util.*;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long[] nums = new long[n];
        String[] s = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            nums[i] = Long.parseLong(s[i]);
        }

        getAns(nums);
    }

    private static void getAns(long[] nums) {
        int n = nums.length, cnt = 0;
        Map<Long, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            if (!map.containsKey(nums[i])) {
                map.put(nums[i], i);
            } else {
                nums[map.get(nums[i])] = -1;
                cnt++;
                map.remove(nums[i]);
                nums[i] *= 2;
                i--;
            }
        }

        System.out.println(n - cnt);

        for (long num : nums) {
            if (num != -1) {
                System.out.print(num + " ");
            }
        }
        System.out.println();
    }

}
