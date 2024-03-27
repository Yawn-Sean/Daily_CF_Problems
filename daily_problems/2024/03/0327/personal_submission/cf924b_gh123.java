import java.util.Scanner;

public class B924 {
    public static void main(String[] args) {
      //输入
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int u=sc.nextInt();
        double[]e=new double[n];
        e[0]=sc.nextInt();
        for (int i = 1; i < e.length; i++) {
            e[i]=sc.nextInt();
           
        }
      //输入结束 下面是函数处理过程
       int l=0,r=0;
       double ans=-1;
       while (l<n) {
        while (r<n&&e[r]-e[l]<=u) {
            r++;
        }
        if(r-l>=3){
            ans=Math.max(ans, (e[r-1]-e[l+1])/(e[r-1]-e[l]));
        }
        l++;
       }
       System.out.println(ans);
        sc.close();
    }
}
