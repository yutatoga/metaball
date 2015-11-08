#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(320, 220);
    BAND = 255.0/NUM_BANDS;
    for (int i = 0; i < NUM_BALLS; i++) {
        balls.push_back(new MetaBall(ofRandom(MIN_SIZE, MIN_SIZE*1.5f)));
    }
    
    img.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_GRAYSCALE);
}

float ofApp::colorLookup(float i) {
    return floor((i/255.0) * NUM_BANDS) * BAND;
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < NUM_BALLS; i++) {
        balls[i]->update();
    }
    
    // non-nested loop gives us about +5 ms per frame
    for (int i = 0; i < ofGetHeight() * ofGetWidth(); i++) {
        float col = 0.0f;
        
        for (int m = 0; m < NUM_BALLS; m++) {
            int y = floor(i / ofGetWidth()); // faster than using int
            int x = i % (int)ofGetWidth();
            
            float xx = (balls[m]->pos.x + ofGetWidth()/2.0) - x;
            float yy = (balls[m]->pos.y + ofGetHeight()/2.0) - y;
            
            col += balls[m]->radius / sqrt( xx * xx + yy * yy);
        }
        img.getPixels()[i] = colorLookup(255 * col);
    }
    img.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    img.draw(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
