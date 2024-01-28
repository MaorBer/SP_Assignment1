CC = gcc
AR = ar
CFLAGS = -g -Wall
OBJECTS_LOOP_BASIC = basicClassification.o advancedClassificationLoop.o
OBJECTS_RECURSIVE_BASIC = basicClassification.o advancedClassificationRecursion.o

all: recursived recursives loopd loops mains maindloop maindrec

loops: libclassloops.a
loopd: libclassloops.so
recursives: libclassrec.a
recursived: libclassrec.so

maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) -o maindrec main.o libclassrec.so -lm

maindloop: main.o libclassloops.a
	$(CC) $(FLAGS) -o maindloop main.o libclassloops.a -lm

mains: main.o libclassrec.a
	$(CC) $(FLAGS) -o mains  main.o libclassrec.a -lm

libclassloops.a: $(OBJECTS_LOOP_BASIC)
	$(AR) -rcs libclassloops.a $(OBJECTS_LOOP_BASIC)

libclassloops.so: $(OBJECTS_LOOP_BASIC)
	$(CC) -shared $(OBJECTS_LOOP_BASIC) -o libclssloops.so 

libclassrec.a: $(OBJECTS_RECURSIVE_BASIC)
	$(AR) -rcs libclassrec.a $(OBJECTS_RECURSIVE_BASIC)

libclassrec.so: $(OBJECTS_RECURSIVE_BASIC)
	$(CC) -shared $(OBJECTS_RECURSIVE_BASIC) -o libclassrec.so 

main.o: main.c NumClass.h
	$(CC) $(CFLAGS) main.c -c

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(CFLAGS)  -fPIC basicClassification.c -c 

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(CFLAGS)  -fPIC advancedClassificationLoop.c -c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(CFLAGS)  -fPIC advancedClassificationRecursion.c -c

.PHONY: clean loops loopd reccursived reccursives

clean:
	rm -f *.o *.a *so mains maindloop maindrec