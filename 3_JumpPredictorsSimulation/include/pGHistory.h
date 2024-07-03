#ifndef PGHISTORY_H
#define PGHISTORY_H

// @brown9804 Belinda Brown
// timna.brown@ucr.ac.cr
// September, 2020

///////////////////////////////

// Jump Predictor
// --> Global History

//////////////////////////////
#include "includes.h"
/////////////////////////////

// branch-trace-gcc.trace.gz | branch -s < # > -bp < # > -gh < # > -ph < # >

// file_name: Compress file entry
// s: Branch History Table (BHT) size
// gh: GShare size (given value)
// ph: PShare size (given value)


// 2 bits counter plus a eregister that contains the history of the last branches
// It's needed the last n bits as a result of the XOR operation between the counter
// and the history counter

// All counter are initalize in strong not taken


class globalHistory_F {
public:
  // VAR
  std::string filepath;

  int s;

  int gh;

  int ph;
  int ph_mask;


  globalHistory_F(std::string filepath, int s, int gh, int ph);

  void begin_prediction_G();
};


#endif
