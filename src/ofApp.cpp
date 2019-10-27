#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  font.load("ArchivoBlack.ttf", 300, true, true, true);

  // ofBuffer buffer = ofBufferFromFile(
  // "/home/max/of/apps/myApps/muriel/bin/data/Bitter.ttf"); // reading into
  ofSetBackgroundAuto(false);
  ofEnableAlphaBlending();
  ofBackground(255, 255, 255);
  // for (auto line : buffer.getLines()) {
  //   // cout << line.asString() << endl;
  //   linesOfTheFile.push_back(line);
  // }
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {

  ofBackground(255);
  // ofEnableBlendMode(OF_BLENDMODE_SCREEN);
  // ofSetColor(255, 255, 255, 255);
  // ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

  // ofEnableDepthTest();

  std::string a = "ssffppcc";
  // std::string a = "tittties";

  // vector<ofPath> paths = font.getStringAsPoints("Abc", true, false);
  ofSetColor(255, 0, 0);
  ofSeedRandom(mouseX);
  ofTranslate(ofGetWidth() / 2 - 600, ofGetHeight() / 2 + 100);

  for (int f = 1; f <= 8; f++) {
    ofTranslate(90, 0);

    std::string str2 = a.substr(f - 1, 1);
    vector<ofPath> paths = font.getStringAsPoints(str2, true, false);
    for (int i = 0; i < paths.size(); i++) {

      vector<ofPolyline> lines = paths[i].getOutline();

      for (int j = 0; j < lines.size(); j++) {

        ofPolyline temp = lines[j].getResampledBySpacing(5);

        for (int layer = 1; layer < 25; layer++) {
          temp = temp.getResampledBySpacing(9);
          for (int k = 0; k < temp.size(); k++) {
            ofPoint m =
                ofPoint(mouseX - ((90 * f - 1) + (ofGetWidth() / 2 - 600)),
                        mouseY - (ofGetHeight() / 2 + 100));
            // ofDrawCircle(m, 10.0);
            float r = 2.0;
            // ((36 - layer) * 0.1) + 0.5;
            r *= 1.5 * MIN(0.01 + (m.distance(temp[k]) / 400.0), 5.0);

            //  MAX(float(mouseX) / float(ofGetWindowWidth()), 0.1);
            // r *= (f / 8.0) + 0.2;
            float p = 10.0 / layer;
            // ofPoint b = temp[(k + temp.size() - 1) % temp.size()];
            ofPoint b = temp[temp.getWrappedIndex(k - 1)];
            ofPoint a = temp[temp.getWrappedIndex(k + 1)];
            // ofPoint a = temp[(k + 1) % temp.size()];

            ofVec2f normal = b - a;
            normal = normal.getPerpendicular();
            normal = normal.normalize();

            r *= ofMap(ofNoise(temp[k].x / p, temp[k].y / p,
                               (f * 9.123) + (layer * 213.4123)),
                       0, 1, 0.2, 0.8);
            // r *= 0.2;
            temp[k].x += normal.x * r;
            temp[k].y += normal.y * r;

            temp[k].x += ofSignedNoise(temp[k].x / p, temp[k].y / p,
                                       (f * 9.123) + (layer * 213.4123)) *
                         r;
            temp[k].y += ofSignedNoise(temp[k].x / p + 50.123, temp[k].y / p,
                                       (f * 9.123) + (layer * 213.4123)) *
                         r;
          }
          temp.simplify();
          // temp = temp.getSmoothed(1);
          ofFill();

          int a = 5;
          //  / layer;
          int off = 40;
          switch (int(f) % 4) {
          case 0:
            ofSetColor(255, off, off, a); // red
            break;
          case 1:
            ofSetColor(255, 255, off, a); //
            break;
          case 2:
            ofSetColor(off, off, 255, a);
            break;
          default:
            ofSetColor(255, off, 255, a);
          }
          ofSetPolyMode(OF_POLY_WINDING_NONZERO);

          ofBeginShape();
          for (int v = 0; v < temp.getVertices().size(); v++) {
            ofVertex(temp.getVertices().at(v).x, temp.getVertices().at(v).y);
          }
          ofEndShape();
        }
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