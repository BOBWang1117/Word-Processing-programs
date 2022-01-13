/********************************************************************************
* @File name: deal_with.cpp
* @Author: WANG HONGBO
* @Date: 2020-5-2
* @Description: The function interface
********************************************************************************/

#include"deal_with.h"

using namespace std;

void SplitString(const string& s, vector<string>& v, const string& c);
//Method function for splitting s character string with ","

DealWith::DealWith(vector<string>vec)
{
	ap_docx = vec;
}
/*
*     Effect: judge byte
*Description: A function that passes bytes into a 
*             function and determines whether it is a number
*/
bool num(char ch)
{
    bool a = false;
    if (ch == '0') { a = true; }
    if (ch == '1') { a = true; }
    if (ch == '2') { a = true; }
    if (ch == '3') { a = true; }
    if (ch == '4') { a = true; }
    if (ch == '5') { a = true; }
    if (ch == '6') { a = true; }
    if (ch == '7') { a = true; }
    if (ch == '8') { a = true; }
    if (ch == '9') { a = true; }
    if (ch == '$') { a = true; }
    return a;

}
/*
*Effect: Remove impurities
*Description: Remove the punctuation, and finally get a vector <string> type word array function
*/
void DealWith::deal()
{
    vector<string> v;
    //Put each line in the text
    for (int i = 0; i < ap_docx.size(); i++)
    {
       string str = ap_docx[i];
       //str is a line of data in the txt file

       transform(str.begin(),str.end(),str.begin(),::tolower);
       //Convert all words to lower case

       SplitString(str, v, " ");
       //Split str with "" (space) and store it in vector <string> named v

    }
    vector<string> v2;
    for (int i = 0; i < v.size(); i++)
    {
        string str2 = v[i];
        //str is a row of data in the vector <string> type named v

        SplitString(str2, v2, "-");
        //Split str2 with "-" and store it in vector <string> named v2
    }
    for (int i = 0; i < v2.size(); i++)
    {
        const char* a = v2[i].c_str();
        //Convert the string in v2 to the form of char [] d named a

        int length = v2[i].length();
        //Get the size of the char [] array

        if (a[length - 1] == '\'')
        //If the word ends with '\', remove the '\' from the word
        {
            v2[i].erase(length - 1, 1);
        }

        if (a[0] == '`')
        //If the word starts with '`', then remove the` `in the word
        {
            v2[i].erase(0, 2);

        }
        int length2 = v2[i].length();
        //Recalculate the size of the char []
        
        for (int j = 0; j < length2; j++)
        {
            if (a[j] == ','|| a[j] == '.'|| a[j]=='<' || a[j]=='>'|| a[j]=='_'|| a[j]=='('|| a[j]==')'|| a[j] == ':'||a[j]=='/'|| a[j] == '?'||a[j]==';'||a[j]=='!'||a[j]=='^')
            //Method of removing symbols from words
            {
                v2[i].erase(j,1);
            }
            if (a[j] == '\'' && a[j + 1] != 's')
            //Remove words containing "'" but keep words containing "' s"
            {
                v2[i].erase(j, 1);
            }
            if (a[j] == '.')
            //If there is a '.' In the word, remove the symbol
            {
                v2[i].erase(j, 1);
            }
            if (a[j] == '`')
            //If there is a `` in the word, remove the symbol
            {
                v2[i].erase(j, 1);
            }
            if (a[j] == ',')
            //If there is a ',' in the word, remove the symbol
            {
                v2[i].erase(j, 1);
            }
            if (a[j] == '`')
            //If there is a `` in the word, remove the symbol
            {
                v2[i].erase(j, 1);
            }
        }
    }
    //If v2 contains a letter or a number, rewrite the content of the position to ""
    for (int i = 0; i < v2.size(); i++)
    {
        const char* a = v2[i].c_str();
        int length = v2[i].length();
        if (length == 1|| num(a[0])|| num(a[1]))
        //Call num () to determine whether it is a number
        {
            v2[i] = "";
        }
       
    }
    //If the words in the array v2 are stored in v3
    //If the "" "in the array v2 is not stored in v3
    vector<string>v3;
    for (int i = 0; i < v2.size(); i++)
    {
        if (v2[i] != "")
        {
            v3.push_back(v2[i]);
        }
    }
    ap_docx = v3;
    //Pass v3 to ap_docx

}

/*
*     Effect: Pass
*Description: Pass ap_docx out of the method to facilitate 
              the use of functions in other classes
*/
vector<string> DealWith::getStringArrayCopy()
{
    return ap_docx;
}
/*
*Effect: Receive
*Description: Pass the external array into this class
*/
void DealWith::setStringArrayCopy(vector<string> vec)
{
    ap_docx = vec;
}
/*
*Effect: Test
*Description: Print the elements in the array ap_docx
*/
void DealWith::test()
{
    for (int i = 0; i < ap_docx.size(); i++)
    {
        cout << ap_docx[i] << endl;
    }
}
/*
*     Effect: merge
*Description: This method is PartA's unique method, a function 
*             method that efficiently combines the same elements 
*             (the elements in ap_docx must be arranged before calling 
*             this function)
*/
vector<string> DealWith::combine_PartA()
{
    int j = 0;
    vector<string> v;
    v.push_back(ap_docx[0]);
    for (int i = 0; i < ap_docx.size(); i++)
    {
        if (v[v.size() - 1] != ap_docx[i])
            //Since it is already in an ordered state, 
            //when the last element in v is not equal to 
            //ap_docx [i], it can be stored in v

        {
            v.push_back(ap_docx[i]);
        }
    }

    return v;
}
/*
*     Effect: merge
*Description: This method is a unique method of PartB, 
*             a function method that efficiently combines the same 
*             elements and can count the number of occurrences of the same elements
*/
map<string, int> DealWith::combine_PartB()
{
    int j = 1;
    map<string, int>m;
    m.insert(pair<string, int>(ap_docx[0], 1));
    for (int i = 1; i < ap_docx.size(); i++)
    {
       
        if (m.count(ap_docx[i]))
        //If there is ap_docx [i] in the map, increase the 
        //value of key = ap_docx [i] by one
        {
            j++;
            m[ap_docx[i]] = j;
        }
        else
        //If there is no ap_docx [i] in m, add ap_docx [i] to the map
        {
            j = 1;
            m.insert(pair<string, int>(ap_docx[i], j));
        }
    }
    //Method of printing map
    /*for (auto i = m.begin(); i != m.end(); ++i)
        cout << i->first << ":" << i->second << endl;*/

    return m;
}

//The network code provides a method for splitting strings
//www.cnblogs.com/yuehouse/p/10230589.html
void SplitString(const string& s, vector<string>& v, const string& c)
{
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2 - pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length())
        v.push_back(s.substr(pos1));
}
