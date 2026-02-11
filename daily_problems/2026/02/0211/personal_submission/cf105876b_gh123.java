import java.util.Scanner;

public class cf105876b {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        solve(n);   
        sc.close();
    }
    static void solve(int n){
       
        if(n%4==3){
            System.out.println(-1);
        }else{
             StringBuilder sb=new StringBuilder();
            int[]a=new int[n];
            for (int i = 0; i < n; i++) {
                a[i]=i+1;
            }
            for (int i = 3; i < n; i+=4) {
                int tem=a[i-1];
                a[i-1]=a[i];
                a[i]=tem;
            }
            for (int i = 0; i < a.length; i++) {
                sb.append(a[i]).append(" ");
            }
            System.out.println(sb.toString().trim());
        }
    }    
}
