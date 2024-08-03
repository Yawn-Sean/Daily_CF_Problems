import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.*;

public class cfsubmit {
    public static void main(String[] args) {
        int m,n;
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        String input = sc.nextLine();
        CF cf = new CF();
        out.println(cf.maxOrder(input));
        sc.close();
        out.close();
    }
}

class CF{
    public int maxOrder(String str) {
        StringBuilder sb = new StringBuilder(str);
        for (int i = 0; i < sb.length() - 1; i++) {
            char c1 = sb.charAt(i);
            char c2 = sb.charAt(i + 1);
            if(c1 == '(' && c2 == ')') sb.replace(i,i + 2,"0");
            if(c1 == '-' && c2 == '>') sb.replace(i,i + 2,",");
        }
        Deque<Character> listChar = new ArrayDeque<>();
        Deque<Integer> listNum = new ArrayDeque<>();
        for (int i = 0; i < sb.length(); i++) {
            char c = sb.charAt(i);
            if(c == '(') listChar.add(c);
            else if(c == ',') listChar.add(c);
            else if(c == '0') listNum.add(0);
            else {
                while (!listChar.isEmpty()){
                    char op = listChar.pollLast();
                    if(op == '(') break;
                    int num1 = listNum.pollLast();
                    int num2 = listNum.pollLast();
                    num1 = Math.max(num2 + 1,num1);
                    listNum.add(num1);
                }
            }
        }
        while (!listNum.isEmpty() && listNum.size() != 1){
            int num1 = listNum.pollLast();
            int num2 = listNum.pollLast();
            num1 = Math.max(num2 + 1,num1);
            listNum.add(num1);
        }
        return listNum.peek();
    }
}
