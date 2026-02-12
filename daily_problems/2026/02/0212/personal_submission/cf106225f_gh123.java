import java.util.Scanner;

public class cf106225f {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            int[]a=new int[n];
            int ans=-1;
            for (int i = 0; i < n; i++) {
                a[i]=sc.nextInt();
            }
            for (int i = 1; i < n; i++) {
                if(a[i]<=a[i-1]){
                    ans=a[i-1]/(a[i]-1);
                }
            }
            if(ans==-1){
                int last=a[n-1];
                int sec=a[n-2];
                ans=Math.max(last-sec,last/(last-sec));
            }
            System.out.println(ans);
        }   
        sc.close();
    }    
}
