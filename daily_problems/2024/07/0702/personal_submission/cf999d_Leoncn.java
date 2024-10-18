import java.util.ArrayDeque;
import java.util.Deque;

public class cf999d_Leoncn {
        public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int[] g = sc.na(n);
        int[] cnt = new int[m];
        Deque<Integer>[] arr = new ArrayDeque[n];
        for (int i = 0; i < m; i++) {
            arr[i] = new ArrayDeque<>();
        }
        for (int i = 0; i < n; i++) {
            int d = g[i]%m;
            cnt[d]++;
            arr[d].add(i);
        }

        long ans = 0;
        int c = n/m;
        int loc = m-1;
        out:
        for (int i = m-1; i >0 ; i--) {
            if(cnt[i] < c) {
                while (true) {
                    if (cnt[loc] >= c) {
                        if (cnt[loc] - c >= c - cnt[i]) {
                            cnt[loc] -= c - cnt[i];
                            int d = c - cnt[i];
                            while (d > 0) {
                                d--;
                                g[arr[loc].poll()] += i - loc;
                            }
                            ans += (long) (i - loc) * (c - cnt[i]);
                            cnt[i] = c;

                            break;
                        } else {
                            cnt[i] += cnt[loc] - c;
                            int d = cnt[loc] - c;
                            while (d > 0) {
                                d--;
                                g[arr[loc].poll()] += i - loc;
                            }
                            ans += (long) (i - loc) * (cnt[loc] - c);
                            cnt[loc] = c;
                        }
                    }
                    loc--;
                    if (loc < 0) {
                        break out;
                    }
                }
            }
            loc = Math.min(loc , i-1);
        }
        loc = m-1;
        for (int i = 0; i < m; i++) {
            if(cnt[i] == c) continue;
            int dif = c - cnt[i];
            if(dif<0){
                System.out.println(i + " " + cnt[i]);
                return;
            }
            while (true){
                if(cnt[loc]>c) {
                   if(cnt[loc] -c >= dif){
                       cnt[loc] -= dif;
                       int d = dif;
                       while (d>0){
                           d--;
                           g[arr[loc].poll()] += i+m-loc;
                       }
                       ans += (long)(i+m-loc)*(dif);
                       cnt[i] = c;
                       break;
                   }else {
                       cnt[i] += cnt[loc]- c;
                       int d = cnt[loc] - c;
                       while (d>0){
                           d--;
                           g[arr[loc].poll()] += i+m-loc;
                       }
                       dif -= cnt[loc]- c;
                       ans += (long)(i+m-loc)*(cnt[loc] - c);
                       cnt[loc] = c;
                   }
                }
                loc--;
            }
        }
        out.println(ans);
        for(int a: g){
            out.print(a  + " ");
        }
    }

}
