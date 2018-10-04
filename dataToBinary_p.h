/*
 * dataToBinary_p.h
 *  Defines data structs read/write to binary files, implement defined
 *  interface.
 */

#ifndef DATATOBINARY_P_H_
#define DATATOBINARY_P_H_

#include "dataToBinary.h"

struct TB_PropagatePair_ {
  TB_PropagatePair_Interface *pi;
  unsigned int srcAddr;
  unsigned int srcVal;
  unsigned int dstAddr;
  unsigned int dstVal;
};


#endif /* DATATOBINARY_P_H_ */
