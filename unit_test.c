#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tiny_json.h"

static int main_ret = 0;
static int test_count = 0;
static int test_pass = 0;

// 用来测试相等的基
// 单元测试剖析： 如果测试通过，就计数；不然就利用stderr指明错误
#define EXPECT_EQ_BASE(equality, expect, actual, format) \
  do {  \
    ++test_count; \
    if (equality) { \
      ++test_pass;  \
    } else {        \
      fprintf(stderr, "%s:%d: expect: " format " actual: " format "\n", __FILE__, __LINE__, expect, actual);\
      main_ret = 1; \
    }\
  } while(0)

#define EXPECT_EQ_INT(expect, actual) EXPECT_EQ_BASE((expect) == (actual), expect, actual, "%d")

// 静态函数只是在声明它的文档可见
static void TestParseNull() {
  tiny_value value;
  value.type = TINY_FALSE;
  // 测试了结果
  // 同时也测试了类型
  EXPECT_EQ_INT(TINY_OK, Parse(&value, "null"));
  EXPECT_EQ_INT(TINY_NULL, GetType(&value));
}