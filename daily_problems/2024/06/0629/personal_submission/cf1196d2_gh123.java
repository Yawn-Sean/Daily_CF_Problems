//https://codeforces.com/problemset/submission/1196/267937259
import java.util.Scanner;
//dp还不会。。。

public class D1196 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int q=sc.nextInt();
        StringBuilder sb=new StringBuilder("RGB");
        for (int i = 0; i < 100000; i++) {
            sb.append("RGB");
        }
        String compare1=sb.substring(0);
        String compare2=sb.substring(1);
        String compare3=sb.substring(2);
        while (q-->0) {
            int n=sc.nextInt();
            int k=sc.nextInt();
            String s=sc.next();
            int ans=Math.min(check(s,compare1,k),Math.min(check(s,compare2, k),check(s,compare3,k)));
            System.out.println(ans);
        }
        sc.close();
    }
    public static int check(String str,String compare,int k){
        int[]a=new int[str.length()+1];
        for (int i = 1; i <=str.length(); i++) {
            a[i]=a[i-1];
            if(str.charAt(i-1)!=compare.charAt(i-1)){
                a[i]++;
            }
        }
        int min=Integer.MAX_VALUE;
        for (int i = k; i <=str.length(); i++) {
            min=Math.min(a[i]-a[i-k], min);
        }
        return min==Integer.MAX_VALUE?0:min;
    }
}
