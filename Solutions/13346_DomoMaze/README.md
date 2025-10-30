# Problem 13346 - DomoMaze
[NTHUOJ Problem 13346 - DomoMaze](https://acm.cs.nthu.edu.tw/problem/13346/)


We use dynamic programming when there's no (1) and use recursion when there is (1)


Imagine the largest map, 15 x 15

If there's no (1), only (0)s, then the number of possibilities can be thousands ~ millions.

That's why we use dynamic programming because it works


However, if there's (1), the possibilities can be BILLIONS or possibly more than that,

even if we use dynamic programming, we will always get TLE.


That's why we know for sure that the TA will not make a large map when there's (1)

In this case, recursion works


## Topics
- Dynamic Programming
- Recursion
- 2D Array


## References
- [Dynamic Programming - GeeksforGeeks](https://www.geeksforgeeks.org/dynamic-programming/#concepts)
- [Tabulation vs. Memoization](https://www.geeksforgeeks.org/tabulation-vs-memoization/)
- [What is the difference between bottom-up and top-down?](https://stackoverflow.com/questions/6164629/what-is-the-difference-between-bottom-up-and-top-down)
- [演算法筆記 - Dynamic Programming](http://web.ntnu.edu.tw/~algo/DynamicProgramming.html)


## Similar Problems
- [NTHUOJ Problem 13348 - DomoMaze - easy version](https://acm.cs.nthu.edu.tw/problem/13348/)
- [NTHUOJ Problem 14529 - Bidirectional DomoMaze](https://acm.cs.nthu.edu.tw/problem/14529/)