//https://codeforces.com/problemset/submission/847/278900632
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class B847 { //二分还是不太熟。。。
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        List<List<Integer>>lists=new ArrayList<>();
        int first=sc.nextInt();
        ArrayList<Integer>tmp=new ArrayList<>();
        tmp.add(first);
        lists.add(tmp);
        for (int i = 1; i < n; i++) {
            int num=sc.nextInt();
            int size=lists.size();
            int l=0,r=size;
            while (l<r) {
                int mid=(l+r)/2;
                if(lists.get(mid).getLast()>num){
                    l=mid+1;
                }else{
                    r=mid;
                }
            }
            if(l==size){
                tmp=new ArrayList<>();
                tmp.add(num);
                lists.add(tmp);
            }else{
                lists.get(l).add(num);
            }
        }
        StringBuilder sb=new StringBuilder();
        for (List<Integer> l : lists) {
            StringBuilder sb2=new StringBuilder();
            for (int i : l) {
                sb2.append(i);
                sb2.append(' ');
            }
            sb.append(sb2.substring(0, sb2.length()-1));
            sb.append('\n');
        }
        System.out.println(sb);
        sc.close();
    }
}
