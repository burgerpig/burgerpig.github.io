# R7 Yield Spread \*\* 收益率基差

Calculate and interpret spread measures for bonds

基差反映风险大小

#### Nominal spread名义基差

- **Nominal spread** is the difference in yield between different bonds

  - Yield spread over benchmark: difference in yield betwen bonds and benchmark rates
  - 可以选择不同的benchmark，是两个yield的差距
  - spread反映的是超额的风险. 比如国库券作为benchmark时，一般认为没有信用风险，但又流动性风险、通货膨胀风险等。计算spread的时候，流动性风险和通胀风险已经包含在国库券的利率中，spread中包含的时基于国库券增加的风险，比如信用风险等。

  1. **G-spread**
     - yield spread over an actual or interpolated **government bond**
     - 相应期限的国库券。没有对应期限的话，用插值法。
  2. **I-spread**
     - yield spread of a specific bond over the **standard swap rate**（标准互换利率） in that currency of the same tenor. 
       - 互换中固定方利率就是swap rate.

#### Z-spread

- **Zero volatility spread(Z-spread, static spread)**
  - 零波动率基差（静态基差）
  - A constant yield spread over a **government spot curve**
  - Implied assumption: the yield curve makes a **parallel shift** 从spot rate curve平行移动得到，所以叫零波动率

$$
PV = \frac{PMT}{(1+s_1+z)}+\frac{PMT}{(1+s_2+z)^2}+...+\frac{PMT+FV}{(1+s_n+z)^n}
$$

- 当用spot rate curve进行债券估值的时候，实际上用bootstrap方法把每一期现金流拆成了若干个零息债券，然后用spot rate进行折现。然后，spot rate是国库券的无风险利率得来，一般的公司债存在风险，无法在估值中体现信用风险。所以，在spot rate上加一个z-spread，把信用风险考虑进去。
- 在没有引入z-spread时，因为使用了无信用风险的spot rate，所以估值偏高。加上spread后，使得估值和实际价格相等，从而求出z-spread.
- Z-spread时曲线之间距离spread，G-spread和I-spread是点和点之间的距离。
- Z-spread越高，该债券的风险越高。
- 在这里的计算中，假设了每一期的spread都一样。这只是一个标准化的计算流程，在是实务中，可以根据每一期的信用风险不一样， 给每一期加的spread不一样。比如balloon payment的时候，信用风险最高，那一期的折现率更高，所以需要更大的spread. （央行不对称加息）

#### Option-Adjusted Spread 

- Option-Adjusted Spread (OAS)
  - yield spread that **remove the influence of embedded option**
  - 考虑含权的情况，OAS把option risk排除掉

| **G-spread/I-spread/Z-spread** 包括了： | OAS 包括了：   |
| --------------------------------------- | -------------- |
| Credit risk                             | Credit Risk    |
| Liquidity risk                          | Liquidity risk |
| Option risk                             |                |

- **OAS = Z-spread - option value (%)**
  - Callable bond $\implies$ option value > 0 $\implies$ OAS < Z-spread
  - Putable bond $\implies$option value < 0 $\implies$ OAS > Z-spread

- 注意，这里的option value是针对issuer 来说

