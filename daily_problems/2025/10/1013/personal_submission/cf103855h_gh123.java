import java.util.Scanner;

public class H103855 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int mod=(int)1e9+7;
        int n=sc.nextInt();
        int cur=0,pos=0;
        long ans=1;
        for (int i = 0; i < n; i++) {
            int x=sc.nextInt();
            if(x>cur){
                ans=1l*ans*(i-pos+1)%mod;
                cur=x;
                pos=i;
            }
        }   
        sc.close();
        System.out.println(ans);
    }
}
