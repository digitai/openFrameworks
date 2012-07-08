//
//  drawingLayer.h
//  Flurrious
//
//  Created by Itai Asseo on 7/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Flurrious_drawingLayer_h
#define Flurrious_drawingLayer_h

#include "ofMain.h"

class drawingLayer
{
    public:
        
    drawingLayer();
    void update(ofPoint p);
    void drawLayer();
    vector <ofPoint> vertexArray; 
    ofColor lineColor;
    
    
    private:
};

#endif
