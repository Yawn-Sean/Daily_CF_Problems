package luogu;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;

public class a{
    private static String[]level;
    private static String s;
    private static Map<Integer,ArrayList<String>> m = new TreeMap<>();
    private static void dfs(int depth,int []pos){
        String s1=level[pos[0]++];
        int x=Integer.parseInt(level[pos[0]++]);
        if(m.get(depth)==null){
            m.put(depth,new ArrayList<String>());
        }
        m.get(depth).add(s1);
        if(x==0) return;
        for(int i=0;i<x;i++){
            dfs(depth+1,pos);
        }
    }

    private static void michael(){
        PrintWriter pr=new PrintWriter(System.out);
        level=s.split(",");
        int []pos=new int[]{0};
        while(pos[0]<level.length){
            dfs(1,pos);
        }
        Set<Integer> se=m.keySet();
        pr.println(m.size());
        for(int t:se){
            for(String te:m.get(t)){
                pr.print(te+" ");
            }
            pr.println();
        }
        pr.close();
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        s=br.readLine();
        michael();
        br.close();
    }
}

