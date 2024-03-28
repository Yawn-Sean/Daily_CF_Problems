
import java.util.Scanner;

public class A891 {
    public static void main(String[] args) {
      //input
      Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]a=new int[n];
        int ones=0;
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextInt();
            if(a[i]==1){
                ones++;
            }
        }
  //input over
        if(ones>0){
            System.out.println(n-ones);
        }else{
            int ans=n;
            for (int i = 0; i < a.length-1; i++) {
                int tem=a[i];
                for (int j = i+1; j < a.length; j++) {
                    tem=gcd(tem, a[j]);
                    if(tem==1){
                        ans=Math.min(ans, j-i);
                        break;
                    }
                }
            }
            if(ans<n){
                System.out.println(ans+n-1);
            }else{
                System.out.println(-1);
            }
        }
        sc.close();
    }
    public static int gcd(int a, int b){
        int mod = a % b;
        if (mod == 0) return b;
        else return gcd(b, mod);
    }
}
