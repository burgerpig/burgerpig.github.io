# V3-M5 Inventory

成本和期间费用不一样

### Inventory Recognition

存货的成本和期间费用认定：达到销售状态前的，都算成本，否则是期间费用。

- Inventory cost 成本
  - Purchase cost（Including import and tax-related duties, transport and related insurance, handling fee) less trade discounts and rebates(必要可销售状态的花费减去返点)
  - conversion cost, 料工费，人工，including direct labor, fixed and variable, overhead costs（间接费用）
- Expensed 期间费用
  - abnormal waste of material, labor or overhead
  - storage costs(unless required as part of production). （已经发酵完毕，已经达到了销售状态，存储算作期间费用）
  - administrative overhead and selling cost。行政管理，营销费用都算期间费用（广告advertising）

### COGS

- When the inventory is sold, inventory goes to income statement as COGS.

- Beg. Inventory - End. Inventory + Purchased Cost = COGS


### Valuation Methods

- IFRS, permissible method:
  - Specific identification
  - FIFO
  - Weighted average cost
- US GAAP permissible methods:
  - Specific identification
  - FIFO
  - **LIFO**
  - weighted average cost

#### Questions

- FIFO/ LIFO which is better? why LIFO is forbidden by IFRS?
  - 会计资产负债观，FIFO做出来的B/S体现最新的存货，B/S更准确。
- Weighted average COGS一定在FIFO COGS 和LIFO COGS中间

### Analysis of Inventory

- LIFO provides the most **useful estimate** of COGS on the **I/S**. LIFO下，进利润表的是最新的存货。
- FIFO provides the most useful estimate of Inventory value on the **B/S**. FIFO下，留在资产负债表的是最新的存货。
- with an increasing purchase price, LIFO brings:
  - higher cost of sales
  - lower gross profit, operating profit, income tax expense, net income
  - lower ending inventory, working capital, total asset, retained earnings, shareholders' equity
  - **higher net cash flow**

- In periods of rising prices，价格上升的时候

| Statements             | LIFO             | FIFO   |
| ---------------------- | ---------------- | ------ |
| I/S: COGS              | Higher           | Lower  |
| I/S: EBIT              | Lower            | Higher |
| I/S: Tax               | Lower            | Higher |
| I/S: NI                | Lower            | Higher |
| B/S: Inventory balance | Lower            | Higher |
| B/S: Working Capital   | Lower            | Higher |
| CF/S: CFO              | Higher(Tax paid) | Lower  |

working capital 流动资产。LIFO下，税交的更少，税算在CFO。

| Ratios                                                       | LIFO   | FIFO   |
| ------------------------------------------------------------ | ------ | ------ |
| Profitability: Gross and net margins = Gross profit / Sales  | Lower  | Higher |
| Liquidity: Current Ratio = CA(current asset) / CL(current liability) | Lower  | Higher |
| Solvency: D/A, D/E debt to equity                            | Higher | Lower  |
| Activity: Inventory turnover = COGS / Inventory              | Higher | Lower  |

- 一道需要注意语法的题目: TWG Co. uses the FIFO inventory accounting method, and HBP Co. uses the LIFO method. During periods of rising prices the cost of goods sold reproted by:

  A. HBP is too low; B. TWG is too low.; C. HBP is too high

  答案： B。对于COGS，是记录在利润表中。LIFO对于利润表才是最准确，反应最新卖出去的存货的数字。所以FIFO下的更“偏小”，所以选B。

### Inventory System(periodic and perpetual) 存货盘存制度

- Periodic system, determined at the end of an accounting period. (Beg. Inv + Purchased - End Inv. = COGS). 在盘点那天确定存货数量。先求ending inventory，再倒推出COGS。**实地盘存制**
  - need a "purchase" account. 借助日常的账本，辅助期末的时候盘点存货。

- Perpetual system, continuously updated as each **sale occurs**(continuously)。**永续盘存制**，每次出库（卖出）的时候，就计算COGS，然后推出ending inventory. 
  - purchase account is not needed.

- 如果使用**specific method**或者**FIFO**，无论使用periodic还是perpetual，都是**一样**的结果。
- 如果使用LIFO和Weighted Average，两种盘存制度也有可能导致一样的结果。出现不一样的结果的时候，只有出现某个时刻卖出的存货，是后面时刻买入的，才有可能出现不一样的结果。比如期初2，买入2，卖出4，买入2，卖出1，期末盘存的时候，剩余存货1.那么按照periodic下的LIFO，剩余的存货是期初的存货。这里最后时刻买入2个只卖出1个，剩下的一个却被当成了卖出，显然不符合逻辑。但是如果最后时刻卖出2个，两种盘存制度就一样。也就是说，如果每两次相邻卖出的中间的所有买入，小于等于后面一次卖出的量的时候，LIFO在两种盘存制度下肯定是一样的。
- 盘点制度，只是会计上的处理，即使periodic和perpetual一样，也有可能和实际情况（specific method）还是不一样。

#### Summary

- Same result for FIFO & specific identification method
- **May be** different result for LIFO & AVCO. 注意是maybe.

### Impairment of Inventory存货的减值 非常重要

一般按照历史成本计量(history cost)计量的资产，需要减值impairment。有些fair value计量的也需要减值（可供出售资产）。

减值实际步骤：

1）出现减值迹象（或者一年一次）=>2）减值测试=>3）减值处理

#### Inventory Impairment in IFRS

- Inventory should be measured at the lower of the cost(carrying value/ book value) or **Net Realizable Value**（可变现净值） 
  - carrying value = min(carrying value, NRV)
  - Net realizable value = Estimate selling price - costs to make the sale - cost to get the inventory in condition for sale. **预期售价**减去为了达到预期售价状态所需要花费的成本。
- If book value/carrying value/cost > NRV:
  - Inventory is written down to NRV on B/S. 减到NRV，确认资产减值损失跑到I/S
  - a loss is recognized in I/S. 在US GAAP下，可以记在资产减值损失或者COGS。
  - **Can be** written up but limited to the amount of the original write-down and a **gain** is recognized in I/S. Reversal is required for a subsequent increase in value of inventory previously written-down**(US GAAP prohibit)**. 美国不让转回。不能转回超过原来的carrying value，history cost（历史成本计量）。
  - written-up 在I/S确认收益。

#### Inventory Impairment in US GAAP

- Inventory is the lower of the cost or **market**
  - replacement cost 重置成本
  - normal profit margin: 卖出一个存货的正常利润
  - market value = max(NRV - normal profit margin, min(NRV, replacement cost))
  - market value是NRV-normal profit margin和NRV之间的replacement cost
  - 用carrying value和market value对比，取最低的作为written down.
- If cost > market 
  - Inventory is written down to market on B/S.
  - A loss is recognized in I/S.
  - No subsequent written up is allowed.

#### Impact of Inventory Impairment

- Inventory write-down **reduces** both profit and the carrying value of inventory
- Inventory write-down has **negative** effect on profitability, liquidity(流动比率下降，不考虑所得税，不影响流动比率和速动比率), solvency ratios（A/E = L/E + 1 上升）. 
  - 这里的negative solvency ratios 指的是杠杆率提高
- Inventory write-down has **positive** effect on activity ratios (inventory turnover =COGS/Inventory 提高, total asset turnover=Sales/Asset 提高). 
  - 这里的positive其实是通过存货贬值导致的，对企业来说，不是健康的positive提高

#### Analysis on Inventory

- Inventory turnover ratio & days of inventory on hand

  - Ratios should be compared with industry benchmark and across several years
  - High inventory turnover and low DOH indicate high inventory management efficiency. But, it may indicate the company doesn't keep adequate inventory along with a low sale growth rate. 如果销售增长率低，存货周转率又低，表明库存不够。所以指标要综合来看，不能单一而论。

  - Inventory written down also results in high inventory turnover and low DOH which indicate poor inventory management.

#### Inventory Adjustment

- If there is an active market exists, for the agricultural and forest products, minerals and mineral products。农产品、林业产品、矿产品, it **may**（可以但是不一定） be measured at **NRV**(fair value - cost to sale and complete). 可以用NRV动态计量（有点像fair value），不一定用历史成本计量（history cost)
- any gain or losses resulting from changing in value should be recognized in **I/S** both under IFRS and US GAAP. 损益确认在利润表中。

#### Inventory Report and Disclosure (US GAAP & IFRS)

- cost flow method used(LIFO, FIFO, etc.)
- Total carrying amount of inventories
- Disclose the carrying value of inventory which is valued at NRV(fair value - selling cost)
- COGS for the period
- the amount of inventory **write down**.
- the amount of **reversal** of inventory write downs and the events or circumstances of reversal (IFRS only)（减值迹象必须说明）

### LIFO Reserve & LIFO Liquidation考试不会特别难

US GAAP要求披露LIFO和FIFO的difference（LIFO reserve后进先出储备）

#### LIFO Reserve

- LIFO reserve is the difference between the reported LIFO inventory carrying amount and the inventory amount that would have been reported if the FIFO method had been used.

LIFO Inv + LIFO Reserve = FIFO Inv, 注意，LIFO Reserve 是**时间点数**

LIFO COGS - $\Delta$LIFO Reserve = FIFO COGS. COGS是时间段数

证明：

Beg. Inv FIFO + Purchase - COGS FIFO = End. Inv. FIFO

Beg. Inv LIFO + Purchase - COGS LIFO = End. Inv. LIFO

上面两个公司相减：

Beg. LIFO Reserve - COGS FIFO + COGS LIFO = End. LIFO Reserve

即，LIFO COGS - $\Delta$LIFO Reserve = FIFO COGS

#### Changes in Inventory Valuation

- Changes in accounting policy
  - From other methods to LIFO => Prospective application未来适用法
  - Other changes=> retrospective application追溯调整法, (包括LIFO改为FIFO的时候)
- Disclosure in footnotes - useful in facilitating comparisons with other firms or industry average.

会计估计变更=》未来适用法

会计政策变更=〉追溯调整法

会计差错=》报表重述

#### LIFO change to FIFO

- Income Statement Change 时间段数
  - **COGS FIFO = COGS LIFO - $\Delta$ LIFO Reserve** 重要
  - NI FIFO = NI LIFO + $\Delta$ LIFO Reserve $\times$ (1 - Tax Rate)
    - COGS影响净利润NI。LIFO调整为FIFO后，EBT变高，交税后，NI增加。
- Balance sheet changes 时间点数
  - **Inventory FIFO = Inventory + LIFO Reserve** 重要
  - Retain Earning FIFO = Retain Earning LIFO + LIFO Reserve Ending $\times$ (1 - 不变动的Tax Rate)
  - Cash FIFO = Cash LIFO - LIFO Reserve Ending $\times$ (不变动的Tax Rate)
    - RE和Cash(注意不是cash flow) 是时间点数。净利润留存到RE。
    - RE = $\sum_{sinceStart} \Delta NI$，NI = Revenue - **COGS** - ...
    - COGSFIFO - COGSLIFO = -$\Delta$ LIFO Reserve
    - 实际上，LIFO Reserve Ending $\times$ (1 - Tax Rate)是等于以前所有年份的$\Delta$ LIFO Reserve $\times$ (1-Tax Rate) 相加。**这里其实假设了Tax Rate不变。**也就是税率不发生变化的时候，这个公式才成立。
    - 所以，如果Tax rate变动，应该按照每年的$\Delta$ LIFO Reserve * (1 -Tax Rate_i) 相加

#### LIFO Liquidation 后进先出清算

如果物价水平上升**且**存货数量上升（normal situation），就会导致LIFO Reserve上升。

如果物价水平下降**或**存货数量下降，都会导致LIFO Reserve下降。

- In normal situation(prices are rising **and** inventory quantities are stable or increasing), the LIFO Reserve will increase.
- A **LIFO liquidation** occurs when purchased volume is less than sales volume(inventory quantities decrease)(Beg. Inv. + Purchased  - COGS = End Inv.)
  - Even if the price is rising, LIFO reserve **may** decline. 
  - COGS no longer reflects recent prices, and an analyst should **adjust** COGS for decrease in LIFO reserve. 压箱底的便宜货的成本跑到了NI 中
  - LIFO liquidation results in **higher profit margin** and **higher income tax**, and higher profits can **not be sustainable**. 便宜的最初的存货不是一直能用，所以LIFO liquidation把一开始的便宜的存货终于算进了COGS，该交的税始终都得还。
- LIFO Reserve下降不一定是LIFO Liquidation发生，有可能是因为price下降。所以，一般只有出现LIFO liquidation出现时，才需要调整I/S。
