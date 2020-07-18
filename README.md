# shuffle-algorithm

## 问题描述

洗牌算法指的是将一个序列打散，生成一个新的随机排列，英文描述如下：

[Fisher-Yates shuffle](https://en.wikipedia.org/wiki/Fisher–Yates_shuffle): The **Fisher–Yates shuffle** is an [algorithm](https://en.wikipedia.org/wiki/Algorithm) for generating a [random permutation](https://en.wikipedia.org/wiki/Random_permutation) of a finite [sequence](https://en.wikipedia.org/wiki/Sequence)—in plain terms, the algorithm [shuffles](https://en.wikipedia.org/wiki/Shuffling) the sequence. 

## Fisher-Yates Shuffle算法

### 算法描述

最原始的洗牌算法，中心思想为从原数组中随机抽出一个数加入到新数组中，并将该数从原数组中删除。用于生成1～N的随机排列算法如下：

~~~
1. Write down the numbers from 1 through N.
2. Pick a random number k between one and the number of unstruck numbers remaining (inclusive).
3. Counting from the low end, strike out the kth number not yet struck out, and write it down at the end of a separate list.
4. Repeat from step 2 until all the numbers have been struck out.
5. The sequence of numbers written down in step 3 is now a random permutation of the original numbers.
~~~

时间复杂度：O(n^2)

空间复杂度：O(n)

## 算法证明

P(原数组中元素m（1<=m<=n）被放在新数组中第i个位置) = P(前i-1次随机选取都没有选中m) * P(第i次随机选取选中m)，即：

![1338474640_7202](/Users/zzx/Downloads/1338474640_7202.gif)

## **Knuth-Durstenfeld Shuffle** 

### 算法描述

基于原始洗牌算法的改进版本，中心思想为不新建数组，每次从数组中随机选出一个数，加入到数组尾部，数组尾部为随机排列的数字。算法描述如下：

~~~
1. 数组arr存放1～n
2. 生成一个0～n-1的随机数pos
3. 将arr[pos]与arr[n-1]交换
4. 同2，生成一个从0到n-2的随机数pos
5. 将arr[pos]与arr[n-2]交换
.....
直到有n个数交换到了数组末尾
~~~

时间复杂度：O(n)

空间复杂度：O(1)

### 算法证明

对于arr[i]（0<=i<=n-1），洗牌后在各位置概率如下：

1. P(交换到arr[n - 1]) = 1 / n（第一次生成的随机数为i）
2. P(交换到arr[n  -2]) = $frac13$
3.  (n - 1 / n) * (1 / n)

