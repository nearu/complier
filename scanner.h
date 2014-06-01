#ifndef _SCANNER_H_
#define _SCANNER_H_
#include "public.h"
#include <string>
#define MAXTOKENLEN 63
std::string currentToken;
int getToken(void);
int yylex();
#endif