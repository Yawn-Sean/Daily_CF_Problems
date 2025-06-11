https://codeforces.com/problemset/submission/1671/263422867
import java.util.Scanner;

public class D1671 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            int x=sc.nextInt();
            int[]a=new int[n];
            int max=Integer.MIN_VALUE;
            int min=Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                a[i]=sc.nextInt();
                max=Math.max(max, a[i]);
                min=Math.min(min, a[i]);
            }
            long sum=0;
            for (int i = 1; i < n; i++) {
                sum+=Math.abs(a[i]-a[i-1]);
            }
            sum+=Math.min(2*(min-1), Math.min(a[n-1]-1, a[0]-1));
            if(x>max){
                sum+=Math.min(2*(x-max), x-Math.max(a[n-1], a[0]));
            }
            System.out.println(sum);
        }
        sc.close();
    }
}
