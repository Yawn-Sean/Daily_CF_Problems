//https://codeforces.com/problemset/submission/1092/316765216
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class C1092 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        String l=sc.nextLine();
        List<String>tem=new ArrayList<>();
        List<String>list=new ArrayList<>();
        int cnt=0;
        for (int i = 0; i < 2*n-2; i++) {
            String s=sc.nextLine();
            tem.add(s);
            if(s.length()==n-1){
                list.add(s);
            }
        }   
        sc.close();
         l="";
        for (int i = 0; i < tem.size(); i++) {
            if(n>=3){
                if(list.get(0).substring(1, n-1).equals(list.get(1).substring(0, n-2))&&tem.get(i).equals(list.get(0).substring(0, tem.get(i).length()))){
                    cnt++;
                }
            }
        }
        if(cnt>=n-1){
            l=list.get(0)+list.get(1).charAt(n-2);
        }else{
            l=list.get(1)+list.get(0).charAt(n-2);
        }
        String ans="";
        HashMap<Integer,Integer>map=new HashMap<>();
        for (int i = 0; i < tem.size(); i++) {
            if(tem.get(i).equals(l.substring(0, tem.get(i).length()))&&!map.containsKey(tem.get(i).length())){
                ans+="P";
                map.put(tem.get(i).length(), 1);
            }else{
                ans+="S";
            }
        }
        System.out.println(ans);
    }
}
