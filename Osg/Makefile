

TARGETS=libodOSG.a libodOSG.so

SRCFILES=$(shell ls *.cpp)
OBJFILES=$(SRCFILES:.cpp=.o)

ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

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

.PHONY: clean
clean:
	-rm $(TARGETS) $(OBJFILES)

.PHONY: install
install: ${TARGETS}
	install -d $(DESTDIR)$(PREFIX)/lib/
	install -m 644 $^ $(DESTDIR)$(PREFIX)/lib/
	ldconfig

.PHONY: uninstall
uninstall:
	-rm $(DESTDIR)$(PREFIX)/lib/libodOSG.a
	-rm $(DESTDIR)$(PREFIX)/lib/libodOSG.so

