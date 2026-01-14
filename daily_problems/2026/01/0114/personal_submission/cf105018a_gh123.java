import java.util.Scanner;

public class A105018 {
    static int[]prep(String s){
        int n=s.length();
        int[]kmp=new int[n];
        int j=0;
        for (int i = 1; i < n; i++) {
            while (j>0&&s.charAt(j)!=s.charAt(i)) {
                j=kmp[j-1];
            }
            if(s.charAt(j)==s.charAt(i)){
                j++;
            }
            kmp[i]=j;
        }
        return kmp;
    }   
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            String s=sc.next();
            StringBuilder sb=new StringBuilder(s);
            sb.append(" ");
            for (int i = 0; i < n; i++) {
                char c=s.charAt(i);
                char flip=(char)(c^1);
                sb.append(flip);
            }
            String s_prime=sb.toString();
            int[]res=prep(s_prime);
            for (int i = n+1; i <= n*2; i++) {
                System.out.print(res[i]);
                if(i<2*n){
                    System.out.print(" ");
                }
            }
            System.out.println();
        }   
        sc.close();
    }
}
