//https://codeforces.com/problemset/submission/1835/315903675
//用math.power就超时，自己写的power就不超时，为什么，，，
import java.util.Scanner;

public class A1835 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int a=sc.nextInt();
            int b=sc.nextInt();
            int c=sc.nextInt();
            long k=sc.nextLong();
            boolean flag=false;
            for (int i = pow(10, a-1); i <(int)pow(10, a); i++) {
                int l=(int)Math.max(pow(10,b-1),pow(10, c-1)-i);
                int r=(int)Math.min(pow(10, b)-1, pow(10, c)-1-i);
                if(l>r)continue;
                int x=r-l+1;
                if(k<=x){
                    System.out.println(i+" + "+(l+k-1)+" = "+(i+l+k-1));
                    flag=true;
                    break;
                }k-=x;
            }
            if(!flag){
                System.out.println(-1);
            }
        }   
        sc.close();
    }
    public static int pow(int n,int m){
        if(m==0) return 1;
        return m==1?n:n*pow(n, m-1);
    }
}
