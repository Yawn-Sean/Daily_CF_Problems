//https://codeforces.com/problemset/submission/670/337485516
import java.util.Scanner;
import java.util.Stack;
//建了4个数组实现的。。。


public class E670 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int p=sc.nextInt()-1;
        String s=sc.next();
        String query=sc.next();
        sc.close();
        int[]open=new int[n];
        int[]close=new int[n];
        int[]right=new int[n];
        int[]left=new int[n];
        for (int i = 0; i < n; i++) {
            right[i]=i+1;
            left[i]=i-1;
        }
        int start=0,end=n-1;
        Stack<Integer>st=new Stack<>();
        for (int i = 0; i < n; i++) {
            if(s.charAt(i)=='('){
                st.push(i);
            }else{
                int x=st.pop();
                close[x]=i;
                open[i]=x;
            }
        }
        for (int i = 0; i < m; i++) {
            char c=query.charAt(i);
            if(c=='R'){
                p=right[p];
            }else if(c=='L'){
                p=left[p];
            }else{
                int l=-1,r=-1;
                if(s.charAt(p)=='('){
                    l=p;
                    r=close[p];
                }else{
                    l=open[p];
                    r=p;
                }
                if(start==l){
                    start=right[r];
                }else{
                    right[left[l]]=right[r];
                }
                if(end==r){
                    end=left[l];
                }else{
                    left[right[r]]=left[l];
                }
                if(right[r]!=n){
                    p=right[r];
                }else{
                    p=left[l];
                }
            }
        }
        while (start!=n) {
            System.out.print(s.charAt(start));
            start=right[start];
        }
    }
}
