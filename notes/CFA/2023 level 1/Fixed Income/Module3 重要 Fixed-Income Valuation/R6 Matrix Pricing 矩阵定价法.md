# R6 Matrix Pricing

估值通常有两种：1）绝对估值：通过自身未来现金流往前折现；2）相对估值法，参考其他定价。

在CFA中，Bond 的相对估值法，是参考其他债券的YTM，根据maturity进行线性插值，确定自身的YTM。

矩阵横纵坐标两个维度：maturity和coupon rate

#### Matrix Pricing

- Estimate the amrket discount rate and price based on the price of more frequently traded comparable bonds
  - comparable bonds: similar times-to-maturity, coupon rates, and credit quality(totally, similar risk)
  - Commonly used for bonds **inactively-traded** or not **yet issued**.债券不活跃，还没有发行
- Linear interpolation can be used when the maturities between the valued bond and the traded bond are different
- Matrix pricing may also be used to estimate the **yield spread** over the benchmarket rate
  - Benchmarket rate is typically the yield to maturity on a government bond having the same, or close to the same, time-to-maturity.

重要的点是：选取和自身相似的债券，进行插值估计。相似意思指是信用等级、债券类型（公司债还是国债）、期限、coupon rate等等相似。
