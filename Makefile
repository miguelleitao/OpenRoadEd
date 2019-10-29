
INC_OSG=-I/usr/include/osg
LD_OSG=-losg -losgViewer -losgSim -l osgDB -l osgGA
CEPHES=Cephes/fresnl.o Cephes/polevl.o Cephes/const.o

#g++ -O2 -o osgRoadViewer osgRoadViewer.o -losg -losgViewer -losgSim -l osgDB -l osgGA -l stdc++ -lm -L OpenDrive/ -l Xodr /usr/lib64/libtinyxml.so.0 -L Osg -l odOSG Cephes/fresnl.o Cephes/polevl.o Cephes/const.o

TARGET=xodr2osg

all: ${TARGET} xodrviewer

${TARGET}: ${TARGET}.o ${CEPHES} 
	g++ -o $@ $^ ${LD_OSG} -L OpenDrive -l Xodr /usr/lib64/libtinyxml.so.0 -L Osg -l odOSG -l stdc++ -lm

${TARGET}.o: ${TARGET}.cpp
	g++  -Wall -O2  -c ${INC_OSG} $<

xodrviewer: ${TARGET}
	ln -s $< $@

push:
	git add .
	git commit -m "update"
	git push


.PHONY: clean
clean:
	rm -f ${TARGET}.o ${TARGET} xodrviewer Cephes/*.o


