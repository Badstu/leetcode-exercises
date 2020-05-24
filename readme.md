This is sayhi's leetcode-exercises repositories💻🎈🥇

If you have any suggestion about this repositories, please feel free to contact [me](mailto:zqws1018@gmail.com)💬, or just add a new issue here~

## 建议（来自labuladong的算法小抄）
* 如果刷题无从下手，可以从二叉树下手，前 10 道也许有点难受；结合框架再做 20 道，也许你就有点自己的理解了；刷完整个专题，再去做什么回溯动规分治专题，你就会发现只要涉及递归的问题，都是树的问题。

* 其实很多动态规划问题就是在遍历一棵树，你如果对树的遍历操作烂熟于心，起码知道怎么把思路转化成代码，也知道如何提取别人解法的核心思路。

* 回溯算法就是个 N 叉树的前后序遍历问题，没有例外。

* 很容易发现，其实状态转移方程直接代表着暴力解法。**千万不要看不起暴力解，动态规划问题最困难的就是写出状态转移方程，即这个暴力解。**优化方法无非是用备忘录或者 DP table，再无奥妙可言。

* 解决一个回溯问题，实际上就是一个决策树的遍历过程，要思考三个问题：
1、路径：也就是已经做出的选择。
2、选择列表：也就是你当前可以做的选择。
3、结束条件：也就是到达决策树底层，无法再做选择的条件。

* **遇到子串问题，首先想到的就是滑动窗口技巧。**


## solution analysis conclusion
solution analysis look at this -> [solution analysis](./tijie)

**4.12**

[887. 鸡蛋掉落](./tijie/887_鸡蛋掉落.md)\
每日一题：面试题 16.03. 交点\
周赛：\
1：5380. 数组中的字符串匹配\
2：5381. 查询带键的排列\
3：1410. HTML 实体解析器\
4：5383. 给 N x 3 网格图涂色的方案数

**4.13**
每日一题：355. 设计推特

**4.14**
[每日一题：445. 两数相加II](./tijie/445_两数相加II.md)

**4.15**
每日一题：542. 01矩阵

**4.16**
每日一题：56. 合并区间
0026.remove-duplicates-from-sorted-array
0053.maximum-sum-subarray
0088.merge-sorted-array
0104.maximum-depth-of-binary-tree
0121.best-time-to-buy-and-sell-stock

**4.17**
每日一题：55. 跳跃游戏
42.接雨水
407.接雨水II（没写出来）

**4.18**
每日一题：11.盛最多的水 双指针
0122.best-time-to-buy-and-sell-stock-ii 贪心
0125.valid-palindrome 双指针
0136.single-number 异或
0155.min-stack 单调栈
0167.two-sum-ii-input-array-is-sorted 双指针
京东2020春招：
1.股票亏损 排序+贪心+堆优化
2.跳格子：dfs

**4.19**
kickstart 1.Bike Tour（遍历找peak）
kickstart 2.Bus Routes（倒数遍历找最接近右边的数）
kickstart 3.Robot Path Decoding （字符串括号匹配，用dfs样例过了，没有AC）
每日一题：466.统计重复个数

**4.20**
每日一题：200.岛屿数量

**4.21**
每日一题: 1248.统计优美子数组

**4.22**
每日一题：199.二叉树的右视图
0169.majority-element（投票法）
0172.factorial-trailing-zeroes（把求0的个数转化为求因子中5的个数）
0191.number-of-1-bits（lowbit操作，-x&x）
0198.house-robber（动态规划）
0203.remove-linked-list-elements（单向链表的删除操作，要定义dummy节点）

**05.04**
每日一题：45.跳跃游戏II（贪心，从前往后做，一个一个跳吧）
0219.contains-duplicate-ii（哈希表，unordered_set维护k的窗口）

**05.06**
每日一题：983. 最低票价（动态规划，两种思路：365天和旅行的次数）

**05.07**
每日一题：572.另一个树的子树（两个递归，第一个递归比较子树的根结点相不相同，相同进入第二个递归，判断子树所有元素相不相同，时间复杂度是o(s*t)）

**05.08**
每日一题：221.最大正方形（DP，状态表示:以(i, j)为右下角的有效正方形边长，状态转移：短板原理。用一个max_side跟踪DP过程中最大的正方形边长）

**05.09**
每日一题：69.x的平方根（公式转换，二分，牛顿法）

**05.10**
每日一题：236.二叉树的最近公共祖先（递归，root->left, root->right）
232.implement-queue-using-stacks
0263.ugly-number

**05.11**
每日一题：50.快速幂（k次幂，化成二进制，每次判断最低位，不断对x平方）

**05.12**
每日一题: 155.最小栈
0283.move-zeroes
0342.power-of-four
0349.intersection-of-two-arrays
0437.path-sum-iii
0371.sum-of-two-integers (异或：不进位加法，与运算：算进位)
0501.find-mode-in-binary-search-tree
0575.distribute-candies
1260.shift-2d-grid
1332.remove-palindromic-subsequences

**05.13**
每日一题：102.二叉树的层序遍历（用队列做宽搜，宽搜过程中用NULL记录下一层的结束，上一层结束的时候下一层都被加入队列中）
面试题 04.04.检查平衡性
面试题 04.05.后继者

**05.14**
每日一题：136.只出现一次的数字

**05.18**
每日一题：152.乘积最大子数组

**05.19**
每日一题：680. 验证回文字符串Ⅱ(双指针，往里走，碰到不一样的尝试左右两个各跳过check，if多的情况下，可以写函数来判断剩下部分是否相等，这样代码看起来比较清楚)

**05.20**
每日一题：1371. 元音出现偶数的最长子串（前缀和+状态压缩的思想，完全想不到，明天再自己手写一遍！）

**05.21**
每日一题：5. 最长回文子串（动态规划，f(i, j)代表i到j的子串是否为回文串，然后从里往外dp）

**05.22**
每日一题：105. 从前序与中序遍历序列构造二叉树

**05.23**
每日一题：76. 最小覆盖子串

**05.24**
每日一题：4. 寻找两个正序数组的中位数