import java.util.HashSet;
import java.util.Objects;
import java.util.Set;

public class cf1147b_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        Set<Pair> set = new HashSet<>();
        for (int i = 0; i < m; i++) {
            int a = sc.ni()-1;
            int b = sc.ni()-1;
            if(a < b){
                int tem = a;
                a = b;
                b = tem;
            }
            set.add(new Pair(a, b));
        }
        int tem = n;
        for (int i = 2; i <=n ; i++) {
            if(n%i==0){
                while (n%i==0){
                    n/=i;
                }
                int x = tem/i;
                boolean f = true;
                for(Pair p : set){
                    int a = (p.i + x)%tem;
                    int b = (p.j + x)%tem;
                    if(!set.contains(new Pair(a,b)) && !set.contains(new Pair(b,a))){
                        f = false;
                        break;
                    }

                }
                if(f){
                    out.println("Yes");
                    return;
                }
            }
        }
        out.println("No");
    }
    static class Pair {

        int i;
        int j;

        Pair(int i, int j) {
            this.i = i;
            this.j = j;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }
            Pair pair = (Pair) o;
            return i == pair.i && j == pair.j;
        }

        @Override
        public int hashCode() {
            return Objects.hash(i, j);
        }
    }
}
