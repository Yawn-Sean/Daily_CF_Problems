func cf103785h(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
 
	var n int
	Fscan(in, &n)
	arr := make([]int, n)
	ans := make([]int, 0)
	for i := 0; i < n; i++ {
		Fscan(in, &arr[i])
		arr[i] -= 1
	}
 
	for i := 0; i < n; i++ {
		for j := n - 1 - i; j >= 0; j-- {
			if arr[j] == j {
				ans, arr = append(ans, j), append(arr[0:j], arr[j+1:]...)
				break
			}
		}
		if len(ans) != i+1 {
			break
		}
	}
	if len(ans) == n {
		Fprintln(out, "YES")
		for i := range ans {
			ans[i] += 1
		}
		reverse(ans)
		Fprintln(out, strings.Trim(Sprintf("%v", ans), "[]"))
	} else {
		Fprintln(out, "NO")
	}
}
