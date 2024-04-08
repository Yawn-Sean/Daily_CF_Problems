import java.util.Scanner;
//https://codeforces.com/problemset/submission/492/255576195
public class D492 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int x=sc.nextInt();
        int y=sc.nextInt();
        StringBuilder sb=new StringBuilder();
        for (int i = 0; i < n; i++) {
            int v=sc.nextInt();
            long l=1;long r=(long)1e15;
            while (l<=r) {
                long m=(l+r)/2;
                if(m/x+m/y>=v){
                    r=m-1;
                }else{
                    l=m+1;
                }
            }
            if(l%x==0){
                if(l%y==0){
                    sb.append("Both");
                }else if(l%x==0){
                    sb.append("Vova");
                }
            }else{
                sb.append("Vanya");
            }
            sb.append("\n");
        }
        System.out.println(sb);
        sc.close();
    }
}
