#pragma once

#define NUM_BALLS 2.0f
#define MIN_SIZE 8.0f
#define MAX_SIZE 20.0f
#define NUM_BANDS 3

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
    
    MetaBall(int x, int y, float r) {
        dir.set(ofRandom(-1, 1), ofRandom(-1, 1));
        dir.normalize();
        pos.set(x, y);
        radius = r;
    }
    
    MetaBall(int x, int y, float dirX, float dirY, float r) {
        dir.set(dirX, dirY);
        dir.normalize();
        pos.set(x, y);
        radius = r;
    }
    
    MetaBall(int x, int y, float dirX, float dirY, float r, bool enableNormalize) {
        dir.set(dirX, dirY);
        if (enableNormalize){
            dir.normalize();
        }
        pos.set(x, y);
        radius = r;
    }
    
    void update() {
        pos.x += dir.x;
        pos.y += dir.y;
        
        if (pos.x > ofGetWidth() | pos.x < 0) {
            dir.x *= -1;
        }
        if (pos.y > ofGetHeight() | pos.y < 0) {
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
    
    bool enableAnimation;
};
