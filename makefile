C_COMPILER=gcc
TESTFILES=test_lock.c
UNITY=../unity/src/unity.c
MAIN=main.c
FUN=input.c lock.c
OBJ=input.o
LIB=input.h
MAINTARGET=lock
TESTTARGET=test

main: main.c input.c input.h
	$(C_COMPILER) -c $(FUN)
	$(C_COMPILER) -o $(MAINTARGET) $(MAIN) $(OBJ)
	-del -f *.o

test: $(TESTFILES) $(FUN) $(LIB)
	$(C_COMPILER) -c $(FUN)
	$(C_COMPILER) -o $(TESTTARGET) $(TESTFILES) $(OBJ) $(UNITY)
	-del -f *.o

clean:
	-del -f *.o *.exe
