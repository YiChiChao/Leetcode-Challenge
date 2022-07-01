# Leetcode-Challenge
## Intro
看了別人的interview發現想法比答案重要，所以不僅要寫題目，還要把想法寫下來。算是一個錯題本，也是訓練自己看題目訓練想法。

## Dynamic Programming
### 509. Fibonacci Number
最簡單的那種，大概寫一下步驟：
1. 確認Base Case：F(0) = 0, F(1) = 1
2. 確立Recursive Form：F(n) = F(n-1) + F(n-2)
3. 觀察需要留多少儲存空間去儲存原先算好的東西：因為Recursive Form會用到F(n-1)和F(n-2)，所以我用f0和f1去儲存每一次會用到的兩個原先的數字而已 (credit to Coherent!!)

**寫後小錯誤：** 因為loop是從`i = 2`開始，一開始就應該要考慮到`i = 1`和`i = 0`的情況。

### 1137. N-th Tribonacci Number
同509.，Recursive Form：F(n) = F(n-1) + F(n-2) + F(n-3)

### 70. Climbing Stairs
**看題目的想法：** 每次爬樓梯時，第一步可以選擇走1階或走2階。如果選擇走1階，就會剩下n-1階(就變成n-1階的問題)，如果選擇走2階，就會剩下n-2階(接下去就是變成n-2階的問題)。也就是說n階樓梯的走法其實是(n-1)階+(n-2)階的走法。

## Sorting
### 1710. Maximum Units on a Truck
**看題目的想法：** 簡單的knapsack problem。排序之後由最大的開始放。

**寫完之後的想法架構：** 這個題目有兩個可被優化的地方，一個是greedy，一個是sorting。(以後要避免去用現成的sorting，而是多去想在sorting是否可以有更優化的方法)

觀察這個 `numberOfBoxes`大小只有1000，加上這個input的形式特質上會有重複(而重複就能夠合併)，應該是何利用bucket sort。(雖然這也是看discussion才想到的)
寫到這裡就有點好奇究竟quicksort 和  bucket sort 在這一題的速度誰會比較快。(理論上還是bucket sort)，用C測試完後的確是bucket sort比較快。(O(n))

## Math

### 462. Minimum Moves to Equal Array Elements II
**看題目的想法：** 跟平均數有關，取平均後每一個數的就能是移動最少步的狀態下完成。

**寫完之後的想法架構：** 要讓每一個數都是移動最小步，要考慮到如果一個數特別大，那麼在算平均數的時候，整個平均數就會偏大。即使當其他小的數字出現比較多次，它在整個數列的權重也會因為平均數被稀釋掉。導致加的步數會重複好多次。結論是應該要取中位數才會使每個數移動的步數最少。

**類似題目：**[UVA 10041](https://zerojudge.tw/ShowProblem?problemid=a737)

