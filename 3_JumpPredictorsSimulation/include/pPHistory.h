#ifndef PPHISTORY_H
#define PPHISTORY_H

// @brown9804 Belinda Brown
// timna.brown@ucr.ac.cr
// September, 2020

///////////////////////////////

// Jump Predictor
// --> Private History

//////////////////////////////
#include "includes.h"
/////////////////////////////

// Two bits counter
// Has four types of posible values:
// * Strongly taken        - 11 = 3
// * Weakly taken          - 10 = 2
// * Weakly not taken      - 01 = 1
// * Strongly not taken    - 00 = 0

// Table counter & all couter init in Strongly not taken

// Considering the mention in the bimodal predictor:
// Two bit table
// MSB                                                      LSB
// X                                                         X
// bit address/prediction             -           Prediction/Conviction
// [taken/untaken]                    -                 How sure?

// branch-trace-gcc.trace.gz | branch -s < # > -bp < # > -gh < # > -ph < # >

// file_name: Compress file entry
// s: Branch History Table (BHT) size
// gh: GShare size (given value)
// ph: PShare size (given value)

// This one follows the same logic but it consider all the history of each branch
// so the output is a table.

class privateHistory_F {
public:
  // VAR
  std::string filepath;

  int s;

  int gh;

  int ph;
  int ph_mask;

  privateHistory_F(std::string filepath, int s, int gh, int ph);

  void begin_prediction_P();
};

#endif
