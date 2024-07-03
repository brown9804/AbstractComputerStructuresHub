# 			C++ proyect

###
######## belindabrownr@gmail.com
###


# 							Makefile logic:
# To create this file you need these files:
# $ @ replace left
# $ ^ right


### Command requested
# gunzip -c branch-trace-gcc.trace.gz | branch -s < # > -bp < # > -gh < # > -ph < # >

# Folders
INCLUDE = ./include/
INPUT = ./input/
RESULT = ./results/
SRC = ./src/

#######
S = 4
BP = 0
GH = 4
PH = 3

.PHONY: all run
all: branch
# buil run

CPP_FLAGS = -std=c++1y -I$(PWD)/include #search includes dir include

%.o: $(SRC)%.cpp
	g++ -c $^ -o $@ $(CPP_FLAGS)

branch: main.o pBimodal.o pPHistory.o pGHistory.o pTournament.o # all compile
	g++ $^ -o $@

.PHONY: run
run: branch
	gunzip -c $(INPUT)branch-trace-gcc.trace.gz | ./branch -s $(S) -bp $(BP) -gh $(GH) -ph $(PH)

.PHONY: clean
clean:
	rm -f *.o branch
