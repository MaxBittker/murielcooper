#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  font.load("ArchivoBlack.ttf", 300, true, true, true);

  ofBuffer buffer = ofBufferFromFile(
      "/home/max/of/apps/myApps/muriel/bin/data/Bitter.ttf"); // reading into
                                                              // the buffer
  ofSetBackgroundAuto(false);
  ofEnableAlphaBlending();
  ofBackground(255, 255, 255);
  ofBackground(255, 255, 255);
  for (auto line : buffer.getLines()) {
    // cout << line.asString() << endl;
    linesOfTheFile.push_back(line);
  }
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {

  ofBackground(255);

  // ofSetColor(255, 255, 255, 255);
  // ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

  // ofEnableDepthTest();

  std::string a = "5";

  // vector<ofPath> paths = font.getStringAsPoints("Abc", true, false);
  ofSetColor(255, 0, 0);
  ofTranslate(ofGetWidth() / 2 - 100, ofGetHeight() / 2 + 100);

  vector<ofPath> paths = font.getStringAsPoints(a, true, false);

  for (int i = 0; i < paths.size(); i++) {

    vector<ofPolyline> lines = paths[i].getOutline();

    for (int j = 0; j < lines.size(); j++) {

      ofPolyline temp = lines[j].getResampledBySpacing(3);

      for (int layer = 1; layer < 30; layer++) {
        temp = temp.getResampledBySpacing(3);
        for (int k = 0; k < temp.size(); k++) {
          float r = (mouseX / 10.0 / layer) + 2.0;
          float p = mouseY / layer;
          // temp[k].y +=
          //     (1.0 + sin(ofGetElapsedTimef())) * (ofGetHeight() - 150.0) *
          //     0.5;

          temp[k].x += ofSignedNoise(temp[k].x / p, temp[k].y / p,
                                     ofGetElapsedTimef() / p) *
                       r;
          temp[k].y += ofSignedNoise(temp[k].x / p + 50.123, temp[k].y / p,
                                     ofGetElapsedTimef() / p) *
                       r;
        }

        ofFill();
        ofSetColor(255, 0, 0, 5);

        ofBeginShape();
        for (int v = 0; v < temp.getVertices().size(); v++) {
          ofVertex(temp.getVertices().at(v).x, temp.getVertices().at(v).y);
        }
        ofEndShape();
      }
    }
  }

  return;
  // for (int l = 0; l < linesOfTheFile.size(); l++) {
  //   string line = linesOfTheFile[l];
  //   // cout << line << endl;

  //   vector<ofPath> paths = font.getStringAsPoints(line, true, true);
  //   // for (int y = 0; y < ofGetHeight() - 100; y += 5) {
  //   // ofSetColor(255, 255, 255, y / 5);
  //   for (int i = 0; i < paths.size(); i++) {

  //     vector<ofPolyline> lines = paths[i].getOutline();

  //     for (int j = 0; j < lines.size(); j++) {

  //       ofPolyline temp = lines[j].getResampledBySpacing(4);
  //       for (int k = 0; k < temp.size(); k++) {
  //         // temp[k].x += 50 * sin(temp[k].y * 0.04 + ofGetElapsedTimef());
  //         // temp[k].y += l * 8.0;
  //       }

  //       // temp = temp.getSmoothed(MAX(mouseX, 1));
  //       temp.draw();

  //       //            for (int k = 0; k < temp.getVertices().size(); k++){
  //       //                ofDrawCircle(temp.getVertices()[k], 2);
  //       //            }

  //       //            ofPolyline temp = lines[j].getSmoothed(MAX(1,
  //       mouseX));
  //       //            temp.draw();
  //     }
  //   }
  // }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  // ofGetKeyPressed
  // string n;
  // text.
  // sprintf(text.c_str(), "%d", key);
  // text.append(string(key));
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}