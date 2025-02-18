public class Main{    
	private static void solve() throws IOException {
        int n = sc.nextInt(), b = sc.nextInt();
        Deque<Long> deque = new LinkedList<>();
        while (n-- > 0) {
            long start = sc.nextLong(), x = sc.nextLong();
            while (!deque.isEmpty() && deque.peekFirst() <= start) {
                deque.pollFirst();
            }
            if (deque.size() > b) {
                sc.print(-1 + " ");
            }else{
                if (!deque.isEmpty()) {
                    start = Math.max(start, deque.peekLast());
                }
                sc.print((start + x) + " ");
                deque.offerLast(start + x);
            }
        }
    }
}
