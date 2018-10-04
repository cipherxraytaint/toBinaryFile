#include "toBinary.h"

int readFromBinary(FILE *fl, TB_PropagatePair_Interface *pi)
{
  return pi->readFrom(fl, pi);
}

int writeToBinary(FILE *fl, TB_PropagatePair_Interface *pi)
{
  return pi->writeTo(fl, pi);
}
