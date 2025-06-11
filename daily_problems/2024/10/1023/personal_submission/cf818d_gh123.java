//https://codeforces.com/problemset/submission/818/287451824
//不会用数组的办法，所以用的hashmap+hashset的办法。还WA了好几次。。。主要是有几种情况忘记讨论了。
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class D818 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int a=sc.nextInt();
        int ax=0;
        int max=n;
        HashMap<Integer,Integer>map=new HashMap<>();
        HashSet<Integer>set=new HashSet<>();
        boolean flag=true;
        for (int i = 0; i < n; i++) {
            int x=sc.nextInt();
            max=Math.max(max,x);
            if(i==0&&a==x){
                flag=false;
            }
            if(a==x){
                ax++;
            }
            if(set.contains(x)){
                continue;
            }
            map.put(x, map.getOrDefault(x, 0)+1);
            if(map.get(x)<=ax){
                set.add(x);
            }
            // System.out.println(map.get(x)+" 此时 "+x);
            // for (int k : set) {
            //     System.out.println(k+" set");
            // }
        }
        // for (int k : map.keySet()) {
        //     System.out.println(k+" "+map.get(k));
        // }
        if(!flag){
            System.out.println(-1);
        }else{
            boolean tem=true;
            for (int i = 1; i <=max; i++) {
                if(!set.contains(i)){
                    if(map.containsKey(i)&&map.get(i)>=ax){
                        System.out.println(i);
                        tem=false;
                        break;
                    }
                }
            }
            if(tem){
                System.out.println(-1);
            }
        }
        sc.close();
    }
}
