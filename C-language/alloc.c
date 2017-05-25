/*
		不易发生错误的内存分配器的实现
功能：　构建内存分配函数：MALLOC(num ,type),并检查是否分配成功
          
author: blueblue
email : 978897910@qq.com  
*/
#include <stdio.h>
#include "alloc.h"

/* 为了防止在程序中调用malloc而产生内存相关问题，我们在alloc.h中宏定义了一个
“#define malloc  非法”这样的一种形式，所以在如果调用malloc 时会导致无法编译
直接报错，但是我们在下面构建分配内存函数时，还是要调用malloc的，所以必须在当前这个
文件域取消对malloc的宏定义。*/
#undef  malloc   


/*size_t 他是一种"整型"的类型  通常用sizeof（XXX）操作，返回的结果就是size_t 类型
主要完成分配内存，判断返回结果是否不为NULL
*/
void  *alloc(size_t size)
{
      void *new_mem;
	  /*分配内存，并检查是否分配成功*/
      new_mem = malloc(size);
	  
	  if(new_mem == NULL)
	  {
		  //printf("Out of memory !/n");
		  exit(1);
	  }
	  return new_mem;
} 

