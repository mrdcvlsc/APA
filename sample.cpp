
/* This is a draft. Further revision is needed.
 *
 * FILE: example.cpp
 * DESCRIPTION: This parses a mathematical expression and stores it to bignum.
 */

#include <iostream>
#include <assert.h>
#include <chrono>
#include <cstdio>
#include <string>
#include "bignum.h"

#define ERROR(...) fprintf(stderr,  __VA_ARGS__)
using namespace std;
using namespace std::chrono;

char line[500]; int cur = 0;
bignum answer;

/*-------.
| Tokens |
`-------*/
typedef enum token_t token_t;
enum token_t {
  TOK_VAL,
  TOK_LBRACE,
  TOK_RBRACE,
  TOK_ADD,
  TOK_SUB,
  TOK_MUL,
  TOK_DIV,
  TOK_EOL /*end of line */
};

/*
/*----------------------------.
| Terminals and non-terminals |
`----------------------------*/
typedef struct symrec_t symrec_t;
struct symrec_t {
   token_t type;
   bignum val;
};


/*--------.
| Scanner |
`--------*/
symrec_t * lex(void){
  while (line[cur]==' '||buff[cur]=='\n') cur++; /* eat whitespace */
  switch (line[cur]){
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
	symrec_t *s = malloc(sizeof(symrec_t));
	assert(s!=NULL);
	int nchar; char buff[400];

	sscanf(line+cur, "399[0-9]%n", &s->val, &nchar);
	s->type = TOK_VAL;
	cur+=nchar-1;
	return s;

	}
	case '+': {
		symrec_t *s = malloc (sizeof(symrec_t));
		s->type = TOK_ADD;
		cur++;
		return s;}
	case '-':{
                symrec_t *s = malloc (sizeof(symrec_t));
                s->type = TOK_SUB;
                cur++;
                return s;}
	case '*': {
                symrec_t *s = malloc (sizeof(symrec_t));
                s->type = TOK_MUL;
                cur++;
                return s;};
	case '/': {
                symrec_t *s = malloc (sizeof(symrec_t));
                s->type = TOK_DIV;
                cur++;
                return s;}
		  ;
	case 0: {
                symrec_t *s = malloc (sizeof(symrec_t));
                s->type = TOK_EOL;
                cur++;
                return s;};
	default: ERROR("error: character %c is illegal\n", line[cur]); exit(1);
	

  }
}

void parse(void){
   expression();
}

void expression(void){


}*/
int main(){

	cout << "q to exit\n";
	while (1) {

		cout<<"> ";
	        scanf("%499s", line);
		if (line[0]=='q') break;
		parse();
		cout<<"= "<<answer<<endl;
	}

	return 0;
}
