//https://codeforces.com/problemset/submission/1153/265436068
import java.util.Scanner;

public class C1153 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        char[]chars=sc.next().toCharArray();
        if(n%2==1){
            System.out.println(":(");
            return;
        }
        int open=0,close=0,unknown=0;
        for (int i = 0; i < n; i++) {
            if(chars[i]=='('){
                open++;
            }else if(chars[i]==')'){
                close++;
            }
        }
        unknown=n-open-close;
        for (int i = 0; i < n; i++) {
            if(chars[i]=='?'){
                if(open<unknown+close){
                    chars[i]='(';
                    open++;
                    unknown--;
                }else{
                    chars[i]=')';
                    close++;
                    unknown--;
                }
            }
        }
        System.out.println(valid(chars)?new String(chars):":(");
        sc.close();
    }
    public static boolean valid(char[]chars){
        int cnt=0;
        for (int i = 0; i < chars.length; i++) {
            if(chars[i]=='('){
                cnt++;
            }else if(chars[i]==')'){
                cnt--;
            }
            if(cnt<=0&&i!=chars.length-1){
                return false;
            }
        }
        if(cnt!=0) return false;
        return true;
    }
}
