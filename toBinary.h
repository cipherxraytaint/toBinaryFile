/*
 * toBinary.h
 *  Write/read tpm src->dst propagate to binary files.
 *
 * All binary files are structure as:
 *  1) header info
 *   a) source buffer header
 *   b) destination buffer header
 *   header info is written to files in initial time.
 *  2) src node -> dst node propagate
 *   propagate info is written files during traversing tpm.
 */

#ifndef TOBINARY_H_
#define TOBINARY_H_

#include <stdio.h>  // FILE
#include "dataToBinary.h"

int readFromBinary(FILE *fl, TB_PropagatePair_Interface *pi);

int writeToBinary(FILE *fl, TB_PropagatePair_Interface *pi);

#endif /* TOBINARY_H_ */
