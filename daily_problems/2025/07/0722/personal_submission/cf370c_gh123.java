//https://codeforces.com/problemset/submission/370/330213866
import java.util.Arrays;
import java.util.Scanner;

public class C370 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int[]left=new int[n];
        int[]right=new int[n];
        int[]cnt=new int[m+1];
        int max=0;
        for (int i = 0; i < n; i++) {
            int x=sc.nextInt();
            cnt[x]++;
            max=Math.max(cnt[x], max);
            left[i]=x;
        }   
        sc.close();
        Arrays.sort(left);
        for (int i = 0; i < n; i++) {
            right[i]=left[(i+max)%n];
        }
        int ans=0;
        for (int i = 0; i < n; i++) {
            if(left[i]!=right[i])
            ans++;
        }
        System.out.println(ans);
        for (int i = 0; i < n; i++) {
            System.out.println(left[i]+" "+right[i]);
        }
    }
}
