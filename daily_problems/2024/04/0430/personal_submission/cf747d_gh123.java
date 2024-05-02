https://codeforces.com/problemset/submission/747/258820542
import java.util.Arrays;
import java.util.Scanner;

public class D747 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int k=sc.nextInt();
        int[]d=new int[n];
        for (int i = 0; i < n; i++) {
            d[i]=sc.nextInt();
        }
        int cnt=0;
        for (int i = 0; i < n; i++) {
            if(d[i]<0) cnt++;
        }
        if(cnt>k)System.out.println(-1);
        else{
            int extra=k-cnt;
            int cur=0;
            int[]b=new int[n];
            int j=0;
            boolean start=false;
           for (int i = 0; i < n; i++) {
            if(d[i]<0){
                b[j]=cur;
                cur=0;
                j++;
                start=true;
            }else if(start){
                cur++;
            }
           }
           Arrays.sort(b);
           for (int i = 0; i < n; i++) {
            if(b[i]<=extra){
                extra-=b[i];
                b[i]=0;
            }else{
                break;
            }
           }
           int change=0;
           for (int i = 0; i < n; i++) {
            if(b[i]>0){
                change+=2;
            }
           }
           if(start) change++;
           if(cur>extra) change++;
           System.out.println(change);
        }
        sc.close();
    }
}
