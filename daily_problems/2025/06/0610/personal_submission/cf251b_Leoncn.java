package daily_problems.2025.06.0610.personal_submission;

public class cf251b_Leoncn {
        public static void solve() {
        int n = sc.ni();
        int k = sc.ni();
        int[] q = sc.na(n);
        int[] tar = sc.na(n);
        int[] now = new int[n];
        for (int i = 0; i < n; i++) {
            now[i] = i + 1;
        }

        boolean v = true;
        for (int i = 0; i < n; i++) {
            if (i + 1 != tar[i]) {
                v = false;
                break;
            }
        }
        if(v){
            out.println("NO");
            return;
        }

        for (int i = 0; i < k; i++) {

            now = add(now, q);
            if(check(now, tar)){
                if( ((k - i - 1) & 1) == 0){
                    now = minus(now, q);
                    if( k-i-1>=2 && check(now, tar)){
                        break;
                    }
                    now = minus(now, q);
                    if(k-i-1>=2&&check(now, tar)){
                        break;
                    }
                    out.println("YES");
                    return;

                }
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            now[i] = i + 1;
        }
        for (int i = 0; i < k; i++) {
            now = minus(now, q);
            if(check(now, tar)){
                if( ((k - i - 1) & 1) == 0){
                    now = add(now, q);
                    if(k-i-1>=2 && check(now, tar)){
                        break;
                    }
                    now = add(now, q);
                    if(k-i-1>=2 && check(now, tar)){
                        break;
                    }

                    out.println("YES");
                    return;
                }
                break;
            }
        }
        out.println("NO");
    }

    private static boolean check(int[] now, int [] tar){
        boolean v = true;
        int n = now.length;
        for (int j = 0; j < n; j++) {
            if (tar[j] != now[j]) {
                v = false;
                break;
            }
        }
        return v;
    }

    private static int[] add(int[] now, int[] q) {
        int n = now.length;
        int[] tem = new int[n];
        for (int j = 0; j < n; j++) {
            tem[j] = now[q[j]-1];
        }
        return tem;
    }

    private static int[] minus(int[] now, int[] q) {
        int n = now.length;
        int[] tem = new int[n];
        for (int j = 0; j < n; j++) {
            tem[q[j]-1] = now[j];
        }
        return tem;
    }
}
