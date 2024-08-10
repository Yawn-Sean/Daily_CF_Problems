import java.util.*;
import java.io.*;

public class Main {

    static void solve() {
        int n = sc.nextInt(), k = sc.nextInt();
        long sum = (long) k * (k + 1) / 2;
        if (sum > n) {
            out.println("NO");
            return;
        }
        long[] arr = new long[k];
        for (int i = 0; i < k; i++) {
            arr[i] = i + 1;
        }
        long rest = n - sum;
        long m = rest / k;
        rest %= k;
        for (int i = 0; i < k; i++) {
            arr[i] += m;
        }
        int i = k - 1;
        while (rest-- > 0) {
            arr[i--]++;
        }
        if (k > 2 && arr[1] > arr[0] * 2) {
            arr[1]--;
            arr[k - 1]++;
        }
        for (i = 1; i < k; i++) {
            if (arr[i] > arr[i - 1] * 2) {
                out.println("NO");
                return;
            }
        }
        out.println("YES");
        for (long v : arr) {
            out.print(v + " ");
        }
        out.println();
    }
  
}
