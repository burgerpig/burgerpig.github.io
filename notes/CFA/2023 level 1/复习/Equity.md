# M1

错题：12、18、21、25、33

关注：1、9、10、11、27、28、29、32、36

12、forward contract是私人定制，比较难转手。

18、买call，卖put，相当于合成了一个forward。未来以某个价格买入underlying。

注意，write a put option，意思是卖出一个put. 卖put和买call都是多头

21、计算题，注意，bought on 75 percentage margin，意思是交了75%的保证金。

- 保证金收益的题目，用现金流解答。
- 第一步求期初投入的金额。
- 第二步求期末，收回的金额。（卖出股票 - 还的钱 - 各种费用 + 各种收益（股利））

25、make the market，和本方最优价相等

- make a new market，超过本方最优价
- take the market，价格是对方最优价。

33、价格优先、price display优先，时间优先。

1、

- information-motivated trader, 寻找错误定价，用技术分析法等等
- investor，投资。跟踪大盘。等
- hedger，对冲

9、对于open-end fund

- 卖open-end fund时候，卖回给基金；卖close-end，在二级市场转卖
- shares of closed-end fund trade at a premium or discount to NAV(net asset value)

10、

- pool investment vehicle，集合类资产->基金

11、发行ETF的一般是financial intermediaries. （investment companies)

27、execution order: 马上执行

- validity order：指的是委托什么时候生效

28、对于GTC(good-till-cancelled)委托

- stop 50, limit 55,buy
- stop意思是价格到达50，委托执行，执行限价为55. 也就是价格到了50，开始发出委托，成交最大价格是55.

29、Good-till-cancelled stop sell order。达到某个价格，止损，卖出。

- stop order: the stop order may not be filled until the stop price condition has been satisified.

32、rights offering 属于primary market

36、流动性越好，越容易交易。

# M2 Indexes

weighting，就是求指数price return和total return进行加权的时候用到。

计算指数的时候，还是通过 sum(nP)/D的公式

错题：4、5、11、18、23、24、25、28、33

关注：1、3、16、17、19、22、26、27、29、30、31、32、34

- A security market index represents the value of **a given security  market**, **market segment**, or **asset class**.
- 只有在期初的时候(inception)，price return和total return才相等
- 构建指数第一步，选取target market
- Security market indexes are constructed and managed like a **portfolio** of securities
- **The target market** determines **the investment universe** and the securities available for inclusion in the index. 构建指数时，选定target market，确定投资范围。
- equal-weighted，低估大盘股、高估小盘股。另外还有：
  - mometum tilt: market-capital-index，大市值股票影响大
  - value tilt: fundamental weighting index，价值类股票影响大
- float-adjusted market-capitalization-weighted index: 范围限于shares available to the investing public.
  - 进一步的：free-float-adjusted market capitalization weighting: 排除外国人不能投资的部分。
- fundamental weighted index leads to **value tilt**
- rebalancing index: 意思是调整weighting, 使得index consitency with the index's weighting method.
- Security market indexes play a critical role as **proxies** for asset classes in asset allocation models.

- Security market indexes are used as proxies for **measuring market** or  **systematic risk**, not as measures of unsystemic risk. 用来估计market risk或者系统性风险。index的几种作用：
  - 估计market sentiment
  - 度量系统性风险
  - 主动管理portfolio的benchmarket
  - model portfolio，比如指数ETF
- **Sector indexes** provide a means to determine whether **a portfolio  manager** is more successful at stock selection or sector allocation. 板块指数。
  - aggregation of a sector index可以当作a broad market index
  - 没有一个统一的划分标准，no universally agreed upon sector classification

- Style Index: 和market capitalization有关。

- Fixed-Income securities有时候流动性较差，无法复制fixed income indexes.
  - Fixed-Income Index特点：
    - broad universe范围广
    - High turnover变化频繁（因为债券会到期，mature）
    - iliquidity，流动性差，需要做市商

- An **aggregate** fixed-income index can be **subdivided** by **market  sector** (government, government agency, collateralized, corporate), **style** (maturity, credit quality), **economic sector**, or some other characteristic to create more  narrowly defined indexes
  - aggregate fixed-income指数可以根据市场、风格、板块进行划分。
- fixed-income indexes的划分维度**不包括**coupon-frequency
  - 包括：type of issuer、type of financing、currency of payment、maturity、credit quality、absence of presence of inflation protection
- Commodities index根据future contract编制指数
- commodities index和现货存在基差（different from underlying commodities）
- real estate index:
  - appraisal index: 主观估值
  - repeat sales: 卖两次
  - REIT index，基金，有市场价格
- hedge funds index都是认为选择成分股，所以是index determined by constituent of the index, 由于存在幸存者偏差，所以会偏高。

<<<<<<< Updated upstream
# M3 Market Efficiency

- 错题：21、23
- 关注：14、15、19、22、25
- 半强semi-strong efficient中，standard fundamental analysis基本面分析没有超额收益，abormal trading profits are zero.
- semi-strong-form efficient中，如果采用主动管理，会产生cost。所以被动管理比主动管理的收益更大。

- January effect abormally:
  - tax-loss selling
  - window dressing
- Momentum abnomalies：股价短期表现，意思是发掘历史价格规律。（weak inefficiency）
- overeaction effect：过度反应。

- value stock的特征：
  - high dividend yield
  - low P/E
  - low P/B
- Growth  stocks
  - low dividend yields
  - high price-to-earnings
  - high market-to-book ratios.
- 如果是semi-strong，发布财报不会引起股价变动。如果是发布财报引起了股价变动，那么就是有additional information。

# M4 Equity security

错题：20、24

关注：3、5、6、8、10、17、22

- preference share特征：
  - 没有投票权
  - 不参与公司经营业绩分配
- 对于private equity security:
  - 不能在二级市场转卖
  - 没有市场报价
  - 主要发行给机构投资者（institutional investors）
- mezzanine夹层。
  - **venture capital investment** can be used to provide **mezzanine financing** to companies in theire early stage of development
  - **Venture capital** investments provide “seed” or start-up capital, early-stage financing, or mezzanine financing to companies that are in the early stages of development and require addi- tional capital for expansion
- emerging market
  - 目前出海上市的趋势，让emerging market的company不用担心本国的流动性差，可以跨国筹集资金（do not have to worry about a lack of liquidity in their home equity markets）（found it easier to raise capital in the markets of developed market）
  - equity markets in developed country have more stringent financial reporting requirements and accounting standards.
- ADR发行制度，Level III和普通上市公司相同，严格监管，发行费用高，可以在NYSE, NASDAQ或者AMEX交易。
- 发行股票，可以用来购买长期资产，投资项目；一般**不会**主要用来keep the company going concern.
- 发债回购股票。Liability增加，Equity减少，所以ROE减少。
  - Treasury Stock记在equity，是个负数（备抵科目）复习财报B/S。
- companies try to raise funds at the lowest possible cost. 所以，**cost of equity** is usd as a proxy for the **minimum** required rate of return.

# M5 Industry Analysis

错题：2、8、9、13、19、21、25

关注：1、3、4、10、15、22、29

最好所有题目过一遍。

- 行业分析用于：sector rotation strategy, performance attributing, top-down analysis、

- sector rotation strategy is conducted by investors wishing to time investment in industries through an analysis of fundamentals and/or **business-cycle** conditions.

- commercial 分类: 只包括public和for-profit的公司
  - government分类，不区分for/non-for profit, large/small, public/private分类
- Comparing the company’s performance measures with those for a potential peer-group company is of limited value when the companies are exposed to different stages of the business cycle. 这句话意思是：当两个公司处于不同商业周期阶段，两个公司的对比的意义不大。

- Concentrated industry 会避免price war.
- lead time：交货时间
  - With short lead times, industry capacity can be rapidly increased to  satisfy demand, but it may also lead to overcapacity and lower profits. 交货时间越短，反而产能过剩，利润降低。

- 卖酒的行业，concentrated并且定价能力高
- economies of scale会降低总成本，对于high fixed capital investment industry 有利，能够提高profit.

# M6 Security valuation

错题：3、4、6、16、20、23、24、30

关注：7、10、11、15、22、26、27、28、29、33、34

- 估值方法分类：
  - Discount cash flow models
  - price multiples model
  - asset-based models:
    - calculate the intrinsic value of equity by substracting liabilities from market value of assets
- 第4题，概念混淆：Enterprise value和price to free cash flow是price multiples models中的两种方法，EV和P/CF. 而FCFE(free cash flow to Equity)可以用作present value模型，用来折现。
- 第6题，discounted cash flow model需要用到FCFE或者用到dividend
- FCFE反应了dividend paying capacity，股利支付能力。
- 10、present value model，包括DDM（dividend discount model），以及FCFE。
  - 其中，DDM可以估计stock that pay a current dividend or is expected to pay a dividend
  - FCFE可以用来估计不支付股利的公司（站在大股东的角度）
- The Gordon growth model (also known as the constant growth model) can be used to value dividend-paying companies in a mature phase of growth.  A stable dividend growth rate is often a plausible assumption for such companies.
  - GGM一般用来估计mature phase的公司，一般假定stable dividend growth

- present value model的一个缺点：small changes 带来大变动

  - present value model也可以用来估计没有dividend的股票，比如FCFE model
  - intrinsic value 和持有期限**无关**！

- 对于mature阶段，使用gordon growth，对于从growth stage 转变到mature stage，用两阶段，对于young company用three-stage.

- price multiplier base on fundamentals 就是**justified P/E**，用Gordon growth model估计P0.

  - $$
    P_0/E_1=\frac{D_1/(r-g)}{E_1}
    $$

  - 如果是price multiplier model base on comparable：

    - 站在law of one price的角度，两个同样的资产不能有不同的价格。
    - 和benchmark对比：比如**historical average**, similar stocks, industry average.

- 26、如上面所说，price multiplier model based on comparable时，可以通过历史的average对比，得出当前的market price is undervalued or overvalued.

- 在使用EV/EBITDA multiplier时：

  - Operating income may be used in place of EBITDA when calculating the enterprise value multiple. 
  - EBITDA may be used when company earnings  are negative because EBITDA is usually positive. 
  - The book value of debt cannot  be used in place of market value of debt.（这也是一个EV method的disavantage, debt market value难以获得）

- asset-base model不适用于intangible assets占比高的公司，因为intangible asset比较难以估值。

- 
