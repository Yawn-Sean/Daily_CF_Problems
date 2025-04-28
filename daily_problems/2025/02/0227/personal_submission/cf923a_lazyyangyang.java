import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int M = (int) 1e6;
        int[] primeFactor = new int[M + 1];
        for (int i = 0; i <= M; i++) {
            primeFactor[i] = i;
        }
        // 线性筛板子
        for (int i = 2; i <= M; i++) {
            if (primeFactor[i] == i) { 
                for (int j = i; j <= M; j += i) {
                    primeFactor[j] = i;
                }
            }
        }
        int x2 = sc.nextInt();
        int ans = x2;
        for (int x1 = x2 - primeFactor[x2] + 1; x1 <= x2; x1++) {
            if (primeFactor[x1] != x1) { 
                ans = Math.min(ans, x1 - primeFactor[x1] + 1);
            }
        }
        System.out.println(ans);
    }
}
