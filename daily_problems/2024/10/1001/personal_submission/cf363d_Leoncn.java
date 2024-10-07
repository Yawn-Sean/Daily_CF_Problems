import java.util.Arrays;
import java.util.Scanner;

public class cf363d_Leoncn {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int a = sc.nextInt();
        int[] nums1 = new int[n];
        for (int i = 0; i < n; i++) {
            nums1[i] = sc.nextInt();
        }
        int[] nums2 = new int[m];
        for (int i = 0; i < m; i++) {
            nums2[i] = sc.nextInt();
        }
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int l = 0, r = Math.min(n,m);
        while (l<=r){
            int mid = (l + r) / 2;
            int cur = 0;
            boolean flg = true;
            for (int i = 0; i < mid; i ++) {
                cur += Math.max(nums2[i] - nums1[n - mid + i], 0);
                if (cur > a) {
                    flg = false;
                    break;
                }
            }
            if (flg) {l = mid + 1;}
            else {r = mid - 1;}
        }
        int ans = -a;
        for (int i = 0; i < r; i ++)
            ans += nums2[i];
        System.out.println(r + " " + Math.max(0, ans));

    }
}
