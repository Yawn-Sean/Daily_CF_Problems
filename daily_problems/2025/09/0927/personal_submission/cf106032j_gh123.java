import java.util.Arrays;
import java.util.Scanner;
//太难了。。。
public class J106032{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        int inf=(int)1e9;
        while (t-->0) {
            int n=sc.nextInt();
            int m=sc.nextInt();
            int q=sc.nextInt();
            int[]a=new int[n];
            int[]cnt=new int[m+1];
            for (int i = 0; i < n; i++) {
                a[i]=sc.nextInt();
                cnt[a[i]]^=1;
            }
            int[]next_odd=new int[m+1];
            Arrays.fill(next_odd, inf);
            for (int i = 0; i <=m; i++) {
                if(cnt[i]==1){
                    next_odd[i]=0;
                }
            }
            for (int i = m; i >0; i--) {
                next_odd[i-1]=Math.min(next_odd[i-1], next_odd[i]+1);
            }
            next_odd[m]=Math.min(next_odd[m], next_odd[0]);
            for (int i = m; i >0; i--) {
                next_odd[i-1]=Math.min(next_odd[i-1], next_odd[i]+1);
            }
            int c=0;
            while (q-->0) {
                int val=sc.nextInt();
                if(val==1){
                    c++;
                }else{
                    int idx=sc.nextInt();
                    int xx=a[idx-1];
                    int step=Math.min(c, next_odd[xx]);
                    System.out.println((xx+step-1)%m+1);
                }
            }
        }   
        sc.close();
    }
}
