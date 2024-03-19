# M1

Sarbanes-Oxley

it is mandatory that mangement's Report to shareholders discuss internal financial controls and ther effectiveness, as well as the company's auditor's opinion of these internal controls

- Analyze and interpret the data在process the data之后。
  - calculate ratio在process the data

# M2

- Audit report需要对internal control内控发表意见

- FASB，IASB是standard setting body，仅仅负责制定标准
- regulatory body才需要负责enforcing standards。比如Financial conduct authority(UK), SEC(US)
- IOSCO不是regulatory body

# M3 Income Statement

- provision for income taxes就是tax expense
- Revenue - estimated returns and allowances  = Net Revenue
- Gain/Loss = sales price - book value
- 有子公司时
  - Net income of parent company = consolidated total income - non-controlling interest
- gross profit = revenue - COGS
- operating profit = gross profit - SG&A - depreciation expense
- 对于financial company, interest expense通常认为是operating expense
- 五步法确认income第二步，identify the separate or distinct **performance obligations** in the contract
  - performance obligation是承诺递交distinct good or service
  - transaction price包括提前交付的奖励
- expense recognition原则，**matching principle**
  - 期间成本**period costs**
- discountinued gain/loss is **net of tax**
  - measurement date确定抛弃日，actual disposal date真实卖掉的日期
    - 这两个日期之间，叫做phaseout period

- 注意，DDB折旧法，不需要减去residual value!!!
- 注意changing an account 可以用retrospective application或者prospective application
- antidilutive securities: 使得diluted EPS升高的，不计入
  - dilutive securiteis，使得EPS下降的，计入diluted EPS

- convertible preferred stock也是preferred stock，在计算basic EPS的时候，要在分子上减去
  - 对每一个complex结构，计算是不是anti-dilutive，如果是，就去掉。留下剩余的。步骤：
    - 计算basic EPS: a / b
    - 对于convertible bond和convertible preferred share: 分子 + c, 分母+d, 如果 c /d < a / b那就是dilutive security
    - 对于option，如果strike price < average stock price 那就是dilutive security
    - 最后根据所有的dilutive security计算dilutive EPS
    - 注意，convertible preferred stock也要在basic EPS的分子中出现！

- 寄售consignment sale，remit 汇款
  - 卖家寄售的时候，中间商卖出，才确认收入
- 确认收入按照已完工进度确认。比如发生了25%的成本，那么确认25%的合同收入
- refurbish

- common-size for income statement适用于across time periods分析（time-series analysis），不同阶段，因为rapid growth，公司会有不同的size，去掉size，更好地分析。
- non-operating items such as investing or financing activities (e.g., interest expense and interest income) may be reported **on a net basis** with the components disclosed separately in the **notes**.
- company recognizes **expenses** in the period that it loses some **previously** recognized economic benefit or consumes the economic benefits associated with the expenditure

- unusual 和 infrequent items在operating profit后面，EBIT之前，但也算as part of continuing operations
- Comprehensive income **includes all changes in equity** during a period except those resulting from **investments by owners** and **distributions to owners**, which means comprehensive income is the sum of all transactions and other events and circumstances from non-owners. 

# M4 BS

- classified balanced sheet: current/ non-current分类

- goodwill developed internally is expensed as incurred.
- 收购产生的goodwill计算时用的是fair value
- securities不是intangilble assets.
- unidentifiable intangible asset是goodwill

- trade receivables are reported **net of an allowance for doubtful accounts** or at their **net realizable value**.
  - trade receivable要么呆账，要么NRV

- debt-to-equity中的debt. debt is considered to be any interest-bearing obligation. 要付利息的，比如bank loans and other financial liabilities, financial liabilities

- liquidity-based presentation, 流动性最高排在最前面，一般bank会采用。

- 为什么equity和真实的market value不一样，因为market value反应的是未来（回忆经济学，股价指数是leading indicator），fails to include all aspects of a company’s ability to generate future cash flow.
  - 另一方面，难以反映intrinsic value，原因是计量方法不一样，一些使用historical, 一些使用fair value等等。

# M5 CF

- CFO indirect method
  - NI + depreciation - gain + loss + $\Delta L$ - $\Delta A$
- CFI，分为cash paid for new asset（purchase），从COGS计算
  - 还有cash from asset sold = book value of the asset  + gain(or - loss) on sale
    - 原理 G/L = sold price - BV
- CFF
  - cash from creditors = Net borrowing - principal amounts repaid
  - cash from shareholders = new equity issued - share repurchases - cash dividends paid
- 用发equity还debt，noncash transaction
  - Non-cash transactions, if significant, are reported as supplementary information, not in the investing or financing sections of the cash flow statement
- cash collections这种表述 只是算收钱inflow
- non cash charge, non cash transaction不一样

- Arguments for the indirect method include that it mirrors a forecasting approach and it is easier and less costly
- equity 中的common stock和additional paid-in capital common stock 是issuance of common stock 的CFF
- An appropriate method to prepare a common-size cash flow statement is to show each line item on the cash flow statement as a percentage of net revenue. An alternative way to prepare a statement of cash flows is to show each item of cash inflow as a percentage of total inflows and each item of cash outflows as a percentage of total outflows.
- Cash to income = Cash flow from operating activities (CFO)/Operating income
- 注意，如果change in inventory是以indirect income statement的形式给出，要注意转换正负号（+L-A）

# M6

- 对于activity 比例有一个有意思的结论，如果比例>1，那么，分子分母同时减少相同量，会导致比例上升

$$
if\ \frac{a}{b}>1, then \frac{a-x}{b-x}<\frac{a}{b}
$$

- 适用场景，比如current ratio = 2，如果动用cash扣减payables，使得CA和CL都减少，导致current ratio上升。
- accounting standard require segment reporting for a distinguishable part of a firm that comprises at least 10%
- forecast a company's earning会假设关键financial ratios不变
- vertical common-size就是单个时间，除以revenue, total asset之类
  - horizontal common-size，就是除以第一年的数值，横向时间对比

- **When purchases are not available (as in this case) the COGS can be used to estimate payables turnover**

- 一个记忆方法，Receivable和Revenue一对R，Purchase和Payables一堆P

conglomerate 

-  The qualifying elements are assets, revenues, and operating profit.

  - Asset Revenue Operating Profit超过10%，就要Segment

- 三个examining the variability of financial outcomes around point estimates

  - **Sensitivity analysis**, also known as “what if” analysis, shows the range of possible outcomes as specific assumptions are changed.
  - **Scenario analysis** shows changes in key financial quantities that result from given economic events.

  - **Simulation** is a computer-generated sensitivity or scenario analysis based on probability models for the factors that drive outcomes.

- efficient是turnover（activity ratio）, profitability 是margin

# M7

- abnormal waste material cost不在cost里
- import duties是关税

- write-up 是 减少COGS
- freight-in cost: 进货运费, freight-out cost: 销货运费，需要capitalized
- Warehousing costs：仓储成本

# M8 long-lived asset

- Training required to use the property and equipments算入expense
  - ready for use之前，这里的use是针对所有人。培训费用只是你不会用，你不会用有别人会用。

# M9 Tax

- Only the portion of the difference between the tax base and the carrying amount that is not the result of the revaluation is recognized as giving rise to a deferred tax liability. The portion arising from the revaluation surplus is used to reduce the revaluation surplus in equity.
  - 如果asset涉及revaluation, carrying value要减去revaluation surplus
  - (carry value - revaluation surplus - tax base) * tax rate = DTL/DTA
- and beyond 以后

# M10

- AR turnover如果变大，说明是正常的revenue增多，健康的盈利。如果是AR turnover变小，说明receivables提前确认。有可能是fititious revenue.
  - 所以，DSO变大，receivables turnover变小，都是有可能recognize revenue prematurely.

- EBITDA 不是GAAP的科目