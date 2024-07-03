#!/bin/bash

# This scripts does a simple comparison of two files
# using diff cmd

# Variable to check for errors
error=0

# Run all BP and do an strict comparison
# BIMODAL
echo "Run Bimodal Branch Predictor"
gunzip -c branch-trace-gcc.trace.gz | ./branch.py -s 4 -bp 0 -gh 4 -ph 3 > actual_result.txt
diff expected_result_sum_bimodal.txt actual_result.txt > diff.txt
echo "Show differences for Bimodal predictor"
cat diff.txt
a=`wc -l diff.txt| cut -f1 -d ' '`
if (($a == 0)); then
   echo "Results for Bimodal predictor are correct"
else
  echo "Results for Bimodal predictor are incorrect"
   error=1
fi

# PSHARE
echo "Run Pshare Branch Predictor"
gunzip -c branch-trace-gcc.trace.gz | ./branch.py -s 5 -bp 1 -gh 4 -ph 3 > actual_result.txt
diff expected_result_sum_pshare.txt actual_result.txt > diff.txt
echo "Show differences for Pshare predictor"
cat diff.txt
a=`wc -l diff.txt| cut -f1 -d ' '`
if (($a == 0)); then
   echo "Results for Pshare predictor are correct"
else
  echo "Results for Pshare predictor are incorrect"
   error=1
fi

# GSHARE
echo "Run Gshare Branch Predictor"
gunzip -c branch-trace-gcc.trace.gz | ./branch.py -s 5 -bp 2 -gh 4 -ph 3 > actual_result.txt
diff expected_result_sum_gshare.txt actual_result.txt > diff.txt
echo "Show differences for Gshare predictor"
cat diff.txt
a=`wc -l diff.txt| cut -f1 -d ' '`
if (($a == 0)); then
   echo "Results for Gshare predictor are correct"
else
  echo "Results for Gshare predictor are incorrect"
   error=1
fi

# TOURNAMENT 
echo "Run Tournament Branch Predictor"
gunzip -c branch-trace-gcc.trace.gz | ./branch.py -s 5 -bp 3 -gh 5 -ph 3 > actual_result.txt
diff expected_result_sum_tournament.txt actual_result.txt > diff.txt
echo "Show differences for Tournament predictor"
cat diff.txt
a=`wc -l diff.txt| cut -f1 -d ' '`
if (($a == 0)); then
   echo "Results for Tournament predictor are correct"
else
  echo "Results for Tournament predictor are incorrect"
  error=1
fi

rm diff.txt
rm actual_result.txt

if (($error == 1));then
  exit -1
fi
