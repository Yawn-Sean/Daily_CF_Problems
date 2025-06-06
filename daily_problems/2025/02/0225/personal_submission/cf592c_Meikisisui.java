import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        BigInteger t = BigInteger.valueOf(Long.parseLong(st.nextToken()));
        BigInteger w = BigInteger.valueOf(Long.parseLong(st.nextToken()));
        BigInteger b = BigInteger.valueOf(Long.parseLong(st.nextToken()));
        if (min(w, b).compareTo(t) > 0) {
            pw.print("1" + "/" + "1");
        } else {
            BigInteger gcd = gcd(w, b);
            BigInteger lcm = w.multiply(b).divide(gcd);
            BigInteger min = min(w, b).subtract(BigInteger.ONE);
            BigInteger res = min;
            BigInteger tmp = t.divide(lcm);
            if (tmp.compareTo(BigInteger.ZERO) > 0) {
                BigInteger tmp1 = tmp.subtract(BigInteger.ONE);
                res = res.add(tmp1.multiply(min.add(BigInteger.ONE)));
                res = res.add(BigInteger.ONE);
                res = res.add(min(min, t.subtract(lcm.multiply(tmp))));
            }
            BigInteger gcd1 = gcd(res, t);
            res = res.divide(gcd1);
            t = t.divide(gcd1);
            pw.print(res + "/" + t);
        }
        pw.close();
        br.close();
    }

    private static BigInteger gcd(BigInteger a, BigInteger b) {
        if (b.compareTo(BigInteger.ZERO) == 0)
            return a;
        return gcd(b, a.remainder(b));
    }

    private static BigInteger min(BigInteger a, BigInteger b) {
        if (a.compareTo(b) >= 0)
            return b;
        return a;
    }

}
