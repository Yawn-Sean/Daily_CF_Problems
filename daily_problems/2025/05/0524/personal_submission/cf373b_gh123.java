//https://codeforces.com/problemset/submission/373/320969904
import java.util.Scanner;

public class B373 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long w=sc.nextLong();
        long m=sc.nextLong();
        long k=sc.nextLong();
        w/=k;   
        sc.close();
        long v=10,digit=1,ans=0;
        while (true) {
            long l=Math.max(0, v-m);
            if(l*digit<=w){
                w-=l*digit;
                ans+=l;
                m+=l;
            }else{
                ans+=w/digit;
                break;
            }
             v*=10;
        digit++;
        }
       
        System.out.println(ans);
    }

    
}
