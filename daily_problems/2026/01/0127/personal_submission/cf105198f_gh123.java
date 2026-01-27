import java.util.Arrays;
import java.util.Scanner;

public class CF105198f {
        public static void main(String[] args) {
            Scanner sc=new Scanner(System.in);
            int[]digits={6,2,5,5,4,5,6,3,7,6};
            long[]ans=new long[22];
            Arrays.fill(ans, 1000);
            for (int i = 0; i < 10; i++) {
                ans[digits[i]]=Math.min(ans[digits[i]], i);
            }   
            for (int i = 1; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    int d=digits[i]+digits[j];
                    ans[d]=Math.min(ans[d], i*10+j);
                }
            }
            for (int i = 1; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 10; k++) {
                        int d=digits[i]+digits[j]+digits[k];
                        ans[d]=Math.min(ans[d], i*100+j*10+k);
                    }
                }
            }
            int t=sc.nextInt();
            StringBuilder sb=new StringBuilder();
            for (int i = 0; i < t; i++) {
                int n=sc.nextInt();
                if(n<=21){
                    sb.append(ans[n]).append("\n");
                }else{
                    int v=(n-15)%7+15;
                    long base=ans[v];
                    int num=(n-v)/7;
                    sb.append(base);
                    for (int j = 0; j < num; j++) {
                        sb.append('8');
                    }
                    sb.append("\n");
                }
            }
            System.out.println(sb.toString());
            sc.close();
        }
}
