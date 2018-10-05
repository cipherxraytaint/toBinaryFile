/*
 * dataToBinary_p.h
 *  Defines data structs read/write to binary files, implement defined
 *  interface.
 */

#ifndef DATATOBINARY_P_H_
#define DATATOBINARY_P_H_

#include "dataToBinary.h"

typedef struct TB_PropagatePair_ {
  TB_PropagatePair_Interface *ppi;
  unsigned int srcAddr;
  unsigned int srcVal;
  unsigned int dstAddr;
  unsigned int dstVal;
} TB_PropagatePair ;

/* function prototype */

TB_PropagatePair *newPropagatePair(
  unsigned int srcAddr,
  unsigned int srcVal,
  unsigned int dstAddr,
  unsigned int dstVal);

void delPropagatePair(TB_PropagatePair *pp);

void printPropagatePair(TB_PropagatePair *pp);

#endif /* DATATOBINARY_P_H_ */
