/*
main部分
openFrameWorkでアプリを起動するところ
(つまり，センサとのやり取りにはあまり関係ない．)
*/

#include <cstdio>
#include<iostream>
#include<fstream>

#include "i2c_d6t.h"

int main()
{
	D6T* sensorPtr = 0;
	int address = 0x0a;
	std::string i2c_bus = "/dev/i2c-1";
	uint8_t iType = 1; // D6T-44L-01
	
	sensorPtr = new D6T(i2c_bus, address, iType);
	
	std:ofstream ofs("Test.csv"); //ファイル出力ストリーム

	int16_t *measurements = 0;
	while(1) {
		measurements = sensorPtr->measure();
		
		float temp_cel[16];
		for(int i = 0; i<15; i++) {
			temp_cel[i] = (float) measurements[i+1]*0.1f;
			printf("%.1f,", temp_cel[i]);
			std:ofs<<temp_cel[i]<<std:endl;
		}	
		temp_cel[15] = (float) measurements[16]*0.1f;
		printf("%.1f\n", temp_cel[15]);
		ofs<<temp_celp[15]<<endl;	
		sleep(1);
	}
	return 0;
}

