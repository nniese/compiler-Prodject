/*
 * Token.cpp
 *
 *  Created on: Aug 30, 2015
 *      Author: bhoward
 *  Modified on: August 22, 2016
 *      Author: sthede
 */

#include "Token.h"

#include <ostream>
using namespace std;

ostream& operator<<( ostream& out, Token_Type type ) 
{
	switch (type) 
	{
	case NUM:
		out << "NUM";
		break;
	case SEMI:
		out << "SEMI";
		break;
	case PLUS:
		out << "PLUS";
		break;
	case MINUS:
		out << "MINUS";
		break;
	case STAR:
		out << "STAR";
		break;
	case STRING:
		out << "STRING";
			break;
	case ID:
		out << "ID";
		break;
		//program, const, begin, print, end, div, mod
	case MOD:
		out << "MOD";
		break;
	case DIV:
		out << "DIV";
		break;
	case END:
		out << "END";
		break;
	case PRINT:
		out << "PRINT";
		break;
	case BEGIN:
		out << "BEGIN";
		break;
	case CONST:
		out << "CONST";
		break;
	case PROGRAM:
		out << "PROGRAM";
		break;
	case KEYWORD:
		out << "KEYWORD";
		break;
	case COMM:
		out << "COMMA";
		break;
	case LPAR:
		out << "LPAR";
		break;
	case RPAR:
		out << "RPAR";
		break;
	case COL:
		out << "COL";
		break;
	case EQUAL:
		out << "EQUAL";
		break;
	case CCB:
		out << "CCB";
		break;
	case BACKSL:
		out << "BACKSL";
		break;
	case PERIOD:
		out << "PERIOD";
		break;
	case EOFILE:
		out << "EOFILE";
	case ERROR:
		out << ""; 
	// TODO add cases for the other Token_Types
	default:
		out << "ERROR";
		break;
	}

	return out;
}

ostream& operator<<( std::ostream& out, const Token& token ) 
{
	out << token.type;

	if (token.lexeme != "") 
	{
		out << " " << token.lexeme << " ";
	}
	else
	{
		out << " ";
	}

	out  << token.line << ":" << token.column;

	return out;
}
