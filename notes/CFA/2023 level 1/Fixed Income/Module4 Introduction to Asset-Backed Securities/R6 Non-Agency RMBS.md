# R6 Non-agency RMBS

- In order to obtain a favorable credit rating, non-agency RMBS often require one or more **credit enhancements**
- **Internal credit enhancements**
  - **Senior/subordinated structures**
    - 分层，结构化，tranche
    - 这里和R5中的PAC逻辑类似，只不过除了prepayment risk, 还引入了credit risk。subordinate tranche承担风险，优先保护senior tranche的支付。
  - Reserve funds: cash reserve or excess spread account
  - Overcollateralization
    - LTV下降（loan / value）
- **External Credit Enhancements**
  - Financial guarantee by a third party

#### Structuring

- **Redistribute** the risk of mortgage-related products to different bond classes or tranches
  - **Time tranching**: redistribute the prepayment risk associated with the collateral. (Sequential pay, Planned Amortization Class)
  - **Credit tranching**: redistribute the credit risk.
- **"Structuring" can not eliminate risk but redistribute risk**

- **senior/subordinated structure**:

  1. the prepayment happens, and junior tranche absorb the prepayments

  2. the balance of junior tranche reduces

  3. the credit protection to senior tranche reduces

  - 也就是说，junior tranche一开始承受的都是prepayment risk, 但是把本金消耗完毕，退出MBS市场，这时候senior tranche完全暴露在prepayment risk 和 credit risk之下。

- **Shifting interest mechanism** is a method for maintain high credit of protected tranches.

  - The mechanism will suspends payments to subordinated tranches if credit quality of senior is decreased
    - 当风险优先级senior tranche的信用评级下降时（因为subordinated本金在消耗，提供的保护下降），也就是subordinated tranche的本金快要消耗殆尽时，停止对subordinated tranche的payment支付。
    - 也就是，senior tranche为了不发生更严重的信用风险credit risk，也选择主动承担一点点prepayment风险。
  - The mechanism can be effectively used to maintain the desired level of credit risk protection, it comes at the expense of increase prepayment risk for the senior tranches
    - 信用风险比prepayment risk更严重