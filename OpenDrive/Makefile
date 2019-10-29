

TARGETS=libXodr.a libXodr.so

SRCFILES=$(shell ls *.cpp)
OBJFILES=$(SRCFILES:.cpp=.o)

all: $(TARGETS)
	@echo "All Done."


libXodr.a: $(OBJFILES)
	ar -crs $@ $^
	@echo "$@ Done."

libXodr.so: $(OBJFILES)
	g++ -shared -o $@ $^
	@echo "$@ Done."\

%.o: %.cpp
	g++ -c -Wall -fpic $<
	@echo $@ created.

clean:
	-rm $(PTSFILES) $(OBJFILES)

