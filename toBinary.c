#include "toBinary.h"

int
readFromBinary(FILE *fl, TB_PropagatePair_Interface *pi)
{
  return pi->readPropagatePairFrom(fl, pi);
}

int
writeToBinary(FILE *fl, TB_PropagatePair_Interface *pi)
{
  return pi->writePropagatePairTo(fl, pi);
}
