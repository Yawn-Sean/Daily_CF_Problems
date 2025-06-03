//https://codeforces.com/problemset/submission/140/322614656
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class C140 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        HashMap<Integer,Integer>map=new HashMap<>();
        PriorityQueue<Integer>pq=new PriorityQueue<>((a,b)->map.get(b)-map.get(a));
        for (int i = 0; i < n; i++) {
            int x=sc.nextInt();
            map.put(x, map.getOrDefault(x, 0)+1);
        }   
        sc.close();
        pq.addAll(map.keySet());
        List<int[]>list=new ArrayList<>();
        while (pq.size()>2) {
            int[]a=new int[3];
            a[0]=pq.poll();
            a[1]=pq.poll();
            a[2]=pq.poll();
            map.put(a[0], map.get(a[0])-1);
            map.put(a[1], map.get(a[1])-1);
            map.put(a[2], map.get(a[2])-1);
            if(map.get(a[0])>0) pq.add(a[0]);
            if(map.get(a[1])>0) pq.add(a[1]);
            if(map.get(a[2])>0) pq.add(a[2]);
            Arrays.sort(a);
            list.add(a);
        }
        System.out.println(list.size());
        for (int i = 0; i < list.size(); i++) {
            int[]cur=list.get(i);
            System.out.println(cur[2]+" "+cur[1]+" "+cur[0]);
        }
    }
}
