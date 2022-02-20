#pragma once

#include <string>

#include "lexer/Symbol.hpp"

class Lexer {

   public:
      Lexer(string s) : flux(s), head(0), buffer(nullptr) {};
      ~Lexer() {};

      Symbol * Consult();
      void Advance();

   protected:
      string flux;
      int head;
      Symbol * buffer;
};
