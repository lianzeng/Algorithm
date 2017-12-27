cyber-dojo 可以读新建的txt文件(所以可以把文件作为输入)，但不能写文件；

可以回到任何历史状态，不能做交互式的输入。可以中断后继续编码，实时保存；可以把sessionId分享给其它人参与，代码保持独立；可以给其它人review.
有时候网速慢会导致跑不出结果，这时候可以再跑一遍，不要误以为是死循环了。

递归+备忘 == 动态规划；
编程技巧：
0)VS2017 windows console project  , filepath:  
ifstream ifs("input.txt"); //the file is in same dir with current .cpp;
ifstream ifs("D:\\CodeJam\\BowlingGame\\input.txt"); //absolute path in windows
1) ? :  三目运算符与引用& 结合可以简化代码，举例：求3元素中值，merge sorted list中next指针移动.
2)使用hashMap时如果要把相同Key,不同value的元素插入，可以转换为： 封装为一个struct, 动态创建一个对象，把对象地址作为Key,因为地址天然是唯一的, shared_ptr<pair<key,value>>
   使用hashMap时一定要显示调用构造函数进行初始化(hashMap(30, myhash)，指定bucketSize,否则会导致coredump;   
3)比较容器元素： EXPECT_TRUE(std::equal(expect.begin(), expect.end(), strVec.begin() ));
4)排序:  std::sort(expect.begin(),expect.end()); 
5)array只有无参构造，通过fill函数给元素赋值，array可以用range-for.
6)递归与递推：考虑问题的出发点不同，前者是怎么由f(n)分解出f(n-1)，后者是考虑怎么由f(n-1)构造出f(n);
7)哈希表需要自定义hash(key),operator==(key),InitalBucketSize;  eg: 
   using HashMap = std::unordered_map<std::vector<int>, double, decltype(hash)*> ; 
   static size_t hash(const std::vector<int>& key){return key;}
   HashMap cache(1000, hash);
8).gtest : EXPECT_DOUBLE_EQ(); //for double ,use this , rather than EXPECT_EQ;
9).文件操作:  
ifstream ifs(filePathStr);  if (ifs.fail()) return error;  ifs.close();
std::ofstream ofs(dstFileName); ofs << std::to_string(i)<< "\n";  ofs.flush();  ofs.close();



0.gtest template: FAIL()<<"ways not correct";  
http://www.cyber-dojo.org/kata/edit/8B5E4EF5E6?avatar=jellyfish      


	1.  http://www.cyber-dojo.org/kata/edit/3EEE4CBBC3?avatar=turtle  Heap(minHeap,maxHeap), 采用了接口与实现隔离的技巧来实现模板类（2个header file，1个提供class定义，1个提供函数实现，不需要cppfile，也可以在cppfile实例化模板类）; 写的比较clean, 用了C++11的lambda表达式；

  1.   http://www.cyber-dojo.org/kata/edit/F115685DBC?avatar=jellyfish   remove duplicated elements from unsorted forward_list; 遍历链表，判断每个元素是否在之前出现过，是则删除；性能更好的方案：用哈希表unordered_map标记元素，直接查表；

	1.  http://www.cyber-dojo.org/kata/edit/9405BE8673?avatar=kangaroo   reverse forward_list; 逆序思想：遍历容器，让每个元素总是往新容器的头部插入!
	2.  判断链表有环： slow fast 2个指针，且每次fast指针比slow指针多走一步，如果在null前相遇就说明有环；
	3.  取出链表的前1/N的节点，不知道链表的总长度：用双指针，fast指针每次走N步，slow指针每次走一步。
	4. 寻找有环链表的交点：先用slow/fast指针找到相遇点，“这个相遇点与交点的距离” 等于 “链表头与交点的距离”，然后从表头和相遇点分别前进，碰撞点就是环的起点；参考《程序员面试金典》2.6题；
	5. 链表相交： 判断每个链表的最后一个节点地址是否相同；
	6. 从无头单链表ABC中删除指定节点B：先交换节点数据BC ,变成ACB,然后删除B，最后变成AC;
	7. 从1个数组中同时找最大最小值：1）分治法  2）相邻2个一组，swap, 大的在前，小的在后，这样再从偶数组找最大的，奇数组找最小的；
	8. 从N个数找最大的K个数： 用最小堆（size=K），堆顶的元素是最有可能被踢出去的，{ 如果后面的元素更大，替换堆顶，重新调整堆 }，遍历完成后留下来的堆中元素就是最大的K个；
	9. http://www.cyber-dojo.org/kata/edit/EA0518D02A?avatar=puffin 24点游戏, 输入4个数字生成数学公式=24，思路：先挑选2个数计算结果后放回去，变成3个数的子问题，精点在于数据结构的设计（需要记录中间结果的来源，用指针来比较对象的唯一性），Expression + Element , 这对数据结构的好处是递归，方便回溯公式的构造过程，递归过程中，如果子问题失败则回退到上一步。
	10. http://www.cyber-dojo.org/kata/edit/8B5E4EF5E6?avatar=ostrich  hano tower汉诺塔，递归实现+OOP，详细打印了盘子移动过程；
	11.  http://www.cyber-dojo.org/kata/edit/23057B90DF?avatar=lion   common code pucch design
	12. 链表删除节点的技巧：if(curr->next == toDelete) {curr->next = curr->next->next;} 因为删除节点时需要修改前驱节点的next值，所以一般是判断curr->next是否待删除，如果toDelete节点是head, 还要特殊处理；
	13. 数组排序：可以用一个额外的索引数组来记录真实顺序，避免直接对原数组交互，提升性能；
	14. 位运算技巧：参考自己的笔记<C专家编程>，最重要的技巧：i & (i - 1) 把最低位的1清零；
	15. count 1的bit位数: 1)移位计数 ；2 )查表：做一个OnesNum[256]记录0~255这个范围的数的1的个数，然后按8bit移位，查表；
	16. 二叉数遍历总结：采用迭代遍历时，每个节点会遇见2次，先判断当前的节点状态是处于自顶向下递归中还是自底向上回溯中（这个状态是节点级别的），如果当前节点的左右子节点都是unvisited，那就处于递归中，需要把子女节点都入栈，否则处于回溯中，不需要再做入栈动作（因为已经在栈中），也就是说只有该节点在递归中才有入栈操作。每个节点访问状态有3种：unvisited(从没压入栈), visiting(正处于栈中), visited(已经从栈中弹出了);在回溯过程中左右子节点是有区别的，因为左节点访问之后还要访问右节点，而右节点访问之后就要回溯了；
	17. 递归：2种方式构建最终解：a）先找到子问题的解，然后combine得到当前问题解并返回，表现为：递归函数有返回值，比如归并排序；b)每层递归得到一部分解，然后把这个解传递给下一层，最终在叶子节点得到解，表现为：递归函数有一个参数用于传递解，比如8皇后问题，硬币挑选；
	18. 

	19. 递归解的构造方法：1)Top -> Down, 上层的结果向下层传递，如果下层返回失败则需要回退，在最底层会得到完整结果，2)Down->Top: 下层的结果向上层传递，如果下层OK，上层在此基础上增加新的结果，如果下层失败则不添加，继续返回失败；
	20. 递归函数参数传递：如果要把一个函数的结果往外传递，可以通过返回值，引用参数（要特别小心），全局变量，成员变量；关键是找出递归函数中哪些参数是变化的，哪些不变，变化的参数能否导致问题收敛，递归函数应该返回什么；如何通过举例子找出状态变量归纳出递推公式；
	21. 剪枝：深搜中的加速技巧，在决定进一步递归前，判断是否满足条件，不满足就return，如果之前有保存操作那return前需要撤销动作;   
	22. 备忘录和动态规划的区别：备忘录是用于自顶向下的递归(getOrUpdate)，DP是自底向上的迭代，有时两者不区分；
	23. 斐波那契数：f(n)=f(n-1)+f(n-2); 两种实现方式：a)自底向上迭代,利用a[2]缓存； b)递归+备忘(getOrUpdate);
	24. 回溯思想：递归中的一种，从终点向起点递归，比如：机器人从一个矩阵的左上角走到右下角（中间有障碍），这种问题就适合用回溯：根据当前这一步反推上一步的位置；
	25. 

	26. http://www.cyber-dojo.org/kata/edit/C86CA72338?avatar=gopher median of two sorted array; using max-heap & min-heap;

  26. http://cyber-dojo.org/kata/edit/337C5BC2C9?avatar=ostrich 保龄球,bowling game, add  class to parse test input file and write result to file(clean code using fstream);
  27.二维动态规划： f[i][j] = func(f[i-1][j-1], f[j-1][i], f[i-1][j]); func = max, min.. 用迭代方式计算时先分别求出f[i][0], f[0][j]，这个依赖具体问题， 然后根据公式迭代求f[i][j];
       最关键的是正确表达状态变量f[i][j] 以及构建递推函数； 举例：两个string的转换，利用最少的操作(replace,delete,insert);
  28.由一个根节点生成树的方法：使用Queue,如果当前节点需要生成子节点，把新子节点加入queue, 然后从queue中取下一个节点，直到Queue为空，效果类似层序遍历方式产生新节点。

	1.   http://www.cyber-dojo.org/kata/edit/4E83487C30?avatar=ray 归并排序 merge sort in both recursive and non-recursive(post-order traversal), a good program I've ever made;
	2. http://www.cyber-dojo.org/kata/edit/95555C4F5A?avatar=seal  快排，quick sort in both recursive and non-recursive(pre-order traversal),they have common method, a good program I've ever made,求3元素的中值代码简洁优美;
	3. http://www.cyber-dojo.org/kata/edit/54403B2B1A?avatar=penguin binary search for sorted vector. 因为只需要在一边查找（左边，右边是互斥的 ），所以迭代实现不需要用stack来缓存，只需要更新迭代变量;

  32 . http://www.cyber-dojo.org/kata/edit/56A76507E2?avatar=alligator 硬币组合，打印所有的组合情况，递归+非递归。
         非递归实现(层序遍历，每个币值对应一层，叶子节点就是最小币值，使用Queue，从顶向下扩展答案，QueueNode = pair<newProblem, HistorySolution>)，QueueNode包含2部分：新的子问题和历史选择，历史选择在不断的累积直到叶子节点。  
         递归结果的构造(自底向上)中子树区间的界定（extendWaysWithNewCoin:waysStart,NumWays），这个子树可以缓存(hashMap<problem, solution>,  solution=vector<vector<T>>)，test结果会输出cacheMiss, cacheHit,  getOrUpdate() 函数实现的非常棒！！
         每个解决方案其实就是一个叶子节点到根节点的路径(vector<Node>),所有的路径用vector<vector<Node>>表示. 这个程序对于 最小币值不是1的情况也是Ok的;
          硬币组合：思路1：每层递归只考虑一种币值，第1层只考虑最大的币值情况(0,1,2,..T/MaxCoin)，然后下层递归考虑下一个币值，最底层只能选最小币值了；思路2：每层递归可选的币值是【当前币值到end】，递归函数里面有个start参数约束可选范围，目的是防止组合结果重复；3)思路3：每层递归都考虑所有的币值情况，尽管有重复但可用cache加速；
 

	1. http://www.cyber-dojo.org/kata/edit/EFC4D1BBB0?avatar=ray  括号匹配配对(使用数据结构stack), Balanced Parentheses;
	2. http://www.cyber-dojo.org/kata/edit/8BC2B9BF64?avatar=vulture  Anagrams , 给定字符串，生成所有的变位词组合，全排列。
	3. http://www.cyber-dojo.org/kata/edit/4BAABD6B55?avatar=panda   八皇后，递归算法写的很简洁，从第1行摆到第8行，打印一种八皇后摆放位置。
	4. http://www.cyber-dojo.org/kata/edit/B1ABF0E956?avatar=snake    fibonacci
	5. http://www.cyber-dojo.org/kata/edit/9436CD7F39?avatar=peacock  search path 避障寻路,找到一条路径即可，采用回溯策略，从目的地开始往起点递归，cache加速；进阶：从任意起点到任意终点；
	6. http://www.cyber-dojo.org/kata/edit/ABECD4FE8A?avatar=flamingo search path 避障寻路（龙门客栈），在规定的步骤内，从任意起点到任意终点，每个点有4个方向选择，思路1)采用递归实现，深度遍历，关键是：在后续节点中需要过滤掉Path中的历史节点，否则会死循环；2)思路2：用Dijkstra算法实现找最短路径，Dij算法对联通图和非联通图都有效，如果要输出path需要在更新最短距离的时候记录前驱节点；3)思路3：广度优先遍历，在求最短路径时广度比深度更有优势，因为是一圈圈往外扩散；4）思路4：贪心广度优先(自创的)，需要用到Priority_Queue而非FIFO Queue,  这个结合了Dij的贪心思想；
	7. http://www.cyber-dojo.org/kata/edit/02F1E2DDCE?avatar=ostrich   质因子分解，迭代，最开始从2开始，每次递归找出一个质因子，下一次递归从上次递归的质因子往后找，直到不可分解为止(<sqrt())，这个分解算法非常的快。 
	8. http://www.cyber-dojo.org/kata/edit/E51905E8A1?avatar=eagle  magic square,给定一个数列，组成3*3方正，任何一行/列/对角的和都相等，递归实现，每次递归选一行数，剪枝策略：行和=sum/3;代码非常的清晰易懂(宏函数技巧使用)，一气呵成，使用了bitset来辅助选择数字;
	9. http://www.cyber-dojo.org/kata/edit/8135892EB1?avatar=lion   100doors
	10. https://leetcode.com/problems/two-sum/description/  two sum;
	11. http://www.cyber-dojo.org/kata/edit/79733EA557?avatar=whale  array shuffle;利用C++11的随机数函数对象重排序列；
	12. http://www.cyber-dojo.org/kata/edit/E8BE814637?avatar=hummingbird   combined number: form largest number，本质是个字符串排序问题，只不过字符串比较函数需要根据需求实现。
	13. http://www.cyber-dojo.org/kata/edit/6801135364?avatar=panda  Diversion(two adjacent 1):非常难得的一题，打印详细状态转换，迭代递推思路清晰，N bit的数是由N-1 bit的数在尾部扩展1bit(=0 ,1), 假定(N-1) bit 的数分成2组S+V，S组满足条件（has adjacent 1），V组不满足条件(又细分为偶数组和奇数组：Vodd+Veven)，奇数组是潜在转化组，只要尾部加bitvalue=1就转移到S组，由此得出结论：N bit的S组=(Sn-1) + Vodd_n-1 ； Vodd_n = Vn-1 - 转正(Vodd_n-1); Veven_n = 不满足条件 = Vn-1; 得到2个递推公式为： Sn=2*Sn-1 + VOddn-1; Voddn=Vn-1 - Voddn-1 = power(2, n-1)-Sn-1 - Voddn-1,进一步抽象得到2个公式：Yn=f1(Yn-1, Xn-1); Xn = f2(Yn-1, Xn-1); 这是一个二元状态转移方程，也是2维动态规划问题。
	14. http://www.cyber-dojo.org/kata/edit/FC82690842?avatar=eagle   number  spell in english, 这题的细节关键在于"and"的位置和完善的测试用例；
	15. http://www.cyber-dojo.org/kata/edit/1927987491?avatar=ray  leap year; 这题考察的是if/else if  的先后逻辑关系，代码几行；
	16. http://www.cyber-dojo.org/kata/edit/F00D0FBB1B?avatar=lizard  remove duplicate numbers from list; create a forward_list from scratch;使用hashset,实现了2个模板方法，都很清晰；
	17. http://www.cyber-dojo.org/kata/edit/785B3843A3?avatar=rabbit   FizzBuzz Plus.
	18. http://www.cyber-dojo.org/kata/edit/9791E0E401?avatar=leopard game of life.
	19. Longest Substring Without Repeating Characters ，这个题的思路类似于“最大连续子序列和”，关键是构建状态变量和递推公式，算法大概5行。
	20. http://www.cyber-dojo.org/kata/edit/31F00976B8?avatar=ray  BigNumberPlus, positive and negative number; to implement in another simple way.
	21. http://www.cyber-dojo.org/kata/edit/28325E5432?avatar=dolphin buy book with a max discount, DP. use Cache and Quick-Cut to improve performance, good code.
	22. http://www.cyber-dojo.org/kata/edit/68A61E8DFB?avatar=vulture  print binary tree.
	23. http://www.cyber-dojo.org/kata/edit/1BCD5F1393?avatar=koala  candy dispatch, 这是一道逻辑题(nokia code jam)，不太像算法题；

