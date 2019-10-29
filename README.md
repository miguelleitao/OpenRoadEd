# Xodr2OSG

Xodr2OSG is aimed in reading OpenDrive scenes to OpenSceneGraph structures. 
Poduced OpenSceneGraph structures can then be viewed in a simple OSG viewer or saved into .osg scene files.

Created by Miguel Leitao from a fork of https://github.com/fhwedel-hoe/OpenRoadEd, 
forked from https://sourceforge.net/projects/openroaded/.  

Forked OpenRoadEd project was created as part of this master's thesis: http://hdl.handle.net/2077/23047 by Dmitri and Egor Kurteanu.  

### Build Instructions

make

Requires OpenSceneGraph-devel and Tinyxml.

### Launch Instructions

  ./xodr2osg test.xodr test.osg
  ./xodr2osg test.xodr 
  ./xodrviewer test.xodr

