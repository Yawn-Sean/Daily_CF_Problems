# Submission link: https://codeforces.com/contest/965/submission/260873863
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var w, l int
	Fscan(in, &w, &l)
	nums := make([]int, w-1)
	for i := range nums {
		Fscan(in, &nums[i])
	}
	cur := 0
	for _, c := range nums[:l] {
		cur += c
	}
	ans := cur
	for i := 0; i+l < w-1; i++ {
		cur += nums[i+l]
		cur -= nums[i]
		ans = min(ans, cur)
	}
	Fprintln(out, ans)
}