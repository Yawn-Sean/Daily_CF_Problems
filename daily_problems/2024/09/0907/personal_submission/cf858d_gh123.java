//https://codeforces.com/problemset/submission/858/280140979
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class D858 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        HashMap<String,Integer>map=new HashMap<>();
        String[]nums=new String[n];
        for (int i = 0; i < n; i++) {
            nums[i]=sc.next();
            HashSet<String>cur=new HashSet<>();
            for (int j = 0; j < 9; j++) {
                for (int k = j; k < 9; k++) {
                    String ss=nums[i].substring(j, k+1);
                    if(cur.contains(ss))continue;
                    cur.add(ss);
                    map.put(ss, map.getOrDefault(ss, 0)+1);
                }
            }
        }//将所有子串进行hashmap存储，方面后面查询
        StringBuilder sb=new StringBuilder();
        sc.close();
        for (int i = 0; i < n; i++) {
            String cur=nums[i];
            for (int j = 0; j < 9; j++) {
                for (int k = j; k < 9; k++) {
                    String ss=nums[i].substring(j,k+1);
                    int v=map.get(ss);
                    if(v==1){
                        if(ss.length()<cur.length()) cur=ss;
                    }
                }
            }
            sb.append(cur);
            if(i!=n-1){
                sb.append('\n');
            }
        }
        System.out.println(sb);
    }    
}
