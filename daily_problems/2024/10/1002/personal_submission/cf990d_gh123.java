//https://codeforces.com/problemset/submission/990/283974888
import java.util.Scanner;
//跟着题解写代码的。。
public class D990 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int a=sc.nextInt();
        int b=sc.nextInt();
        sc.close();
        if(a>1&&b>1){
            System.out.println("NO");
            return;
        }
        if(a==1&&b==1&&(n==2||n==3)){
            System.out.println("NO");
            return;
        }
        int[][]res=new int[n+1][n+1];
       
        if(b==1){
            int num=n-a;
            for (int i = 1; i <=num; i++) {
                res[i][i+1]=1;
                res[i+1][i]=1;
            }
        }else{
            int num=n-b;
            for (int i = 1; i <=num; i++) {
                res[i][i+1]=1;
                res[i+1][i]=1;
            }
            for (int i = 1; i <=n; i++) {
                for (int j = 1; j <=n; j++) {
                    if(i!=j){
                        res[i][j]=1-res[i][j];
                    }
                }
            }
        }
        System.out.println("YES");
        for (int i = 1; i <=n; i++) {
            for (int j = 1; j <=n; j++) {
                System.out.print(res[i][j]);
            }
            System.out.println();
        }
    }
}
