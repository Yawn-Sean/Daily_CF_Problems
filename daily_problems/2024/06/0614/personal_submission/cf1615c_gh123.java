//https://codeforces.com/problemset/submission/1615/265700672
import java.security.Identity;
import java.util.Scanner;

public class C1615 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            String a=sc.next();
            String b=sc.next();
            int a1=0;
            int b1=0;
            int dif=0;
            for (int i = 0; i < n; i++) {
                if(a.charAt(i)=='1'){
                    a1++;
                }
                if(b.charAt(i)=='1'){
                    b1++;
                }
                if(a.charAt(i)!=b.charAt(i)){
                    dif++;
                }
            }
            int res=Integer.MAX_VALUE;
            if(a1==b1){
                res=Math.min(res, dif/2*2);//偶数次交换
            }
            //翻一次，看能不能偶数次交换
            if(a1>=1){
                int a0=n-a1;
                a1=1+a0;
                dif=(n-dif)-1;
                if(a1==b1&&dif%2==0){
                    res=Math.min(res, dif/2*2+1);
                }
            }
            System.out.println(res==Integer.MAX_VALUE?-1:res);
        }
        sc.close();
    }
}
