#include <string>
#include"IoTxt.h"
#include"deal_with.h"
#include <algorithm>
#include<windows.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

/*
*     Effect: Construct a dictionary
*Description: Enter and process the file into a dictionary
*            
*/
void fill_completions(vector<string>&c_dict,const char* fd)
{
    IoTxt IoTxt(fd);
    //Pass the path fd into IoTxt

    IoTxt.txtLine();
    //Count the number of lines in this txt file

    IoTxt.ioOut();
    //Store each line of the txt file in an array of vector <string>

    vector<string>test;
    test = IoTxt.stringArrarCopy();
    //Output this file

    DealWith DealWith(test);
    DealWith.deal();
    //Break sentences into words and deal the illege word

    vector<string>test2;
    test2 = DealWith.getStringArrayCopy();
    sort(test2.begin(), test2.end());
    //Sort array

    DealWith.setStringArrayCopy(test2);
    //Pass back the array of aligned amounts

    c_dict = DealWith.combine_PartA();
    //Output the processed array to c_dict
}
/*
*     Effect: inquire
*Description: Find the prefix in c_dict, and finally return an array of type vector <string> named vec_str
*
*/
vector<string> find_completions(string prefix,const vector<string> c_dict)
{
    vector<string>vec_str;

    for (int i = 0; i < c_dict.size(); i++)
    {

        if (c_dict[i][0] > prefix[0])
        {
            break;
        }
        if (c_dict[i].find(prefix) == 0)
        {
            vec_str.push_back(c_dict[i]);
            //If the prefix string is found in the dictionary, 
            //and the position is in the 0th position, then 
            //c_dict [i] is output to vec_str
        }

    }

    return vec_str;
    //Return array
}
/*
*     Effect: Run the program
*Description: Call the find_completions function method repeatedly, 
*           knowing that the user enters "#", exit
*
*/
/*
int main()
{

    cout << "Waiting..." << endl;
    //Wait for the program to respond
    cout << "Please input you path : " << endl;
    string path;//C:\\Users\\User\\Desktop\\ap_docx.txt
    cin >> path;
    vector<string>c_dictionary;
    const char* fild = path.c_str();
    //User needs to process files

    fill_completions(c_dictionary, fild);
    //Call the fill_completions method
    while (true)
    //Loop until exiting the program
    {
        cout << "If you conplete , input '#' to quit " << endl;
        //The user is repeatedly prompted to enter "#" if he wants to quit

        vector<string>vec;
        string str;
        cout << "Please input what you want find : " << endl;
        //The user enters the byte fragment that he wants to query

        cin >> str;

        if (str == "#")
        //exit the program
        {
            system("cls");
            cout << "Exit!" << endl;
            //Show it means successfully exit

            break;
        }
        system("cls");//Prevent screen clutter
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        //Convert user input to lowercase

        vec = find_completions(str, c_dictionary);
        //Call find_completions to find str and return vec array

        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << endl;
            //Print elements that meet the requirements
        }
        cout << endl;
        cout << "There has " << vec.size() << " output : " << endl;
        //Show how many elements were printed


    }

    return 0;
}
*/