package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var queue []int

func enqueue(value int) {
	queue = append(queue, value)
}

func dequeue() int {
	v := queue[0]
	queue[0] = 0
	queue = queue[1:]
	return v
}

func main() {
	var N, K int
	var sol string

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d %d", &N, &K)

	// N 크기의 배열을 만든다.
	queue = make([]int, N)

	if(N == 1 && K == 1) {
		fmt.Println("<1>")
		return
	}

	// 1, 2 ... N 의 데이터를 queue에 입력한다
	for i := 0; i < N; i++ {
		queue[i] = i+1
	}

	for i := 0; i < N; i++ {
		for j := 0; j < K; j++ {
			if j + 1 == K {
				tmp := dequeue()

				if i == 0 {
					sol += "<" + strconv.Itoa(tmp) + ", "
				} else if i == N-1 {
					sol += strconv.Itoa(tmp) + ">"
				} else {
					sol += strconv.Itoa(tmp) + ", "
				}
			} else {
				tmp := dequeue()
				enqueue(tmp)
			}
		}
	}

	fmt.Println(sol)
}

//<3, 6, 2, 7, 5, 1, 4>
