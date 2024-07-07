//分数为 𝑎和 b。
//$𝑎×𝑏=𝑘^3$ 
//a 和 b 都能整除 𝑘

import java.io.*;
import java.util.*;
import java.math.*;

public class a833 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }
    static long nextLong()throws  Exception{
        cin.nextToken();
        return (long) cin.nval;
    }
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        int n = nextInt();
        while (n-- > 0) {
            long a = nextLong();
            long b = nextLong();
            long k = Math.round(Math.pow(a * b, 1.0 / 3));
            if (k * k * k == a * b && a % k == 0 && b % k == 0) {
                pw.println("Yes");
            } else {
                pw.println("No");
            }
        }
        pw.flush();
    }
}
