# V4-M2 Measures of Leverage 杠杆	

### 1）definition of leverage

- A given change in one variable leads to a greater change in other variable because of **fixed cost**，固定成本
  - Fixed operating cost经营性固定成本：created by fixed operating cost(e.g. depreciation and rent)
  - Fixed financial cost财务性固定成本：created by fixed financial cost(e.g. Interest利息)
  - 固定成本导致杠杆

原因：

利润增长 = （第二期收入 - Fixed Cost - (第一期收入- Fixed cost)）/ (第一期收入 - Fixed cost)

= （第二期收入  - 第一期收入) / (第一期收入 - Fixed cost)

可见，如果有Fixed cost，分母变小，从而利润增长变大。

固定成本越大，杠杆越大

- Leverage increases the **volatility** of a company's earnings and cash flows(both up and down), as well as increases the risk of creditors or shareholders of a company。波动
- Dividend不会导致leverage，因为dividend在NI之后分配，不会影响到波动

### 2）measures of leverage

#### Risk decomposition

- **Business risk**业务风险：the risk associated with **operating earning**, and is the combination of **sales risk** and **operating risk**
  - **Sales risk**销售风险: uncertainty with respect to the price and quantity of goods and services
    - 行业竞争、价格、科技因素
  - **Operating risk**经营风险: risk attributed to the use of **fixed cost** in operation(e.g. rent, depreciation)
    - 和固定成本有关，折旧、租金
    - 经营性固定成本FOC越高，经营性杠杆越高，经营风险越大
- **Financial risk**财务风险: the risk associated with how a company finances its operation.
  - 和利息有关，利息越多，财务杠杆越大，财务风险越大

#### Degree of operating leverage(DOL) 重要，经营性杠杆

在本章节，假设了以下利润表计算：Sales->EBIT->NI，从上到下产生影响。

| Sales - VC - F = EBIT | DOL = %EBIT / %Sales |
| --------------------- | -------------------- |
| EBIT - I = EBT        |                      |
| EBT - T = NI          | DFL = %NI / %EBIT    |

DTL = %NI / %Sales=DOL\*DFL，衡量Sales波动一个单位，NI波动多少

F: Fixed Cost，VC：Variable cost

- DOL is quantitative measure of the **sensitivity of operating income to changes in revenues** 经营性收入对营收的敏感度，也就是Sales变动一单位，EBIT变动多少
- DOL的定义式：这里假设了商品的**价格P不变**

$$
DOL = \frac{Percentage\ Change\ In\ EBIT}{Percentage\ Change\ In\ Sales}=\frac{\frac{\Delta EBIT}{EBIT}}{\frac{\Delta Q}{Q}}
$$

- DOL的计算式：

$$
DOL = \frac{Q(P-V)}{Q(P-V)-F}=\frac{Contribution\ Margin}{Contribution\ Margin-F}=\frac{EBIT+F}{EBIT}
$$

- 证明：
- 因为EBIT=Sales - VC - F = Q(P - V) - F, 所以

$$
\frac{\frac{\Delta EBIT}{EBIT}}{\frac{\Delta Q}{Q}}=\frac{\frac{\Delta Q(P-V)}{Q(P-V)-F}}{\frac{\Delta Q}{Q}}=\frac{Q(P-V)}{Q(P-V)-F}
$$



- If EBIT is positive and fixed operating cost is greater than 0, DOL is greater than 1.
- 只要EBIT、F是正数，则**DOL必须大于等于1**
  - 如果F=0，则DOL = 1，没有杠杆，如果F>0，则DOL>1，则有经营性杠杆。

Example:

If DOL at a given level of unit sales is 2.0, a 5% increase in unit sales from that level would be expected to result in a:

A. 10% of decrease in operating income

B. 10% of increase in net incom

**C. 10% of increase in operating income**

operating income约等于EBIT, 所以5%销售收入上升，operating income 上升10%。这里是百分比2倍，如果是金额则不一样。

#### Degree of financial leverage (DFL)财务杠杆

- DFL is a quantitative measure of the sensitivity of net income to changes in operating income.

$$
DFL = \frac{Percentage\ Change\ In\ NI}{Percentage\ Change\ In\ EBIT}=\frac{\frac{\Delta NI}{NI}}{\frac{\Delta EBIT}{EBIT}}=\frac{EBIT}{EBIT-Interest}
$$

证明：

NI=EBIT-I-T=EBIT-I-EBT \*t=EBIT-I-(EBIT-I)\*t=(EBIT-I)(1-t)
$$
\frac{\frac{\Delta NI}{NI}}{\frac{\Delta EBIT}{EBIT}}=\frac{\frac{\Delta EBIT(1-t)}{(EBIT-I)(1-t)}}{\frac{\Delta EBIT}{EBIT}}=\frac{EBIT}{EBIT-Interest}
$$

- If Interest is greater than 0, **DFL is greater than 1.**
- DFL is no affected by the tax rate because tax is not fixed cost. 税不会影响DFL

#### Degree of Total leverage(DTL)总杠杆

- Measure of the sensitivity of net income to changes in the number of units produced and sold.
- A combination of DOL and DFL

$$
DTL =\frac{\frac{\Delta NI}{NI}}{\frac{\Delta Sales}{Sales}}=\frac{\frac{\Delta EBIT}{EBIT}}{\frac{\Delta Sales}{Sales}}\times \frac{\frac{\Delta NI}{NI}}{\frac{\Delta EBIT}{EBIT}}=DOL\times DFL
$$

$$
DTL=\frac{Q(P-V)}{Q(P-V)-F-Interest}
$$

- 如果公式没有负债，没有财务性杠杆，DTL=DOL

Example:

A firm's degree of operating leverage is 2.5 at 100,000 units sales and degree of financial leverage is 2 accordingly. If sales quantity decrease to 95,000. net income decrease by 25%.

#### Breakeven point盈亏平衡点

- Breakeven point($Q_{BE}$): quantity of sales at which the company's net income is zero

Sales - cost = 0所以，sales = QP=QV+F+I=cost，所以：


$$
Q_{BE}=\frac{FixedCost}{UnitContributionMargin}=\frac{F+Int.}{P-V}
$$

Unit contribution margin是P-V，卖出单位产品的收益。就是单位产品能赚P-V，要去覆盖所有固定成本：F+Int.

- Operating Breakeven point($Q_{OBE}$): quantity of sales at which the company's operaing income is zero:

同理，Operating Income约等于EBIT=Sales - VC - F = PQ-VQ-F = 0，所以：


$$
Q_{OBE}=\frac{Fixed Operating Cost}{Unit Contribution Margin}=\frac{F}{P-V}
$$
同理，P-V，覆盖operating fixed cost: F. 用这个思路去记忆。