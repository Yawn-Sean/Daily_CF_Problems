import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Test3 {

    private static int[] prime = new int[100001];
    private static boolean[] vis = new boolean[100001];
    // 存放某个质因数对应的那个数
    private static int[] primeS = new int[100001];
    private static Set<Integer> set = new HashSet<>();
    private static int cnt = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        findPrime(100000);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        boolean[] mark = new boolean[n + 1];
        for (int ez = 0; ez < m; ez++) {
            st = new StringTokenizer(br.readLine());
            char ch = st.nextToken().charAt(0);
            int num = Integer.parseInt(st.nextToken());
            if (ch == '+') {
                if (mark[num])
                    pw.println("Already on");
                else {
                    int tmp = isExist(num);
                    if (tmp == 0) {
                        pw.println("Success");
                        add(num);
                        mark[num] = true;
                    } else
                        pw.println("Conflict with " + primeS[tmp]);
                }
            } else if (ch == '-') {
                if (!mark[num])
                    pw.println("Already off");
                else {
                    del(num);
                    mark[num] = false;
                    pw.println("Success");
                }
            }
        }
        pw.close();
    }

    private static void findPrime(int n) {
        for (int ez = 2; ez <= n; ez++) {
            if (!vis[ez]) {
                prime[cnt++] = ez;
                for (int vn = ez + ez; vn <= n; vn += ez)
                    vis[vn] = true;
            }
        }
    }

    private static int isExist(int x) {
        int tmp = x;
        for (int ez = 0; ez < cnt && prime[ez] * prime[ez] <= tmp; ez++) {
            if (x % prime[ez] == 0) {
                if (set.contains(prime[ez]))
                    return prime[ez];
                while (x % prime[ez] == 0)
                    x /= prime[ez];
            }
        }
        if (x > 1) {
            if (set.contains(x))
                return x;
        }
        return 0;
    }

    private static void add(int x) {
        int tmp = x;
        for (int ez = 0; ez < cnt && prime[ez] * prime[ez] <= x; ez++) {
            if (x % prime[ez] == 0) {
                primeS[prime[ez]] = tmp;
                set.add(prime[ez]);
                while (x % prime[ez] == 0)
                    x /= prime[ez];
            }
        }
        if (x > 1) {
            primeS[x] = tmp;
            set.add(x);
        }
    }

    private static void del(int x) {
        for (int ez = 0; ez < cnt && prime[ez] * prime[ez] <= x; ez++) {
            if (x % prime[ez] == 0) {
                set.remove(prime[ez]);
                primeS[prime[ez]] = 0;
                while (x % prime[ez] == 0)
                    x /= prime[ez];
            }
        }
        if (x > 1) {
            set.remove(x);
            primeS[x] = 0;
        }
    }

}
