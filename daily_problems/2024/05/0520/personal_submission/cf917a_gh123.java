https://codeforces.com/problemset/submission/917/261718488
import java.util.Scanner;

public class A917 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String s=sc.next();
        sc.close();
        int ans=0;
        for (int i = 0; i < s.length(); i++) {
            int que=0,balance=0;
            for (int j = i; j < s.length(); j++) {
                char c=s.charAt(j);
                if(c=='('){
                    balance++;
                }else if(c==')'){
                    balance--;
                }else if(c=='?'){
                    que++;
                    balance--;//先认定为右括号
                }
                if(balance<0){
                    //这个时候，右括号多了，判断que的值，如果可以补充，就补充，不可以就退出
                    if(que==0){
                        break;
                    }else{
                        balance+=2;
                        que--;
                    }
                }
                if(balance==0){
                    ans++;
                }
            }
        }
        System.out.println(ans);
    }
}
