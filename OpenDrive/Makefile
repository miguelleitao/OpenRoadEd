

TARGETS=libXodr.a libXodr.so

SRCFILES=$(shell ls *.cpp)
OBJFILES=$(SRCFILES:.cpp=.o)

ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

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

clean:
	-rm $(TARGETS) $(OBJFILES)

install: ${TARGETS}
	install -d $(DESTDIR)$(PREFIX)/lib/
	install -m 644 $^ $(DESTDIR)$(PREFIX)/lib/
	ldconfig

uninstall:
	-rm $(DESTDIR)$(PREFIX)/lib/libXodr.a
	-rm $(DESTDIR)$(PREFIX)/lib/libXodr.so
