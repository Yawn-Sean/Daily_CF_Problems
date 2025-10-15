//https://codeforces.com/problemset/submission/747/321857284
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;
//挺难的，想不到要用stack
public class E747 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String[]a=sc.nextLine().split(",");   
        sc.close();
        ArrayList<ArrayList<String>>ans=new ArrayList<>();
        Stack<Integer>st=new Stack<>();
        for (int i = 0; i < a.length; i++) {
            if(a[i].charAt(0)>='0'&&a[i].charAt(0)<='9'){
                int x=Integer.parseInt(a[i]);
                st.add(x);
            }else{
                while (!st.isEmpty()&&st.peek()==0) {
                    st.pop();
                }
                if(st.isEmpty()){
                    if(ans.size()<1){
                        ans.add(new ArrayList<>());
                    }
                    ans.get(0).add(a[i]);
                }else{
                    st.add(st.pop()-1);
                    if(ans.size()<st.size()+1){
                        ans.add(new ArrayList<>());
                    }
                    ans.get(st.size()).add(a[i]);
                }
            }
             
        }
        System.out.println(ans.size());
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans.get(i).size(); j++) {
                System.out.print(ans.get(i).get(j)+" ");
            }
            System.out.println();
        }
    }
}
