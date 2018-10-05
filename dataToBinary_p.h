/*
 * dataToBinary_p.h
 *  Defines data structs read/write to binary files, implement defined
 *  interface.
 */

#ifndef DATATOBINARY_P_H_
#define DATATOBINARY_P_H_

#include "dataToBinary.h"

#define u32 unsigned int

typedef struct TB_Header_ {
  TB_Header_Interface *hi;
  u32 srcBufBegin;
  u32 srcBufEnd;
  u32 dstBufBegin;
  u32 dstBufEnd;
} TB_Header;

typedef struct TB_PropagatePair_ {
  TB_PropagatePair_Interface *ppi;
  u32 srcAddr;
  u32 srcVal;
  u32 dstAddr;
  u32 dstVal;
} TB_PropagatePair ;

/* function prototype */

TB_Header *
newHeader(u32 srcBufBegin, u32 srcBufEnd, u32 dstBufBegin, u32 dstBufEnd);

void
delHeader(TB_Header *h);

void
printHeader(TB_Header *h);

TB_PropagatePair *
newPropagatePair(u32 srcAddr, u32 srcVal, u32 dstAddr, u32 dstVal);

void
delPropagatePair(TB_PropagatePair **pp);

void
printPropagatePair(TB_PropagatePair *pp);

#endif /* DATATOBINARY_P_H_ */
