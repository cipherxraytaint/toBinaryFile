#include "dataToBinary_p.h"
#include "toBinary.h"

int main(int argc, char **argv) {

  FILE *wfl = fopen("testbin","wb");

  TB_PropagatePair *pp = newPropagatePair(0xb,0xe,0xe,0xf);
  writeToBinary(wfl, (TB_PropagatePair_Interface *)pp );

  pp->srcAddr = 0xd;
  pp->srcVal  = 0xe;
  pp->dstAddr = 0xa;
  pp->dstVal  = 0xd;
  writeToBinary(wfl, (TB_PropagatePair_Interface *)pp );

  fclose(wfl);

  FILE *rfl = fopen("testbin","rb");

  readFromBinary(wfl, (TB_PropagatePair_Interface *)pp );
  printPropagatePair(pp);
  readFromBinary(wfl, (TB_PropagatePair_Interface *)pp );
  printPropagatePair(pp);

  fclose(rfl);

  delPropagatePair(&pp);

  return 0;
}
