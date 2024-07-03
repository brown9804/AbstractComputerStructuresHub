#ifndef PBIMODAL_H
#define PBIMODAL_H

// @brown9804 Belinda Brown
// timna.brown@ucr.ac.cr
// September, 2020

///////////////////////////////

// Jump Predictor
// --> Bimodal

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

// Also know as Decode History Table (DHT):
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

class bimodal_F {
public:
  // VAR
  std::string filepath;

  int s;

  int gh;

  int ph;

  bimodal_F(std::string filepath, int s, int gh, int ph);

  void begin_prediction_B();

};


#endif
