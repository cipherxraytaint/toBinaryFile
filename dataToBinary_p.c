#include <assert.h>
#include <stdlib.h> // calloc
#include <stdio.h>  // fread/fwrite
#include "dataToBinary_p.h"

/* static function prototype */
static int readHeaderFrom_(FILE *fl, TB_Header_Interface *hi);
static int writeHeaderTo_(FILE *fl, TB_Header_Interface *hi);

static int readPropagatePairFrom_(FILE *fl, TB_PropagatePair_Interface *pi);
static int writePropagatePairTo_(FILE *fl, TB_PropagatePair_Interface *pi);

/* static function */
static int
readPropagatePairFrom_(FILE *fl, TB_PropagatePair_Interface *pi)
{
  TB_PropagatePair *pp = (TB_PropagatePair *)pi;
  size_t sz = sizeof(TB_PropagatePair) - sizeof(TB_PropagatePair_Interface);

  if(fread(&(pp->srcAddr), sz, 1, fl) > 0) {
    printf("read from binary:%u bytes\n", sz);
    return 0;
  }
  else{
    fprintf(stderr, "error read from binary\n");
    return 1;
  }
}

static int
writePropagatePairTo_(FILE *fl, TB_PropagatePair_Interface *pi)
{
  TB_PropagatePair *pp = (TB_PropagatePair *)pi;
  size_t sz = sizeof(TB_PropagatePair) - sizeof(TB_PropagatePair_Interface);

  if(fwrite(&(pp->srcAddr), sz, 1, fl) > 0) { // exclude the TB_PropagatePair_Interface
    printf("write to binary:%u bytes\n", sz);
    return 0;
  }
  else
    return 1;
}

/* non-static function */
TB_Header *
newHeader(u32 srcBufBegin, u32 srcBufEnd, u32 dstBufBegin, u32 dstBufEnd)
{
  return NULL;
}

void
delHeader(TB_Header *h) {}

void
printHeader(TB_Header *h) {}


TB_PropagatePair *
newPropagatePair(u32 srcAddr, u32 srcVal, u32 dstAddr, u32 dstVal)
{
  TB_PropagatePair *pp = calloc(1, sizeof(TB_PropagatePair));
  assert(pp != NULL);

  pp->ppi.readPropagatePairFrom = readPropagatePairFrom_;
  pp->ppi.writePropagatePairTo  = writePropagatePairTo_;

  pp->srcAddr   = srcAddr;
  pp->srcVal    = srcVal;
  pp->dstAddr   = dstAddr;
  pp->dstVal    = dstVal;

  return pp;
}

void delPropagatePair(TB_PropagatePair **pp)
{
  assert(pp != NULL);
  if(*pp != NULL) {
    free(*pp);
    *pp = NULL;
  }
}

void printPropagatePair(TB_PropagatePair *pp)
{
  assert(pp);
  printf("propagatepair: srcAddr:%u - srcVal:%u - dstAddr:%u - dstVal:%u\n",
      pp->srcAddr, pp->srcVal, pp->dstAddr, pp->dstVal);
}
