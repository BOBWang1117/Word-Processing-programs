
/********************************************************************************
* @File name: IoTxt.cpp
* @Author: WANG HONGBO
* @Date: 2020-5-1
* @Description: Implementation method of IoTxt.h
********************************************************************************/
#include"IoTxt.h"
#include <fstream>
#include <cassert>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
/*
*     Effect: pass path parameters
*Description: Obtain the absolute path str of the user's txt file, 
*             and transfer str to the private type strPass
*/
IoTxt::IoTxt(const char* str)
{
	strPass = str;
}
/*
*     Effect: count (number of lines in txt file)
*Description: Open the txt file, when you read it
*             and you encounter a newline character, change the line value, 
*             and finally get the total number of lines in the txt file
*/
int IoTxt::txtLine()
{
    FILE* fd;
    if (fd = fopen(strPass, "r"))
    {
        while (!feof(fd))
        {
            if ('\n' == fgetc(fd))
            {
                line++;
            }
        }
    }
    if (fd)
    {
        fclose(fd);
    }

    return line;
}
/*
*     Effect: output file
*Description: Output the file processed by the program 
*             to the computer and store it
*/
void IoTxt::ioIn()
{


}
/*
*     Effect: input file
*Description: The function of inputting the file from 
*             the computer into the program
*/
void IoTxt::ioOut()
{
    ifstream infile;
    string file = strPass;
    infile.open(file.data());   //Connect file stream objects to files
    assert(infile.is_open());   //If it fails, output an error message and terminate the program

    string s;
    while (getline(infile, s))
    {
        ioOutFile.push_back(s);//Enter each line of information s and number 
                               //in the file into an array of type vector <string>
    }

    infile.close();    // Close file input stream
}
/*
*     Effect: pass the array
*Description: Provides the transfer of cross-cpp files
*/
vector<string> IoTxt::stringArrarCopy()
{
    return ioOutFile;
}