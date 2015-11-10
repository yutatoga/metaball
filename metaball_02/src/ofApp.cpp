#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    overlayImage.loadImage("kenpoku.png");
    ofSetWindowShape(320, 341);
    BAND = 255.0/NUM_BANDS;
    
    balls.push_back(new MetaBall(100, 240, -0.1, -0.6, ofRandom(MIN_SIZE, MIN_SIZE*1.5f), false));
    balls.push_back(new MetaBall(100, 240,  0.2, -0.3, ofRandom(MIN_SIZE, MIN_SIZE*1.5f), false)); // long center place
    balls.push_back(new MetaBall(100, 240, 0.4, -0.5, ofRandom(MIN_SIZE, MIN_SIZE*1.5f), false));
    balls.push_back(new MetaBall(100, 240, 0.7, -0.7, ofRandom(MIN_SIZE, MIN_SIZE*1.5f), false));
    balls.push_back(new MetaBall(100, 240, 0.55, -0.2, ofRandom(MIN_SIZE, MIN_SIZE*1.5f), false));
    balls.push_back(new MetaBall(100, 240, 0.01, -0.002, ofRandom(MIN_SIZE, MIN_SIZE*1.5f), false));
    
    img.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_GRAYSCALE);
    
    enableAnimation = false;
}

float ofApp::colorLookup(float i) {
    return floor((i/255.0) * NUM_BANDS) * BAND;
}

//--------------------------------------------------------------
void ofApp::update(){
    if (enableAnimation) {
        for (int i = 0; i < NUM_BALLS; i++) {
            balls[i]->update();
        }
    }
    // non-nested loop gives us about +5 ms per frame
    for (int i = 0; i < ofGetHeight() * ofGetWidth(); i++) {
        float col = 0.0f;
        
        for (int m = 0; m < NUM_BALLS; m++) {
            int y = floor(i / ofGetWidth()); // faster than using int
            int x = i % (int)ofGetWidth();
            
            float xx = (balls[m]->pos.x) - x;
            float yy = (balls[m]->pos.y) - y;
            
            col += balls[m]->radius / sqrt( xx * xx + yy * yy);
        }
        img.getPixels()[i] = colorLookup(255 * col);
    }
    img.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    img.draw(0, 0, ofGetWidth(), ofGetHeight());
    overlayImage.draw(0, 0, overlayImage.width, overlayImage.height);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    enableAnimation = !enableAnimation;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
