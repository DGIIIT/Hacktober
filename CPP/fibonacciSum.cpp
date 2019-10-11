std::vector<int> fibonacciSum(int n) {

  std::vector<int> fib;
  int fib0 = 1;
  int fib1 = 1;
  fib.push_back(fib1);
  while (fib1 < n) {
    int fib2 =  fib1+fib0 ;
    fib.push_back(fib2);
    fib0 = fib1;
    fib1 = fib2;
  }

  std::vector<int> ans;
  for (int i = (int)fib.size() - 1; i >= 0; i--) {
    if (n >= fib[i]) {
      n -= fib[i];
      ans.push_back(fib[i]);
    }
  }

  std::reverse(ans.begin(), ans.end());
  return ans;
}
