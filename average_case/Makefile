MF=     Makefile
 
CC=     g++
 
CFLAGS= -g -Wall -Wextra -pedantic -fopenmp -msse4.2 -fomit-frame-pointer -funroll-loops 
 
LFLAGS= -std=c++11 -O3 -DNDEBUG 

EXE=   index 
 
SRC=    main.cpp input.cpp estimation.cpp weighted_sequence.cpp property_string.cpp PSA.cpp radixsort.cpp

HD=     input.h estimation.h weighted_sequence.h property_string.h PSA.h radixsort.h Makefile

# 
# No need to edit below this line 
#
 
.SUFFIXES: 
.SUFFIXES: .cpp .o 
 
OBJ=    $(SRC:.cpp=.o) 
 
.cpp.o: 
	$(CC) $(CFLAGS)-c $(LFLAGS) $< 
 
all:    $(EXE) 
 
$(EXE): $(OBJ) 
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LFLAGS) 
 
$(OBJ): $(MF) $(HD) 
 
clean: 
	rm -f $(OBJ) $(EXE) *~



