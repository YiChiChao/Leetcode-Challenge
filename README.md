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

### 376. Wiggle Subsequence
**看題目的想法：** 因為看到題目是要求`Longest Subsequece`，就想到之前演算法課有教過求類似題目時是用dp，照著這個想法去想。
1. 確認Base Case：f(1) = 1, f(2) 如果前兩個數字不相同的話就一定是2
2. 確立Recursive Form：
```cpp =
MaxSequenceLength = MaxSequenceLength + (((arr[i]-arr[i-1])*(arr[i-1]-arr[i-2]))<0)? 1 : 0
```
3. 這個Recursive Form大致上是對的，但是當碰到上一個間隔是兩個相同數(`ex:[3,3,3,2,5]`)就會有問題，如果把`(arr[i-1]-arr[i-2])`用一個變數`sign`去紀錄正負，並且在相等的時候也視為正數，就能解決這個問題。
4. 另一個問題當我們把相等視為正數的時候，當`MaxSequenceLength`初始化是1時(代表前兩個數是相同數)，下一個間隔如果也是正數(`ex:[3,3,4,2,5]`)，就會Miss掉。所以要額外判別`MaxSequenceLength == 1`的情況，只要下一個間隔不是0(相異數)，就一定要加1。

**寫完的想法：** 有抓到一點dp的感覺，也有記得去處理邊界條件。

### 746. Min Cost Climbing Stairs
**看題目的想法：** 

這題有點像 `70` 的延伸題。

從小的階數來看，要到達每一階的最小cost就是「本階梯的cost」加上「到達上一步階梯的總cost」。

然而我們不知道我們走到這一步階梯是跨一步還是兩步到達的，所以要去比較上一階和上兩階的總cost哪一個比較小，才能推測到達現在這一階的最小cost。

**優化過後：** 和前面幾題一樣，其實不需要利用整個vector去記錄每一階階梯的總cost。觀察Recursive Form可看出只需要留下前兩階階梯的紀錄。將vector改成變數f0和f1，時間從11ms降到7ms。

### 198. House Robber
**看題目的想法：** 用了和上一題一樣的想法去做，但是沒有注意到這一題他不一定是取前一個房子的數字，而是只要不是相鄰房子個個數都可以取。

所以寫法應該要修正成訂定一個變數去紀錄前面所有的max rob數，去和前一個房子得rob數比較。

Base Case: 
```cpp = 
int Max = nums[0];
int f1(adjacent house) = nums[1];
```
Recursive Form：
```cpp = 
int temp = f1;
f1 (current house rob count) = max( Max + nums[i], f1);
Max = max(Max, temp); //將相鄰的房子rob數也納入Max中
```

### 213. House Robber II
**看題目的想法：** 和上一題的差別是在於頭跟尾只有一個能夠被偷，所以我就把dp 做了兩次。

一次是只能取頭，一次是只能取尾。而到底會不會偷頭或是尾就讓dp去決定，但可以保證兩種狀況不會重疊就好。


## Sorting
### 1710. Maximum Units on a Truck
**看題目的想法：** 簡單的knapsack problem。排序之後由最大的開始放。

**寫完之後的想法架構：** 這個題目有兩個可被優化的地方，一個是greedy，一個是sorting。(以後要避免去用現成的sorting，而是多去想在sorting是否可以有更優化的方法)

觀察這個 `numberOfBoxes`大小只有1000，加上這個input的形式特質上會有重複(而重複就能夠合併)，應該適合利用bucket sort。(雖然這也是看discussion才想到的)
寫到這裡就有點好奇究竟quicksort 和  bucket sort 在這一題的速度誰會比較快。(理論上還是bucket sort)，用C測試完後的確是bucket sort比較快。(O(n))

## Math

### 462. Minimum Moves to Equal Array Elements II
**看題目的想法：** 跟平均數有關，取平均後每一個數的就能是移動最少步的狀態下完成。

**寫完之後的想法架構：** 要讓每一個數都是移動最小步，要考慮到如果一個數特別大，那麼在算平均數的時候，整個平均數就會偏大。即使當其他小的數字出現比較多次，它在整個數列的權重也會因為平均數被稀釋掉。導致加的步數會重複好多次。結論是應該要取中位數才會使每個數移動的步數最少。

**類似題目：**[UVA 10041](https://zerojudge.tw/ShowProblem?problemid=a737)
### 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
**看題目的想法：** 一開始想法就是要知道所有格線之間的間隔，所以要先排序。因為這次要排序的東西都是獨一的，沒辦法用特殊的bucket sort，所以就直接用algo內建的sort寫。最後算出行還有欄的最大間隔後相乘得解。

**寫完之後的想法debugging：** 這題都是小細節錯誤。因為數字很大，所以要mod $10^{9}+7$。再來因為寫法是從`i = 1`開始，所以一定會有`i = 0`沒考慮到。加上了`maxhor`和`maxver`的初始化之後就沒問題了。
```cpp = 
long long int maxhor = max(horizontalCuts[0], h - horizontalCuts[horizontalCuts.size()-1];
long long int maxver = max(verticalCuts[0], w - verticalCuts[verticalCuts.size()-1]);
```

## Union Find

### 128. Longest Consecutive Sequence
寫得很矇，原本想要用Disjoint Set實作出來，但可能寫得不太好，最後還是TLE。
最後用Unordered Map去完成，查了資料Unordered Map是利用紅黑數和hash table構成的，有空來補這個知識。

