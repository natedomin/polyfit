PROJECT := polyfit

CC := gcc
CPP := g++

IDIR   := $(CPPUTEST_HOME)/include
CFLAGS := -I$(IDIR) -Wall

LDIR := -L$(CPPUTEST_HOME)/lib
UNITTESTEXE := runUnitTests

LIBS := -lCppUTest -lCppUTestExt

C_SRC = polyfit.c

CPP_SRC = test_polyfit.cpp

OBJS := polyfit.o \
        test_polyfit.o

all: $(PROJECT)
	./$(UNITTESTEXE)

$(PROJECT):
	$(CC) -c $(C_SRC) $(CFLAGS)
	$(CPP) -c $(CPP_SRC) $(CFLAGS)
	$(CPP) -o $(UNITTESTEXE) $(OBJS) $(LIBS) $(LDIR)

.PHONY: clean
clean:
	$(RM) $(OBJS) $(PROJECT) $(UNITTESTEXE)


