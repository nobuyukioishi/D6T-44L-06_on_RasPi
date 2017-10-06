#include <cstdio>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sys/time.h>
#include "i2c_d6t.h"
#include <fluent.hpp>

int main()
{
	D6T* sensorPtr = 0;
	int address = 0x0a;
	std::string i2c_bus = "/dev/i2c-1";
	uint8_t iType = 1; // D6T-44L-01
	
	sensorPtr = new D6T(i2c_bus, address, iType);
	fluent::Logger *logger = new fluent::Logger();
	logger->new_forward("localhost", 24224);
	
	int16_t *measurements = 0;
	while(1) {
 		// create fluentd logger instance
	    // logger->new_forward("192.168.11.181", 24224);
		fluent::Message *msg = logger->retain_message("d6t44l06");
		fluent::Message::Array *data = msg->retain_array("surface_temp");
			
		// get the sensor's data	
		measurements = sensorPtr->measure();
		float temp_cel[16];
		for(int i = 0; i<15; i++) {
			temp_cel[i] = (float) measurements[i+1]*0.1f;
			// printf("%.1f,", temp_cel[i]);
			data->push(temp_cel[i]);
		}	
		temp_cel[15] = (float) measurements[16]*0.1f;
		data->push(temp_cel[15]);
		// printf("%.1f\n", temp_cel[15]);
		logger->emit(msg);
	    sleep(1);
	}
    delete logger;
	return 0;
}

