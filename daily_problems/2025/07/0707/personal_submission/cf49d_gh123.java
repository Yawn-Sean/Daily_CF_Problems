//https://codeforces.com/problemset/submission/49/327885866
import java.util.Scanner;

public class D49 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        String s=sc.next();
        int opa=0,opb=0;
        //opa 1010.. opb 0101...
        for (int i = 0; i < n; i++) {
            int c=s.charAt(i)-'0';
            if(i%2==0){
                if(c==1){
                    opb++;
                }else{
                    opa++;
                }
            }else{
                //i%2==1
                if(c==0){
                    opb++;
                }else{
                    opa++;
                }
            }
        }   
        System.out.println(Math.min(opa, opb));
        sc.close();
    }
}
