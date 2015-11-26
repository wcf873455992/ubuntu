CC = gcc
CFLAGS = -Wall -Werror -Wcast-align -g
LDFLAGS =

SWCOBJECT = swc.o opt.o video.o screen.o

all: swc

swc: $(SWCOBJECT)
	$(CC) $(LDFLAGS)    $(SWCOBJECT) -o  $@  `pkg-config --libs --cflags sdl`
#gcc `sdl-config-libs-cflags` test.c -o test。
#pkg-config --libs sdl
swc.o: swc.c
	$(CC) $(CFLAGS) `pkg-config --cflags sdl` -c $<

opt.o: opt.c opt.h
	$(CC) $(CFLAGS) `pkg-config --cflags sdl`  -c $<

video.o: video.c video.h
	$(CC) $(CFLAGS)  -c $<

screen.o: screen.c screen.h
	$(CC) $(CFLAGS) `pkg-config --cflags sdl` -c $<

clean:
	rm -f *.o *~ swc

.PHONY: all clean
