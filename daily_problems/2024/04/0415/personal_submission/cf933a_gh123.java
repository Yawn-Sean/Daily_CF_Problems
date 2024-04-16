import java.util.Scanner;

/**
 * A933
 */
public class A933 {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]a=new int[n];
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextInt();
        }
        int dp1=0;
        int dp12=0;
        int dp121=0;
        int dp1212=0;
        for (int i = 0; i < n; i++) {
            if(a[i]==1){
                dp1++;
                dp121++;
            }else{
                dp12++;
                dp1212++;
            }
            dp12=Math.max(dp1, dp12);
            dp121=Math.max(dp12, dp121);
            dp1212=Math.max(dp121, dp1212);
        }
        System.out.println(dp1212);
        sc.close();
    }
}
