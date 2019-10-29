

TARGETS=libodOSG.a libodOSG.so

SRCFILES=$(shell ls *.cpp)
OBJFILES=$(SRCFILES:.cpp=.o)

all: $(TARGETS)
	@echo "All Done."


libodOSG.a: $(OBJFILES)
	ar -crs $@ $^
	@echo "$@ Done."

libodOSG.so: $(OBJFILES)
	g++ -shared -o $@ $^
	@echo "$@ Done."\

%.o: %.cpp
	g++ -c -Wall -fpic $<
	@echo $@ created.

clean:
	-rm $(TARGETS) $(OBJFILES)

