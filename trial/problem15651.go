package main

import (
	"fmt"
)

var N, M int
var sol []int

func main() {
	fmt.Scanf("%d %d", &N, &M)
	sol = make([]int, M)

	f(0, 0)
}

func f(length int, j int){
	if(length == M) {
		for k := 0; k < M; k++ {
			fmt.Printf("%d ", sol[k])
		}
		fmt.Printf("\n")
		return
	}

	for i := 0; i < N; i++ {
		sol[j] = i+1
		f(length + 1, j+1)
		sol[j] = 0
	}
}