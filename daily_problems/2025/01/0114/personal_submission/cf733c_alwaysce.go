package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

func CF733C(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, k int
	Fscan(in, &n)
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		Fscan(in, &nums[i])
	}

	type tuple struct {
		idx, dir int
	}
	pt, start_idx := 0, 1
	ans := make([]tuple, 0)
	Fscan(in, &k)

	for ; k > 0; k-- {
		var v int
		Fscan(in, &v)
		l := pt
		cur := 0
		for pt < n && cur < v {
			cur += nums[pt]
			pt++
		}
		r := pt

		if cur != v {
			Fprintln(out, "NO")
			return
		}

		if r-l > 1 {
			mx := 0
			for i := l; i < r; i++ {
				if nums[i] > mx {
					mx = nums[i]
				}
			}

			find := false
			for i := l; i < r; i++ {
				if nums[i] == mx {
					if i > l && nums[i] > nums[i-1] {
						find = true
						for j := i - 1; j >= l; j-- {
							// 0 for L
							ans = append(ans, tuple{start_idx + j + 1 - l, 0})
						}
						for j := i + 1; j < r; j++ {
							// 1 for R
							ans = append(ans, tuple{start_idx, 1})
						}
						break
					} else if i+1 < r && nums[i] > nums[i+1] {
						find = true
						for j := i + 1; j < r; j++ {
							// 0 for L
							ans = append(ans, tuple{start_idx + i - l, 1})
						}
						for j := i - 1; j >= l; j-- {
							// 1 for R
							ans = append(ans, tuple{start_idx + j + 1 - l, 0})
						}
						break
					}
				}
			}
			if !find {
				Fprintln(out, "NO")
				return
			}
		}
		start_idx++
	}
	if pt < n {
		Fprintln(out, "NO")
		return
	}
	Fprintln(out, "YES")
	for _, v := range ans {
		if v.dir == 0 {
			Fprintln(out, v.idx, "L")
		} else {
			Fprintln(out, v.idx, "R")
		}
	}
}

func main() {
	CF733C(bufio.NewReader(os.Stdin), os.Stdout)
}
