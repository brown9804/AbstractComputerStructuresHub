// @brown9804 Belinda Brown
// timna.brown@ucr.ac.cr
// September, 2020

// Jump predictor algorithm
// using an input file trace

// 1. Size of the BTH table. (-s)
// 2. Prediction type (-bp)
// 3. Size of the global prediction record (-gh)
// 4. Size of private history records (-ph)

/// gunzip -c branch-trace-gcc.trace.gz | branch -s < # > -bp < # > -gh < # > -ph < # >

////////// Lib /////////////
#include <iostream>
#include "pBimodal.h"
#include "pGHistory.h"
#include "pPHistory.h"
#include "pTournament.h"

using namespace std;

/// So we have
// prediction   bimodal    option 0
// prediction   gshared    option 1
// prediction   pshared    option 2
// prediction   tournament option 3


/// VAR
int s;
int bp;
int gh;
int ph;

string filepath;

/// Getting input
// gunzip -c branch-trace-gcc.trace.gz | branch -s < # > -bp < # > -gh < # > -ph < # >

int main (int argc, char *argv[]) {


for (int i = 1; i < argc-1; i=i+2)    {      // obteniendo variables ingresadas por linea de comandos
    string index = argv[i];
    if (index == "-c"){
      filepath = atoi(argv[i+1]);
    }
    else if (index == "-s"){
      s = atoi(argv[i+1]);
     }
    else if(index == "-bp"){
      bp = atoi(argv[i+1]);
      }
    else if(index == "-gh"){
      gh = atoi(argv[i+1]);
      }
    else if(index == "-ph"){
      ph = atoi(argv[i+1]);
      }
  } // end for
/// Decision Logic
if (bp == 0){ // Bimodal
  bimodal_F(filepath, s, gh, ph).begin_prediction_B();
}
else if (bp == 1){ // private
  privateHistory_F(filepath, s, gh, ph).begin_prediction_P();
}

else if (bp == 2){ // global

  globalHistory_F(filepath, s, gh, ph).begin_prediction_G();
}

else if (bp == 3){ // tournament
  pTournament_F(filepath, s, gh, ph).begin_prediction_T();
}
else {
  cout << "Wrong option, you have 0 = Bimodal, 1 = Private, 2 = Global, 3 = Tournament";
}

return 0;
} // end main
