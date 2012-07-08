//
//  drawingLayer.cpp
//  Flurrious
//
//  Created by Itai Asseo on 7/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "drawingLayer.h"
#include "testApp.h"

drawingLayer::drawingLayer()
{
    
}

void drawingLayer::update(ofPoint p){
    
    if (vertexArray.size()>0){
        if (p != vertexArray[vertexArray.size()-1]){
            vertexArray.push_back(p);
        }
    }else{
        vertexArray.push_back(p);
    }
}
    
void drawingLayer::drawLayer()
{
    ofSetColor(lineColor);
    ofNoFill();
    ofEnableSmoothing();
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    if (vertexArray.size() > 0){
        
        for (int j = 0; j < SLICES; j++){
            ofPushMatrix();
            ofBeginShape();
            float r = ofDegToRad(360/SLICES);
            ofRotate(360/SLICES*j);
            for (int i = 0; i < vertexArray.size(); i++){
                ofCurveVertex(vertexArray[i]);
            }
            ofEndShape();
            ofPopMatrix();   
        }
        
        ofPushMatrix();
        ofScale(-1,1);
        
        for (int j = 0; j < SLICES; j++){
            ofPushMatrix();
            ofBeginShape();
            float r = ofDegToRad(360/SLICES);
            ofRotate(360/SLICES*j);
            for (int i = 0; i < vertexArray.size(); i++){
                ofCurveVertex(vertexArray[i]);
            }
            ofEndShape();
            ofPopMatrix();
        }
        ofPopMatrix();
    }
    
    ofPopMatrix();
    ofDisableSmoothing();
}
