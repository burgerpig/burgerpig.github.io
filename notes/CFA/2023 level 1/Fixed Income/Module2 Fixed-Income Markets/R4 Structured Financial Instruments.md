# R4 Structured Financial Instruments

结构化金融工具。定性分析，了解概念。基础金融工具+衍生品 

#### Basic Features of Structured Financial Instruments

- Respresent a broad sector(一系列) of financial instruments which has a comon attribute（基本特征） that they **repackage and redistribute risks**（风险重新打包和重新分配）
- Categories of structured financial instruments 主要是后四个
  - Asset-backed securities(ABS)
  - Collateralized debt obligations(CDOs)
  - Capital protected instruments 资本保护型
    - 保证凭证
  - Yield enhancement instruments 收益增强型
  - Participation intstruments 
  - Leveraged instruments

#### Captial Protected Instruments

- Capital protected instruments offer full or partial capital protection
  - 分为全额保护，部分保护
  - **Guarantee certificate**（保证凭证） is an example which is a combination of zero-coupon bond and call option.
    - Investor will receive no less than 100% of the capital invested
    - zero-coupon bond保证能收到本金，剩下的买看涨期权。
  - Note the protection is only as good as the issuer of the instrument
    - 这句话意思protection仅在issuer不发生信用风险时有效。

#### Yield Enhancement Instruments 收益增强型

- Yield enhancement refers to increasing risk exposure in the hope of realizing a higher expected return. 
  - callable bond 本质就是yield enhancement instrument
- A **credit-linked note(CLN)** 信用联结票据 is an example
  - Issuers could transfer the effect of a particular credit event to investors
  - issuer把issuer承担的部分信用风险转移给investor
  - 可以理解为：issuer卖bond给investor，并且从investor卖了issuer一份保险，保险的保护标的为issuer面临的其他债务关系。A借钱给B，B卖CLN给C。则如果A不还钱给B，B就有权利不还钱给C。
  - 一般CLN会深度折价，比一般的bond更便宜。

#### Participation Instrument 参与型

- A participation instrument is one that allows investors to participate in the return of an underlying asset
  - **Floating-rate bond** is an example which allow investor to participant in movement of interest rate
    - 浮息债券，类似于investor买了债券后，再进行了一笔互换。
  - Participation instruments usually do **not** offer capital protection
    - 一般没有资本保护，本金无法保护
  - Most participation instruments are designed to give investors **indirect exposure** to a particular index or asset price
    - 通常时和指数、特定资产挂钩，间接获得风险头寸。

#### Leveraged Instruments 杠杆

- Leveraged instruments are created to magnify returns and offer the possibility of high payoffs from small investments.
  - 同时放大收益和风险
- **Inverse floater** is an example: 浮息债券里的逆向浮动
  - Inverse floater coupon rate = C - (L \* R)
  - C = maximum coupon rate
  - R: the reference rate(e.g. LIBOR)
  - L: leverage
    - L > 1: leverage inverse floater
    - 1 > L > 0：deleveraged inverse floater
- 其实正向浮动也可以，floater coupon rate = C+L\*R
