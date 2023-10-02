
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;


// Generated from ADA.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  ADALexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, PROGRAM = 22, CONST = 23, TYPE = 24, ARRAY = 25, OF = 26, 
    RECORD = 27, VAR = 28, BEGIN = 29, END = 30, DIV = 31, MOD = 32, AND = 33, 
    OR = 34, NOT = 35, IF = 36, THEN = 37, ELSE = 38, ELSIF = 39, CASE = 40, 
    REPEAT = 41, UNTIL = 42, WHILE = 43, DO = 44, FOR = 45, TO = 46, DOWNTO = 47, 
    WRITE = 48, WRITELN = 49, READ = 50, READLN = 51, PROCEDURE = 52, FUNCTION = 53, 
    EXIT = 54, WHEN = 55, IN = 56, REVERSE = 57, LOOP = 58, IS = 59, PUT = 60, 
    PUTLINE = 61, GET = 62, GETLINE = 63, OUT = 64, RETURN = 65, NEWLINE = 66, 
    IDENTIFIER = 67, INTEGER = 68, REAL = 69, NEW_LINE = 70, WS = 71, QUOTE = 72, 
    CHARACTER = 73, STRING = 74, COMMENT = 75
  };

  explicit ADALexer(antlr4::CharStream *input);
  ~ADALexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

