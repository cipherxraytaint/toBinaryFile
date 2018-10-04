/*
 * dataToBinary.h
 *  Defines data structs interface read/write to binary files.
 */

#ifndef DATATOBINARY_H_
#define DATATOBINARY_H_

#include <stdio.h>  // FILE

struct TB_Header_Interface_ {

};

typedef struct TB_PropagatePair_Interface_ {
  int (*writeTo)(FILE *fl, struct TB_PropagatePair_Interface_ *pi);
  int (*readFrom)(FILE *fl, struct TB_PropagatePair_Interface_ *pi);
} TB_PropagatePair_Interface;

#endif /* DATATOBINARY_H_ */
