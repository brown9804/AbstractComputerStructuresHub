# Simulation of Jump Predictors

----------

University of Costa Rica

Belinda Brown, timna.brown@ucr.ac.cr

September, 2020

----------


### Four types of jump predictor:

Average of time running less than 29 seconds for a 
sixteen million conditional jumps trace. 

#### 1.Bimodal (-bp 0):
Two bits counter
Has four types of posible values:
* Strongly taken        - 11 = 3
* Weakly taken          - 10 = 2
* Weakly not taken      - 01 = 1
* Strongly not taken    - 00 = 0

Table counter & all couter init in Strongly not taken, also known as Decode 
History Table DHT

------------------------------------------------------------------------
                            Two bit table
 ------------------------------------------------------------------------
         MSB                                                  LSB
          X                                                    X
     bit address/prediction              -           Prediction/Conviction
      [taken/untaken]                    -                 How sure?
------------------------------------------------------------------------

`````
branch-trace-gcc.trace.gz | branch -s < # > -bp < # > -gh < # > -ph < # >
``````


-> file_name: Compress file entry

-> s: Branch History Table (BHT) size

-> gh: GShare size (given value)

-> ph: PShare size (given value)

#### 2.Private History (-bp 1):

Table counter & all couter init in Strongly not taken
Has four types of posible values:
* Strongly taken        - 11 = 3
* Weakly taken          - 10 = 2
* Weakly not taken      - 01 = 1
* Strongly not taken    - 00 = 0

Table counter & all couter init in Strongly not taken, also known as Decode 
History Table DHT

------------------------------------------------------------------------
                            Two bit table
 ------------------------------------------------------------------------
         MSB                                                  LSB
          X                                                    X
     bit address/prediction              -           Prediction/Conviction
      [taken/untaken]                    -                 How sure?
------------------------------------------------------------------------

`````
branch-trace-gcc.trace.gz | branch -s < # > -bp < # > -gh < # > -ph < # >
``````


-> file_name: Compress file entry

-> s: Branch History Table (BHT) size

-> gh: GShare size (given value)

-> ph: PShare size (given value)


This one follows the same logic but it consider all the history of each branch
so the output is a table.



#### 3.Global History (-bp 2):
Two bits counter plus a eregister that contains the 
history of the last branches. It's needed the last n bits as a result of 
the XOR operation between the counter and the history counter. All
counter are initalize in strong not taken.

`````
branch-trace-gcc.trace.gz | branch -s < # > -bp < # > -gh < # > -ph < # >
```````

-> file_name: Compress file entry

-> s: Branch History Table (BHT) size

-> gh: GShare size (given value)

-> ph: PShare size (given value)

#### 4."Tournament" (-bp 3):
This one choose between GShare and Pshare.

### Compile Instructions 

Remember the requested command:

````
gunzip -c branch-trace-gcc.trace.gz | branch -s < # > -bp < # > -gh < # > -ph < # >
````

Where:

-> file_name: Compress file entry

-> s: Branch History Table (BHT) size

-> gh: GShare size (given value)

-> ph: PShare size (given value)


Entry to run a general configuration ---->  s = 16, bp = 0, gh = 4, ph = 3: 

`````
<path this reposity on your local machine>$ make run
`````

Or entry for example:

`````
<path this reposity on your local machine>$ make run BP <value>
`````




