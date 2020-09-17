CC = g++

LD = $(CC)

CFLAGS = -Wall

LFLAGS = $(CFLAGS)

COVID = covid\

COVIDOBJS = covid.o covidmain.o

EXECS = $(COVID)\

ALL = $(EXECS)

#Regra Implicita
.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(ALL)

covid: $(COVIDOBJS)
	$(LD) $(LFLAGS) -o $@ $(COVIDOBJS)
	@cp -f $@ $@-$(OS)-$(CC)

clean:
	rm -f *.o $(ALL)
