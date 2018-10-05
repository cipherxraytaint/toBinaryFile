/*
 * dataToBinary.h
 *  Interface of read/write to binary files.
 */

#ifndef DATATOBINARY_H_
#define DATATOBINARY_H_

#include <stdio.h>  // FILE

typedef struct TB_Header_Interface_ {
  int (*writeHeaderTo)(FILE *fl, struct TB_Header_Interface_ *hi);
  int (*readHeaderFrom)(FILE *fl, struct TB_Header_Interface_ *hi);
} TB_Header_Interface;

typedef struct TB_PropagatePair_Interface_ {
  int (*writePropagatePairTo)(FILE *fl, struct TB_PropagatePair_Interface_ *pi);
  int (*readPropagatePairFrom)(FILE *fl, struct TB_PropagatePair_Interface_ *pi);
} TB_PropagatePair_Interface;

#endif /* DATATOBINARY_H_ */
