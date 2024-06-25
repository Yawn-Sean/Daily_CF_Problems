public class cfsubmit {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int m = sc.nextInt();
            int min = Integer.MAX_VALUE;
            int[] arr = new int[m];
            int[] count = new int[m + 1];
            List<Integer> list = new ArrayList<>();
            for (int j = 0; j < m; j++) {
                arr[j] = sc.nextInt();
                count[arr[j]]++;
            }
            for(Integer x : count){
                if(x != 0){
                    list.add(x);
                    min = Math.min(x,min);
                }
            }
            int ans = m;
            for (int j = 1; j <= min + 1; j++) {
                int cnt = 0;
                for(Integer x : list){
                    int temp = x;
                    int cur = (temp - 1) / (j + 1) + 1;
                    cnt += cur;
                    if(cur * j > temp){
                        cnt = m;
                        break;
                    }
                }
                if(cnt < ans){
                    ans = cnt;
                }
            }
            out.println(ans);
        }
        sc.close();
        out.close();
    }
}
