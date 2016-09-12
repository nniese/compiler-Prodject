/*
 * Scanner.cpp
 *
 *  Created on: Aug 30, 2015
 *      Author: bhoward
 *  Modified on: August 22, 2016
 *      Author: sthede
 */

#include "Scanner.h"

#include <iostream>
#include <cctype>
#include <map>
using namespace std;

Scanner::Scanner( istream& in ) : in(in) 
{
	line_num = 1;
	column_num = 1;
	getline( in, line );
}

Token Scanner::next() 
{
	Token token;
	
	
	while (!at_EOF()){
		// checks Token ID and checks if keywords 
		if (isalpha(current_char())){
			token.line = line_num;
			token.type = ID;
			token.lexeme = "";
			token.column = column_num;
			string keyword = "";
			string lexeme = "";
			while (isalpha(current_char()) || isdigit(current_char())){
				lexeme += current_char();
				keyword += tolower(current_char());
				advance();
			}
			//checks for key words
			if (keyword == "program")
				token.type = PROGRAM;
			if (keyword == "const")
				token.type = CONST;
			if (keyword == "end")
				token.type = END;
			if (keyword == "div")
				token.type = DIV;
			if (keyword == "mod")
				token.type = MOD;
			if (keyword == "print")
				token.type = PRINT;
			if (keyword == "begin")
				token.type = BEGIN;
			if (keyword == "eof"){
				token.type = EOFILE;

			}
			else
				token.lexeme = lexeme;
			if (token.type != ID)
				token.lexeme = "";
			return token;
		}
		// checks Token Number
		else if (isdigit(current_char())){
			token.line = line_num;
			token.type = NUM;
			token.lexeme = "";
			string lexeme = "";
			token.column = column_num;
			while (isdigit(current_char())){
				lexeme += current_char();
				advance();
			}
			token.lexeme = lexeme;
			return token;
		}


		// ,,:,;,(,),. below
		/*if (current_char() == ','){
			token.line = line_num;
			token.type = COMM;
			token.lexeme = "";
			token.column = column_num;
			advance();
			return token;
			}*/
		else if (current_char() == ';'){
			token.line = line_num;
			token.type = SEMI;
			token.lexeme = "";
			token.column = column_num;
			advance();
			return token;
		}
		else if (current_char() == '.'){
			token.line = line_num;
			token.type = PERIOD;
			token.lexeme = "";
			token.column = column_num;
			advance();
			return token;
		}
		/*if (current_char() == ')'){
			token.line = line_num;
			token.type = RPAR;
			token.lexeme = "";
			token.column = column_num;
			advance();
			return token;
			}
			if (current_char() == '('){
			token.line = line_num;
			token.type = LPAR;
			token.lexeme = "";
			token.column = column_num;
			advance();
			return token;
			}*/
		/*if (current_char() == ':'){
			token.line = line_num;
			token.type = COL;
			token.lexeme = "";
			token.column = column_num;
			advance();
			return token;
			}*/
		// +-=* below
		else if (current_char() == '+'){
			token.line = line_num;
			token.type = PLUS;
			token.lexeme = "";
			token.column = column_num;
			advance();
			return token;
		}
		else if (current_char() == '-'){
			token.line = line_num;
			token.type = MINUS;
			token.lexeme = "";
			token.column = column_num;
			advance();
			return token;
		}
		else if (current_char() == '*'){
			token.line = line_num;
			token.type = STAR;
			token.lexeme = "";
			token.column = column_num;
			advance();
			return token;
		}
		else if (current_char() == '='){
			token.line = line_num;
			token.type = EQUAL;
			token.lexeme = "";
			token.column = column_num;
			advance();
			return token;
		}

		else if (current_char() == '{'){
			token.line = line_num;
			token.type = CCB;
			token.lexeme = "";
			token.column = column_num;
			while ((current_char() != '}')){// } ends the comment and eof will cause a error
				advance();
				if (tolower(current_char())== 'e'){
					advance();
					if (tolower(current_char()) == 'o'){
						advance();
						if (tolower(current_char()) == 'f'){
							token.type = ERROR;
							token.lexeme = "must have }";
							advance();
							return token;
						}
					}
				}
				if (at_EOF())
				{
					token.type = ERROR;
					token.lexeme = "must have }";
					advance();
					return token;
				}
			}
			advance();
			return token;
		}
		// for comments // and {} // is until end of line 
		else if (current_char() == '/'){
			token.line = line_num;

			token.lexeme = "";
			token.column = column_num;
			int line = line_num;
			advance();
			if (current_char() == '/')
				token.type = BACKSL;
			else{
				token.type = ERROR;
				token.lexeme = "two / needed for comments";
				return token;
			}
			while (line != line_num){
				advance();
			}

		}
		else if (at_EOF()){
			token.type = EOFILE;
			token.column = column_num;
			token.line = line_num;
			token.lexeme = "";
		}
		else if (isspace(current_char()))
			advance();

		else
		{
			token.column = column_num;
			token.line = line_num;
			token.type = ERROR;
			token.lexeme = "unknow char";
			advance();
			return token;
		}
	}
	return token;
}

char Scanner::current_char() 
{
	if ( column_num <= (signed)line.size() ) 
	{
		// still within the current line
		return line[column_num - 1];
	} 
	else if (in) 
	{
		// at end of current line, but input still valid
		return '\n';
	} 
	else 
	{
		// past end of input
		return char_traits<char>::eof();
	}
}

bool Scanner::at_EOF() 
{
	return current_char() == char_traits<char>::eof();
}

void Scanner::advance() 
{
	if (column_num <= (signed)line.size()) 
	{
		// still within current line
		++column_num;
	} 
	else if (in) 
	{
		// attempt to read another line
		line.clear();
		getline(in, line);
		++line_num;
		column_num = 1;
	} 
	else 
	{
		// do nothing -- at EOF
	}
}
