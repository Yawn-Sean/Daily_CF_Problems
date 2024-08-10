import java.util.Scanner;

public class MinSegment {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // 读取数组长度 n
        int m = sc.nextInt(); //  m

        int x = Integer.MAX_VALUE; 
        
        for (int i = 0; i < m; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            x = Math.min(x, r - l + 1);
        }

        System.out.println(x); // 输出最小长度

        // 构造并输出数组
        for (int i = 1; i <= n; i++) {
            System.out.print(i % x + " "); 
        }
    }
}
