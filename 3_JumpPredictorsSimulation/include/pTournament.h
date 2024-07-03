#ifndef PTOURNAMENT_H
#define PTOURNAMENT_H

// @brown9804 Belinda Brown
// timna.brown@ucr.ac.cr
// September, 2020

///////////////////////////////

// Jump Predictor
// --> Tournament

//////////////////////////////
#include "includes.h"
/////////////////////////////


// branch-trace-gcc.trace.gz | branch -s < # > -bp < # > -gh < # > -ph < # >

// file_name: Compress file entry
// s: Branch History Table (BHT) size
// gh: GShare size (given value)
// ph: PShare size (given value)

// It uses GShare and PShare, it access in parallel
// and has an output. These two counters has 2*s
// size 2 bit. It has like an arbiter that decides
// which chose, this one init as trongly prefer pshared.

class pTournament_F {
public:
  // VAR
  std::string filepath;

  int s;

  int gh;

  int ph;
  int ph_mask;
  int gh_mask;

  pTournament_F(std::string filepath,int s, int gh, int ph);

  void begin_prediction_T();
};

#endif
