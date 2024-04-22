public class cfsubmit {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int a = sc.nextInt();
        int b = sc.nextInt();
        long sum = a + b;
        long x = (long)Math.sqrt(sum * 2);
        if(x * (x + 1) > sum * 2) x--;
        long temp = x;
        while (a < x){
            x--;
        }
        int[] arr = new int[(int) temp + 1];
        int count = 0;
        while (x > 0) {
            if(a >= x){
                a -= (int) x;
                count++;
                arr[(int) x] = 1;
            }
            x--;
        }
        int count2 = (int)temp - count;
        out.println(count);
        for (int i = arr.length - 1; i > 0; i--) {
            if(arr[i] == 1) out.print(i + " ");
        }
        out.println("\n" + count2);
        for (int i = arr.length - 1; i > 0; i--) {
            if(arr[i] == 0) out.print(i + " ");
        }
        sc.close();
        out.close();
    }
}
