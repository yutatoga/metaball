#pragma once

#define NUM_BALLS 6.0f
#define MIN_SIZE 8.0f
#define MAX_SIZE 20.0f
#define NUM_BANDS 10

#include "ofMain.h"

class MetaBall {
public:
    ofVec2f pos;
    float radius;
    ofVec2f dir;
    
    MetaBall(float r) {
        dir.set(ofRandom(-1, 1), ofRandom(-1, 1));
        dir.normalize();
        pos.set(0, 0);
        radius = r;
    }
    
    void update() {
        pos.x += dir.x;
        pos.y += dir.y;
        
        if (abs(pos.x) > ofGetWidth()/2) {
            dir.x *= -1;
        }
        if (abs(pos.y) > ofGetHeight()/2) {
            dir.y *= -1;
        }
    }
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    float colorLookup(float i);
		
    vector<MetaBall*> balls;
    ofImage img;
    float BAND;
};
