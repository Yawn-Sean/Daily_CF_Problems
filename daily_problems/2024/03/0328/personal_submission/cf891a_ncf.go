func main() { CF891A(os.Stdin, os.Stdout) }

func min891a(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func gcd891a(a int, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
// 暴力
func CF891A(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	count1 := 0
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		if a[i] == 1 {
			count1 += 1
		}
	}
	if count1 > 0 {
		fmt.Fprintf(out, "%d ", n-count1)
	} else {
		count := math.MaxInt
		for i := 0; i < n; i++ {
			cur := a[i]
			j := i + 1
			for ; cur > 1 && j < n; j++ {
				cur = gcd891a(a[j], cur)
			}
			if cur == 1 {
				count = min891a(j-i, count)
			}
		}
		if count == math.MaxInt {
			fmt.Fprintf(out, "-1")
		} else {
			fmt.Fprintf(out, "%d ", n+count-2)
		}
	}
}

// 二分线段树 https://codeforces.com/problemset/submission/891/253568391
//func CF891A(_r io.Reader, out io.Writer) {
//	in := bufio.NewReader(_r)
//	var n int
//	fmt.Fscan(in, &n)
//	a := make([]int, n)
//	count1 := 0
//	for i := 0; i < n; i++ {
//		fmt.Fscan(in, &a[i])
//		if a[i] == 1 {
//			count1 += 1
//		}
//	}
//	if count1 > 0 {
//		fmt.Fprintf(out, "%d ", n-count1)
//	} else {
//		st := BuildSegmentTreeRangeGcd(a)
//		count := math.MaxInt
//		for i := 0; i < n; i++ {
//			l, r := i, n-1
//			for l <= r {
//				mid := l + (r-l)/2
//				v := st.QueryRange(i, mid)
//				if v > 1 {
//					l = mid + 1
//				} else {
//					r = mid - 1
//				}
//			}
//			if l < n {
//				count = min891a(l-i, count)
//			}
//		}
//		if count == math.MaxInt {
//			fmt.Fprintf(out, "-1")
//		} else {
//			fmt.Fprintf(out, "%d ", n+count-1)
//		}
//	}
//}
