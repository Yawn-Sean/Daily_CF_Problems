https://codeforces.com/problemset/submission/1168/259076249
import java.util.Scanner;
//二分, 左闭右开区间
public class A1168 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int[]a=new int[n];
        for (int i = 0; i < a.length; i++) {
            a[i]=sc.nextInt();
        }
        sc.close();
        int l=0,r=m;
        while (l<r) {
            int mid=(l+r)/2;
            if(valid(mid, a, n, m)){
                r=mid;
            }else l=mid+1;
        }
        System.out.println(l);
    }
    public static boolean valid(int mid,int[]a,int n,int m){
        int pre=0;
        for (int i = 0; i < n; i++) {
            if(a[i]>pre&&a[i]+mid-m<pre){
                pre=a[i];
            }
            if(a[i]<pre&&a[i]+mid<pre) return false;
        }
        return true;
    }    
}
