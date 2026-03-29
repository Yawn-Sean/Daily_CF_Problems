import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        int w = Integer.parseInt(s[1]);

        int[] nums = new int[n];
        s = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(s[i]);
        }

        Arrays.sort(nums);
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (2L * i - (n - 1)) * nums[i];
        }

        double res = (double) ans * 2 / n + w;
        System.out.printf("%.15f\n", res);
    }
}
