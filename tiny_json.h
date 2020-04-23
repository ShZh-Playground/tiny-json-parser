#ifndef TINYJSON_H__
#define TINYJSON_H__

// JSON的各种数据类型
typedef enum {
  TINY_NULL,
  TINY_FALSE,
  TINY_TRUE,
  TINY_NUMBER,
  TINY_STRING,
  TINY_ARRAY,
  TINY_OBJECT
} tiny_type;

// JSON的各种解析结果
enum {
  TINY_OK,
  TINY_EXCEPT_VALUE,
  TINY_INVAILD_VALUE,
  TINY_ROOT_NOT_SINGULAR
};

// 用来存储json键值对信息的
typedef struct {
  tiny_type type;
} tiny_value;


int Parse(tiny_value* v, const char* json);
tiny_type GetType(const tiny_value* v); 

#endif // TINYJSON_H__ ends