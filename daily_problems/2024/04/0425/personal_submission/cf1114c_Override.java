//使用token的输入 对于long型数据有问题好像，还是用普通的scanner输入
//java的数组索引只能用int  这一点需注意

import java.io.*;
import java.util.Scanner;

public class c1114 {


    public static void main(String[] args)throws Exception{
        Scanner sc = new Scanner(System.in);

        long n = sc.nextLong();
        long b = sc.nextLong();

        long ans = Long.MAX_VALUE;
        for(long i=2;i<=b;i++){
            if(i*i > b) i=b;
            int cnt = 0;
            while (b%i==0){
                b/=i;
                cnt++;
            }
            if(cnt>0){
                long cur = 0;
                long temp  =n;
                while (temp/i >0){
                    cur += temp/i;
                    temp/=i;
                }
                ans = Math.min(ans,cur/cnt);
            }
        }

        System.out.println(ans);


    }


}
