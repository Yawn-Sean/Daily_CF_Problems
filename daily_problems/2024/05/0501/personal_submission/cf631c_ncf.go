package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() { CF631C(os.Stdin, os.Stdout) }

func CF631C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, m int
	fmt.Fscan(in, &n, &m)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	t := make([][]int, m)
	for i := 0; i < m; i++ {
		t[i] = make([]int, 2)
		fmt.Fscan(in, &t[i][0], &t[i][1])
	}
	var st []int
	for i := m - 1; i > -1; i-- {
		if len(st) == 0 || t[i][1] > t[st[len(st)-1]][1] {
			st = append(st, i)
		}
	}
	mx := t[st[len(st)-1]][1]
	nums := make([]int, mx)
	for i := 0; i < mx; i++ {
		nums[i] = a[i]
	}
	sort.Ints(nums)
	l, r := 0, mx-1
	for len(st) > 0 {
		cur := st[len(st)-1]
		st = st[:len(st)-1]
		nextVal := 0
		if len(st) > 0 {
			nextVal = t[st[len(st)-1]][1]
		}
		v := t[cur][1] - nextVal
		for i := 0; i < v; i++ {
			if t[cur][0] == 1 {
				a[t[cur][1]-i-1] = nums[r]
				r -= 1
			} else {
				a[t[cur][1]-i-1] = nums[l]
				l += 1
			}
		}
	}
	for i := 0; i < n; i++ {
		fmt.Fprintf(out, "%d ", a[i])
	}
}
