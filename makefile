C_COMPILER=gcc
TESTFILES=test_lock.c
UNITY=../unity/src/unity.c
MAIN=main.c
FUN=input.c lock.c
OBJ=input.o lock.o
LIB=input.h lock.h
MAINTARGET=lock
TESTTARGET=test
Q=@

main: $(MAIN) $(FUN) $(LIB)
	@echo Building client version
	$(Q) $(C_COMPILER) -c $(FUN)
	$(Q) $(C_COMPILER) -o $(MAINTARGET) $(MAIN) $(OBJ)
	$(Q) -del -f *.o
	@echo Build complete

test: $(TESTFILES) $(FUN) $(LIB)
	@echo Building test version
	$(Q) $(C_COMPILER) -c $(FUN)
	$(Q) $(C_COMPILER) -o $(TESTTARGET) $(TESTFILES) $(OBJ) $(UNITY)
	$(Q) -del -f *.o
	@echo Build complete

help:
	@echo ----  To see process, type "Q=" at the end of command  ----
	@echo *
	@echo *   main     Build client version
	@echo *   test     Build test version
	@echo *   clean    Clean away objectfiles and executives
	@echo *   install  Upload build to target
	@echo *   help     Lists available make commands

clean:
	$(Q) -del -f *.o *.exe
	@echo Clean complete
