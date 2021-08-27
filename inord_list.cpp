/*
 * inord_list.cpp
 *
 *  Created on: May 11, 2021
 *      Author: student
 */

#include "inord_list.h"
#include <iostream>
#include <string.h>
#include <sstream>
#include <cstddef>
#include <fstream>
#include <cctype>
#include <cmath>
#include <string>
using namespace std;

/**********************Design of orderdList Operations*************************///

ordered_List ::ordered_List()
{
	ordered_head = NULL;
	ordered_current = NULL;
	ordered_pred = NULL;
}

bool ordered_List ::insert(const ListElemType &word, const int &occurrences)
{
	Node *New_Word;
	New_Word = new Node;
	  if(New_Word == NULL){return false;} //check if allocation failed
	New_Word ->ordered_Word = word;
	New_Word ->num_occ = occurrences;
	if(ordered_head == NULL || ((New_Word ->ordered_Word) < (ordered_head -> ordered_Word)))
	{ //empty List
		New_Word ->next = ordered_head;
		ordered_head = New_Word;

	}
	else
	{
		ordered_pred = ordered_head;
		while(ordered_pred->next != NULL && ((ordered_pred ->next ->ordered_Word)  < (New_Word ->ordered_Word)))
		{
			ordered_pred = ordered_pred ->next;
		}
		New_Word ->next = ordered_pred ->next;
		ordered_pred ->next = New_Word;
	}
	return true;
}

bool ordered_List ::insert_Line(const ListElemType &word,const List_of_Lines Line_num_list)
{
	ordered_current = ordered_head;
	while(ordered_current != NULL)
	{
		if(ordered_current->ordered_Word==word)
		  ordered_current->List=Line_num_list;
		ordered_current = ordered_current ->next;
	}
	return true;
}

bool ordered_List ::get_words_freq()
{   cout << "Most frequent word is:" << " ";
	ordered_current = ordered_head;
	while(ordered_current != NULL)
		{
		cout << ordered_current ->ordered_Word << " " ;
		ordered_current = ordered_current->next;
		}
	return true;
}

bool ordered_List ::get_words_starting()
{   ordered_current = ordered_head;
	while(ordered_current != NULL)
		{
		cout << ordered_current ->ordered_Word << ": "<< ordered_current ->num_occ<<"	" ;
		ordered_current = ordered_current->next;
		}
	return true;
}

bool ordered_List ::get_words_containing()
{
	ordered_current = ordered_head;
	while(ordered_current != NULL)
		{
		cout << ordered_current ->ordered_Word << ": "<< ordered_current ->num_occ<<"	" ;
		ordered_current = ordered_current->next;
		}
	return true;
}

bool ordered_List ::get_words_search()
{
	ordered_current = ordered_head;
	while(ordered_current != NULL)
		{
		cout<< ordered_current->ordered_Word<<":	lines ";
				  ordered_current ->List.getlines();
				  ordered_current = ordered_current ->next;
		}
	return true;
}




//////////*design of list of line operations*////////////
//constructor
List_of_Lines :: List_of_Lines(){

	//initializing state variables of list
	List_of_Lines_head = NULL;
	List_of_Lines_current = NULL;
	List_of_Lines_tail = NULL;
}

bool List_of_Lines ::  insertLine(const int &Line_num)
{

	LineNode *AddedLineNode; //declare a pointer to the new node
	AddedLineNode = new LineNode; //allocate a LineNode
     	if(AddedLineNode == NULL){return false;} //check if allocation failed
	AddedLineNode -> Line = Line_num; //storing the line number in LineNode
	AddedLineNode -> nextLine = NULL;

	if(List_of_Lines_head == NULL) //check if list is empty or not
	{ //empty list insertion

			//AddedLineNode -> Line = Line_num; //storing the line number in LineNode
			AddedLineNode ->num_repeat_same_line = 1;
			List_of_Lines_head = AddedLineNode;
		//AddedLineNode -> nextLine = NULL;
		List_of_Lines_tail = AddedLineNode;

	}
	else
	{ //insertion in nonempty list
	  if(AddedLineNode -> Line == List_of_Lines_tail -> Line)//check whether the line is already existing
	  {
		  List_of_Lines_tail ->num_repeat_same_line ++;
		  delete AddedLineNode;
	  }

	  else
	  {


		  AddedLineNode ->num_repeat_same_line = 1;
		  List_of_Lines_tail -> nextLine = AddedLineNode;
		  List_of_Lines_tail = AddedLineNode;
	  }

	}
	return true;
}

int List_of_Lines :: getsize()
 { int size = 0;
 List_of_Lines_current = List_of_Lines_head;
 if(List_of_Lines_current == NULL)
   { return size;

   }
 while(List_of_Lines_current  !=NULL)
 { size += 1 * (List_of_Lines_current -> num_repeat_same_line);

	 List_of_Lines_current = List_of_Lines_current -> nextLine;
 }


  return size;}

void List_of_Lines ::getlines()
{
	List_of_Lines_current = List_of_Lines_head;
	while(List_of_Lines_current  !=NULL)
	{
		cout<<List_of_Lines_current ->Line << " ";
		List_of_Lines_current = List_of_Lines_current ->nextLine;
	}
	cout<<'\n';
}


/************Design of ListOfWords Operatins**************************/


List_of_Words ::List_of_Words()
{
	head = NULL;
	current = NULL;
	tail = NULL;
}

bool List_of_Words :: insertWord(const ListElemType &AddedWord, const int &Line_num)
{  //bool insert_line_flag;
  WordNode *AddedWordNode;
  WordNode *current_insert;
  bool found_word;
  AddedWordNode = new WordNode;
  if(AddedWordNode==NULL){return false;}
  AddedWordNode ->word = AddedWord;
   AddedWordNode ->Line_num_list .insertLine(Line_num);
   //if(!insert_line_flag){cout<<"Insertion Failed"; return 0;}
  AddedWordNode ->nextWord = NULL;
  if(head==NULL)
  { //empty list
	  head = AddedWordNode;
	  tail = AddedWordNode;

  }
  else
  { current_insert = head;
  	found_word = false;
	  while(current_insert != NULL)
	  {
		  if(current_insert->word == AddedWord)
			  {
			  found_word = true;
			  break;
			  }
		  current_insert = current_insert->nextWord;
	  }
	  if(found_word)
	  {
		  current_insert ->Line_num_list.insertLine(Line_num);
		  			  delete AddedWordNode;
	  }

	  else{

	  tail -> nextWord = AddedWordNode;
    tail = AddedWordNode;
	  }
  }
 return true;
}

int List_of_Words :: wordCount()
{ int num_words = 0;
  int occurrences;
  current = head;
  while(current!=NULL)
  {
      occurrences = current -> Line_num_list.getsize();
	  num_words+=occurrences;
      current = current -> nextWord;
  }
  return num_words;
}

int List_of_Words :: distWords()
{
	int num_disWord = 0;
	current = head;
	while(current!=NULL)
	{
		num_disWord++;
		current = current ->nextWord;
	}

	return num_disWord;
}

void List_of_Words :: frequentWord()
{
	string language_Constructs[9] = {"and" , "a" , "the" , "an" , "is" , "are" , "in","on","of"};
	//int occurrences;
	WordNode *MAX;
	current = head ->nextWord;
	if(current ==NULL){cout<<"Word not found"<<'\n';}
	//current_freq = head->nextWord;
	ordered_List freq_List;
	 MAX = head;
	 n:for(int i = 0; i<9 ; i++)
	 		{
	 		if(MAX ->word == language_Constructs[i] ){MAX = MAX ->nextWord; goto n;}
	 		}

	z:while(current!=NULL)
	{
		for(int i = 0; i<9 ; i++)
		{
		if(current ->word == language_Constructs[i] ){current = current ->nextWord; goto z;}
		}
		//occurrences = current -> Line_num_list.getsize();
		if(current -> Line_num_list.getsize()<= MAX->Line_num_list.getsize()){current = current ->nextWord; continue;}
		else
		{
			MAX = current;
			current = current ->nextWord;
			continue;
		}
	}
	freq_List.insert(MAX ->word , MAX ->Line_num_list.getsize());
	current = head;
	l:while(current!=NULL)
	{
		for(int i = 0; i<9 ; i++)
				{
				if(current ->word == language_Constructs[i] ){current = current ->nextWord; goto l;}
				}
		if(current ->Line_num_list.getsize() == MAX ->Line_num_list.getsize()&&current ->word != MAX ->word){freq_List.insert(current ->word ,current ->Line_num_list.getsize());}
		current = current->nextWord;
	}



	freq_List.get_words_freq(); //print the words with the highest frequency
}


void List_of_Words ::countWord(const string &word_to_be_counted)
{
   current = head;
   while(current != NULL && current ->word !=word_to_be_counted)
   {
	   current = current ->nextWord;
   }
   if(current == NULL){cout<<"Word not found"<<'\n';return;}
   else
   {
	   cout<< current ->word  << " "<<"is repeated"<<" "<<current ->Line_num_list.getsize()<<" "<<"times"<<'\n';
   }

}


void List_of_Words ::starting(const string &mysub)
{
	ordered_List starting_List;
	int found = 0;
	bool got;
    string curr_wrd_starting;
    current = head;
    while(current != NULL)
	{   found = 0;
    	curr_wrd_starting= current ->word;
		for(int i =0; i<int(mysub.length());i++)
				      if(mysub[i] == curr_wrd_starting[i])
				    	  found++;
		if(found==int(mysub.length()))
			{
			starting_List.insert(current ->word,current->Line_num_list.getsize());
			got = true;
			}

		current = current->nextWord;

	}
    if(!got){cout<<"Word not found";return;}

    starting_List.get_words_starting();
}


void List_of_Words :: containing(const string &mystr_containing)
{
	ordered_List containing_List;

	string curr_wrd_containing;
	bool got_containing;
	current = head;
	while(current != NULL)
	{
	  curr_wrd_containing= current ->word;
	  if(curr_wrd_containing.find(mystr_containing) != string::npos)

		  {
		  containing_List.insert(curr_wrd_containing,current ->Line_num_list.getsize());
		  got_containing = true;
		  }


	  current = current->nextWord;
	}
	if(!got_containing){cout<<"Word not found";return;}
	containing_List.get_words_containing();
}

void List_of_Words :: search(const string &mystr_search)
{
	ordered_List search_List;
	string curr_wrd_search;
	bool got_search;
		current = head;
		while(current != NULL)
		{
		  curr_wrd_search= current ->word;
		  if(curr_wrd_search.find(mystr_search) != string::npos)
			  {
			  got_search = true;
			  search_List.insert(current->word,current->Line_num_list.getsize());
			  search_List.insert_Line(current->word,current->Line_num_list);

			  }


		  current = current->nextWord;
		}
		if(!got_search){cout<<"Word not found"<<'\n';return;}
		search_List.get_words_search();

}

void List_of_Words ::show()
{
	current = head;
	while(current!=NULL)
	{
		cout<<current->word<<'\n';
		current = current->nextWord;
	}
}


//int List_of_Words :: distWords()









