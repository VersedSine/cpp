# `Vss/bigint` 库
###### by Versed_sine 

- `#include "Vss/bigint"` 以导入该库。

- 提供调试宏 `VSS_BIGINT_DEBUG__` 用于调试，可以在部分错误运行出抛出 `Assertion failed`，

   - 若需使用该功能请在 `#include "Vss/bigint"` 语句之前输入 `#define VSS_BIGINT_DEBUG__`。

- `bigint <变量名>;` 以声明一个 `bigint` 型变量。

  - 若赋值为 `float`、`double`、`long double` 的其中之一，会舍去小数部分，请注意精度误差而导致的问题。
  
  - 若赋值为 `const char*`、`std::string` 的其中之一，请保证字符串的内容只有数字，否则在调试时会抛出 `Assertion failed`。

- 提供字面量后缀 `_bint`，可在 `unsigned long long int`、`long double`、`const char*` 型字面量末尾加上 `_bint` 以转化为 `bigint` 型字面量。

  - 注意事项同直接赋值。

- 支持流输入、流输出