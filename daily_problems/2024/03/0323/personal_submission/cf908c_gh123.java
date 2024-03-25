import java.util.Scanner;

public class C908 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt(),r=sc.nextInt();
        int[]a=new int[n];
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextInt();
        }
        double br[]=new double[n];
        for (int i = 0; i < n; i++) {
            for (int j = i-1; j >=0; j--) {
                int x=Math.abs(a[i]-a[j]);
                if(x<=2*r){
                    br[i]=Math.max(br[j]+Math.sqrt(4*r*r-x*x),br[i]);
                }
            }
            if(br[i]==0) br[i]=r;
        }
        for (int i = 0; i < n; i++) {
            System.out.print(br[i]+" ");
        }
        sc.close();
    }
}
