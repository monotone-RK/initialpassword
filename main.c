/******************************************************************************/
/* Initial Password Generator for Accounts Ver 1.0                monotone-RK */
/*                                                    Last updated 2014.01.28 */
/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ACCOUNT_NUM  40
#define PASSWD_DIGIT 10

/* choose from A~Z */
/**********************************************************/
char getAlphabetBig() {
  return 'A' + (char)(rand() % 26);
}

/* choose from a~z */ 
/**********************************************************/
char getAlphabetSmall() {
  return 'a' + (char)(rand() % 26);
}

/* choose from 2~9 */
/**********************************************************/
char getNumber() {
  return '2' + (char)(rand() % 8);
}

/* choose from A~Z, a~z, 2~9, at rondom */
/**********************************************************/
char getAllSymbol() {
  switch (rand() % 3) {
    case 0:
      return getAlphabetBig();
    case 1:
      return getAlphabetSmall();
    default:
      return getNumber();
  }
}

/* function of shuffle string */
/**********************************************************/
void shuffleString(char* pwd) {
  char buf = '\0';
  int  swap;
  
  for (unsigned int i = 0; i < strlen(pwd); i++) {
    /* shuffling */
    swap      = rand() % strlen(pwd);
    buf       = pwd[i];
    pwd[i]    = pwd[swap];
    pwd[swap] = buf;
  }
}

/**********************************************************/
int main(void) {
  int  account;
  char pwd[ACCOUNT_NUM][PASSWD_DIGIT+1] = {};
  
  srand((unsigned)time(NULL));
  
  /* generate passwd for the number of accounts */
  for (account = 0; account < ACCOUNT_NUM; account++) {
  
    /* choose A~Z, a~z, 2~9 */
    pwd[account][0] = getAlphabetBig();
    pwd[account][1] = getAlphabetSmall();
    pwd[account][2] = getNumber();
    
    /* choose the others */
    for (int i = 3; i < PASSWD_DIGIT; i++) {
      pwd[account][i] = getAllSymbol();
    }
    
    /* shuffle string */
    shuffleString(pwd[account]);
  }
  
  /* display passwd */
  for (account = 0; account < ACCOUNT_NUM; account++) {
    printf("account%03d:%s\n", account+1, pwd[account]);
  }
  
  return 0;
}
