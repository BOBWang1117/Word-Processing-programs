
/********************************************************************************
* @File name: IoTxt.h
* @Author: WANG HONGBO
* @Date: 2020-5-1
* @Description: The function interface 
********************************************************************************/
#include <string>
#include<vector>
#ifndef IOTXT_H
#define IOTXT_H

using namespace std;

class IoTxt
{
public:
	IoTxt(const char* str);
	//Provide an interface to input the absolute path 
	//of txt to the interface in the program

	int txtLine();
	//Get the total number of lines in a txt file, which is 
	//convenient for creating a vector array interface

	void ioIn();
	//Interface for outputting files processed by the program

	void ioOut();
	//Input the txt file to the interface in the program

	vector<string> stringArrarCopy();
	//Interface to output private ioOutFile

private:
	const char* strPass;
	//Absolute path of txt file

	int line = 1;
	//The first line of the txt file
	vector<string>ioOutFile;
};


#endif