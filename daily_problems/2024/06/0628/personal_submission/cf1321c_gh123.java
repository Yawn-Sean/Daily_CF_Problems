//https://codeforces.com/problemset/submission/1321/267794048
import java.util.Scanner;
 
public class C1321 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        String a=sc.next();
        StringBuilder sb=new StringBuilder(a);
        for(char c='z';c>='a';c--){
            for (int i = 0; i <sb.length(); i++) {
                if(sb.charAt(i)==c){
                    if((i>0&&sb.charAt(i-1)==c-1)||(i<sb.length()-1&&sb.charAt(i+1)==c-1)){
                        sb.deleteCharAt(i);
                        i=Math.max(-1, i-2);
                    }
                }
            }
        }
        System.out.println(n-sb.length());
        sc.close();
    }
}
