import java.util.Scanner;

public class cf106430b {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int x=sc.nextInt(),y=sc.nextInt();
            if(x==y){
                System.out.println("0");
            }else if(x<y){
                int ans=0;
                while (x<y) {
                    x*=2;
                    ans++;
                }
                System.out.println(ans);
            }else{
                if(y<=2){
                    System.out.println(-1);
                }else{
                    int ans=0;
                    while (x>y) {
                        x=2*x/3+1;
                        ans++;
                    }
                    System.out.println(ans);
                }
            }
        }   
        sc.close();
    }    
}
