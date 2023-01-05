# Adjust the next three lines if you're on a Pi
FLAVOR = nopi
INCLUDE = $(INCLUDE_NOPI)
LDFLAGS = $(LDFLAGS_NOPI)

INCLUDE_NOPI := 
LDFLAGS_NOPI := -lncurses

all: clock

clock: main.o display.o
	cc -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o clock
main.o: main.c display.h
	cc -c $<
display.o: display.c display.h
	cc -o $@ -c $< $(INCLUDE)

run:
	./clock.sh | ./clock
