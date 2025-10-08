import java.util.Arrays;
import java.util.Scanner;

public class E104679 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=(int)1e7;
        int[]prime=new int[n+1];
        Arrays.fill(prime, 1);
        prime[0]=0;
        prime[1]=0;
        for (int i = 2; i <=n; i++) {
            if(prime[i]==1){
                for (int j = 2*i; j <=n; j+=i) {
                    prime[j]=0;
                }
            }
        }
        for (int i = 1; i <=n; i++) {
            prime[i]+=prime[i-1];
        }

        int t=sc.nextInt();
        StringBuilder sb=new StringBuilder();
        while (t-->0) {
            int val=sc.nextInt();
            if(val<=3){
                sb.append(val-2).append("\n");
            }else{
                sb.append((prime[val]-prime[val/2])).append("\n");    
            }
            
        }
        System.out.println(sb.toString().trim());
        sc.close();
    }
}
