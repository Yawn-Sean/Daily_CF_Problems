
public class cf609d_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);


    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int k = sc.ni();
        int s = sc.ni();
        int[] A = sc.na(n);
        int[] B = sc.na(n);
        int[] indexA = new int[n];
        int[] indexB = new int[n];
        for (int i = 0; i < n; i++) {
            indexB[i] = i;
            indexA[i] = i;
        }
        for (int i = 1; i < n; i++) {
            if(A[i]>A[i-1]){
                A[i] = A[i-1];
                indexA[i] = indexA[i-1];
            }
            if(B[i]>B[i-1]){
                B[i] = B[i-1];
                indexB[i] = indexB[i-1];
            }
        }

        ArrayList<int[]> c1 = new ArrayList<>();
        ArrayList<int[]> c2 = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int a = sc.ni();
            int b = sc.ni();
            if(a == 1){
                c1.add(new int[]{b,i});
            }else {
                c2.add(new int[]{b,i});
            }

        }
        c1.sort((a,b)->Integer.compare(a[0], b[0]));
        c2.sort((a,b)->Integer.compare(a[0], b[0]));
        int s1 = c1.size(), s2 = c2.size();
        int l = 0, r = n;
        int loc1 = 0, loc2 = 0;
        while (l < r){
            int mid = l + r >> 1;
            loc1 = 0;
            loc2 = 0;
            long tot = 0;
            for (int i = 0; i < k; i++) {
                if(loc1 == s1){
                    tot += (long)c2.get(loc2)[0] * B[mid];
                    loc2++;
                }else if(loc2 == s2){
                    tot += (long)c1.get(loc1)[0] * A[mid];
                    loc1++;
                }else if((long)c1.get(loc1)[0] *A[mid] < (long)c2.get(loc2)[0] * B[mid]){
                    tot += (long)c1.get(loc1)[0] * A[mid];
                    loc1++;
                }else {
                    tot += (long)c2.get(loc2)[0] * B[mid];
                    loc2++;
                }
            }

            if(tot<=s){
                r = mid;
            }else {
                l = mid+1;
            }
        }
        if(l == n){
            out.println(-1);
            return;
        }
        out.println(l+1);
        loc1 = 0;
        loc2 = 0;
        List<String> ans = new ArrayList<>();

        for (int i = 0; i < k; i++) {
             if(loc2 == s2 || (loc1 != s1 && (long)c1.get(loc1)[0] *A[l] < (long)c2.get(loc2)[0] * B[l])){
                 ans.add( (c1.get(loc1)[1] + 1) + " " + (indexA[l] + 1));
                loc1++;
            }else {
                 ans.add( (c2.get(loc2)[1] + 1) + " " + (indexB[l] + 1));
                loc2++;
            }
        }
        for(String a: ans){
            out.println(a);
        }

    }
}
