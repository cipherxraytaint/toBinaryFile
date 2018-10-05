#include <assert.h>
#include <stdlib.h> // calloc
#include "dataToBinary_p.h"

/* static function prototype */
static int readPropagatePairFrom_(FILE *fl, TB_PropagatePair_Interface *pi);
static int writePropagatePairTo_(FILE *fl, TB_PropagatePair_Interface *pi);

/* static function */
static int readPropagatePairFrom_(FILE *fl, TB_PropagatePair_Interface *pi)
{

}

static int writePropagatePairTo_(FILE *fl, TB_PropagatePair_Interface *pi)
{

}

/* non-static function */
TB_PropagatePair *newPropagatePair(
  unsigned int srcAddr,
  unsigned int srcVal,
  unsigned int dstAddr,
  unsigned int dstVal)
{
  TB_PropagatePair *pp = calloc(1, sizeof(TB_PropagatePair));
  assert(pp != NULL);

  pp->ppi->readPropagatePairFrom = readPropagatePairFrom_;
  pp->ppi->writePropagatePairTo  = writePropagatePairTo_;

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

}
