/*
 * a2.cpp
 *
 *  Created on: May 11, 2021
 *      Author: student
 */
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <cctype>
#include <cmath>
#include <string>
#include <string.h>
#include <fstream>
#include<bits/stdc++.h>
#include "inord_list.h"
using namespace std;

int main(int argc, char *argv[])
{
	//check that the number of arguments are 3 or not
	if(argc!=3)
	{	cout<<"Incorrect number of arguments";
	     return 0;
	}

	FILE *pFile;// pointer to file characters
	string InpFileName = argv[1];
	string CommandFileName = argv[2];
	pFile = fopen(argv[1], "r" ); //open the input file
	if(pFile==NULL){cout<<"File not found"; return 0;}
	List_of_Words MyList;
	int c;
	bool is_Sep = false;
	int char_count = 0;
	int Line_num = 1;
	string AddedWord = "";

	int sep[16]= { 32,44 , 59 , 58, 39, 38, 34, 46 , 91 , 93 ,123, 125, 40, 41,33,63};

	do // as long as the pointer didn't reach the end of the file it will perform the following
	{
		is_Sep = false;
		 c = tolower(getc(pFile)); //getting the first character in the file to be able to perform the while condition checking
		if(c!=EOF)
		 char_count++;// inc the counter of characters
         if(c == '\n')
           { // end of line

        	 if(AddedWord!="")
        	   MyList.insertWord(AddedWord, Line_num);
        	 AddedWord.clear();
        	 Line_num++;
        	 //c = tolower(getc(pFile));
        	 continue;// it goes to the beginning of while and discards sentences following it
           }
        for(int i = 0; i<16; i++)
        { //checking on separators
           if(c == sep[i])
            {
        	   is_Sep = true;
        	   break;
            }



        }
        if(is_Sep){
        	if(AddedWord !="")
        	  MyList.insertWord(AddedWord, Line_num);

        	        	   AddedWord.clear();

        }
        else
        {
        AddedWord+=char(c);
        }


	}
		while(c!= EOF);

	fclose(pFile);




	string Command;
	string CMD_word;
	string unwanted;
	string line;
	ifstream Command_file(argv[2]);
	if(Command_file.is_open())
	{
		k:while(getline(Command_file , line))
	  {
			istringstream iss(line);
			CMD_word.clear();
			iss>>Command>>CMD_word>>unwanted;
        if(unwanted != ""){cout<<"Incorrect number of arguments"<<'\n';unwanted.clear();goto k;}

			transform(CMD_word.begin(), CMD_word.end(), CMD_word.begin(), ::tolower);
		if(Command == "wordCount")
			{
			    if(CMD_word != ""){cout<<"Incorrect number of arguments"<<'\n';CMD_word.clear();goto k;}
			    int num_word;
			    num_word = int(MyList.wordCount());
			    cout << num_word  << " " << "words"<<'\n';

			}
		else if(Command == "distWords")
					{
						if(CMD_word != ""){cout<<"Incorrect number of arguments"<<'\n';CMD_word.clear();goto k;}
					    int num_distWords;
					    num_distWords = int(MyList.distWords());
					    cout << num_distWords  << " " << "distinct words"<<'\n';

					}
		else if(Command == "charCount")
							{
								if(CMD_word != ""){cout<<"Incorrect number of arguments"<<'\n';CMD_word.clear();goto k;}

							    cout << char_count  << " " << "characters"<<'\n';

							}
		else if(Command == "frequentWord")
					{
						if(CMD_word != ""){cout<<"Incorrect number of arguments"<<'\n';CMD_word.clear();goto k;}

					    MyList.frequentWord();
					    cout<<'\n';


					}

		else if(Command == "countWord")
							{

							  if(CMD_word==""){cout<<"Incorrect number of arguments"<<'\n';CMD_word.clear();goto k;}
			                  string word_to_be_counted;
			                  word_to_be_counted = CMD_word;
			                  MyList.countWord(word_to_be_counted);




							}
		else if(Command == "starting")
									{

									  if(CMD_word==""){cout<<"Incorrect number of arguments"<<'\n';CMD_word.clear();goto k;}
									  string mysub;
									  mysub = CMD_word;
					                  MyList.starting(mysub);
					                  cout<<'\n';
									}

		else if(Command == "containing")
											{

												if(CMD_word==""){cout<<"Incorrect number of arguments"<<'\n';CMD_word.clear();goto k;}
											    string mystr_containing;
											    mystr_containing = CMD_word;
							                    MyList.containing(mystr_containing);

							                  cout<<'\n';
											}

		else if(Command == "search")
													{

														if(CMD_word==""){cout<<"Incorrect number of arguments"<<'\n';CMD_word.clear();goto k;}
														string mystr_search;
													    mystr_search = CMD_word;
									                    MyList.search(mystr_search);


													}

		else
			cout<<"Undefined command"<<'\n';

	  }

	}
	else
		{
			cout<<"File not found";
		    return 0;
		}
return 0;
}








