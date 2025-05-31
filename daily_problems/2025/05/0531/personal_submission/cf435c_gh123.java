//https://codeforces.com/problemset/submission/435/322119773
import java.util.Arrays;
import java.util.Scanner;
//构造题，众多软肋之一。。。
public class C435 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int sum=0;
        int mx=0;
        int mn=0;
        int[]a=new int[n];
        int cur=0;
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextInt();
            sum+=a[i];
            if(i%2==0){
                cur+=a[i];
            }else{
                cur-=a[i];
            }
            mx=Math.max(cur, mx);
            mn=Math.min(cur, mn);
        }
        char[][]cs=new char[mx-mn][sum];
        for (int i = 0; i < cs.length; i++) {
            Arrays.fill(cs[i], ' ');
        }
        int x=cs.length-1-Math.abs(mn);
        int y=0;
        for (int i = 0; i < n; i++) {
            if(i%2==0){
                for (int j = 0; j < a[i]; j++) {
                    cs[x-j][y+j]='/';
                }
                y+=a[i];
                x-=a[i]-1;
            }else{
                for (int j = 0; j < a[i]; j++) {
                    cs[x+j][y+j]='\\';
                }
                y+=a[i];
                x+=a[i]-1;
            }
        }
        for (int i = 0; i < cs.length; i++) {
            System.out.println(new String(cs[i]));
        }
    }
}
