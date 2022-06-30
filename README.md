# Leetcode-Challenge
## Intro
看了別人的interview發現想法比答案重要，所以不僅要寫題目，還要把想法寫下來。算是一個錯題本，也是訓練自己看題目訓練想法。

## Dynamic Programming
### 509. Fibonacci Number
最簡單的那種，大概寫一下步驟：
1. 確認Base Case：F(0) = 0, F(1) = 1
2. 確立Recursive Form：F(n) = F(n-1) + F(n-2)
3. 觀察需要留多少儲存空間去儲存原先算好的東西：因為Recursive Form會用到F(n-1)和F(n-2)，所以我用f0和f1去儲存每一次會用到的兩個原先的數字而已(credit to Coherent!!)

**寫後小錯誤：** 因為loop是從i = 2開始，一開始就應該要考慮到i = 1和i = 0的情況。 

## Math

### 462. Minimum Moves to Equal Array Elements II
**看題目的想法：** 跟平均數有關，取平均後每一個數的就能是移動最少步的狀態下完成。

**寫完之後的想法架構：** 要讓每一個數都是移動最小步，要考慮到如果一個數特別大，那麼在算平均數的時候，整個平均數就會偏大。即使當其他小的數字出現比較多次，它在整個數列的權重也會因為平均數被稀釋掉。導致加的步數會重複好多次。結論是應該要取中位數才會使每個數移動的步數最少。

**類似題目：**[UVA 10041](https://zerojudge.tw/ShowProblem?problemid=a737)

