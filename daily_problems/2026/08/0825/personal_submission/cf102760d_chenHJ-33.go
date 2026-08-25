package main

import (
	"fmt"
	"slices"
)

func main() {
	var n int
	fmt.Scan(&n)
	m := n * (n - 1) / 2
	arr := make([]int64, m)
	for i := range m {
		fmt.Scan(&arr[i])
	}
	slices.Sort(arr)
	mi := int64(0)
	mx := int64(0)
	for i := range n - 1 {
		mi += arr[i]
	}
	for i := 1; i <= n-1; i++ {
		mx += arr[i*(i-1)/2]
	}
	fmt.Println(mi, mx)
}
