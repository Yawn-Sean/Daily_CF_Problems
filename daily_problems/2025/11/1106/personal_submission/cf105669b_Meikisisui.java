import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    private static int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        String[] ch = new String[3];
        ch[0] = st.nextToken();
        ch[1] = st.nextToken();
        ch[2] = st.nextToken();
        long begin = 0, end = 0;
        for (char c : ch[0].toCharArray())
            begin = (10 * begin + (c - '0')) % MOD;
        for (char c : ch[2].toCharArray())
            end = (10 * end + (c - '0')) % (ch[1].equals("^") ? (MOD - 1) : MOD);
        if (ch[1].equals("+"))
            pw.println((begin + end) % MOD);
        else if (ch[1].equals("-"))
            pw.println((begin - end + MOD) % MOD);
        else if (ch[1].equals("*"))
            pw.println((begin * end) % MOD);
        else
            pw.println(quickPow(begin, end, MOD));
        pw.close();
    }

    public static long quickPow(long a, long b, int p) {
        // 防止p=1，否则返回0
        long res = 1 % p;
        while (b > 0) {
            // b最后一位是否是1
            if ((b & 1) == 1)
                res = res * a % p;
            a = (int) ((long) a * a % p);
            // 删除b最后一位
            b >>= 1;
        }
        return (int) res;
    }

}
