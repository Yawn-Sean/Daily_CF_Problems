//https://codeforces.com/problemset/submission/833/267452610

/*
*  这道题不能用Scanner读入，会超时，我超了很多次才知道的。。。。
*/
import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;
 
 
public class A833 {
 
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter output = new PrintWriter(System.out);
        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            String[] s = br.readLine().split(" ");
            int a = Integer.parseInt(s[0]);
            int b = Integer.parseInt(s[1]);
            long x = 1L * a * b;
            double y = Math.cbrt(x);
            if (a % y == 0 && b % y == 0)
                output.println("Yes");
            else
                output.println("No");
        }
        br.close();
        output.close();
    }
}
 
 
