# R5 Quote Convention 报价惯例

Describe and calculate the falt price, accrued interest, and the full price of a bond.

#### Accrued interest 应计利息

- Accrued interest is the interest received by the seller when a bond trades between coupon dates. 也就是交易之前产生的利息，体现在应计算利息中。

$$
AccruedInterest=\frac{t}{T}\times PMT
$$

T = 两个coupon之间的间隔

t = 交易日距离上一个交易日的间隔

#### Clean Price and Dirty Price

- Clean price/ flat price 
  - the agreed upon price of the bond
- Dirty price / full price 全价
  - The amount that the buyer pays to the seller, which equals the clean price plus any accrued interst
- **Full price  = Clean price + Accrued interest**

- 一般报价用flat price，交易价格用full price. 因为报价用flat price排除掉应计利息导致的价格上涨，把accrued interest 和市场供求关系导致的价格波动区分开。另外，full price中，图像锯齿状。

#### Conventions for Quote

- Bond dealers usually **quote flat price** while the **full price will be paid**, and there can be a difference between them
- Conventions to count days: **actual/actual** and **30/360**
  - accrued：30/360:按照月份计算；acutal/actual按照实际天数计算。 
  - Vary from market to market
  - actual/actual is most common for government bonds
  - 30/360 is often used on corportate bonds

#### Example\*

- Consider a 5% semiannual coupon bond with par value of 100 and required yield of 4.8%
- The bond wil matures on 15 Feb. 2024, and coupon are made on 15Feb and 15 Aug of each year.
- The bond is to be priced for settlement on 14May 2015, and that date is 88days into the 181day period. 这句话意思是距离上一次付息88天，两个coupon之间距离 181天
- What should be the price paid and what should be the price quoted?

Answer: 

<img src="./181 days.jpeg" alt="181 days" style="zoom:33%;" />

- 注意：Feb15th 的PV，既不是full price，也不是clean price。而是债券未来现金流折现的理论价格。**理论价格需要通过复利计算到full price**（复利时惯例）

- 先算前一个coupon payment date的PV，然后通过复利计算full price，然后通过单利计算accrued interest. 然后full price - Acrrued interest = flat price。一共四个步骤。