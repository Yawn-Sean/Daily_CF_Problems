package main

import (
	"cmp"
	"fmt"
	"slices"
)

func main() {
	var n int
	fmt.Scan(&n)
	arr := make([][]int, n)
	for i := range n {
		arr[i] = make([]int, 2)
		fmt.Scan(&arr[i][0], &arr[i][1])
	}
	order := make([]int, n)
	for i := range n {
		order[i] = i
	}
	slices.SortFunc(order, func(a int, b int) int {
		if c := cmp.Compare(arr[a][0], arr[b][0]); c != 0 {
			return cmp.Compare(arr[a][0], arr[b][0])
		} else {
			return cmp.Compare(arr[a][1], arr[b][1])
		}
	})
	for i := n - 2; i >= 0; i-- {
		order = append(order, order[i])
	}
	fmt.Println(2*n - 1)
	for i := range order {
		fmt.Print(order[i]+1, " ")
	}
	fmt.Println()
}
