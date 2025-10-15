//https://codeforces.com/problemset/submission/617/317900174
import java.util.Scanner;

public class D617{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int[]x=new int[3];
        int[]y=new int[3];
        for (int i = 0; i < 3; i++) {
            x[i]=sc.nextInt();
            y[i]=sc.nextInt();
        }
        sc.close();
        if(x[0]==x[1]&&x[0]==x[2]||y[0]==y[1]&&y[0]==y[2]){
            System.out.println(1);
        }else{
            for (int i = 0; i < 3; i++) {
                int j=(i+1)%3;
                int k=(i+2)%3;
                if(x[j]==x[k]&&!(Math.min(y[j], y[k])<y[i] && y[i]<Math.max(y[j], y[k]))){
                    System.out.println(2);
                    return;
                }
                if(y[j]==y[k]&&!(Math.min(x[j], x[k])<x[i] && x[i]<Math.max(x[j], x[k]))){
                    System.out.println(2);
                    return;
                }
            }
            System.out.println(3);
        }
    }//想不出这个条件。。。
}
