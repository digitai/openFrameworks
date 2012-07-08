#include "testApp.h"
#define LINE_COLOR "LINE_COLOR"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0);
    drawing = false;
    myFBO.allocate(ofGetWidth(), ofGetHeight());
    lineColor.setHue(ofRandom(130.f,190.f));
    lineColor.setSaturation(255);
    lineColor.setBrightness(255);
    setupGui();
    
    blur.setup(ofGetWidth(), ofGetHeight(), 2,.2,1);
    myFBO.allocate(ofGetWidth(), ofGetHeight());
}

void testApp::setupGui()
{
        
    gui = new ofxUICanvas(0,40,320,420);		
    gui->addWidgetDown(new ofxUILabel("Flurrious", OFX_UI_FONT_LARGE)); 
    gui->addWidgetDown(new ofxUISlider(304,16,130.0,190.0,130.0,LINE_COLOR));

    ofAddListener(gui->newGUIEvent, this, &testApp::guiEvent); 
    
    gui->loadSettings("GUI/guiSettings.xml");
}

void testApp::guiEvent(ofxUIEventArgs &e)
{
    if (drawing){
        drawing = false;
        layerArray.pop_back(); //mouse event fires first, so lets cancel our last drawingLayer
    }

	if(e.widget->getName() == LINE_COLOR)	
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;    

        lineColor.setHue(slider->getScaledValue());
    }
}

//--------------------------------------------------------------
void testApp::update(){
    if (drawing){
        ofPoint p;
        p.x = mouseX-ofGetWidth()/2;
        p.y = mouseY-ofGetHeight()/2;
        layerArray[layerArray.size()-1].update(p);
    }
    
    ofSetWindowTitle( ofToString( ofGetFrameRate() ) ) ; 
}

//--------------------------------------------------------------
void testApp::draw(){
     myFBO.begin();
    ofSetColor(0, 0, 0);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
   
    for (int i = 0; i < layerArray.size(); i ++){
       
        layerArray[i].drawLayer();
        
    }
    myFBO.end();
    
    myFBO.draw(0,0);
    
    

}

void testApp::undoLastMove()
{
    layerArray.pop_back();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
            
        case 'u':
            undoLastMove();
            break;
            
        case 'f':
            ofToggleFullscreen();
            
            break;   
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    drawing = true;
    drawingLayer dl;
    dl.lineColor = lineColor;
    layerArray.push_back(dl);

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    drawing = false;
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::exit()
{
	gui->saveSettings("GUI/guiSettings.xml");     
    delete gui;
}