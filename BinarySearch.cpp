What else?
  -BinarySearch in Integer Domain.
  -BinarySearch in Real Domain.

Terminology:
  Search Space
  low
  high
  median
  Check function

You can solve the problem using BinarySearch if and only if:
- You can design a check function whose domain is the problem's search space
  and its range is separated into at most one "False" segment and one "True" segment.


Can you design the upper_bound function?

bool isGreater(int a, int b){
  return a > b;
}

int upperBound(int *A, int val){
  int lo = 0, med, hi = n-1;
  while(lo<hi){
    mid = (lo+hi)>>1;
    if(isGreater(A[med], val))  hi = mid;
    else  lo = med+1;
  }
  return lo;
}


We have two cases:
1- Minimization Problems:
  -FFFFFFFFFFFFFFFFFFFTTTTTTTTTTTTTTTT
  -the range is separated into False-True range.
  -the target is the first True
  -We ceil the low and floor the median.

bool ok(int val){
  //Some Checking Statements
}

int binarySearch(){
  int lo = 0, med, hi = 1000000000;
  while(lo<hi){
    mid = (lo+hi)>>1;
    if(ok(A[med]))  hi = med;
    else  lo = med+1;
  }
  return hi;
}

2- Maximization Problems:
  -TTTTTTTTTTTTTTTFFFFFFFFFFFFFFF
  -the range is separated into True-False range.
  -the target is the last True.
  -We ceil the median and floor the high.

bool ok(int val){
  //Some Checking Statements
}

int binarySearch(){
  int lo = 0, med, hi = 1000000000;
  while(lo<hi){
    mid = (lo+hi+1)>>1;
    if(ok(A[med]))  lo = med;
    else  hi = med-1;
  }
  return lo;
}
