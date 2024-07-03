

#include "pGHistory.h"

globalHistory_F::globalHistory_F(std::string filepath,int s, int gh, int ph){
    this->filepath=filepath; //Compress file entry
    this->s=s; // Branch History Table (BHT) size
    this->gh=gh; //GShare size (given value)
    this->ph=ph; //PShare size (given value)
    this->ph_mask = (1 << gh) - 1;
    };

void globalHistory_F::begin_prediction_G(){
  int Table_Nentry = pow(2, s); // 2^s
  int counter_miss_T = 0; // Incorrect Taken branches
  int counter_miss_N = 0; // Incorrect Not Taken branches
  int counter_T = 0; // Right Taken branches
  int counter_N = 0; // Right Not Taken branches
  char *BHT_t = (char *)calloc(Table_Nentry, sizeof(char));
  int global_history = 0;
  int mask = (1 << s) - 1; // mask size for redirecting network

  /////////////
  std::string op_mode = "GShared"; // Pshared Private History / Private Shared
  int num_branch = 0; // number of branches (jumps)
  /////////
  time_t current_time;
  time_t final_time;

  time(&current_time); // capture time
  std::ofstream results_file ("results/result_sum_gshare.txt", std::ofstream::out);       // result file write
  if(!results_file) {// if no file
         std::cout<<"ERROR, there is no file created ............. ERROR ..... ERROR";
    }
  /////// File open
  for (std::string line; std::getline(std::cin, line);) {
    long pc_dd = 0;
    char result = ' ';
    sscanf(line.c_str(), "%ld %c", &pc_dd, &result);

    // std::string pc_dd_10 = line.substr(0,10);  // Decimal direction // position // how many
    // char result = line.substr(11,1).c_str()[0];    // Result? -> T or N
    // long pc_dd = (int)std::strtol(pc_dd_10.c_str(), nullptr, 10); // 10 is the base which parse the string

    if ((result != 'N') && (result != 'T')) {
      std::cout << "Parser error at line " << num_branch << std::endl;
    }

    //std::cout << "Address " << pc_dd << " mapped to " << pc_mask_access << " with mask " << mask << std::endl;
    // Predicting
    long pc_mask_access = (global_history ^ pc_dd) & mask;

    if (BHT_t[pc_mask_access] <= 1) {
      if (result == 'N') {
        counter_N++;
      } else {
        counter_miss_T++;
      }
    } else {
      if (result == 'T') {
        counter_T++;
      } else {
        counter_miss_N++;
      }
    }

    // Adjust counters based on result
    global_history = (global_history << 1) & ph_mask;
    if (result == 'N') {
      // Decrement if not 0
      if (BHT_t[pc_mask_access] > 0) {
        BHT_t[pc_mask_access]--;
      }
    } else {
      global_history |= 1;
      // Increment if 3
      if (BHT_t[pc_mask_access] < 3) {
        BHT_t[pc_mask_access]++;
      }
    }

num_branch=num_branch+1;
}

time(&final_time); // capture time
int ex_time = difftime(final_time,current_time);
float percentage = (float)(counter_T + counter_N)*(float)(100/((float)num_branch)); // for all lines

/////////////////////Results////////////////////////////////////////////////////
results_file << "------------------------------------------------------------------------ \n";
results_file << "Prediction parameters: \n ";
results_file << "------------------------------------------------------------------------ \n";
results_file << "Branch prediction type: " << op_mode << std::endl;
results_file << "BHT_t size (entries): " << Table_Nentry << std::endl;
results_file << "Global history register size: " << gh << std::endl;
results_file << "Private history register size: " << ph << std::endl;
results_file << "------------------------------------------------------------------------ \n";
results_file << "Simulation results: " << std::endl;
results_file << "------------------------------------------------------------------------\n";
results_file << "Number of branch: " << num_branch << std::endl;
results_file << "Number of correct prediction of taken branches: " << counter_T << std::endl;
results_file << "Number of incorrect prediction of taken branches: " << counter_miss_T << std::endl;
results_file << "Correct prediction of not taken branches: " << counter_N << std::endl;
results_file << "Incorrect prediction of not taken branches: " << counter_miss_N << std::endl;
results_file << "Percentage of correct predictions: " << percentage << "%" <<std::endl;
results_file << "Time running: " << ex_time << std::endl;

/////////////////////Results////////////////////////////////////////////////////
std::cout << "------------------------------------------------------------------------ \n";
std::cout << "Prediction parameters: \n ";
std::cout << "------------------------------------------------------------------------ \n";
std::cout << "Branch prediction type: " << op_mode << std::endl;
std::cout << "BHT_t size (entries): " << Table_Nentry << std::endl;
std::cout << "Global history register size: " << gh << std::endl;
std::cout << "Private history register size: " << ph << std::endl;
std::cout << "------------------------------------------------------------------------ \n";
std::cout << "Simulation results: " << std::endl;
std::cout << "------------------------------------------------------------------------\n";
std::cout << "Number of branch: " << num_branch << std::endl;
std::cout << "Number of correct prediction of taken branches: " << counter_T << std::endl;
std::cout << "Number of incorrect prediction of taken branches: " << counter_miss_T << std::endl;
std::cout << "Correct prediction of not taken branches: " << counter_N << std::endl;
std::cout << "Incorrect prediction of not taken branches: " << counter_miss_N << std::endl;
std::cout << "Percentage of correct predictions: " << percentage << "%" <<std::endl;
std::cout << "Time running: " << ex_time << " seconds" << std::endl;

free(BHT_t);
} // end all
