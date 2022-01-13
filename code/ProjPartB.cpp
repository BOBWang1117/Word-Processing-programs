/********************************************************************************
* @File name: ProjPartB.cpp
* @Author: WANG HONGBO
* @Date: 2020-5-12
* @Description: Create a dictionary, and when the user enters the query word, divide it by the number of uses
********************************************************************************/


#include <string>
#include"IoTxt.h"
#include"deal_with.h"
#include <algorithm>
#include<windows.h>
using namespace std;

int N;//Number of outputs requested by the user

bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.second < b.second;
}

/*
*     Effect: Construct a dictionary
*Description: Enter and process the file into a dictionary
*            
*/
void fill_completions(map<string, int> &m, const char* fd)
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
    //Processing files

    DealWith.deal();
    //Break sentences into words and deal the illege word

    vector<string>test2;
    test2 = DealWith.getStringArrayCopy();

    sort(test2.begin(), test2.end());
    //Sort array

    DealWith.setStringArrayCopy(test2);
    //Pass back the array of aligned amounts

    m = DealWith.combine_PartB();
    //Call the DealWith.combine_PartB () function to get the map

}




/*
*     Effect: inquire
*Description: Query whether c_dict contains the prefix field, 
*             if it exists, store it in the array in the order 
*             from most to least
*/
vector<string> find_completions(string prefix,map<string, int> c_dict)
{

    map<string, int> m;
    //Determine whether there is a prefix in c_dict, store the key and value in m

    map<string, int>::iterator it;
    for (it,it = c_dict.begin(); it != c_dict.end(); ++it)
    {
        string str=it->first;
        if (str[0] > prefix[0])
        //If the first letter of the search is greater than the first 
        //letter of the prefix, it means that there must be no more behind, 
        //then stop the query
        {
            break;
        }
        if (str.find(prefix) == 0)
        //If the query word coincides with the 0th position 
        //of str, it means that we want the key
        {
            m.insert(pair<string, int>(it->first, it->second));
            //Store the key and value at this position in the map in a map named m
        }
    }

    //Store the key and value in the map into the vector, and then sort by value
    vector< pair<string, int> > vec; 
    for (map<string, int>::iterator it2 = m.begin(); it2 != m.end(); it2++) 
    { 
        vec.push_back(pair<string, int>(it2->first, it2->second)); 
    }
    sort(vec.begin(), vec.end(), cmp);



    //At this time, the value in m2 is arranged in the order from least to many
    //Put these values into an array of type vector <string> called vec_str
    vector<string>vec_str;
    vector<pair<string, int>>::iterator it3;
    for (it3, it3 = vec.begin(); it3 != vec.end(); ++it3)
    {
        vec_str.push_back(it3->first);
    }
    
    //Reverse the order in the vec_str array and store it in 
    //an array of type vector <string> named vec_str2

    //At this time, the words in vec_str2 that meet the user's 
    //query requirements, and these words are arranged in order from most to less
    vector<string>vec_str2;
    for (int i = 0; i < vec_str.size(); i++)
    {
        vec_str2.push_back( vec_str[vec_str.size()-1 - i]);
    }
    
    //Get the number of words output by the user N
    //If N> = number in vec_str2 array, input all elements in vec_str2 to vec_str3
    //If N <the number of vec_str2 arrays, then input the elements of N vec_str2 to vec_str3
    vector<string>vec_str3;
    if (vec_str2.size() >= N)
    {
        for (int i = 0; i < N; i++)
        {
            vec_str3.push_back(vec_str2[i]);
        }
    }
    else
    {
        for (int i = 0; i < vec_str2.size(); i++)
        {
            vec_str3.push_back(vec_str2[i]);
        }
    }

    return vec_str3;//Return the final array
}
/*
*     Effect: Run the program
*Description: Call the find_completions function method repeatedly, 
*             knowing that the user enters "#", exit
*/
int main()
{
    cout << "Waiting..." << endl;
    //When you see this, the program starts to respond
    cout << "Please input you path : " << endl;
    string path;//C:\\Users\\User\\Desktop\\ap_docx.txt
    cin >> path;
    map<string, int>c_dictionary;
    const char* fild = path.c_str();
    //Dictionary to be processed in the user's computer

    fill_completions(c_dictionary, fild);
    //Call fill_completions to fill in the dictionary
    cout << "How many words do you want?" << endl;
    //Ask the user how many words they want to output

    cin >> N;
    //Get the number

    while (true)
    //Start looping until the user wishes to exit the program
    {

        cout << "If you conplete , input '#' to quit " << endl;
        //How to exit the program

        string str;
        cout << "Please input what you want find : " << endl;
        //Ask the user for the word they want to find

        cin >> str;
        //Get input
        
        //Prevent clutter

        if (str == "#")
        //exit the program
        {
			 system("cls");
			 cout << "Exit!" << endl;
            break;
        }
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        system("cls");
        vector<string>v;
        v = find_completions(str, c_dictionary);
        //Call the find_completions function to complete the search

        cout << endl;
        cout <<"There has "<<v.size()<< " output : " << endl;
        //The output finds how many suitable content

        for (int i = 0; i < v.size(); i++)
        //Output content
        {
            cout << v[i] << endl;
        }
    }

    return 0;
}