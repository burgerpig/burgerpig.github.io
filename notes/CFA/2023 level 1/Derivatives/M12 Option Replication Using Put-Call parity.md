# M12 Option Replicatin Using Put-Call Parity

**Explain** put-call parity for European options

**Explain** put-call forward parity for European options

#### Put-Call parity

##### Fiduciary call

$c+X/(1+r_f)^T$

- Combination of a European call option with exercise price of X and a pure-discount, risk-less bond with face value of X.
  - 注意是零息债券

##### Protective put

$S+p$

- A share of stock together with a put option on the stock with exercise price of X.
- **Note**: the call and put must be European-style(c, p) with same exercise price(X) and time to expiration (T). Also, the maturity of the bond should be the same(T).

##### Payoff at expiration:

|             | Fiduciary call  | Protective put  |
| ----------- | --------------- | --------------- |
| if $S\le X$ | 0 + X = X       | S + (X - S) = X |
| if $S > X$  | (S - X) + X = S | S + 0 = S       |

- 未来现金流相等的两份资产，应该视为同一种资产，应该定价一样，否则存在套利空间。
- long call + long bond = long put + long underlying
- In either case, the payoff on a fiduciary call is the same as the payoff on a protective put, so put-call parity is:

$$
S_0+p_0=c_0+X/(1+r_f)^T
$$

call put 平价公式一般用来寻找套利机会，而不是用来求期权价格

##### Arbitrage opportunity

- If $S_0+p_0>c_0+X/(1+r_f)^T$
  - Selling the put and the underlying and purchasing the call and the risk-free asset at initiation. 也就是long fiduciary call, short protective put, 低买高卖。
- If $S_0+p_0<c_0+X/(1+r_f)^T$
  - Purchasing the put and the underlying and selling the call and the risk-free asset at initiation.

call put parity可用用来合成复制replication

##### Replication

- The put-call parity can be rearranged to create synthetic equivalences.
  - Synthetic call: $c = S+p-X/(1+R_f)^T$
    - 比如short call是危险操作（复习，short call的亏损无限，盈利有限）。所以如果市场上没有人卖call，可以自己合成一个call.
  - Synthetic put: $p = c+X/(1+R_f)^T-S$
  - Synthetic stock: $S = c + X/(1+R_f)^T-p$
  - Synthetic bond: $X/(1+R_f)^T=S+p-c$
    - 也就是说，long stock + long put + short call是无风险组合
  - Note: the term"+" means long and "-" means short

#### Put-Call Forward Parity 衍生的put call parity

- Put-call-forward parity is derived with a forward contract (forward price: $F_0(T)$) rather than the underlying asset itself.
  - Substituting $F_0(T)/(1+R_f)^T$ for $S_0$ in put-call parity gives us the put-call-forward parity:
    - $F_0(T)/(1+R_f)^T+p=c+X/(1+R_f)^T$
    - or:
    - $[F_0(T)-X]/(1+R_f)^T=c-p$

- 相当于用远期合约替换当前long asset。

### 拓展内容

#### Put-call parity application

- Put-call parity can be used to model the value of a firm's equity holder and debt holder.
  - The company defaults when the value of its assets falls below the default barrier(i.e., the liability).
  - It assumes limited liability and equity values are non-negative. 假设负债是零息债券，股价非负。

##### **Equity option analogy**

- holding the **company's equity** is economically equivalent to **owning a European call option on the company's assets(A)** with strike price K(Debt) and maturity T(maturity of debt). 持有公司equity和持有European call 的payoff曲线一致。
- At maturity:
  - If A > K(solvency), exercise the call option and realize a value of (A - K).
  - If A < K(insolvency), do not exercise the call option and the value is 0.

**Debt option analogy**: 

考虑C + K = P + S, 以及会计恒等式A = L + E。

由于持有Equity和Call相等，S相当于是asset，那L = K - P。所以负债相当于long bond 和short put. （考虑short put的曲线向上平移(无风险收益bond)）

- owning the **company's debt** is economically equivalent to **owning a riskless bond**, and simultaneously **selling a European put option** on the asset(A) with strike price K and maturity T(maturity of debt)

$$
V_{risky\ debt}=V_{risk-free\ debt} - V_{put\ option}
$$

- At maturity:
  - If A < K(solvency), exercise the put option and the value is A.
  - If A > K (insolvency), do not exercise the put option and the value is K.

















