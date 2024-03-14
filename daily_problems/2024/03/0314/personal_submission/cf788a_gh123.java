```java
import java.util.Scanner;

public class A788 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]a=new int[n];
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextInt();
        }
        int[] jdz=new int[n-1];
        for (int i = 0; i < n-1; i++) {
            jdz[i]=Math.abs(a[i]-a[i+1]);
        }
        long sum=0;
        long max=0;
        int flag=0;
        for (int i = 0; i < n-1; i++) {
            if(flag==0){
                sum+=jdz[i];
            }else{
                sum-=jdz[i];
            }
            if(sum<0) sum=0;
            flag++;
            flag=flag==2?0:1;
            max=max<sum?sum:max;
        }
        flag=0;
        sum=0;
        for (int i = 1; i < n-1; i++) {
            if(flag==0)
            sum+=jdz[i];
            else{
                sum-=jdz[i];
            }
            if(sum<0) sum=0;
            flag++;
            flag=flag==2?0:1;
            max=max<sum?sum:max;
        }
        System.out.println(max);
        sc.close();
    }
}
```
