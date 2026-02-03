import java.math.BigInteger;
import java.util.Scanner;

public class cf105400e {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            int[]a=new int[n];
            for (int i = 0; i < a.length; i++) {
                a[i]=sc.nextInt();
            }
            int min=Integer.MAX_VALUE;
            int max=Integer.MIN_VALUE;
            for (int i = 0; i < a.length; i++) {
                min=Math.min(min, a[i]);
                max=Math.max(max, a[i]);
            }
            if(min==max){
                StringBuilder sb=new StringBuilder();
                sb.append("1");
                for (int i = 0; i < n; i++) {
                    sb.append("0");
                }
                System.out.println(sb.toString());
            }else{
                BigInteger ans=BigInteger.ONE;
                for (int i = 0; i < a.length; i++) {
                    if(a[i]==min){
                        ans=ans.multiply(BigInteger.valueOf(a[i]));
                    }else if(a[i]==max){
                        ans=ans.multiply(BigInteger.valueOf(11-a[i]));
                    }
                }
                System.out.println(ans.toString());
            }
        }   
        sc.close();
    }    
}
