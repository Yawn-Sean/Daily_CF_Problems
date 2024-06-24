//有些题解涉及了剩余类的tip
//i*i+j*j mod m = (i mod m)(i mod m) + (j mod m)(j mod m) mod m
import java.util.Scanner;

public class b1056 {

    public static void main(String[] args)throws Exception{
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long m = sc.nextLong();
        long ans = 0;
        for(int i=1;i<=(int)m;i++){
            long ci = (n-i+m)/m;  //多少项小于n的 模m同余i
            for (int j=1;j<=(int)m;j++){
                long cj = (n-j+m)/m;
                if((i*i+j*j)%m==0){
                    ans+=(ci*cj);  //符合要求计数
                }
            }
        }
        System.out.println(ans);
    }

}
