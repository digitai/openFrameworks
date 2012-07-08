#pragma once

#include "ofMain.h"
#include "drawingLayer.h"
#include "ofxUI.h"
#include "ofxBlur.h"
#define SLICES 6

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    void undoLastMove();
    void setupGui();
    void guiEvent(ofxUIEventArgs &e);
    
    ofColor lineColor;
    ofxUICanvas *gui;
    
    void exit();
    
    vector <drawingLayer> layerArray;
    drawingLayer currentLayer;
    bool drawing;
    ofFbo myFBO;
    ofxBlur blur;
};
