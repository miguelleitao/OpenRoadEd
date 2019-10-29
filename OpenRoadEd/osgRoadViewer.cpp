/*
	xodr2osg.cpp 
	OpenDrive Xodr to OSG converter and Xodr viewer.
	Miguel Leitao, ISEP, 2019
*/


#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osg/MatrixTransform>
#include <osgGA/TrackballManipulator>

#include "OpenDrive/OpenDrive.h"
#include "Osg/OSGMain.h"
#include "OpenDrive/OpenDriveXmlParser.h"


void usage(char *app_name) {
    printf("Usage: %s [options] file_in [file_out]\n", app_name);
    exit(1);
}

int main(int argc, char* argv[])
{
//	osg::Matrix myMatrix;

    if ( argc<2 ) usage(argv[0]);
    
    int runViewer = 0;
    
    char *fout_name = NULL;
    if ( strstr(argv[0], "xodrviewer")!=NULL ) {
        runViewer = 1;
    }
    else {
        if ( argc<3 ) {
            fout_name = (char *)malloc(strlen(argv[1]+6));
            strcpy(fout_name,argv[1]);
            strcat(fout_name,".osg");
        }
        else fout_name = strdup(argv[2]);
    }
    
	// Creating the root node
    osg::Group* SceneRoot = new osg::Group;

    // Creates the OpenDrive structure
    OpenDrive mOpenDrive;

	OpenDriveXmlParser mOpenDriveParser(&mOpenDrive);
	mOpenDriveParser.ReadFile(argv[1]);

    // Creates the OSG object
    OSGMain mOsgMain( &(mOpenDrive) );
    mOsgMain.DrawRoads();

    if ( ! runViewer ) {
        osgDB::writeNodeFile(*(mOsgMain.mRoadsGroup.get()), fout_name);
        //osgDB::writeNodeFile(*(SceneRoot), "scene.osg");
    }
    else {
        // Creating the viewer
        osgViewer::Viewer viewer ;
        viewer.setSceneData( mOsgMain.mRootGroup );

        //SceneRoot->addChild(mOsgMain.mRootGroup);

        // Setup camera
        osg::Matrix matrix;
        matrix.makeLookAt( osg::Vec3(0.,-30.,5.), osg::Vec3(0.,0.,0.), osg::Vec3(0.,0.,1.) );
        viewer.getCamera()->setViewMatrix(matrix);

        viewer.setCameraManipulator(  new osgGA::TrackballManipulator() );

        while( !viewer.done() ) {
            viewer.frame();
        }
    }
    free(fout_name);
}

