#include "../inc/lexer/Lexer.hpp"

Symbol * Lexer::Consult() {
   if (!buffer) {

      if (head==flux.length())
         buffer = new Symbol(END);
      else
      {

         switch (flux[head]) {
            case '(':
               buffer = new Symbol(OPENPAR);
               head++;
               break;
            case ')':
               buffer = new Symbol(CLOSEPAR);
               head++;
               break;
            case '*':
               buffer = new Symbol(MULT);
               head++;
               break;
            case '+':
               buffer = new Symbol(PLUS);
               head++;
               break;
            default:
               if (flux[head]<='9' && flux[head]>='0') {
                  int resultat = flux[head]-'0';
                  int i=1;
                  while (flux[head+i]<='9' && flux[head+i]>='0') {
                     resultat = resultat*10+(flux[head+i]-'0');
                     i++;
                  }
                  head = head+i;
                  buffer = new Int(resultat);
               }
               else {
                  buffer = new Symbol(ERREUR);
               }
         }
      }
   }
   return buffer;
}

void Lexer::Advance() {
   buffer = nullptr;
}

