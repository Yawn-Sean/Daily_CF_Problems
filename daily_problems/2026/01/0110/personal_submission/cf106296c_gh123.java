
import java.util.Scanner;

public class C106296 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            int v=(n+1)/2;
            int l=1,r=v-1;
            while (l<=r) {
                int mid=(r-l)/2+l;
                System.out.println(2+" "+(2*mid-1));
                int v1=sc.nextInt();
                System.out.println(1+" "+2*mid);
                int v2=sc.nextInt();
                if(v1==v2){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            System.out.println(3+" "+(2*r-1)+" "+(2*r+1));
        }
        sc.close();
    }    
  
}
