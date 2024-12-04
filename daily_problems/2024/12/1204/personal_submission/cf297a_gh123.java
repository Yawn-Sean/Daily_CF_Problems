//https://codeforces.com/problemset/submission/297/294708761
import java.util.Scanner;

public class A297 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        char[]csa=sc.next().toCharArray();
        char[]csb=sc.next().toCharArray();
        int cnt=0;
        for (int i = 0; i < csa.length; i++) {
            if(csa[i]=='1'){
                cnt++;
            }
        }
        if(cnt%2==1)cnt++;
        for (int i = 0; i < csb.length; i++) {
            if(csb[i]=='1')cnt--;
        }
        if(cnt>=0){
            System.out.println("YES");
        }else{
            System.out.println("NO");
        }
        sc.close();
    }
}
