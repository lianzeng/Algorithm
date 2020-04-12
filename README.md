 ## Algorithm and Data Structure implementation using C++ with gtest framework.
 
 All of the algorithm is written in C++11 online [cyber dojo](http://www.cyber-dojo.org) . All the code is  written by zeng,liang.  
 
  Note: if you open the URL, please Don't modify the source code.
 
 Currently, I have complete the following programme:
 

 1.[Heap(minHeap,maxHeap)](https://www.cyber-dojo.org/kata/edit/c1s9FT) 最小堆，最大堆
 
 2.[remove duplicated elements from unsorted forward list](https://www.cyber-dojo.org/kata/edit/5hjsjc)从无序单链表移除重复元素
 
 3.[reverse forward list](https://www.cyber-dojo.org/kata/edit/v5m7qX) 反转单链表
 
 4.[hano tower]( https://www.cyber-dojo.org/kata/edit/4gSMuM) 汉诺塔
 
 5.[common code pucch design(class design)]( https://www.cyber-dojo.org/kata/edit/qyLeL5) C++模板+继承
 
 6.[median of two sorted array](  https://www.cyber-dojo.org/kata/edit/Z7Ymf5) 两个有序数组的中值
 
 7.[bowling game](   https://www.cyber-dojo.org/kata/edit/TQDmzJ) 保龄球游戏
 
 8.[merge sort(recursive and non-recursive)]( https://www.cyber-dojo.org/kata/edit/H3F2Cg) 归并排序，递归 + 非递归
 
 9.[quick sort (recursive and non-recursive)]( https://www.cyber-dojo.org/kata/edit/3bL8dx ) 快速排序，递归 +  非递归
 
 10.[binary search for sorted vector]( https://www.cyber-dojo.org/kata/edit/lzkFVV)  二分查找
 
 11.[Count Coins  ]( https://www.cyber-dojo.org/kata/edit/ejFa3H) 硬币组合，递归+非递归
 
 12.[Balanced Parentheses]( https://www.cyber-dojo.org/kata/edit/qyPKzS) 括号配对
 
 13.[24点游戏]( https://www.cyber-dojo.org/kata/edit/DnVATL ) 关键是数据结构的设计，用来回溯计算过程
 
 14.[anagrams变位词,](https://www.cyber-dojo.org/kata/edit/Lnunpj) 全排列

 15.[Eight Queens]( https://www.cyber-dojo.org/kata/edit/UMrKTK)  八皇后
 
 16.[fibonacci](  https://www.cyber-dojo.org/kata/edit/HZz4Qv)  斐波那契
 
 17.[Find Path Avoid Obstacles]( https://www.cyber-dojo.org/kata/edit/EPQyRr) 躲避障碍寻路
 
 18.[Factorize prime factors](  https://www.cyber-dojo.org/kata/edit/NygRte) 质因数分解
 
 19.[magic square(数独游戏)](https://www.cyber-dojo.org/kata/edit/nzY139)  给定一个数列，组成3*3方正，任何一行/列/对角的和都相等，递归实现，每次递归选一行数，剪枝策略：行和=sum/3;代码非常的清晰易懂(宏函数技巧使用)，一气呵成，使用了bitset来辅助选择数字;
 
 20.[数独游戏golang版本，打印所有结果](https://www.cyber-dojo.org/kata/edit/cLgCs7) , 代码简洁清晰


 21.[array shuffle]( https://www.cyber-dojo.org/kata/edit/9Pyuja)
 
 22.[combine to largest number](  https://www.cyber-dojo.org/kata/edit/pFecgM )
 
 23.[find adjacent 1bits number(Diversion)]( https://www.cyber-dojo.org/kata/edit/bUyltJ ) 非常难得的一题，打印详细状态转换，迭代递推思路清晰，N bit的数是由N-1 bit的数在尾部扩展1bit(=0 ,1), 假定(N-1) bit 的数分成2组S+V，S组满足条件（has adjacent 1），V组不满足条件(又细分为偶数组和奇数组：Vodd+Veven)，奇数组是潜在转化组，只要尾部加bitvalue=1就转移到S组，由此得出结论：N bit的S组=(Sn-1) + Vodd_n-1 ； Vodd_n = Vn-1 - 转正(Vodd_n-1); Veven_n = 不满足条件 = Vn-1; 得到2个递推公式为： Sn=2*Sn-1 + VOddn-1; Voddn=Vn-1 - Voddn-1 = power(2, n-1)-Sn-1 - Voddn-1,进一步抽象得到2个公式：Yn=f1(Yn-1, Xn-1); Xn = f2(Yn-1, Xn-1); 这是一个二元状态转移方程，也是2维动态规划问题。
 
 24.[spell number in english]( https://www.cyber-dojo.org/kata/edit/cGEJm8) 
 

 
 26.[remove duplicate from unsorted list]( https://www.cyber-dojo.org/kata/edit/Hw2ARG)
 
 27.[buy book with best discount, DP. use Cache and Quick-Cut to improve performance(if not cache, will run long long time..)](  https://www.cyber-dojo.org/kata/edit/e1eWD3 )  codeJam, 动态规划，使用缓存和减枝 来加速
 
 28.[BigNumberPlus(大数相加)]( https://www.cyber-dojo.org/kata/edit/aFuWaw ) codeJam
 
 29.[SearchPath Any Start&&End, with required steps](https://www.cyber-dojo.org/kata/edit/UjAYAc) 路径搜索
 
 30.[Candy Dispatch]( https://www.cyber-dojo.org/kata/edit/SEuu9L)  codeJam
 
 31.[DFS-BFS(非递归遍历)](https://www.cyber-dojo.org/kata/edit/McTXNQ) 深度，广度 遍历，非递归
 
 32.[Red-Black-BST(print)]( https://www.cyber-dojo.org/kata/edit/Xvs1Q0) 打印红黑树

 33.[BTree(print)](  https://www.cyber-dojo.org/kata/edit/BYqkde)  打印B树
 
 34.[queue(implement with cycle-array) ](  https://www.cyber-dojo.org/kata/edit/N2QHpV) 实现有界队列

 35.[List(BiLinkList,iterator)](  https://www.cyber-dojo.org/kata/edit/lw9bKt) 实现迭代器
 
 36.[rar payload build(3GPP)](  https://www.cyber-dojo.org/kata/edit/Aefhn3) 
 
 37.[reverse integer](  https://www.cyber-dojo.org/kata/edit/sccC5U)   数值反转
 
 38.[string to integer(atoi)](  https://www.cyber-dojo.org/kata/edit/MDvnxW)  字符串转数值
 
 39.[remove Nth node from End of list](  https://www.cyber-dojo.org/kata/edit/sDqsuP) 从链表移除倒数第N个节点

 40.[merge two sorted lists]( https://www.cyber-dojo.org/kata/edit/0bLbwY)  归并2个有序链表,代码简洁优雅
 
 41.[decorator c11](https://www.cyber-dojo.org/kata/edit/nTHRcg) 装饰者模式
 
 42.[cJSON test case](https://www.cyber-dojo.org/kata/edit/1dhMxs )  写的几个测试用例基本覆盖了cJSON库的用法,由于cJSON.h原始文件太大，会被cyberDojo截断，所以没法跑，但是在本地可以跑过, cJSON Github: https://github.com/DaveGamble/cJSON
 
 
 
