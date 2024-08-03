
https://codeforces.com/problemset/submission/439/255945150
```java
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class D439 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        ArrayList<Integer>a=new ArrayList<>();
        ArrayList<Integer>b=new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(sc.nextInt());
        }
        for (int i = 0; i < m; i++) {
            b.add(sc.nextInt());
        }
        Collections.sort(a);
        Collections.sort(b,Collections.reverseOrder());
        int size=Math.min(n, m);
        long ans=0;
        int x,y;
        for (int i = 0; i < size; i++) {
            x=a.get(i);
            y=b.get(i);
            if(y>x){
                ans+=y-x;
            }else{
                break;
            }
        }
        System.out.println(ans);
        sc.close();
    }
}
```
