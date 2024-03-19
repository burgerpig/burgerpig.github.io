# R8 Other ABS

#### Auto Loan Receivable-Backed Securities

- Backed by auto loan and lease receivables
- The cash flows consist of regularly scheduled monthly loan payments(interest payment and scheduled principal repayments) and any prepayments.
  - 资产池现金流：loan payment, prepayment
- Refinancing is **not** a major factor contributing to prepayment
  - Prepayment is more predictable and less dependent on interest rate change
  - 汽车贷款，利率下降时借新还旧不是提前还款的主要动因。因为金额较少，refinancing扣除手续费并不能节省多少钱。
- All have some form of credit enhacement, often a senior/subordinated structure.

#### Credit Card Receivable-Backed Securities

三点：1) cashflow三种；2）cash flow是non-armortization loans; 3) 存在lockout period

- Backed by credit card receivables
- The cash flows consist of finance charges collected, fees, and principal repayments
  - cash flow应收账款包括三个：
    - finance charges collected 分期付款的手续费（可以理解为利息）
    - fees 信用卡年费
    - principal repayments 还本金
  - 这里的cash flow is **non-amortizing loans** with lockout period, during which the principal is reinvested and only finance charges collected and fees is paid to investors.
    - lockout period中本金会被银行占用重新投资，finance charges collected 和 fees给ABS投资者。

#### Collateralized Debt Obligation担保债务凭证

CDO可以动态调整资产池，和之前的RMBS, CMBS不一样

- a generic term to describe a security backed by a diversified pool of one or more debt obligations

  - 根据资产池中的资产不同，分为CBO/CLO
  - Collateralized bond obligation(CBO)
    - US domestic high-yield corporate bonds
    - Structured financial products
    - Emerging market bonds 发展中国家债券

  - Collateralized loan obligation(CLO)
    - Bank loans
    - Special situation loans and distressed debt

- CDO requires a collateral manager to buy and sell debt obligations for and from the CDO portfolio of assets to generate sufficient cash flows 
- Structure of a CDO includes senior, mezzanine, and subordinate/equity bond classes
  - equity tranche是次级tranche（因为风险最大）
- In typical structure, one or more of the tranches is a floating-rate security
  - Asset manager uses interest rate swap to deal with the mismatch
  - 一般CDO是floating rate, 银行使用swap进行管理资产池和CDO的利率不匹配。

#### Covered Bonds 担保债券

- **Covered bonds** are **<u>senior</u>** debt obligations（这里的senior指安全级别较高） issued by **a financial institution** and **backed by a segregated pool of assets** that typically consist of commercial or residential mortgages or public sector assets.
  - 由financial institution发行
  - Covered bonds are similar to ABS, but offer bondholders **dual recourse**（双重保证） to both the issuing financial institution and the underlying asset pool.
    - 双重保障：第一层背后的支持资产，第二层金融机构担保。
    - 金融机构提供双重担保。如果资产池中资产中违约，金融机构履行担保责任，用自有资金进行偿还。
- **Redemption regimes**（赎回制度） exist to align the covered bond's cash flows as closely as possible with the original maturity schedule in the event of default of a covered bond's financial sponsor
  - If payments from **hard-bullet covered bonds** do not occur according to the original schedule, a bond default is triggered and bond payments are accelerated.
    - 如果没有按照约定还款，立即宣布违约，金融机构赎回covered bond，履行担保责任。
  - **Soft-bullet covered bonds** delay the bond default and payment accelerate of bond cash flows until a new final maturity date
    - 违约后，确认一个新的maturity date，新的日期还没有还钱，金融机构履行担保责任。
  - **Conditional pass-through covered bonds** convert to pass-through security after the original maturity date if all bond payments have no yet been made.
  - 上面的三种赎回制度的担保程度从强到弱。

#### Covered Bond vs. ABS

|                           | Covered Bonds                                                | ABS                                                          |
| ------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Accounting Treatment      | The pool of underlying assets remain on the financial institution's balance sheet（不能出表） | Transfer securitized assets to a bankruptcy-remote special legal entity. 出表，破产隔离 |
| Structured Design         | Usually consist of one bond class per cover pool             | Often use credit tranching to create bond classes            |
| **Underlying Adjustment** | Dynamic nature: replace any prepaid or non-performing assets in the cover pool to ensure sufficient cash flows until the maturity of the covered bond. 因为有金融机构担保，需要保证资产优质，且充足。底层资产可以动态调整。 | Static pool of mortgage loans that expose investors to prepayment risk 一般不能还资产池 |
| Funding channels          | Stable and reliable source of funding                        | Relatively less stable and reliable                          |
| Risk and return           | Lower credit risks and offer lower yields                    | Relatively high credit risk and offer higher yields          |























