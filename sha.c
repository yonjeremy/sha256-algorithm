// Jeremy Yon 2019 g00330435
// Secure Hash Algorithm, 256 bit version
// https://ws680.nist.gov/publication/get_pdf.cfm?pub_id=910977


// the usual input/output file header
#include <stdio.h>
// For using fixed bit length integers.
#include <stdint.h>

void sha256();

int main(int argc, char *argv[]){

   return 0;
}

void sha256(){

   // message schedule (section 6.2)
   uint32_t W[64];
   // working variables (section 6.2)
   uint32_t a,b,c,d,e,f,g,h;
   // two temporary variables (section 6.2)
   uint32_t T1,T2;

   // the hash value (section 6.2)
   // the values come from (section 5.3.3)
   uint32_t H[8] = {
      0x6a09e667,
      0xbb67ae85,
      0x3c6ef372,
      0xa54ff53a,
      0x510e527f,
      0x9b05688c,
      0x1f83d9ab,
      0x5be0cd19
   };
}