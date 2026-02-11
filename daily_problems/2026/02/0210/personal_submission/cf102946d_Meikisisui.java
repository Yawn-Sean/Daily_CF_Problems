import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Test4 {

    public static void main(String[] args) throws Exception {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(f.readLine());
        PrintWriter pw = new PrintWriter(System.out);
        int idx = -1;
        boolean isOk = false;
        for (int ez = 0; ez < n; ez++) {
            if (ask(f, pw, 0, ez) == n) {
                if (idx != -1)
                    isOk = true;
                idx = ez;
            }
        }
        if (!isOk) {
            int tq = (idx != 0 ? idx - 1 : 1);
            for (int ez = 0; ez < n; ez++) {
                if (ask(f, pw, ez, tq) == n) {
                    int res = (idx - ez + n) % n;
                    pw.println("! " + res);
                    pw.flush();
                    return;
                }
            }
        } else {
            for (int ez = 0; ez < n; ez++) {
                if (ask(f, pw, 1, ez) == n) {
                    pw.println("! " + ez);
                    pw.flush();
                    return;
                }
            }
        }
    }

    private static int ask(BufferedReader f, PrintWriter pw, int a, int b) throws Exception {
        pw.println("? " + a + " " + b);
        pw.flush();
        return Integer.parseInt(f.readLine());
    }

}
