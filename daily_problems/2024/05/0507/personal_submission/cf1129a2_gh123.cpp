https://codeforces.com/problemset/submission/1129/259838346
import java.util.Arrays;
import java.util.Scanner;

public class A1129 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int[]cnt=new int[n];
        int[]min=new int[n];
        Arrays.fill(min, Integer.MAX_VALUE);
        for (int i = 0; i < m; i++) {
            int l=sc.nextInt();
            int r=sc.nextInt();
            cnt[l-1]++;
            min[l-1]=Math.min(min[l-1], (r-l+n)%n);
        }
        for (int i = 0; i < n; i++) {
            int max=Integer.MIN_VALUE;
            for (int j = 0; j < n; j++) {
                if(cnt[j]==0) continue;
                max=Math.max(max, (cnt[j]-1)*n+(j-i+n)%n + min[j]);
            }
            System.out.print(max+" ");
        }
        sc.close();
    }
}
