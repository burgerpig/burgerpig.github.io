# V3-M6 Ratios

- Activity Ratio
  - Efficiency in using assets to generate revenue.
- Liquidity Ratio
  - Ability to meet short-term obligations
- Solvency Ratio
  - Ability to meet long-term obligations
- Profitability Ratio
  - Ability generate profit

### 1) Ratio Analysis - Activity Ratios 经营效率

turnover周转率，资产类周转率越高越好，负债周转率越慢越好（欠别人钱越慢还越好）

- **Inventory turnover** = COGS / Average Inventory
  - **Days of inventory on hand(DOH)** = 365 / Inventory turnover
- **Receivable turnover** 应收账款周转率 = Revenue / Average Receivable
  - **Days of sales outstanding(DSO)** = 365 / Receivable turnover
  - 这里的Revenue优先使用赊销销售收入(还没给钱的收入，权责发生制)，没有就用全部Revenue
  - 如果应收账款计提过多坏账准备，使得Average receivable减少，导致周转率上升。这种情况不是好的周转率提高。所以周转率变高，还要观察变高的原因。
  - 所以如果有allowance，计算Average receivable的时候，需要account receivable - allowance
- **Payable turnover** = Purchase / Average Accounts payable
  - **Number of days of payable** = 365 / Payable turnover
  - 同样，Purchase应该优先用赊购金额，没有就用全部的Purchase
  - Purchase是中间变量，Inv. End. = Inv Begin + Purchase - COGS
- Total asset turnover = Revenue / Average total asset
- Fixed asset turnover = Revenue / Average net fixed assets 固定资产周转率
  - 注意，Net 意思是要扣除折旧、摊销
- Working capital turnover 营运资产周转率 = Revenue / Average WC
  - Working capital = current assets - current liabilities

一般都是xx周转率 = Revenue / average xx

average xx =(begin. xx + xx end.) / 2

这里的Revenue指的是net revenue，扣除discount 返点等。

#### Operating Cycle & Cash Conversion Cycle

| Inventory                                                 | Account Receivable                                         | Account Payable                                    |
| --------------------------------------------------------- | ---------------------------------------------------------- | -------------------------------------------------- |
| Inventory Turnover = COGS / Average Inventory             | Receivable Turnover = Revenue / Average Receivable         | Payable Turnover = Purchase / Average Payable      |
| Days of inventory on hand(DOH) = 365 / inventory turnover | Days of sales outstanding(DSO) = 365 / Receivable turnover | Number of days of payable = 365 / payable turnover |

- **Operating Cycle = DOH + DSO**
  - 复习：区分current asset，按照max(一年, one operating cycle) 为区分点

- **Cash conversion cycle（Net operating cycle） = DOH + DSO - Number of days of payable**

- 买存货付钱用了Number of days payables 天，卖存货用了DOH，收到钱用了DSO，所以，付钱到收到钱，就用了DOH+DSO-Number of days payable天。

##### Example

Sales: 4,800, COGS: 2,880, Average receivables: 625, Beginning inventory: 500, Ending Inventory: 1,200, Average Payables: 145. 

Cash conversion cycle(in days) is closest to?

- Inventory turnover = COGS / Average Inventory = 2,880 / ((500 + 1200) / 2) = 3.39
  - DOH = 365 / Inventory turnover = 108

- Receivables Turnover = Revenue / Average Receivable = 4,800 / 625
  - DSO = 365 / Receivables turnover = 48
- Payables turnover = Purchase / Average Payables
  - Purchase = Inv. Ending - Inv. Begin. + COGS  = 3580
  - payables turnover  = 3580 / 145
  - Number of days of Payables = 15
- Cash conversion cycle = DOH + DSO - Number of days of payables = 141

### 2) Ratio analysis- liquidity Ratios

A firm's ability to meet short-term obligations.

- **Current ratio** = current assets / current liabilities 流动比率
- **Quick Ratio** = (cash + short-term marketable security + receivable) / current liabilities
  - 速动比率
- **cash ratio** = (cash + short-term marketable security) / current liabilities
  - 现金比率

现金比率 < 速冻比率 < 流动比率。逐渐严格的流动性的指标。

前三个比较重要

- Defensive interval = (cash + short-term marketable security + receivable) / Daily cash expenditures
  - 分子和quick ratio一样

- liquidity 能力不仅仅体现在这些比率上，还在表外因素体现，比如银行授信额度，声誉

### 3) Solvency Ratios

A firm's ability to pay long-term debt

- Debt-to-equity ratio = total debt / total shareholder's Equity
- Debt-to-capital = Total debt / (Total Debt + Total shareholder's equity)
  - 这个capital只是分析师的工具，不是会计科目里的Capital股本。这里的capital翻译为资本。
  - 这里的capital = total debt + total shareholder's equity.
- Debt-to-assets = total debt / total assets
- debt-to-EBITDA = total debt / EBITDA
- **Financial leverage** = **average** total assets / **average** total equity 财务杠杆率
  - 这里solvency ratio有没有average看题目要求，不用语境下，也可以不含average
  - A / E = L / E + 1，注意 liabilities != debt，（debt一般指含利息的负债，liabilities包含interest bearing和不含息的负债）

total debt is the sum of interest-bearing short-term and long-term debt.

### 4) Coverage Ratios

- **Interest coverage** = EBIT / Interest
  - EBIT能够用来偿息的部分，Interest需要给的利息
- Fixed charge coverage = (EBIT + lease payment) / (Interest + lease payments)
  - 核心原理：能够支付部分 / 所需要支付部分
  - lease payment在EBIT之前扣减，所以需要加在分子上。

### 5）Profitability Ratios

#### Profit/ IS items

- **Gross profit margin** = gross profit / net revenue 
  - 毛利率
  - Net revenue是指Revenue扣除折扣、返点等的收入
- Operating profit margin = EBIT / Net Revenue
  - 经营净利率
- Pretax margin = EBT / Net Revenue 税前利润率
- **Net profit margin** = Net Income / Net Revenue  销售净利率，利润表最后一项除以第一项
  - Sales - COGS = Gross Profit
  - Gross Profit - SG&A = Operating Income = EBIT 简化公式
  - EBIT - I = EBT
  - EBT - T = NI
  - 上面每一个过程都除以最上面的Net Revenue（Sales），类似common size analysis

#### Profit B/S Items

- **Return on Asset(ROA)** = NI / Average total assets (Definition 资产净利率)
  - average为期初加期末除以2
  - 这里有不匹配性：分子归属股东，分子归属股东和债权人
- ROA = [NI + Interest \* (1 - t)] / Average total assets (For analysis)
  - 部分分析师会采用这种ROA形式，这样更进一步消除了分子分母的不匹配性
- Operating ROA = EBIT / Average total assets
  - EBIT = NI + I + T
  - 比上面的ROA更进一步接近消除分子分母不匹配性
- **Return on equity(ROE)**  = NI / Average total equity （权益净利率）
  - ROE比ROA更能反应归属股东的利润

#### DuPont System of Analysis 重点

##### Two-part approach

ROE = ROA \* Financial Leverage Ratio

##### Three-part approach

ROE = $\frac{NetIncome}{Revenue}\frac{Revenue}{AverageTotalAssets}\frac{AverageTotalAssets}{AverageShareholders'Equity}$

= Net Profit Margin \* Asset turnover \* Financial Leverage

通过分解ROE，看是哪个因素。

##### Five-part approach

ROE = $\frac{NetIncome}{EBT}\frac{EBT}{EBIT}\frac{EBIT}{Revenue}\frac{Revenue}{AverageTotalAssets}\frac{AverageTotalAssets}{AverageShareholders'Equity}$

 = tax burden \* interest burden \* EBIT margin \* asset turnover \* leverage ratio

- NI / EBT 称为Tax burden = 1 - t，tax burden 越高指的是税率越低，所得税率影响ROE
- Interest Burden = EBT / EBIT，Interest Burden越高，指的是利息**越低**（注意和理解上的burden不一样）

##### Practice

The following information (US millions) for two companies operating in the same industry during the same time period is available:

|                   | Company A | Company B |
| ----------------- | --------- | --------- |
| Net Sales         | 240       | 600       |
| Total Assets      | 140       | 280       |
| Total liabilities | 50        | 80        |

If both companies achieve a return on equity of 15% for the period, which of the following statments is most likely correct? Compared to Company B, Company A has a:

A. Higher net profit margin

B. Higher total asset turnover

C. Lower financial leverage multiplier

ROE = net profit margin \* asset turnover \* financial leverage

= net profit margin \* Revenue / Equity

ROE大家一样，所以比较Revenue/Equity即可

### 6) Equity, Credit analysis & segment analysis

#### Equity Analysis

- Dividend payout ratio = dividends / Net Income 股利支付率

- Retention rate = 1 - dividend payout ratio 利润留存率

  - NI 分为Dividend和$\Delta$留存收益，Dividend又分为普通股和优先股的股利

- Sustainable Growth Rate 可持续增长率

  = **ROE \* Retention Ratio** 必须记忆

  = ROE \* (1 - Dividend payout ratio)

  - 这里的增长率指的是**红利**dividend的增长率，不是净利润和销售的增长率
  - ROE代表企业赚钱能力，Retention Ratio代表赚的钱留存下来的能力。

##### Practice

The following financial data is available for golden investment Co.:

| ROA                  | 6.2%        |
| -------------------- | ----------- |
| Total asset turnover | 1.7         |
| Financial leverage   | 1.75        |
| Net Income           | \$1,500,000 |
| Dividend paid        | \$400,000   |

The company's sustainable growth rate is closest to:

 = ROE \* retention ratio = ROA \* leverage * (1 - dividend / NI)

#### Credit Risk

##### Credit Risk

- The risk of loss caused by a counter party's or debtor's failure to make a promised payments. 违约风险

##### Credit analysis

- Z- score

Z score < 1.81 则 有可能破产bankruptcy

#### Segment analysis 分部报告

- A company must disclose separate information about any operating segment which the segment constitutes **10%** or more of the company's revenue, asset or profit.
- For each reportable segment, the following information should be disclosed:
  - Segment revenue
  - Capital expenditure during the current year
  - depreciation and amortization expense
  - Interest revenue and interest expense
  - Income tax expense or income.

#### Segment Ratios 了解

- Segment Margin = Segment Profit / Segment Revenue
- Segment Turnover = Segment Revenue / Segment Assets
- Segment ROA = Segment Profit /Segment Assets
- Segment Debt Ratio = Segment Liabilities / Segment Assets









