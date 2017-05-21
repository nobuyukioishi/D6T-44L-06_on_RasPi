/*
main部分
openFrameWorkでアプリを起動するところ
(つまり，センサとのやり取りにはあまり関係ない．)
*/

#include "ofMain.h"
#include "ofApp.h"


int main()
{
	ofSetupOpenGL(500, 500, OF_WINDOW);
	ofRunApp( new ofApp() );
}
