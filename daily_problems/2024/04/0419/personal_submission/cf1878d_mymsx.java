public class cfsubmit {
    public static void main(String[] args) {
        CF cf = new CF();
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int t = sc.nextInt();
        while (t-->0){
            int m = sc.nextInt();
            int n = sc.nextInt();
            sc.nextLine();
            String str = sc.nextLine();
            int[] left = new int[n];
            int[] right = new int[n];
            for (int i = 0; i < n; i++) {
                left[i] = sc.nextInt();
            }
            for (int i = 0; i < n; i++) {
                right[i] = sc.nextInt();
            }
            int x = sc.nextInt();
            int[] query = new int[x];
            for (int i = 0; i < x; i++) {
                query[i] = sc.nextInt();
            }
            out.println(cf.resString(str,left,right,query));
        }
        sc.close();
        out.close();
    }
}
class CF{
    public String resString(String str,int[] left,int[] right,int[] x) {
        StringBuilder sb = new StringBuilder(str);
        int[] group = new int[sb.length()];
        Arrays.fill(group,-1);
        int[] diff = new int[str.length() + 1];
        for (int i = 0; i < left.length; i++) {
            for (int j = left[i] - 1; j <= right[i] - 1; j++) {
                group[j] = i;
            }
        }
        for (int j : x) {
            int index = group[j - 1];
            int y = left[index] + right[index] - 1 - j;
            int a = Math.max(j - 1, y);
            int b = Math.min(j - 1, y);
            diff[b] ^= 1;
            diff[a + 1] ^= 1;
        }
        for (int i = 0; i < str.length(); i++) {
            diff[i + 1] ^= diff[i];
        }
        for (int i = 0; i < str.length(); i++) {
            double t = (left[group[i]] + right[group[i]] - 2) / 2.0;
            if(diff[i] % 2 == 1 && i < t){
                char temp = sb.charAt(i);
                sb.setCharAt(i, sb.charAt((int) ((2 * t) - i)));
                sb.setCharAt((int) (2 * t - i),temp);
            }
        }
        return sb.toString();
    }
}
