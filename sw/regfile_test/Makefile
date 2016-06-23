ALL_EXE = regfile_test
all: $(ALL_EXE) 

CC=gcc
CFLAGS=-I. -I../include  -I../API -I../hw -Wall

DEPS = Makefile ../hw/proto2_hw.h 

PUBLIC_LIBS = ../API/mem-io.o
LIB_FILES =

LIB_OBJS := $(subst .c,.o,$(LIB_FILES))

regfile_test: regfile_test.o $(LIB_OBJS) $(PUBLIC_LIBS)
# $@: target file name, $^: all prerequisites
	gcc -g -o $@ $^

run: regfile_test 
	@echo "You must be in root."
	./regfile_test

clean:
	rm -rf *.o $(ALL_EXE) 

#pattern rules
%.o: %.c $(DEPS)
# $<: first prerequisite
	$(CC) -g -c -o $@ $< $(CFLAGS)
