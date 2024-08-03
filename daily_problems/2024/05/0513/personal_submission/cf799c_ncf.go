package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() { CF799C(os.Stdin, os.Stdout) }

type bp799c struct {
	b, p int
}

func CF799C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, c, d, b, p int
	fmt.Fscan(in, &n, &c, &d)

	var cc, dd []bp799c
	var chr string
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &b, &p, &chr)
		if chr == "C" {
			cc = append(cc, bp799c{b, p})
		} else {
			dd = append(dd, bp799c{b, p})
		}
	}

	sort.Slice(cc, func(i, j int) bool { // C根据造价倒序排序
		return cc[i].p > cc[j].p
	})
	sort.Slice(dd, func(i, j int) bool { // D根据造价倒序排序
		return dd[i].p > dd[j].p
	})
	ans := 0
	sufCc := make([]int, len(cc)+1) // C的后缀最大美观程度
	sufDd := make([]int, len(dd)+1) // D的后缀最大美观程度
	for i := len(cc) - 1; i > -1; i-- {
		sufCc[i] = max(sufCc[i+1], cc[i].b)
	}
	for i := len(dd) - 1; i > -1; i-- {
		sufDd[i] = max(sufDd[i+1], dd[i].b)
	}
	flag := false // 用于标记是否能凑够两个
	idx1 := len(cc) - 1
	for idx1 > -1 && cc[idx1].p <= c { // 只选C
		idx := max(idx1+1, getIndex(cc, c-cc[idx1].p)) // 二分剩余的造价找到能购买的最小索引
		if idx < len(cc) {
			ans = max(ans, cc[idx1].b+sufCc[idx])
			flag = true
		}
		idx1 -= 1
	}
	idx2 := len(dd) - 1
	for idx2 > -1 && dd[idx2].p <= d { // 只选D
		idx := max(idx2+1, getIndex(dd, d-dd[idx2].p)) // 二分剩余的造价找到能购买的最小索引
		if idx < len(dd) {
			ans = max(ans, dd[idx2].b+sufDd[idx])
			flag = true
		}
		idx2 -= 1
	}
	if len(cc)-(idx1+1) > 0 && len(dd)-(idx2+1) > 0 {
		ans = max(ans, sufCc[idx1+1]+sufDd[idx2+1]) // 两边各选一个
		flag = true
	}
	if !flag {
		fmt.Fprintf(out, "0")
	} else {
		fmt.Fprintf(out, "%d", ans)
	}
}

func getIndex(arr []bp799c, val int) int {
	l, r := 0, len(arr)-1
	for l <= r {
		mid := (l + r) / 2
		if arr[mid].p > val {
			l = mid + 1
		} else {
			r = mid - 1
		}
	}
	return l
}
