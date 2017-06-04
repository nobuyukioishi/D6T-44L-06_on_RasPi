#include <cstdio>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sys/time.h>
#include "i2c_d6t.h"


int main()
{
	D6T* sensorPtr = 0;
	int address = 0x0a;
	std::string i2c_bus = "/dev/i2c-1";
	uint8_t iType = 1; // D6T-44L-01
	
	sensorPtr = new D6T(i2c_bus, address, iType);
	
	struct timeval now;
	gettimeofday(&now, NULL);
	struct tm *pnow = localtime(&now.tv_sec);
	// print current time including millisecond
	/* std::cout << pnow->tm_year+1900 << "/" << pnow->tm_mon + 1 << "/" << pnow->tm_mday
		<< " " << pnow->tm_hour << ":" <<pnow->tm_min << ":" << pnow->tm_sec << "." << now.tv_usec; */
	std::ofstream ofs("Test.csv");
	
	int16_t *measurements = 0;
	while(1) {
		measurements = sensorPtr->measure();
		gettimeofday(&now, NULL);
		pnow = localtime(&now.tv_sec);
		ofs << pnow->tm_year+1900 << "/" << pnow->tm_mon + 1 << "/" << pnow->tm_mday
		<< " " << pnow->tm_hour << ":" <<pnow->tm_min << ":" << pnow->tm_sec << "." << now.tv_usec << "," <<std::flush;
		float temp_cel[16];
		for(int i = 0; i<15; i++) {
			temp_cel[i] = (float) measurements[i+1]*0.1f;
			printf("%.1f,", temp_cel[i]);
			ofs<< std::fixed << std::setprecision(1) << temp_cel[i]<< "," <<std::flush;
		}	
		temp_cel[15] = (float) measurements[16]*0.1f;
		printf("%.1f\n", temp_cel[15]);
		ofs<< std::fixed << std::setprecision(1) << temp_cel[15]<<std::endl;	
		sleep(1);
	}
	return 0;
}

