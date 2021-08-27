/*
 * inord_list.h
 *
 *  Created on: May 11, 2021
 *      Author: Ahmed Saied
 */

#ifndef INORD_LIST_H_
#define INORD_LIST_H_
#include <iostream>
#include <string.h>
#include <sstream>
#include <cstddef>
#include <fstream>
#include <cctype>
#include <cmath>
#include <string>
using namespace std;


#define ListElemType string





//List to store lines where repeated words occurred
class List_of_Lines{
public:
	List_of_Lines(); //constructor
	bool insertLine(const int &Line_num);
	int getsize();//to get the number of word occurrences
	void getlines();


private:
	struct LineNode{
		int Line;
		int num_repeat_same_line;
		LineNode *nextLine;
	};

	//state variables
	LineNode *List_of_Lines_head;
	LineNode *List_of_Lines_current;
	LineNode *List_of_Lines_tail;
};


class ordered_List{
public:
	ordered_List();
	bool insert(const ListElemType &word, const int &occurrences);
	bool insert_Line(const ListElemType &word,const List_of_Lines Line_num_list);
	bool get_words_freq();
	bool get_words_starting();
	bool get_words_containing();
	bool get_words_search();
private:
	struct Node{
		string ordered_Word;
		int num_occ;
		Node *next;
		List_of_Lines List;
	};

	//state variables
	Node *ordered_head;
	Node *ordered_pred;
	Node *ordered_current;

};


//A list to store words inside the file , these words are ordered alphabetically
class List_of_Words{
  public:
	List_of_Words();
	bool insertWord(const ListElemType &AddedWord, const int &Line_num);
	int wordCount();
	int distWords();
	int charCount();
	void frequentWord();
	void countWord(const string &word_to_be_counted);
	void starting(const string &mysub);
	void containing(const string &mystr_containing);
	void search(const string &mystr_search);
    void show();
  private:
      struct WordNode{
    	  string word;
    	  List_of_Lines Line_num_list;
    	  WordNode *nextWord;

      };
      //state variables
      WordNode *head;
      WordNode *current;
      WordNode *tail;


};



#endif /* INORD_LIST_H_ */
