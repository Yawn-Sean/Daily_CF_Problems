
import java.util.*;

public class a1019 {
    static long maxn = 30005;
    static long INF = Long.MAX_VALUE;
    static long n, m;
    static ArrayList<Integer>[] c = new ArrayList[(int) maxn];
    static ArrayList<Integer> rest = new ArrayList<>();
    static long[] rc = new long[(int) maxn];
    static long[] ch = new long[(int) maxn];
    static long[] vc = new long[(int) maxn];
    static long tot = INF;
    static long p, cur, val;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextLong();
        m = scanner.nextLong();

        for (int i = 0; i < maxn; i++) {
            c[i] = new ArrayList<>();
        }

        for (int i = 1; i <= n; i++) {
            p = scanner.nextLong();
            val = scanner.nextLong();
            c[(int) p].add((int) val);
            rc[(int) p]++;
        }
        //对选民的金额进行排序
        for (int i = 1; i <= m; i++) {
            Collections.sort(c[i]);
        }
        //枚举1号党最终的票数
        for (int i = 1; i <= n; i++) {
            cur = 0;//获得至少i票时所需的金额
            for (int j = 1; j <= m; j++) {
                vc[j] = rc[j];//初始化
                ch[j] = 0;
            }

            for (int j = 2; j <= m; j++) {
                //如果该党票数>i，那我们就贿赂该党选民直到其票数<i
                while (vc[j] >= i) {
                    vc[1]++;
                    vc[j]--;
                    cur += c[j].get((int) ch[j]);
                    ch[j]++;
                }
            }
            //处理票数不够的情况
            if (vc[1] < i) {
                rest.clear();
                for (int j = 2; j <= m; j++) {
                    for (int k = (int) ch[j]; k < c[j].size(); k++) {
                        rest.add(c[j].get(k));
                    }
                }
                Collections.sort(rest);
                for (int j = 0; vc[1] < i; j++, vc[1]++) {
                    cur += rest.get(j);//不断贿赂选民直到1号党票数=i
                }
            }
            //更新解
            tot = Math.min(tot, cur);
        }

        System.out.println(tot);
    }
}
