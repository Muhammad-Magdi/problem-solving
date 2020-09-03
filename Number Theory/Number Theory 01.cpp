/*
  Session : Number Theory
  By : Muhammad Magdi
  On : 28/09/2017
*/

What to know?
  -Multiples -> All the numbers that are divisible by some Integer.
  -Divisors -> All the numbers that divide some Integer.
  -Primes -> A Number which is divisible only by 1 and itself.
  -Factors -> The prime numbers that divide an Integer exactly.
  -Modular Arithmetic.
  -Fast Powering.
  -GCD(a, b) -> The greatest number that divides both 'a' and 'b'.
  -LCM(a, b) -> The smallest number that's divisible by both 'a' and 'b'.

/********************************* Multiples ***************************************/

Problem #1 -> Given an integer 'n' find all of its Multiples that are less than 'N'.

  for(int i = 2*n ; i < N ; i+=n){    //note the assignment statement
    printf("%d ", i);
  }

/******************************** Divisors ****************************************/

Problem #2 -> Given an integer 'n' find all of its Divisors.
  Solution #1:
    "Iterate through all numbers from 1 to n and check its divisibility"

  vector<int> v;
  void findDivisors1(int n){                //O(N)
    for(int i = 1 ; i <= n ; ++i){
      if(n%i == 0)  v.push_back(i);
    }
  }

  Example -> n = 36
    36 / 1  = 36
    36 / 2  = 18
    36 / 3  = 12
    36 / 4  = 9
    36 / 6  = 6
    36 / 9  = 4
    36 / 12 = 3
    36 / 18 = 2
    36 / 36 = 1
  Can you find any Observation?
    -Square root :D

  set<int> st;
  void findDivisors2(int n){                //O(sqrt(N)*log(n))
    for(int i = 1 ; i*i <= n ; ++i){        //O(sqrt(n))
      if(n%i == 0){
        st.insert(i);                       //O(log(n))
        st.insert(n/i);
      }
    }
  }

/************************************ Primes ******************************************/

Problem #3 -> Given an integer 'n' find if it's prime or not?
  Primality Check #1:
    "Iterate through all the numbers from 2 to n-1 and check the divisibility"
    bool isPrime(int n){                //O(n)
      for(int i = 2 ; i < n ; ++i){     //from 2 to n-1
        if(n%i==0)  return 0;           //not Prime
      }
      return 1;                         //Prime
    }

  Observation #1 -> "Square root"
  Observation #2 -> "Even Numbers"

Problem #4 -> Given Q numbers for each of them find if it's prime or not?
  Solution #1:

  int A[N];
  void primalityCheck1(){               //O(Q*sqrt(n))
    for(int i = 0 ; i < Q ; ++i){      //The given numbers
      bool isPrime = 1;
      for(long long j = 2 ; j * j <= A[i] ; ++j){
        if(A[i]%j == 0) isPrime = 0;
      }
      if(isPrime)   printf("%d is a Prime Number\n", A[i]);
      else          printf("%d is NOT a Prime Number\n", A[i]);
    }
  }

  Solution #2:  "Sieve of Eratosthenes"

  bitset<N> isComposite;
  void sieve(){                             //O(N*Log(Log(N)))
    isComposite[0] = isComposite[1] = 1;
    for(long long i = 2 ; i <= N ; ++i){      //The Maximum value
      if(!isComposite[i]) for(int j = i*i ; j <= N ; j+=i){
        isComposite[j] = 1;
      }
    }
  }

Goldbech`s conjecture:
  -Every even integer greater than 2 can be expressed as the sum of 2 primes.

/********************************** Factors ************************************/

  vector<pair<int, int> > factors;      // <prime, power> that represents P^e
  void factorize1(){
    for(long long i = 2 ; i*i <= n ; ++i){
      int power = 0;
      while(n%i==0){
        n/=i;
        ++power;
      }
      if(power) factors.push_back({i, power});
    }
    if(n > 1) factors.push_back({n, 1});
  }

/********************************** Powring **************************************/

-Do you know that A^x = A^(x-1) * A          and     A^0 = 1 ?
-Do you know that A^x = A^(x/2) * A^(x/2)    and     A^0 = 1 ?

  int power1(int b, int p){               //O(p)
    if(!p)  return 1;
    return b*power1(b, p-1);
  }

  int power2(int b, int p){               //O(Log(p))
    if(!p)  return 1;
    int ret = power2(b, p/2);
    return (p&1 ? ret*ret*b : ret*ret);
  }

/********************************* Modular Arithmetic *******************************/

Modular Arithmetic:
  (a + b) % m = ((a % m) + (b % m)) % m
  (a * b) % m = ((a % m) * (b % m)) % m
  (a - b) % m = ((a % m) – (b % m)) % m
  (a + m) % m = a%m
  (a ^ b) % m = (a ^ ( b % (m-1))) % m

  int add(int a, int b, int m){
      return (a%m + b%m) % m;
  }

  int sub(int a, int b, int m){
      return (a%m - b%m) % m;
  }

  int mul(int a, int b, int m){
      return (a%m * b%m) % m;
  }

/********************************* GCD & LCM *******************************/

int GCD(int a, int b){    //you can use built-in function __gcd(a, b)
  if(!b)  return a;
  return GCD(b, a%b);
}

int LCM(int a, int b){
  return (a*b)/GCD(a, b);
}
