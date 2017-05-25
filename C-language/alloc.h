#ifndef  __ALLOC_H
#define  __ALLOC_H

#include  <stdlib.h>

#define  malloc  非法
#define  MALLOC(num,type)   (type*)alloc( (num) * sizeof(type) )
extern  void *alloc(size_t size);
#endif	 