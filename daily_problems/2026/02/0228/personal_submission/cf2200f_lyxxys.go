type hp struct{ data []int }
func (h hp) Len() int           { return len(h.data) }
func (h hp) Less(i, j int) bool { return h.data[i] < h.data[j] }
func (h hp) Swap(i, j int)      { h.data[i], h.data[j] = h.data[j], h.data[i] }
func (h *hp) Push(x any) { h.data = append(h.data, x.(int)) }
func (h *hp) Pop() any {
	old := h.data
	v := old[len(old)-1]
	h.data = old[:len(old)-1]
	return v
}

func main() {
	in, out := bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n, m, T, x, y int
	for fmt.Fscan(in, &T); T > 0; T-- {
		fmt.Fscan(in, &n, &m)
		buk := make([][]int, n+1)
		f := make([]int, n+1)
		for i := range buk {
			buk[i] = make([]int, 0)
		}
		for range n {
			fmt.Fscan(in, &x, &y)
			buk[y] = append(buk[y], x)
		}
		var ma, sm int
		pq := hp{data: make([]int, 0)}
		heap.Init(&pq)

		for i := n; i >= 0; i-- {
			for _, v := range buk[i] {
				heap.Push(&pq, v)
				sm += v
			}
			for pq.Len() > i+1 {
				sm -= heap.Pop(&pq).(int)
			}
			ma = max(ma, sm)

			if pq.Len() > 0 {
				if pq.Len() == i+1 {
					f[i] = sm - pq.data[0]
				} else {
					f[i] = sm
				}
			}
		}
		for i := 1; i <= n; i++ {
			f[i] = max(f[i], f[i-1])
		}
		for i := range m {
			if i > 0 {
				fmt.Fprintf(out, " ")
			}
			fmt.Fscan(in, &x, &y)
			fmt.Fprintf(out, "%d", max(ma, x+f[y]))
		}
		fmt.Fprintln(out)
	}
}
