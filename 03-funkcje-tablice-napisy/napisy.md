
## Zadanie

Napisz funkcję w języku C++, która przyjmuje jako argumenty dwa ciągi znaków i zwraca długość najdłuższego wspólnego podciągu (LCS, ang. Longest Common Subsequence) tych ciągów.

```
input: "ABCD", "ACDF"
output: 2
```

```cpp
#include <iostream>
#include <string>

int LCS(std::string str1, std::string str2) {
  int m = str1.length();
  int n = str2.length();
  int dp[m+1][n+1];

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else if (str1[i-1] == str2[j-1])
        dp[i][j] = dp[i-1][j-1] + 1;
      else
        dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
    }
  }

  return dp[m][n];
}

int main() {
  std::string str1 = "ABCD";
  std::string str2 = "ACDF";
  std::cout << "LCS length: " << LCS(str1, str2) << std::endl;
  return 0;
}

```
