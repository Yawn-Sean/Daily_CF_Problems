import java.util.HashMap;
import java.util.Scanner;

public class cf1176c {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        HashMap<Integer,Integer>map=new HashMap<>();
        map.put(4, 1);
        map.put(8, 2);
        map.put(15, 3);
        map.put(16, 4);
        map.put(23, 5);
        map.put(42, 6);
        int[]cnt=new int[7] ;
        int n=sc.nextInt();
        cnt[0]=n;
        for (int i = 0; i < n; i++) {
            int x=sc.nextInt();
            x=map.get(x);
            if(cnt[x-1]>0){
                cnt[x-1]--;
                cnt[x]++;
            }
        }   
        System.out.println(n-6*cnt[6]);
        sc.close();
    }    
}
