/********************************************************************************
* @File name: deal_with.h
* @Author: WANG HONGBO
* @Date: 2020-5-2
* @Description: The function interface
********************************************************************************/

#ifndef DEAL_WITH
#define DEAL_WITH
#include<string>
#include<iostream>
#include<vector>
#include <algorithm>
#include <map>

using namespace std;

class DealWith
{
public:
	DealWith(vector<string>vec);
	//Pass the vector <string> type array to the interface of deal_with

	void deal();
	//Interface to handle incoming arrays

	vector<string> getStringArrayCopy();
	//Interface to transfer the processed array

	void setStringArrayCopy(vector<string> vec);
	//Interface to pass the array

	vector<string> combine_PartA();
	//Provides an interface for PartA processing methods

	map<string, int> combine_PartB();
	//Provide the interface of PartB processing method

	void test();
	//Print the interface of ap_docx test function (PartA and PartB does not exist)
private:
	vector<string>ap_docx;
};

#endif
