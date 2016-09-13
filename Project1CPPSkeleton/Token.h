/*
 * Token.h
 *
 *  Created on: Aug 30, 2015
 *      Author: bhoward
 *  Modified on: August 22, 2016
 *      Author: sthede
 */

#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>
#include <iosfwd>
using namespace std;

enum Token_Type 
{
	NUM,
	SEMI,
	PLUS,
	MINUS,
	STAR,
	STRING,
	ID,
	KEYWORD,
	//keywords
	PROGRAM,
	CONST,
	BEGIN, 
	PRINT,
	END, 
	DIV, 
	MOD,
	//keywords
	COMM, //","
	LPAR,//"("
	RPAR,//")"
	COL, //":"
	EQUAL,//"="
	CCB,//"{}"
	BACKSL, // "/"
	PERIOD,//"."
	ERROR, // for other errors 

	// TODO add other Token_Types
	EOFILE // EOF is already used in cstdio
};

// Format a Token_Type for display on an output stream
ostream& operator<<( ostream& out, Token_Type type );

struct Token 
{
	int line, column;
	Token_Type type;
	std::string lexeme;
};

// Format a Token for display on an output stream
std::ostream& operator<<( ostream& out, const Token& token );

#endif /* TOKEN_H_ */
