
# Stars and Bars

#### 1. The number of ways to put n identical objects into  k  labeled boxes is :- 

```sh
Empty Box Allowed -> (x1+x2+...xk=n) where xi>=0      Ans = nCr(n+k-1,n)
Empty Box Not Allowed -> (x1+x2...kx=n) where xi>=1   Ans = nCr(n-1,k-1)
```

#### 2. Lower Bound
```sh
If xi>=a then ((x1+a)+(x2+a)...(xk+a)=n) -> (x1 + x2 + ... xk = n - k*a) where xi>=0
```

#### 3. Upper Bound -> Inclusion Exclusion (not that easy)(CP Algos)
