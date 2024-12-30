//https://codeforces.com/problemset/submission/1151/266646259
import java.util.Arrays;
import java.util.Scanner;

public class D1151 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        long[]diff=new long[n];
        long sum=0;
        for (int i = 0; i < n; i++) {
            long a=sc.nextLong();
            long b=sc.nextLong();
            diff[i]=a-b;
            sum+=b*n-a;
        }
        Arrays.sort(diff);
        for (int i = 0; i < n; i++) {
            sum+=diff[i]*(n-i);
        }
        System.out.println(sum);
        sc.close();
    }
}
