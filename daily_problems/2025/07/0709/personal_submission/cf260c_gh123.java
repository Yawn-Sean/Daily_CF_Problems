//https://codeforces.com/problemset/submission/260/328176145
import java.util.Scanner;

public class C260 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int idx=sc.nextInt()-1;
        long[]a=new long[n];
        long min=Long.MAX_VALUE;
        for (int i = 0; i < a.length; i++) {
            a[i]=sc.nextLong();
            min=Math.min(min, a[i]);
        }
        sc.close();
        for (int i = 0; i < a.length; i++) {
            a[i]-=min;
        }
        min*=n;
        while (a[idx]>0) {
            a[idx]-=1;
            min++;
            idx--;
            if(idx<0){
                idx+=n;
            }
        }
        a[idx]=min;
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i]+" ");
        }
    }
}
