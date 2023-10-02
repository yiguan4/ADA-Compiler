
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;


// Generated from ADA.g4 by ANTLR 4.9.1


#include "ADAVisitor.h"

#include "ADAParser.h"


using namespace antlrcpp;
using namespace antlr4;

ADAParser::ADAParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ADAParser::~ADAParser() {
  delete _interpreter;
}

std::string ADAParser::getGrammarFileName() const {
  return "ADA.g4";
}

const std::vector<std::string>& ADAParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ADAParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

ADAParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::ProgramHeaderContext* ADAParser::ProgramContext::programHeader() {
  return getRuleContext<ADAParser::ProgramHeaderContext>(0);
}

ADAParser::BlockContext* ADAParser::ProgramContext::block() {
  return getRuleContext<ADAParser::BlockContext>(0);
}

ADAParser::ProgramIdentifierContext* ADAParser::ProgramContext::programIdentifier() {
  return getRuleContext<ADAParser::ProgramIdentifierContext>(0);
}


size_t ADAParser::ProgramContext::getRuleIndex() const {
  return ADAParser::RuleProgram;
}


antlrcpp::Any ADAParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ProgramContext* ADAParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, ADAParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(194);
    programHeader();
    setState(195);
    block();
    setState(197);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ADAParser::IDENTIFIER) {
      setState(196);
      programIdentifier();
    }
    setState(199);
    match(ADAParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramHeaderContext ------------------------------------------------------------------

ADAParser::ProgramHeaderContext::ProgramHeaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::ProgramHeaderContext::PROCEDURE() {
  return getToken(ADAParser::PROCEDURE, 0);
}

ADAParser::ProgramIdentifierContext* ADAParser::ProgramHeaderContext::programIdentifier() {
  return getRuleContext<ADAParser::ProgramIdentifierContext>(0);
}

tree::TerminalNode* ADAParser::ProgramHeaderContext::IS() {
  return getToken(ADAParser::IS, 0);
}


size_t ADAParser::ProgramHeaderContext::getRuleIndex() const {
  return ADAParser::RuleProgramHeader;
}


antlrcpp::Any ADAParser::ProgramHeaderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitProgramHeader(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ProgramHeaderContext* ADAParser::programHeader() {
  ProgramHeaderContext *_localctx = _tracker.createInstance<ProgramHeaderContext>(_ctx, getState());
  enterRule(_localctx, 2, ADAParser::RuleProgramHeader);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
    match(ADAParser::PROCEDURE);
    setState(202);
    programIdentifier();
    setState(203);
    match(ADAParser::IS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramIdentifierContext ------------------------------------------------------------------

ADAParser::ProgramIdentifierContext::ProgramIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::ProgramIdentifierContext::IDENTIFIER() {
  return getToken(ADAParser::IDENTIFIER, 0);
}


size_t ADAParser::ProgramIdentifierContext::getRuleIndex() const {
  return ADAParser::RuleProgramIdentifier;
}


antlrcpp::Any ADAParser::ProgramIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitProgramIdentifier(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ProgramIdentifierContext* ADAParser::programIdentifier() {
  ProgramIdentifierContext *_localctx = _tracker.createInstance<ProgramIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 4, ADAParser::RuleProgramIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    match(ADAParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementIdentifierContext ------------------------------------------------------------------

ADAParser::StatementIdentifierContext::StatementIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::StatementIdentifierContext::IDENTIFIER() {
  return getToken(ADAParser::IDENTIFIER, 0);
}


size_t ADAParser::StatementIdentifierContext::getRuleIndex() const {
  return ADAParser::RuleStatementIdentifier;
}


antlrcpp::Any ADAParser::StatementIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitStatementIdentifier(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::StatementIdentifierContext* ADAParser::statementIdentifier() {
  StatementIdentifierContext *_localctx = _tracker.createInstance<StatementIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 6, ADAParser::RuleStatementIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(207);
    match(ADAParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

ADAParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::DeclarationsContext* ADAParser::BlockContext::declarations() {
  return getRuleContext<ADAParser::DeclarationsContext>(0);
}

ADAParser::CompoundStatementContext* ADAParser::BlockContext::compoundStatement() {
  return getRuleContext<ADAParser::CompoundStatementContext>(0);
}


size_t ADAParser::BlockContext::getRuleIndex() const {
  return ADAParser::RuleBlock;
}


antlrcpp::Any ADAParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::BlockContext* ADAParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 8, ADAParser::RuleBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    declarations();
    setState(210);
    compoundStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

ADAParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::SubprogramPartContext* ADAParser::DeclarationsContext::subprogramPart() {
  return getRuleContext<ADAParser::SubprogramPartContext>(0);
}

ADAParser::ConstantsPartContext* ADAParser::DeclarationsContext::constantsPart() {
  return getRuleContext<ADAParser::ConstantsPartContext>(0);
}

ADAParser::TypesPartContext* ADAParser::DeclarationsContext::typesPart() {
  return getRuleContext<ADAParser::TypesPartContext>(0);
}

ADAParser::VariablesPartContext* ADAParser::DeclarationsContext::variablesPart() {
  return getRuleContext<ADAParser::VariablesPartContext>(0);
}


size_t ADAParser::DeclarationsContext::getRuleIndex() const {
  return ADAParser::RuleDeclarations;
}


antlrcpp::Any ADAParser::DeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitDeclarations(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::DeclarationsContext* ADAParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 10, ADAParser::RuleDeclarations);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ADAParser::PROCEDURE

    || _la == ADAParser::FUNCTION) {
      setState(212);
      subprogramPart();
      setState(213);
      match(ADAParser::T__0);
    }
    setState(220);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ADAParser::CONST) {
      setState(217);
      constantsPart();
      setState(218);
      match(ADAParser::T__0);
    }
    setState(225);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ADAParser::TYPE) {
      setState(222);
      typesPart();
      setState(223);
      match(ADAParser::T__0);
    }
    setState(230);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ADAParser::IDENTIFIER) {
      setState(227);
      variablesPart();
      setState(228);
      match(ADAParser::T__0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantsPartContext ------------------------------------------------------------------

ADAParser::ConstantsPartContext::ConstantsPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::ConstantsPartContext::CONST() {
  return getToken(ADAParser::CONST, 0);
}

ADAParser::ConstantDefinitionsListContext* ADAParser::ConstantsPartContext::constantDefinitionsList() {
  return getRuleContext<ADAParser::ConstantDefinitionsListContext>(0);
}


size_t ADAParser::ConstantsPartContext::getRuleIndex() const {
  return ADAParser::RuleConstantsPart;
}


antlrcpp::Any ADAParser::ConstantsPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitConstantsPart(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ConstantsPartContext* ADAParser::constantsPart() {
  ConstantsPartContext *_localctx = _tracker.createInstance<ConstantsPartContext>(_ctx, getState());
  enterRule(_localctx, 12, ADAParser::RuleConstantsPart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    match(ADAParser::CONST);
    setState(233);
    constantDefinitionsList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantDefinitionsListContext ------------------------------------------------------------------

ADAParser::ConstantDefinitionsListContext::ConstantDefinitionsListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ADAParser::ConstantDefinitionContext *> ADAParser::ConstantDefinitionsListContext::constantDefinition() {
  return getRuleContexts<ADAParser::ConstantDefinitionContext>();
}

ADAParser::ConstantDefinitionContext* ADAParser::ConstantDefinitionsListContext::constantDefinition(size_t i) {
  return getRuleContext<ADAParser::ConstantDefinitionContext>(i);
}


size_t ADAParser::ConstantDefinitionsListContext::getRuleIndex() const {
  return ADAParser::RuleConstantDefinitionsList;
}


antlrcpp::Any ADAParser::ConstantDefinitionsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitConstantDefinitionsList(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ConstantDefinitionsListContext* ADAParser::constantDefinitionsList() {
  ConstantDefinitionsListContext *_localctx = _tracker.createInstance<ConstantDefinitionsListContext>(_ctx, getState());
  enterRule(_localctx, 14, ADAParser::RuleConstantDefinitionsList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(235);
    constantDefinition();
    setState(240);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(236);
        match(ADAParser::T__0);
        setState(237);
        constantDefinition(); 
      }
      setState(242);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantDefinitionContext ------------------------------------------------------------------

ADAParser::ConstantDefinitionContext::ConstantDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::ConstantIdentifierContext* ADAParser::ConstantDefinitionContext::constantIdentifier() {
  return getRuleContext<ADAParser::ConstantIdentifierContext>(0);
}

ADAParser::ConstantContext* ADAParser::ConstantDefinitionContext::constant() {
  return getRuleContext<ADAParser::ConstantContext>(0);
}


size_t ADAParser::ConstantDefinitionContext::getRuleIndex() const {
  return ADAParser::RuleConstantDefinition;
}


antlrcpp::Any ADAParser::ConstantDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitConstantDefinition(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ConstantDefinitionContext* ADAParser::constantDefinition() {
  ConstantDefinitionContext *_localctx = _tracker.createInstance<ConstantDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 16, ADAParser::RuleConstantDefinition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(243);
    constantIdentifier();
    setState(244);
    match(ADAParser::T__1);
    setState(245);
    constant();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantIdentifierContext ------------------------------------------------------------------

ADAParser::ConstantIdentifierContext::ConstantIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::ConstantIdentifierContext::IDENTIFIER() {
  return getToken(ADAParser::IDENTIFIER, 0);
}


size_t ADAParser::ConstantIdentifierContext::getRuleIndex() const {
  return ADAParser::RuleConstantIdentifier;
}


antlrcpp::Any ADAParser::ConstantIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitConstantIdentifier(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ConstantIdentifierContext* ADAParser::constantIdentifier() {
  ConstantIdentifierContext *_localctx = _tracker.createInstance<ConstantIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 18, ADAParser::RuleConstantIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(247);
    match(ADAParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

ADAParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::ConstantContext::IDENTIFIER() {
  return getToken(ADAParser::IDENTIFIER, 0);
}

ADAParser::UnsignedNumberContext* ADAParser::ConstantContext::unsignedNumber() {
  return getRuleContext<ADAParser::UnsignedNumberContext>(0);
}

ADAParser::SignContext* ADAParser::ConstantContext::sign() {
  return getRuleContext<ADAParser::SignContext>(0);
}

ADAParser::CharacterConstantContext* ADAParser::ConstantContext::characterConstant() {
  return getRuleContext<ADAParser::CharacterConstantContext>(0);
}

ADAParser::StringConstantContext* ADAParser::ConstantContext::stringConstant() {
  return getRuleContext<ADAParser::StringConstantContext>(0);
}


size_t ADAParser::ConstantContext::getRuleIndex() const {
  return ADAParser::RuleConstant;
}


antlrcpp::Any ADAParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ConstantContext* ADAParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 20, ADAParser::RuleConstant);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(258);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ADAParser::T__2:
      case ADAParser::T__3:
      case ADAParser::IDENTIFIER:
      case ADAParser::INTEGER:
      case ADAParser::REAL: {
        enterOuterAlt(_localctx, 1);
        setState(250);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == ADAParser::T__2

        || _la == ADAParser::T__3) {
          setState(249);
          sign();
        }
        setState(254);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case ADAParser::IDENTIFIER: {
            setState(252);
            match(ADAParser::IDENTIFIER);
            break;
          }

          case ADAParser::INTEGER:
          case ADAParser::REAL: {
            setState(253);
            unsignedNumber();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case ADAParser::CHARACTER: {
        enterOuterAlt(_localctx, 2);
        setState(256);
        characterConstant();
        break;
      }

      case ADAParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(257);
        stringConstant();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignContext ------------------------------------------------------------------

ADAParser::SignContext::SignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ADAParser::SignContext::getRuleIndex() const {
  return ADAParser::RuleSign;
}


antlrcpp::Any ADAParser::SignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitSign(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::SignContext* ADAParser::sign() {
  SignContext *_localctx = _tracker.createInstance<SignContext>(_ctx, getState());
  enterRule(_localctx, 22, ADAParser::RuleSign);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(260);
    _la = _input->LA(1);
    if (!(_la == ADAParser::T__2

    || _la == ADAParser::T__3)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypesPartContext ------------------------------------------------------------------

ADAParser::TypesPartContext::TypesPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::TypesPartContext::TYPE() {
  return getToken(ADAParser::TYPE, 0);
}

ADAParser::TypeDefinitionsListContext* ADAParser::TypesPartContext::typeDefinitionsList() {
  return getRuleContext<ADAParser::TypeDefinitionsListContext>(0);
}


size_t ADAParser::TypesPartContext::getRuleIndex() const {
  return ADAParser::RuleTypesPart;
}


antlrcpp::Any ADAParser::TypesPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitTypesPart(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::TypesPartContext* ADAParser::typesPart() {
  TypesPartContext *_localctx = _tracker.createInstance<TypesPartContext>(_ctx, getState());
  enterRule(_localctx, 24, ADAParser::RuleTypesPart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
    match(ADAParser::TYPE);
    setState(263);
    typeDefinitionsList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDefinitionsListContext ------------------------------------------------------------------

ADAParser::TypeDefinitionsListContext::TypeDefinitionsListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ADAParser::TypeDefinitionContext *> ADAParser::TypeDefinitionsListContext::typeDefinition() {
  return getRuleContexts<ADAParser::TypeDefinitionContext>();
}

ADAParser::TypeDefinitionContext* ADAParser::TypeDefinitionsListContext::typeDefinition(size_t i) {
  return getRuleContext<ADAParser::TypeDefinitionContext>(i);
}


size_t ADAParser::TypeDefinitionsListContext::getRuleIndex() const {
  return ADAParser::RuleTypeDefinitionsList;
}


antlrcpp::Any ADAParser::TypeDefinitionsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitTypeDefinitionsList(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::TypeDefinitionsListContext* ADAParser::typeDefinitionsList() {
  TypeDefinitionsListContext *_localctx = _tracker.createInstance<TypeDefinitionsListContext>(_ctx, getState());
  enterRule(_localctx, 26, ADAParser::RuleTypeDefinitionsList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(265);
    typeDefinition();
    setState(270);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(266);
        match(ADAParser::T__0);
        setState(267);
        typeDefinition(); 
      }
      setState(272);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDefinitionContext ------------------------------------------------------------------

ADAParser::TypeDefinitionContext::TypeDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::TypeIdentifierContext* ADAParser::TypeDefinitionContext::typeIdentifier() {
  return getRuleContext<ADAParser::TypeIdentifierContext>(0);
}

ADAParser::TypeSpecificationContext* ADAParser::TypeDefinitionContext::typeSpecification() {
  return getRuleContext<ADAParser::TypeSpecificationContext>(0);
}


size_t ADAParser::TypeDefinitionContext::getRuleIndex() const {
  return ADAParser::RuleTypeDefinition;
}


antlrcpp::Any ADAParser::TypeDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitTypeDefinition(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::TypeDefinitionContext* ADAParser::typeDefinition() {
  TypeDefinitionContext *_localctx = _tracker.createInstance<TypeDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 28, ADAParser::RuleTypeDefinition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(273);
    typeIdentifier();
    setState(274);
    match(ADAParser::T__1);
    setState(275);
    typeSpecification();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeIdentifierContext ------------------------------------------------------------------

ADAParser::TypeIdentifierContext::TypeIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::TypeIdentifierContext::IDENTIFIER() {
  return getToken(ADAParser::IDENTIFIER, 0);
}


size_t ADAParser::TypeIdentifierContext::getRuleIndex() const {
  return ADAParser::RuleTypeIdentifier;
}


antlrcpp::Any ADAParser::TypeIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitTypeIdentifier(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::TypeIdentifierContext* ADAParser::typeIdentifier() {
  TypeIdentifierContext *_localctx = _tracker.createInstance<TypeIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 30, ADAParser::RuleTypeIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(277);
    match(ADAParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeSpecificationContext ------------------------------------------------------------------

ADAParser::TypeSpecificationContext::TypeSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ADAParser::TypeSpecificationContext::getRuleIndex() const {
  return ADAParser::RuleTypeSpecification;
}

void ADAParser::TypeSpecificationContext::copyFrom(TypeSpecificationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- SimpleTypespecContext ------------------------------------------------------------------

ADAParser::SimpleTypeContext* ADAParser::SimpleTypespecContext::simpleType() {
  return getRuleContext<ADAParser::SimpleTypeContext>(0);
}

ADAParser::SimpleTypespecContext::SimpleTypespecContext(TypeSpecificationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ADAParser::SimpleTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitSimpleTypespec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayTypespecContext ------------------------------------------------------------------

ADAParser::ArrayTypeContext* ADAParser::ArrayTypespecContext::arrayType() {
  return getRuleContext<ADAParser::ArrayTypeContext>(0);
}

ADAParser::ArrayTypespecContext::ArrayTypespecContext(TypeSpecificationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ADAParser::ArrayTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitArrayTypespec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RecordTypespecContext ------------------------------------------------------------------

ADAParser::RecordTypeContext* ADAParser::RecordTypespecContext::recordType() {
  return getRuleContext<ADAParser::RecordTypeContext>(0);
}

ADAParser::RecordTypespecContext::RecordTypespecContext(TypeSpecificationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ADAParser::RecordTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitRecordTypespec(this);
  else
    return visitor->visitChildren(this);
}
ADAParser::TypeSpecificationContext* ADAParser::typeSpecification() {
  TypeSpecificationContext *_localctx = _tracker.createInstance<TypeSpecificationContext>(_ctx, getState());
  enterRule(_localctx, 32, ADAParser::RuleTypeSpecification);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(282);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ADAParser::T__2:
      case ADAParser::T__3:
      case ADAParser::T__4:
      case ADAParser::IDENTIFIER:
      case ADAParser::INTEGER:
      case ADAParser::REAL:
      case ADAParser::CHARACTER:
      case ADAParser::STRING: {
        _localctx = dynamic_cast<TypeSpecificationContext *>(_tracker.createInstance<ADAParser::SimpleTypespecContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(279);
        simpleType();
        break;
      }

      case ADAParser::ARRAY: {
        _localctx = dynamic_cast<TypeSpecificationContext *>(_tracker.createInstance<ADAParser::ArrayTypespecContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(280);
        arrayType();
        break;
      }

      case ADAParser::RECORD: {
        _localctx = dynamic_cast<TypeSpecificationContext *>(_tracker.createInstance<ADAParser::RecordTypespecContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(281);
        recordType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleTypeContext ------------------------------------------------------------------

ADAParser::SimpleTypeContext::SimpleTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ADAParser::SimpleTypeContext::getRuleIndex() const {
  return ADAParser::RuleSimpleType;
}

void ADAParser::SimpleTypeContext::copyFrom(SimpleTypeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- SubrangeTypespecContext ------------------------------------------------------------------

ADAParser::SubrangeTypeContext* ADAParser::SubrangeTypespecContext::subrangeType() {
  return getRuleContext<ADAParser::SubrangeTypeContext>(0);
}

ADAParser::SubrangeTypespecContext::SubrangeTypespecContext(SimpleTypeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ADAParser::SubrangeTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitSubrangeTypespec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EnumerationTypespecContext ------------------------------------------------------------------

ADAParser::EnumerationTypeContext* ADAParser::EnumerationTypespecContext::enumerationType() {
  return getRuleContext<ADAParser::EnumerationTypeContext>(0);
}

ADAParser::EnumerationTypespecContext::EnumerationTypespecContext(SimpleTypeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ADAParser::EnumerationTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitEnumerationTypespec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeIdentifierTypespecContext ------------------------------------------------------------------

ADAParser::TypeIdentifierContext* ADAParser::TypeIdentifierTypespecContext::typeIdentifier() {
  return getRuleContext<ADAParser::TypeIdentifierContext>(0);
}

ADAParser::TypeIdentifierTypespecContext::TypeIdentifierTypespecContext(SimpleTypeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ADAParser::TypeIdentifierTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitTypeIdentifierTypespec(this);
  else
    return visitor->visitChildren(this);
}
ADAParser::SimpleTypeContext* ADAParser::simpleType() {
  SimpleTypeContext *_localctx = _tracker.createInstance<SimpleTypeContext>(_ctx, getState());
  enterRule(_localctx, 34, ADAParser::RuleSimpleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(287);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<SimpleTypeContext *>(_tracker.createInstance<ADAParser::TypeIdentifierTypespecContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(284);
      typeIdentifier();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<SimpleTypeContext *>(_tracker.createInstance<ADAParser::EnumerationTypespecContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(285);
      enumerationType();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<SimpleTypeContext *>(_tracker.createInstance<ADAParser::SubrangeTypespecContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(286);
      subrangeType();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumerationTypeContext ------------------------------------------------------------------

ADAParser::EnumerationTypeContext::EnumerationTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ADAParser::EnumerationConstantContext *> ADAParser::EnumerationTypeContext::enumerationConstant() {
  return getRuleContexts<ADAParser::EnumerationConstantContext>();
}

ADAParser::EnumerationConstantContext* ADAParser::EnumerationTypeContext::enumerationConstant(size_t i) {
  return getRuleContext<ADAParser::EnumerationConstantContext>(i);
}


size_t ADAParser::EnumerationTypeContext::getRuleIndex() const {
  return ADAParser::RuleEnumerationType;
}


antlrcpp::Any ADAParser::EnumerationTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitEnumerationType(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::EnumerationTypeContext* ADAParser::enumerationType() {
  EnumerationTypeContext *_localctx = _tracker.createInstance<EnumerationTypeContext>(_ctx, getState());
  enterRule(_localctx, 36, ADAParser::RuleEnumerationType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(289);
    match(ADAParser::T__4);
    setState(290);
    enumerationConstant();
    setState(295);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ADAParser::T__5) {
      setState(291);
      match(ADAParser::T__5);
      setState(292);
      enumerationConstant();
      setState(297);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(298);
    match(ADAParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumerationConstantContext ------------------------------------------------------------------

ADAParser::EnumerationConstantContext::EnumerationConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::ConstantIdentifierContext* ADAParser::EnumerationConstantContext::constantIdentifier() {
  return getRuleContext<ADAParser::ConstantIdentifierContext>(0);
}


size_t ADAParser::EnumerationConstantContext::getRuleIndex() const {
  return ADAParser::RuleEnumerationConstant;
}


antlrcpp::Any ADAParser::EnumerationConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitEnumerationConstant(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::EnumerationConstantContext* ADAParser::enumerationConstant() {
  EnumerationConstantContext *_localctx = _tracker.createInstance<EnumerationConstantContext>(_ctx, getState());
  enterRule(_localctx, 38, ADAParser::RuleEnumerationConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(300);
    constantIdentifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubrangeTypeContext ------------------------------------------------------------------

ADAParser::SubrangeTypeContext::SubrangeTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ADAParser::ConstantContext *> ADAParser::SubrangeTypeContext::constant() {
  return getRuleContexts<ADAParser::ConstantContext>();
}

ADAParser::ConstantContext* ADAParser::SubrangeTypeContext::constant(size_t i) {
  return getRuleContext<ADAParser::ConstantContext>(i);
}


size_t ADAParser::SubrangeTypeContext::getRuleIndex() const {
  return ADAParser::RuleSubrangeType;
}


antlrcpp::Any ADAParser::SubrangeTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitSubrangeType(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::SubrangeTypeContext* ADAParser::subrangeType() {
  SubrangeTypeContext *_localctx = _tracker.createInstance<SubrangeTypeContext>(_ctx, getState());
  enterRule(_localctx, 40, ADAParser::RuleSubrangeType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(302);
    constant();
    setState(303);
    match(ADAParser::T__7);
    setState(304);
    constant();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayTypeContext ------------------------------------------------------------------

ADAParser::ArrayTypeContext::ArrayTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::ArrayTypeContext::ARRAY() {
  return getToken(ADAParser::ARRAY, 0);
}

ADAParser::ArrayDimensionListContext* ADAParser::ArrayTypeContext::arrayDimensionList() {
  return getRuleContext<ADAParser::ArrayDimensionListContext>(0);
}

tree::TerminalNode* ADAParser::ArrayTypeContext::OF() {
  return getToken(ADAParser::OF, 0);
}

ADAParser::TypeSpecificationContext* ADAParser::ArrayTypeContext::typeSpecification() {
  return getRuleContext<ADAParser::TypeSpecificationContext>(0);
}


size_t ADAParser::ArrayTypeContext::getRuleIndex() const {
  return ADAParser::RuleArrayType;
}


antlrcpp::Any ADAParser::ArrayTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitArrayType(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ArrayTypeContext* ADAParser::arrayType() {
  ArrayTypeContext *_localctx = _tracker.createInstance<ArrayTypeContext>(_ctx, getState());
  enterRule(_localctx, 42, ADAParser::RuleArrayType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(306);
    match(ADAParser::ARRAY);
    setState(307);
    match(ADAParser::T__4);
    setState(308);
    arrayDimensionList();
    setState(309);
    match(ADAParser::T__6);
    setState(310);
    match(ADAParser::OF);
    setState(311);
    typeSpecification();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayDimensionListContext ------------------------------------------------------------------

ADAParser::ArrayDimensionListContext::ArrayDimensionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ADAParser::SimpleTypeContext *> ADAParser::ArrayDimensionListContext::simpleType() {
  return getRuleContexts<ADAParser::SimpleTypeContext>();
}

ADAParser::SimpleTypeContext* ADAParser::ArrayDimensionListContext::simpleType(size_t i) {
  return getRuleContext<ADAParser::SimpleTypeContext>(i);
}


size_t ADAParser::ArrayDimensionListContext::getRuleIndex() const {
  return ADAParser::RuleArrayDimensionList;
}


antlrcpp::Any ADAParser::ArrayDimensionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitArrayDimensionList(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ArrayDimensionListContext* ADAParser::arrayDimensionList() {
  ArrayDimensionListContext *_localctx = _tracker.createInstance<ArrayDimensionListContext>(_ctx, getState());
  enterRule(_localctx, 44, ADAParser::RuleArrayDimensionList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(313);
    simpleType();
    setState(318);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ADAParser::T__5) {
      setState(314);
      match(ADAParser::T__5);
      setState(315);
      simpleType();
      setState(320);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RecordTypeContext ------------------------------------------------------------------

ADAParser::RecordTypeContext::RecordTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::RecordTypeContext::RECORD() {
  return getToken(ADAParser::RECORD, 0);
}

ADAParser::RecordFieldsContext* ADAParser::RecordTypeContext::recordFields() {
  return getRuleContext<ADAParser::RecordFieldsContext>(0);
}

tree::TerminalNode* ADAParser::RecordTypeContext::END() {
  return getToken(ADAParser::END, 0);
}


size_t ADAParser::RecordTypeContext::getRuleIndex() const {
  return ADAParser::RuleRecordType;
}


antlrcpp::Any ADAParser::RecordTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitRecordType(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::RecordTypeContext* ADAParser::recordType() {
  RecordTypeContext *_localctx = _tracker.createInstance<RecordTypeContext>(_ctx, getState());
  enterRule(_localctx, 46, ADAParser::RuleRecordType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(321);
    match(ADAParser::RECORD);
    setState(322);
    recordFields();
    setState(324);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ADAParser::T__0) {
      setState(323);
      match(ADAParser::T__0);
    }
    setState(326);
    match(ADAParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RecordFieldsContext ------------------------------------------------------------------

ADAParser::RecordFieldsContext::RecordFieldsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::VariableDeclarationsListContext* ADAParser::RecordFieldsContext::variableDeclarationsList() {
  return getRuleContext<ADAParser::VariableDeclarationsListContext>(0);
}


size_t ADAParser::RecordFieldsContext::getRuleIndex() const {
  return ADAParser::RuleRecordFields;
}


antlrcpp::Any ADAParser::RecordFieldsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitRecordFields(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::RecordFieldsContext* ADAParser::recordFields() {
  RecordFieldsContext *_localctx = _tracker.createInstance<RecordFieldsContext>(_ctx, getState());
  enterRule(_localctx, 48, ADAParser::RuleRecordFields);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(328);
    variableDeclarationsList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariablesPartContext ------------------------------------------------------------------

ADAParser::VariablesPartContext::VariablesPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::VariableDeclarationsListContext* ADAParser::VariablesPartContext::variableDeclarationsList() {
  return getRuleContext<ADAParser::VariableDeclarationsListContext>(0);
}


size_t ADAParser::VariablesPartContext::getRuleIndex() const {
  return ADAParser::RuleVariablesPart;
}


antlrcpp::Any ADAParser::VariablesPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitVariablesPart(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::VariablesPartContext* ADAParser::variablesPart() {
  VariablesPartContext *_localctx = _tracker.createInstance<VariablesPartContext>(_ctx, getState());
  enterRule(_localctx, 50, ADAParser::RuleVariablesPart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(330);
    variableDeclarationsList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationsListContext ------------------------------------------------------------------

ADAParser::VariableDeclarationsListContext::VariableDeclarationsListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ADAParser::VariableDeclarationsContext *> ADAParser::VariableDeclarationsListContext::variableDeclarations() {
  return getRuleContexts<ADAParser::VariableDeclarationsContext>();
}

ADAParser::VariableDeclarationsContext* ADAParser::VariableDeclarationsListContext::variableDeclarations(size_t i) {
  return getRuleContext<ADAParser::VariableDeclarationsContext>(i);
}


size_t ADAParser::VariableDeclarationsListContext::getRuleIndex() const {
  return ADAParser::RuleVariableDeclarationsList;
}


antlrcpp::Any ADAParser::VariableDeclarationsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarationsList(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::VariableDeclarationsListContext* ADAParser::variableDeclarationsList() {
  VariableDeclarationsListContext *_localctx = _tracker.createInstance<VariableDeclarationsListContext>(_ctx, getState());
  enterRule(_localctx, 52, ADAParser::RuleVariableDeclarationsList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(332);
    variableDeclarations();
    setState(337);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(333);
        match(ADAParser::T__0);
        setState(334);
        variableDeclarations(); 
      }
      setState(339);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationsContext ------------------------------------------------------------------

ADAParser::VariableDeclarationsContext::VariableDeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::VariableIdentifierListContext* ADAParser::VariableDeclarationsContext::variableIdentifierList() {
  return getRuleContext<ADAParser::VariableIdentifierListContext>(0);
}

ADAParser::TypeSpecificationContext* ADAParser::VariableDeclarationsContext::typeSpecification() {
  return getRuleContext<ADAParser::TypeSpecificationContext>(0);
}

ADAParser::ExpressionContext* ADAParser::VariableDeclarationsContext::expression() {
  return getRuleContext<ADAParser::ExpressionContext>(0);
}


size_t ADAParser::VariableDeclarationsContext::getRuleIndex() const {
  return ADAParser::RuleVariableDeclarations;
}


antlrcpp::Any ADAParser::VariableDeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarations(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::VariableDeclarationsContext* ADAParser::variableDeclarations() {
  VariableDeclarationsContext *_localctx = _tracker.createInstance<VariableDeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 54, ADAParser::RuleVariableDeclarations);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(340);
    variableIdentifierList();
    setState(341);
    match(ADAParser::T__8);
    setState(342);
    typeSpecification();
    setState(345);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ADAParser::T__9) {
      setState(343);
      match(ADAParser::T__9);
      setState(344);
      expression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableIdentifierListContext ------------------------------------------------------------------

ADAParser::VariableIdentifierListContext::VariableIdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ADAParser::VariableIdentifierContext *> ADAParser::VariableIdentifierListContext::variableIdentifier() {
  return getRuleContexts<ADAParser::VariableIdentifierContext>();
}

ADAParser::VariableIdentifierContext* ADAParser::VariableIdentifierListContext::variableIdentifier(size_t i) {
  return getRuleContext<ADAParser::VariableIdentifierContext>(i);
}


size_t ADAParser::VariableIdentifierListContext::getRuleIndex() const {
  return ADAParser::RuleVariableIdentifierList;
}


antlrcpp::Any ADAParser::VariableIdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitVariableIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::VariableIdentifierListContext* ADAParser::variableIdentifierList() {
  VariableIdentifierListContext *_localctx = _tracker.createInstance<VariableIdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 56, ADAParser::RuleVariableIdentifierList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(347);
    variableIdentifier();
    setState(352);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ADAParser::T__5) {
      setState(348);
      match(ADAParser::T__5);
      setState(349);
      variableIdentifier();
      setState(354);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableIdentifierContext ------------------------------------------------------------------

ADAParser::VariableIdentifierContext::VariableIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::VariableIdentifierContext::IDENTIFIER() {
  return getToken(ADAParser::IDENTIFIER, 0);
}


size_t ADAParser::VariableIdentifierContext::getRuleIndex() const {
  return ADAParser::RuleVariableIdentifier;
}


antlrcpp::Any ADAParser::VariableIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitVariableIdentifier(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::VariableIdentifierContext* ADAParser::variableIdentifier() {
  VariableIdentifierContext *_localctx = _tracker.createInstance<VariableIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 58, ADAParser::RuleVariableIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(355);
    match(ADAParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubprogramPartContext ------------------------------------------------------------------

ADAParser::SubprogramPartContext::SubprogramPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ADAParser::SubprogramBodyContext *> ADAParser::SubprogramPartContext::subprogramBody() {
  return getRuleContexts<ADAParser::SubprogramBodyContext>();
}

ADAParser::SubprogramBodyContext* ADAParser::SubprogramPartContext::subprogramBody(size_t i) {
  return getRuleContext<ADAParser::SubprogramBodyContext>(i);
}


size_t ADAParser::SubprogramPartContext::getRuleIndex() const {
  return ADAParser::RuleSubprogramPart;
}


antlrcpp::Any ADAParser::SubprogramPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitSubprogramPart(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::SubprogramPartContext* ADAParser::subprogramPart() {
  SubprogramPartContext *_localctx = _tracker.createInstance<SubprogramPartContext>(_ctx, getState());
  enterRule(_localctx, 60, ADAParser::RuleSubprogramPart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(357);
    subprogramBody();
    setState(362);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(358);
        match(ADAParser::T__0);
        setState(359);
        subprogramBody(); 
      }
      setState(364);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubprogramBodyContext ------------------------------------------------------------------

ADAParser::SubprogramBodyContext::SubprogramBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::SubprogramBodyContext::IS() {
  return getToken(ADAParser::IS, 0);
}

ADAParser::BlockContext* ADAParser::SubprogramBodyContext::block() {
  return getRuleContext<ADAParser::BlockContext>(0);
}

ADAParser::ProcedureHeadContext* ADAParser::SubprogramBodyContext::procedureHead() {
  return getRuleContext<ADAParser::ProcedureHeadContext>(0);
}

ADAParser::FunctionHeadContext* ADAParser::SubprogramBodyContext::functionHead() {
  return getRuleContext<ADAParser::FunctionHeadContext>(0);
}

ADAParser::RoutineIdentifierContext* ADAParser::SubprogramBodyContext::routineIdentifier() {
  return getRuleContext<ADAParser::RoutineIdentifierContext>(0);
}


size_t ADAParser::SubprogramBodyContext::getRuleIndex() const {
  return ADAParser::RuleSubprogramBody;
}


antlrcpp::Any ADAParser::SubprogramBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitSubprogramBody(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::SubprogramBodyContext* ADAParser::subprogramBody() {
  SubprogramBodyContext *_localctx = _tracker.createInstance<SubprogramBodyContext>(_ctx, getState());
  enterRule(_localctx, 62, ADAParser::RuleSubprogramBody);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(367);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ADAParser::PROCEDURE: {
        setState(365);
        procedureHead();
        break;
      }

      case ADAParser::FUNCTION: {
        setState(366);
        functionHead();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(369);
    match(ADAParser::IS);
    setState(370);
    block();
    setState(372);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ADAParser::IDENTIFIER) {
      setState(371);
      routineIdentifier();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureHeadContext ------------------------------------------------------------------

ADAParser::ProcedureHeadContext::ProcedureHeadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::ProcedureHeadContext::PROCEDURE() {
  return getToken(ADAParser::PROCEDURE, 0);
}

ADAParser::RoutineIdentifierContext* ADAParser::ProcedureHeadContext::routineIdentifier() {
  return getRuleContext<ADAParser::RoutineIdentifierContext>(0);
}

ADAParser::ParametersContext* ADAParser::ProcedureHeadContext::parameters() {
  return getRuleContext<ADAParser::ParametersContext>(0);
}


size_t ADAParser::ProcedureHeadContext::getRuleIndex() const {
  return ADAParser::RuleProcedureHead;
}


antlrcpp::Any ADAParser::ProcedureHeadContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitProcedureHead(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ProcedureHeadContext* ADAParser::procedureHead() {
  ProcedureHeadContext *_localctx = _tracker.createInstance<ProcedureHeadContext>(_ctx, getState());
  enterRule(_localctx, 64, ADAParser::RuleProcedureHead);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(374);
    match(ADAParser::PROCEDURE);
    setState(375);
    routineIdentifier();
    setState(377);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ADAParser::T__4) {
      setState(376);
      parameters();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionHeadContext ------------------------------------------------------------------

ADAParser::FunctionHeadContext::FunctionHeadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::FunctionHeadContext::FUNCTION() {
  return getToken(ADAParser::FUNCTION, 0);
}

ADAParser::RoutineIdentifierContext* ADAParser::FunctionHeadContext::routineIdentifier() {
  return getRuleContext<ADAParser::RoutineIdentifierContext>(0);
}

tree::TerminalNode* ADAParser::FunctionHeadContext::RETURN() {
  return getToken(ADAParser::RETURN, 0);
}

ADAParser::TypeIdentifierContext* ADAParser::FunctionHeadContext::typeIdentifier() {
  return getRuleContext<ADAParser::TypeIdentifierContext>(0);
}

ADAParser::ParametersContext* ADAParser::FunctionHeadContext::parameters() {
  return getRuleContext<ADAParser::ParametersContext>(0);
}


size_t ADAParser::FunctionHeadContext::getRuleIndex() const {
  return ADAParser::RuleFunctionHead;
}


antlrcpp::Any ADAParser::FunctionHeadContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitFunctionHead(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::FunctionHeadContext* ADAParser::functionHead() {
  FunctionHeadContext *_localctx = _tracker.createInstance<FunctionHeadContext>(_ctx, getState());
  enterRule(_localctx, 66, ADAParser::RuleFunctionHead);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(379);
    match(ADAParser::FUNCTION);
    setState(380);
    routineIdentifier();
    setState(382);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ADAParser::T__4) {
      setState(381);
      parameters();
    }
    setState(384);
    match(ADAParser::RETURN);
    setState(385);
    typeIdentifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RoutineIdentifierContext ------------------------------------------------------------------

ADAParser::RoutineIdentifierContext::RoutineIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::RoutineIdentifierContext::IDENTIFIER() {
  return getToken(ADAParser::IDENTIFIER, 0);
}


size_t ADAParser::RoutineIdentifierContext::getRuleIndex() const {
  return ADAParser::RuleRoutineIdentifier;
}


antlrcpp::Any ADAParser::RoutineIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitRoutineIdentifier(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::RoutineIdentifierContext* ADAParser::routineIdentifier() {
  RoutineIdentifierContext *_localctx = _tracker.createInstance<RoutineIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 68, ADAParser::RuleRoutineIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(387);
    match(ADAParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

ADAParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::ParameterDeclarationsListContext* ADAParser::ParametersContext::parameterDeclarationsList() {
  return getRuleContext<ADAParser::ParameterDeclarationsListContext>(0);
}


size_t ADAParser::ParametersContext::getRuleIndex() const {
  return ADAParser::RuleParameters;
}


antlrcpp::Any ADAParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ParametersContext* ADAParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 70, ADAParser::RuleParameters);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(389);
    match(ADAParser::T__4);
    setState(390);
    parameterDeclarationsList();
    setState(391);
    match(ADAParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterDeclarationsListContext ------------------------------------------------------------------

ADAParser::ParameterDeclarationsListContext::ParameterDeclarationsListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ADAParser::ParameterDeclarationsContext *> ADAParser::ParameterDeclarationsListContext::parameterDeclarations() {
  return getRuleContexts<ADAParser::ParameterDeclarationsContext>();
}

ADAParser::ParameterDeclarationsContext* ADAParser::ParameterDeclarationsListContext::parameterDeclarations(size_t i) {
  return getRuleContext<ADAParser::ParameterDeclarationsContext>(i);
}


size_t ADAParser::ParameterDeclarationsListContext::getRuleIndex() const {
  return ADAParser::RuleParameterDeclarationsList;
}


antlrcpp::Any ADAParser::ParameterDeclarationsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitParameterDeclarationsList(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ParameterDeclarationsListContext* ADAParser::parameterDeclarationsList() {
  ParameterDeclarationsListContext *_localctx = _tracker.createInstance<ParameterDeclarationsListContext>(_ctx, getState());
  enterRule(_localctx, 72, ADAParser::RuleParameterDeclarationsList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(393);
    parameterDeclarations();
    setState(398);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ADAParser::T__0) {
      setState(394);
      match(ADAParser::T__0);
      setState(395);
      parameterDeclarations();
      setState(400);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterDeclarationsContext ------------------------------------------------------------------

ADAParser::ParameterDeclarationsContext::ParameterDeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::ParameterIdentifierListContext* ADAParser::ParameterDeclarationsContext::parameterIdentifierList() {
  return getRuleContext<ADAParser::ParameterIdentifierListContext>(0);
}

ADAParser::TypeIdentifierContext* ADAParser::ParameterDeclarationsContext::typeIdentifier() {
  return getRuleContext<ADAParser::TypeIdentifierContext>(0);
}

tree::TerminalNode* ADAParser::ParameterDeclarationsContext::IN() {
  return getToken(ADAParser::IN, 0);
}

tree::TerminalNode* ADAParser::ParameterDeclarationsContext::OUT() {
  return getToken(ADAParser::OUT, 0);
}


size_t ADAParser::ParameterDeclarationsContext::getRuleIndex() const {
  return ADAParser::RuleParameterDeclarations;
}


antlrcpp::Any ADAParser::ParameterDeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitParameterDeclarations(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ParameterDeclarationsContext* ADAParser::parameterDeclarations() {
  ParameterDeclarationsContext *_localctx = _tracker.createInstance<ParameterDeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 74, ADAParser::RuleParameterDeclarations);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(401);
    parameterIdentifierList();
    setState(402);
    match(ADAParser::T__8);
    setState(407);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      setState(403);
      match(ADAParser::IN);
      break;
    }

    case 2: {
      setState(404);
      match(ADAParser::IN);
      setState(405);
      match(ADAParser::OUT);
      break;
    }

    case 3: {
      setState(406);
      match(ADAParser::OUT);
      break;
    }

    default:
      break;
    }
    setState(409);
    typeIdentifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterIdentifierListContext ------------------------------------------------------------------

ADAParser::ParameterIdentifierListContext::ParameterIdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ADAParser::ParameterIdentifierContext *> ADAParser::ParameterIdentifierListContext::parameterIdentifier() {
  return getRuleContexts<ADAParser::ParameterIdentifierContext>();
}

ADAParser::ParameterIdentifierContext* ADAParser::ParameterIdentifierListContext::parameterIdentifier(size_t i) {
  return getRuleContext<ADAParser::ParameterIdentifierContext>(i);
}


size_t ADAParser::ParameterIdentifierListContext::getRuleIndex() const {
  return ADAParser::RuleParameterIdentifierList;
}


antlrcpp::Any ADAParser::ParameterIdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitParameterIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ParameterIdentifierListContext* ADAParser::parameterIdentifierList() {
  ParameterIdentifierListContext *_localctx = _tracker.createInstance<ParameterIdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 76, ADAParser::RuleParameterIdentifierList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(411);
    parameterIdentifier();
    setState(416);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ADAParser::T__5) {
      setState(412);
      match(ADAParser::T__5);
      setState(413);
      parameterIdentifier();
      setState(418);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterIdentifierContext ------------------------------------------------------------------

ADAParser::ParameterIdentifierContext::ParameterIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::ParameterIdentifierContext::IDENTIFIER() {
  return getToken(ADAParser::IDENTIFIER, 0);
}


size_t ADAParser::ParameterIdentifierContext::getRuleIndex() const {
  return ADAParser::RuleParameterIdentifier;
}


antlrcpp::Any ADAParser::ParameterIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitParameterIdentifier(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ParameterIdentifierContext* ADAParser::parameterIdentifier() {
  ParameterIdentifierContext *_localctx = _tracker.createInstance<ParameterIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 78, ADAParser::RuleParameterIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(419);
    match(ADAParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

ADAParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::CompoundStatementContext* ADAParser::StatementContext::compoundStatement() {
  return getRuleContext<ADAParser::CompoundStatementContext>(0);
}

ADAParser::AssignmentStatementContext* ADAParser::StatementContext::assignmentStatement() {
  return getRuleContext<ADAParser::AssignmentStatementContext>(0);
}

ADAParser::IfStatementContext* ADAParser::StatementContext::ifStatement() {
  return getRuleContext<ADAParser::IfStatementContext>(0);
}

ADAParser::CaseStatementContext* ADAParser::StatementContext::caseStatement() {
  return getRuleContext<ADAParser::CaseStatementContext>(0);
}

ADAParser::LoopStatementContext* ADAParser::StatementContext::loopStatement() {
  return getRuleContext<ADAParser::LoopStatementContext>(0);
}

ADAParser::ExitStatementContext* ADAParser::StatementContext::exitStatement() {
  return getRuleContext<ADAParser::ExitStatementContext>(0);
}

ADAParser::PutStatementContext* ADAParser::StatementContext::putStatement() {
  return getRuleContext<ADAParser::PutStatementContext>(0);
}

ADAParser::PutLineStatementContext* ADAParser::StatementContext::putLineStatement() {
  return getRuleContext<ADAParser::PutLineStatementContext>(0);
}

ADAParser::GetStatementContext* ADAParser::StatementContext::getStatement() {
  return getRuleContext<ADAParser::GetStatementContext>(0);
}

ADAParser::GetLineStatementContext* ADAParser::StatementContext::getLineStatement() {
  return getRuleContext<ADAParser::GetLineStatementContext>(0);
}

ADAParser::ProcedureCallStatementContext* ADAParser::StatementContext::procedureCallStatement() {
  return getRuleContext<ADAParser::ProcedureCallStatementContext>(0);
}

ADAParser::ReturnStatementContext* ADAParser::StatementContext::returnStatement() {
  return getRuleContext<ADAParser::ReturnStatementContext>(0);
}

ADAParser::EmptyStatementContext* ADAParser::StatementContext::emptyStatement() {
  return getRuleContext<ADAParser::EmptyStatementContext>(0);
}

ADAParser::NewLineStatementContext* ADAParser::StatementContext::newLineStatement() {
  return getRuleContext<ADAParser::NewLineStatementContext>(0);
}


size_t ADAParser::StatementContext::getRuleIndex() const {
  return ADAParser::RuleStatement;
}


antlrcpp::Any ADAParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::StatementContext* ADAParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 80, ADAParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(435);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(421);
      compoundStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(422);
      assignmentStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(423);
      ifStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(424);
      caseStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(425);
      loopStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(426);
      exitStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(427);
      putStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(428);
      putLineStatement();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(429);
      getStatement();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(430);
      getLineStatement();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(431);
      procedureCallStatement();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(432);
      returnStatement();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(433);
      emptyStatement();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(434);
      newLineStatement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompoundStatementContext ------------------------------------------------------------------

ADAParser::CompoundStatementContext::CompoundStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::CompoundStatementContext::BEGIN() {
  return getToken(ADAParser::BEGIN, 0);
}

ADAParser::StatementListContext* ADAParser::CompoundStatementContext::statementList() {
  return getRuleContext<ADAParser::StatementListContext>(0);
}

tree::TerminalNode* ADAParser::CompoundStatementContext::END() {
  return getToken(ADAParser::END, 0);
}


size_t ADAParser::CompoundStatementContext::getRuleIndex() const {
  return ADAParser::RuleCompoundStatement;
}


antlrcpp::Any ADAParser::CompoundStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitCompoundStatement(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::CompoundStatementContext* ADAParser::compoundStatement() {
  CompoundStatementContext *_localctx = _tracker.createInstance<CompoundStatementContext>(_ctx, getState());
  enterRule(_localctx, 82, ADAParser::RuleCompoundStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(437);
    match(ADAParser::BEGIN);
    setState(438);
    statementList();
    setState(439);
    match(ADAParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EmptyStatementContext ------------------------------------------------------------------

ADAParser::EmptyStatementContext::EmptyStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ADAParser::EmptyStatementContext::getRuleIndex() const {
  return ADAParser::RuleEmptyStatement;
}


antlrcpp::Any ADAParser::EmptyStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitEmptyStatement(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::EmptyStatementContext* ADAParser::emptyStatement() {
  EmptyStatementContext *_localctx = _tracker.createInstance<EmptyStatementContext>(_ctx, getState());
  enterRule(_localctx, 84, ADAParser::RuleEmptyStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementListContext ------------------------------------------------------------------

ADAParser::StatementListContext::StatementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ADAParser::StatementContext *> ADAParser::StatementListContext::statement() {
  return getRuleContexts<ADAParser::StatementContext>();
}

ADAParser::StatementContext* ADAParser::StatementListContext::statement(size_t i) {
  return getRuleContext<ADAParser::StatementContext>(i);
}


size_t ADAParser::StatementListContext::getRuleIndex() const {
  return ADAParser::RuleStatementList;
}


antlrcpp::Any ADAParser::StatementListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitStatementList(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::StatementListContext* ADAParser::statementList() {
  StatementListContext *_localctx = _tracker.createInstance<StatementListContext>(_ctx, getState());
  enterRule(_localctx, 86, ADAParser::RuleStatementList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(443);
    statement();
    setState(448);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(444);
        match(ADAParser::T__0);
        setState(445);
        statement(); 
      }
      setState(450);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentStatementContext ------------------------------------------------------------------

ADAParser::AssignmentStatementContext::AssignmentStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::LhsContext* ADAParser::AssignmentStatementContext::lhs() {
  return getRuleContext<ADAParser::LhsContext>(0);
}

ADAParser::RhsContext* ADAParser::AssignmentStatementContext::rhs() {
  return getRuleContext<ADAParser::RhsContext>(0);
}


size_t ADAParser::AssignmentStatementContext::getRuleIndex() const {
  return ADAParser::RuleAssignmentStatement;
}


antlrcpp::Any ADAParser::AssignmentStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitAssignmentStatement(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::AssignmentStatementContext* ADAParser::assignmentStatement() {
  AssignmentStatementContext *_localctx = _tracker.createInstance<AssignmentStatementContext>(_ctx, getState());
  enterRule(_localctx, 88, ADAParser::RuleAssignmentStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(451);
    lhs();
    setState(452);
    match(ADAParser::T__9);
    setState(453);
    rhs();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

ADAParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::ReturnStatementContext::RETURN() {
  return getToken(ADAParser::RETURN, 0);
}

ADAParser::ExpressionContext* ADAParser::ReturnStatementContext::expression() {
  return getRuleContext<ADAParser::ExpressionContext>(0);
}


size_t ADAParser::ReturnStatementContext::getRuleIndex() const {
  return ADAParser::RuleReturnStatement;
}


antlrcpp::Any ADAParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ReturnStatementContext* ADAParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 90, ADAParser::RuleReturnStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(455);
    match(ADAParser::RETURN);
    setState(456);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LhsContext ------------------------------------------------------------------

ADAParser::LhsContext::LhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::VariableContext* ADAParser::LhsContext::variable() {
  return getRuleContext<ADAParser::VariableContext>(0);
}


size_t ADAParser::LhsContext::getRuleIndex() const {
  return ADAParser::RuleLhs;
}


antlrcpp::Any ADAParser::LhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitLhs(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::LhsContext* ADAParser::lhs() {
  LhsContext *_localctx = _tracker.createInstance<LhsContext>(_ctx, getState());
  enterRule(_localctx, 92, ADAParser::RuleLhs);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(458);
    variable();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RhsContext ------------------------------------------------------------------

ADAParser::RhsContext::RhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::ExpressionContext* ADAParser::RhsContext::expression() {
  return getRuleContext<ADAParser::ExpressionContext>(0);
}


size_t ADAParser::RhsContext::getRuleIndex() const {
  return ADAParser::RuleRhs;
}


antlrcpp::Any ADAParser::RhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitRhs(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::RhsContext* ADAParser::rhs() {
  RhsContext *_localctx = _tracker.createInstance<RhsContext>(_ctx, getState());
  enterRule(_localctx, 94, ADAParser::RuleRhs);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(460);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NewLineStatementContext ------------------------------------------------------------------

ADAParser::NewLineStatementContext::NewLineStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::NewLineStatementContext::NEWLINE() {
  return getToken(ADAParser::NEWLINE, 0);
}


size_t ADAParser::NewLineStatementContext::getRuleIndex() const {
  return ADAParser::RuleNewLineStatement;
}


antlrcpp::Any ADAParser::NewLineStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitNewLineStatement(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::NewLineStatementContext* ADAParser::newLineStatement() {
  NewLineStatementContext *_localctx = _tracker.createInstance<NewLineStatementContext>(_ctx, getState());
  enterRule(_localctx, 96, ADAParser::RuleNewLineStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(462);
    match(ADAParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

ADAParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ADAParser::IfStatementContext::IF() {
  return getTokens(ADAParser::IF);
}

tree::TerminalNode* ADAParser::IfStatementContext::IF(size_t i) {
  return getToken(ADAParser::IF, i);
}

ADAParser::IfConditionContext* ADAParser::IfStatementContext::ifCondition() {
  return getRuleContext<ADAParser::IfConditionContext>(0);
}

std::vector<tree::TerminalNode *> ADAParser::IfStatementContext::THEN() {
  return getTokens(ADAParser::THEN);
}

tree::TerminalNode* ADAParser::IfStatementContext::THEN(size_t i) {
  return getToken(ADAParser::THEN, i);
}

ADAParser::TrueStatementListContext* ADAParser::IfStatementContext::trueStatementList() {
  return getRuleContext<ADAParser::TrueStatementListContext>(0);
}

tree::TerminalNode* ADAParser::IfStatementContext::END() {
  return getToken(ADAParser::END, 0);
}

tree::TerminalNode* ADAParser::IfStatementContext::ELSE() {
  return getToken(ADAParser::ELSE, 0);
}

ADAParser::FalseStatementListContext* ADAParser::IfStatementContext::falseStatementList() {
  return getRuleContext<ADAParser::FalseStatementListContext>(0);
}

std::vector<tree::TerminalNode *> ADAParser::IfStatementContext::ELSIF() {
  return getTokens(ADAParser::ELSIF);
}

tree::TerminalNode* ADAParser::IfStatementContext::ELSIF(size_t i) {
  return getToken(ADAParser::ELSIF, i);
}

std::vector<ADAParser::ElsifConditionContext *> ADAParser::IfStatementContext::elsifCondition() {
  return getRuleContexts<ADAParser::ElsifConditionContext>();
}

ADAParser::ElsifConditionContext* ADAParser::IfStatementContext::elsifCondition(size_t i) {
  return getRuleContext<ADAParser::ElsifConditionContext>(i);
}

std::vector<ADAParser::ElseStatementListContext *> ADAParser::IfStatementContext::elseStatementList() {
  return getRuleContexts<ADAParser::ElseStatementListContext>();
}

ADAParser::ElseStatementListContext* ADAParser::IfStatementContext::elseStatementList(size_t i) {
  return getRuleContext<ADAParser::ElseStatementListContext>(i);
}


size_t ADAParser::IfStatementContext::getRuleIndex() const {
  return ADAParser::RuleIfStatement;
}


antlrcpp::Any ADAParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::IfStatementContext* ADAParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 98, ADAParser::RuleIfStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(464);
    match(ADAParser::IF);
    setState(465);
    ifCondition();
    setState(466);
    match(ADAParser::THEN);
    setState(467);
    trueStatementList();
    setState(468);
    match(ADAParser::T__0);
    setState(480);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      setState(477);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ADAParser::ELSIF) {
        setState(469);
        match(ADAParser::ELSIF);
        setState(470);
        elsifCondition();
        setState(471);
        match(ADAParser::THEN);
        setState(472);
        elseStatementList();
        setState(473);
        match(ADAParser::T__0);
        setState(479);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    default:
      break;
    }
    setState(486);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ADAParser::ELSE) {
      setState(482);
      match(ADAParser::ELSE);
      setState(483);
      falseStatementList();
      setState(484);
      match(ADAParser::T__0);
    }
    setState(488);
    match(ADAParser::END);
    setState(489);
    match(ADAParser::IF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TrueStatementListContext ------------------------------------------------------------------

ADAParser::TrueStatementListContext::TrueStatementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::StatementListContext* ADAParser::TrueStatementListContext::statementList() {
  return getRuleContext<ADAParser::StatementListContext>(0);
}


size_t ADAParser::TrueStatementListContext::getRuleIndex() const {
  return ADAParser::RuleTrueStatementList;
}


antlrcpp::Any ADAParser::TrueStatementListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitTrueStatementList(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::TrueStatementListContext* ADAParser::trueStatementList() {
  TrueStatementListContext *_localctx = _tracker.createInstance<TrueStatementListContext>(_ctx, getState());
  enterRule(_localctx, 100, ADAParser::RuleTrueStatementList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(491);
    statementList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FalseStatementListContext ------------------------------------------------------------------

ADAParser::FalseStatementListContext::FalseStatementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::StatementListContext* ADAParser::FalseStatementListContext::statementList() {
  return getRuleContext<ADAParser::StatementListContext>(0);
}


size_t ADAParser::FalseStatementListContext::getRuleIndex() const {
  return ADAParser::RuleFalseStatementList;
}


antlrcpp::Any ADAParser::FalseStatementListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitFalseStatementList(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::FalseStatementListContext* ADAParser::falseStatementList() {
  FalseStatementListContext *_localctx = _tracker.createInstance<FalseStatementListContext>(_ctx, getState());
  enterRule(_localctx, 102, ADAParser::RuleFalseStatementList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(493);
    statementList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseStatementListContext ------------------------------------------------------------------

ADAParser::ElseStatementListContext::ElseStatementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::StatementListContext* ADAParser::ElseStatementListContext::statementList() {
  return getRuleContext<ADAParser::StatementListContext>(0);
}


size_t ADAParser::ElseStatementListContext::getRuleIndex() const {
  return ADAParser::RuleElseStatementList;
}


antlrcpp::Any ADAParser::ElseStatementListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitElseStatementList(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ElseStatementListContext* ADAParser::elseStatementList() {
  ElseStatementListContext *_localctx = _tracker.createInstance<ElseStatementListContext>(_ctx, getState());
  enterRule(_localctx, 104, ADAParser::RuleElseStatementList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(495);
    statementList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfConditionContext ------------------------------------------------------------------

ADAParser::IfConditionContext::IfConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::ExpressionContext* ADAParser::IfConditionContext::expression() {
  return getRuleContext<ADAParser::ExpressionContext>(0);
}


size_t ADAParser::IfConditionContext::getRuleIndex() const {
  return ADAParser::RuleIfCondition;
}


antlrcpp::Any ADAParser::IfConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitIfCondition(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::IfConditionContext* ADAParser::ifCondition() {
  IfConditionContext *_localctx = _tracker.createInstance<IfConditionContext>(_ctx, getState());
  enterRule(_localctx, 106, ADAParser::RuleIfCondition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(497);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElsifConditionContext ------------------------------------------------------------------

ADAParser::ElsifConditionContext::ElsifConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::ExpressionContext* ADAParser::ElsifConditionContext::expression() {
  return getRuleContext<ADAParser::ExpressionContext>(0);
}


size_t ADAParser::ElsifConditionContext::getRuleIndex() const {
  return ADAParser::RuleElsifCondition;
}


antlrcpp::Any ADAParser::ElsifConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitElsifCondition(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ElsifConditionContext* ADAParser::elsifCondition() {
  ElsifConditionContext *_localctx = _tracker.createInstance<ElsifConditionContext>(_ctx, getState());
  enterRule(_localctx, 108, ADAParser::RuleElsifCondition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(499);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExitStatementContext ------------------------------------------------------------------

ADAParser::ExitStatementContext::ExitStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::ExitStatementContext::EXIT() {
  return getToken(ADAParser::EXIT, 0);
}

tree::TerminalNode* ADAParser::ExitStatementContext::WHEN() {
  return getToken(ADAParser::WHEN, 0);
}

ADAParser::ExpressionContext* ADAParser::ExitStatementContext::expression() {
  return getRuleContext<ADAParser::ExpressionContext>(0);
}


size_t ADAParser::ExitStatementContext::getRuleIndex() const {
  return ADAParser::RuleExitStatement;
}


antlrcpp::Any ADAParser::ExitStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitExitStatement(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ExitStatementContext* ADAParser::exitStatement() {
  ExitStatementContext *_localctx = _tracker.createInstance<ExitStatementContext>(_ctx, getState());
  enterRule(_localctx, 110, ADAParser::RuleExitStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(501);
    match(ADAParser::EXIT);
    setState(504);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ADAParser::WHEN) {
      setState(502);
      match(ADAParser::WHEN);
      setState(503);
      expression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopStatementContext ------------------------------------------------------------------

ADAParser::LoopStatementContext::LoopStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ADAParser::LoopStatementContext::LOOP() {
  return getTokens(ADAParser::LOOP);
}

tree::TerminalNode* ADAParser::LoopStatementContext::LOOP(size_t i) {
  return getToken(ADAParser::LOOP, i);
}

ADAParser::StatementListContext* ADAParser::LoopStatementContext::statementList() {
  return getRuleContext<ADAParser::StatementListContext>(0);
}

tree::TerminalNode* ADAParser::LoopStatementContext::END() {
  return getToken(ADAParser::END, 0);
}

std::vector<ADAParser::StatementIdentifierContext *> ADAParser::LoopStatementContext::statementIdentifier() {
  return getRuleContexts<ADAParser::StatementIdentifierContext>();
}

ADAParser::StatementIdentifierContext* ADAParser::LoopStatementContext::statementIdentifier(size_t i) {
  return getRuleContext<ADAParser::StatementIdentifierContext>(i);
}

ADAParser::WhileStatementContext* ADAParser::LoopStatementContext::whileStatement() {
  return getRuleContext<ADAParser::WhileStatementContext>(0);
}

ADAParser::ForStatementContext* ADAParser::LoopStatementContext::forStatement() {
  return getRuleContext<ADAParser::ForStatementContext>(0);
}


size_t ADAParser::LoopStatementContext::getRuleIndex() const {
  return ADAParser::RuleLoopStatement;
}


antlrcpp::Any ADAParser::LoopStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitLoopStatement(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::LoopStatementContext* ADAParser::loopStatement() {
  LoopStatementContext *_localctx = _tracker.createInstance<LoopStatementContext>(_ctx, getState());
  enterRule(_localctx, 112, ADAParser::RuleLoopStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(509);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ADAParser::IDENTIFIER) {
      setState(506);
      statementIdentifier();
      setState(507);
      match(ADAParser::T__8);
    }
    setState(513);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ADAParser::WHILE: {
        setState(511);
        whileStatement();
        break;
      }

      case ADAParser::FOR: {
        setState(512);
        forStatement();
        break;
      }

      case ADAParser::LOOP: {
        break;
      }

    default:
      break;
    }
    setState(515);
    match(ADAParser::LOOP);
    setState(516);
    statementList();
    setState(517);
    match(ADAParser::END);
    setState(518);
    match(ADAParser::LOOP);
    setState(520);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ADAParser::IDENTIFIER) {
      setState(519);
      statementIdentifier();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseStatementContext ------------------------------------------------------------------

ADAParser::CaseStatementContext::CaseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ADAParser::CaseStatementContext::CASE() {
  return getTokens(ADAParser::CASE);
}

tree::TerminalNode* ADAParser::CaseStatementContext::CASE(size_t i) {
  return getToken(ADAParser::CASE, i);
}

ADAParser::ExpressionContext* ADAParser::CaseStatementContext::expression() {
  return getRuleContext<ADAParser::ExpressionContext>(0);
}

tree::TerminalNode* ADAParser::CaseStatementContext::IS() {
  return getToken(ADAParser::IS, 0);
}

ADAParser::CaseBranchListContext* ADAParser::CaseStatementContext::caseBranchList() {
  return getRuleContext<ADAParser::CaseBranchListContext>(0);
}

tree::TerminalNode* ADAParser::CaseStatementContext::END() {
  return getToken(ADAParser::END, 0);
}


size_t ADAParser::CaseStatementContext::getRuleIndex() const {
  return ADAParser::RuleCaseStatement;
}


antlrcpp::Any ADAParser::CaseStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitCaseStatement(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::CaseStatementContext* ADAParser::caseStatement() {
  CaseStatementContext *_localctx = _tracker.createInstance<CaseStatementContext>(_ctx, getState());
  enterRule(_localctx, 114, ADAParser::RuleCaseStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(522);
    match(ADAParser::CASE);
    setState(523);
    expression();
    setState(524);
    match(ADAParser::IS);
    setState(525);
    caseBranchList();
    setState(526);
    match(ADAParser::T__0);
    setState(527);
    match(ADAParser::END);
    setState(528);
    match(ADAParser::CASE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseBranchListContext ------------------------------------------------------------------

ADAParser::CaseBranchListContext::CaseBranchListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ADAParser::CaseBranchContext *> ADAParser::CaseBranchListContext::caseBranch() {
  return getRuleContexts<ADAParser::CaseBranchContext>();
}

ADAParser::CaseBranchContext* ADAParser::CaseBranchListContext::caseBranch(size_t i) {
  return getRuleContext<ADAParser::CaseBranchContext>(i);
}


size_t ADAParser::CaseBranchListContext::getRuleIndex() const {
  return ADAParser::RuleCaseBranchList;
}


antlrcpp::Any ADAParser::CaseBranchListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitCaseBranchList(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::CaseBranchListContext* ADAParser::caseBranchList() {
  CaseBranchListContext *_localctx = _tracker.createInstance<CaseBranchListContext>(_ctx, getState());
  enterRule(_localctx, 116, ADAParser::RuleCaseBranchList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(530);
    caseBranch();
    setState(535);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(531);
        match(ADAParser::T__0);
        setState(532);
        caseBranch(); 
      }
      setState(537);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseBranchContext ------------------------------------------------------------------

ADAParser::CaseBranchContext::CaseBranchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::CaseBranchContext::WHEN() {
  return getToken(ADAParser::WHEN, 0);
}

ADAParser::CaseConstantListContext* ADAParser::CaseBranchContext::caseConstantList() {
  return getRuleContext<ADAParser::CaseConstantListContext>(0);
}

ADAParser::StatementContext* ADAParser::CaseBranchContext::statement() {
  return getRuleContext<ADAParser::StatementContext>(0);
}


size_t ADAParser::CaseBranchContext::getRuleIndex() const {
  return ADAParser::RuleCaseBranch;
}


antlrcpp::Any ADAParser::CaseBranchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitCaseBranch(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::CaseBranchContext* ADAParser::caseBranch() {
  CaseBranchContext *_localctx = _tracker.createInstance<CaseBranchContext>(_ctx, getState());
  enterRule(_localctx, 118, ADAParser::RuleCaseBranch);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(538);
    match(ADAParser::WHEN);
    setState(539);
    caseConstantList();
    setState(540);
    match(ADAParser::T__10);
    setState(541);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseConstantListContext ------------------------------------------------------------------

ADAParser::CaseConstantListContext::CaseConstantListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ADAParser::CaseConstantContext *> ADAParser::CaseConstantListContext::caseConstant() {
  return getRuleContexts<ADAParser::CaseConstantContext>();
}

ADAParser::CaseConstantContext* ADAParser::CaseConstantListContext::caseConstant(size_t i) {
  return getRuleContext<ADAParser::CaseConstantContext>(i);
}


size_t ADAParser::CaseConstantListContext::getRuleIndex() const {
  return ADAParser::RuleCaseConstantList;
}


antlrcpp::Any ADAParser::CaseConstantListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitCaseConstantList(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::CaseConstantListContext* ADAParser::caseConstantList() {
  CaseConstantListContext *_localctx = _tracker.createInstance<CaseConstantListContext>(_ctx, getState());
  enterRule(_localctx, 120, ADAParser::RuleCaseConstantList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(543);
    caseConstant();
    setState(548);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ADAParser::T__11) {
      setState(544);
      match(ADAParser::T__11);
      setState(545);
      caseConstant();
      setState(550);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseConstantContext ------------------------------------------------------------------

ADAParser::CaseConstantContext::CaseConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::ConstantContext* ADAParser::CaseConstantContext::constant() {
  return getRuleContext<ADAParser::ConstantContext>(0);
}


size_t ADAParser::CaseConstantContext::getRuleIndex() const {
  return ADAParser::RuleCaseConstant;
}


antlrcpp::Any ADAParser::CaseConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitCaseConstant(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::CaseConstantContext* ADAParser::caseConstant() {
  CaseConstantContext *_localctx = _tracker.createInstance<CaseConstantContext>(_ctx, getState());
  enterRule(_localctx, 122, ADAParser::RuleCaseConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(551);
    constant();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStatementContext ------------------------------------------------------------------

ADAParser::WhileStatementContext::WhileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::WhileStatementContext::WHILE() {
  return getToken(ADAParser::WHILE, 0);
}

ADAParser::ExpressionContext* ADAParser::WhileStatementContext::expression() {
  return getRuleContext<ADAParser::ExpressionContext>(0);
}


size_t ADAParser::WhileStatementContext::getRuleIndex() const {
  return ADAParser::RuleWhileStatement;
}


antlrcpp::Any ADAParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::WhileStatementContext* ADAParser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 124, ADAParser::RuleWhileStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(553);
    match(ADAParser::WHILE);
    setState(554);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStatementContext ------------------------------------------------------------------

ADAParser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::ForStatementContext::FOR() {
  return getToken(ADAParser::FOR, 0);
}

ADAParser::VariableContext* ADAParser::ForStatementContext::variable() {
  return getRuleContext<ADAParser::VariableContext>(0);
}

tree::TerminalNode* ADAParser::ForStatementContext::IN() {
  return getToken(ADAParser::IN, 0);
}

ADAParser::SubrangeTypeContext* ADAParser::ForStatementContext::subrangeType() {
  return getRuleContext<ADAParser::SubrangeTypeContext>(0);
}

tree::TerminalNode* ADAParser::ForStatementContext::REVERSE() {
  return getToken(ADAParser::REVERSE, 0);
}


size_t ADAParser::ForStatementContext::getRuleIndex() const {
  return ADAParser::RuleForStatement;
}


antlrcpp::Any ADAParser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ForStatementContext* ADAParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 126, ADAParser::RuleForStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(556);
    match(ADAParser::FOR);
    setState(557);
    variable();
    setState(558);
    match(ADAParser::IN);
    setState(560);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ADAParser::REVERSE) {
      setState(559);
      match(ADAParser::REVERSE);
    }
    setState(562);
    subrangeType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureCallStatementContext ------------------------------------------------------------------

ADAParser::ProcedureCallStatementContext::ProcedureCallStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::ProcedureNameContext* ADAParser::ProcedureCallStatementContext::procedureName() {
  return getRuleContext<ADAParser::ProcedureNameContext>(0);
}

ADAParser::ArgumentListContext* ADAParser::ProcedureCallStatementContext::argumentList() {
  return getRuleContext<ADAParser::ArgumentListContext>(0);
}


size_t ADAParser::ProcedureCallStatementContext::getRuleIndex() const {
  return ADAParser::RuleProcedureCallStatement;
}


antlrcpp::Any ADAParser::ProcedureCallStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitProcedureCallStatement(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ProcedureCallStatementContext* ADAParser::procedureCallStatement() {
  ProcedureCallStatementContext *_localctx = _tracker.createInstance<ProcedureCallStatementContext>(_ctx, getState());
  enterRule(_localctx, 128, ADAParser::RuleProcedureCallStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(564);
    procedureName();
    setState(565);
    match(ADAParser::T__4);
    setState(567);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ADAParser::T__2)
      | (1ULL << ADAParser::T__3)
      | (1ULL << ADAParser::T__4)
      | (1ULL << ADAParser::NOT))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (ADAParser::IDENTIFIER - 67))
      | (1ULL << (ADAParser::INTEGER - 67))
      | (1ULL << (ADAParser::REAL - 67))
      | (1ULL << (ADAParser::CHARACTER - 67))
      | (1ULL << (ADAParser::STRING - 67)))) != 0)) {
      setState(566);
      argumentList();
    }
    setState(569);
    match(ADAParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureNameContext ------------------------------------------------------------------

ADAParser::ProcedureNameContext::ProcedureNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::ProcedureNameContext::IDENTIFIER() {
  return getToken(ADAParser::IDENTIFIER, 0);
}


size_t ADAParser::ProcedureNameContext::getRuleIndex() const {
  return ADAParser::RuleProcedureName;
}


antlrcpp::Any ADAParser::ProcedureNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitProcedureName(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ProcedureNameContext* ADAParser::procedureName() {
  ProcedureNameContext *_localctx = _tracker.createInstance<ProcedureNameContext>(_ctx, getState());
  enterRule(_localctx, 130, ADAParser::RuleProcedureName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(571);
    match(ADAParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentListContext ------------------------------------------------------------------

ADAParser::ArgumentListContext::ArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ADAParser::ArgumentContext *> ADAParser::ArgumentListContext::argument() {
  return getRuleContexts<ADAParser::ArgumentContext>();
}

ADAParser::ArgumentContext* ADAParser::ArgumentListContext::argument(size_t i) {
  return getRuleContext<ADAParser::ArgumentContext>(i);
}


size_t ADAParser::ArgumentListContext::getRuleIndex() const {
  return ADAParser::RuleArgumentList;
}


antlrcpp::Any ADAParser::ArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitArgumentList(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ArgumentListContext* ADAParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 132, ADAParser::RuleArgumentList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(573);
    argument();
    setState(578);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ADAParser::T__5) {
      setState(574);
      match(ADAParser::T__5);
      setState(575);
      argument();
      setState(580);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentContext ------------------------------------------------------------------

ADAParser::ArgumentContext::ArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::ExpressionContext* ADAParser::ArgumentContext::expression() {
  return getRuleContext<ADAParser::ExpressionContext>(0);
}


size_t ADAParser::ArgumentContext::getRuleIndex() const {
  return ADAParser::RuleArgument;
}


antlrcpp::Any ADAParser::ArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitArgument(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ArgumentContext* ADAParser::argument() {
  ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
  enterRule(_localctx, 134, ADAParser::RuleArgument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(581);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PutStatementContext ------------------------------------------------------------------

ADAParser::PutStatementContext::PutStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::PutStatementContext::PUT() {
  return getToken(ADAParser::PUT, 0);
}

ADAParser::PutArgumentsContext* ADAParser::PutStatementContext::putArguments() {
  return getRuleContext<ADAParser::PutArgumentsContext>(0);
}


size_t ADAParser::PutStatementContext::getRuleIndex() const {
  return ADAParser::RulePutStatement;
}


antlrcpp::Any ADAParser::PutStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitPutStatement(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::PutStatementContext* ADAParser::putStatement() {
  PutStatementContext *_localctx = _tracker.createInstance<PutStatementContext>(_ctx, getState());
  enterRule(_localctx, 136, ADAParser::RulePutStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(583);
    match(ADAParser::PUT);
    setState(584);
    putArguments();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PutLineStatementContext ------------------------------------------------------------------

ADAParser::PutLineStatementContext::PutLineStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::PutLineStatementContext::PUTLINE() {
  return getToken(ADAParser::PUTLINE, 0);
}

ADAParser::PutArgumentsContext* ADAParser::PutLineStatementContext::putArguments() {
  return getRuleContext<ADAParser::PutArgumentsContext>(0);
}


size_t ADAParser::PutLineStatementContext::getRuleIndex() const {
  return ADAParser::RulePutLineStatement;
}


antlrcpp::Any ADAParser::PutLineStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitPutLineStatement(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::PutLineStatementContext* ADAParser::putLineStatement() {
  PutLineStatementContext *_localctx = _tracker.createInstance<PutLineStatementContext>(_ctx, getState());
  enterRule(_localctx, 138, ADAParser::RulePutLineStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(586);
    match(ADAParser::PUTLINE);
    setState(588);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ADAParser::T__4) {
      setState(587);
      putArguments();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PutArgumentsContext ------------------------------------------------------------------

ADAParser::PutArgumentsContext::PutArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ADAParser::PutArgumentContext *> ADAParser::PutArgumentsContext::putArgument() {
  return getRuleContexts<ADAParser::PutArgumentContext>();
}

ADAParser::PutArgumentContext* ADAParser::PutArgumentsContext::putArgument(size_t i) {
  return getRuleContext<ADAParser::PutArgumentContext>(i);
}


size_t ADAParser::PutArgumentsContext::getRuleIndex() const {
  return ADAParser::RulePutArguments;
}


antlrcpp::Any ADAParser::PutArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitPutArguments(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::PutArgumentsContext* ADAParser::putArguments() {
  PutArgumentsContext *_localctx = _tracker.createInstance<PutArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 140, ADAParser::RulePutArguments);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(590);
    match(ADAParser::T__4);
    setState(591);
    putArgument();
    setState(596);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ADAParser::T__5) {
      setState(592);
      match(ADAParser::T__5);
      setState(593);
      putArgument();
      setState(598);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(599);
    match(ADAParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PutArgumentContext ------------------------------------------------------------------

ADAParser::PutArgumentContext::PutArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::ExpressionContext* ADAParser::PutArgumentContext::expression() {
  return getRuleContext<ADAParser::ExpressionContext>(0);
}

ADAParser::FieldWidthContext* ADAParser::PutArgumentContext::fieldWidth() {
  return getRuleContext<ADAParser::FieldWidthContext>(0);
}


size_t ADAParser::PutArgumentContext::getRuleIndex() const {
  return ADAParser::RulePutArgument;
}


antlrcpp::Any ADAParser::PutArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitPutArgument(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::PutArgumentContext* ADAParser::putArgument() {
  PutArgumentContext *_localctx = _tracker.createInstance<PutArgumentContext>(_ctx, getState());
  enterRule(_localctx, 142, ADAParser::RulePutArgument);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(601);
    expression();
    setState(604);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ADAParser::T__8) {
      setState(602);
      match(ADAParser::T__8);
      setState(603);
      fieldWidth();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldWidthContext ------------------------------------------------------------------

ADAParser::FieldWidthContext::FieldWidthContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::IntegerConstantContext* ADAParser::FieldWidthContext::integerConstant() {
  return getRuleContext<ADAParser::IntegerConstantContext>(0);
}

ADAParser::SignContext* ADAParser::FieldWidthContext::sign() {
  return getRuleContext<ADAParser::SignContext>(0);
}

ADAParser::DecimalPlacesContext* ADAParser::FieldWidthContext::decimalPlaces() {
  return getRuleContext<ADAParser::DecimalPlacesContext>(0);
}


size_t ADAParser::FieldWidthContext::getRuleIndex() const {
  return ADAParser::RuleFieldWidth;
}


antlrcpp::Any ADAParser::FieldWidthContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitFieldWidth(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::FieldWidthContext* ADAParser::fieldWidth() {
  FieldWidthContext *_localctx = _tracker.createInstance<FieldWidthContext>(_ctx, getState());
  enterRule(_localctx, 144, ADAParser::RuleFieldWidth);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(607);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ADAParser::T__2

    || _la == ADAParser::T__3) {
      setState(606);
      sign();
    }
    setState(609);
    integerConstant();
    setState(612);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ADAParser::T__8) {
      setState(610);
      match(ADAParser::T__8);
      setState(611);
      decimalPlaces();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DecimalPlacesContext ------------------------------------------------------------------

ADAParser::DecimalPlacesContext::DecimalPlacesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::IntegerConstantContext* ADAParser::DecimalPlacesContext::integerConstant() {
  return getRuleContext<ADAParser::IntegerConstantContext>(0);
}


size_t ADAParser::DecimalPlacesContext::getRuleIndex() const {
  return ADAParser::RuleDecimalPlaces;
}


antlrcpp::Any ADAParser::DecimalPlacesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitDecimalPlaces(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::DecimalPlacesContext* ADAParser::decimalPlaces() {
  DecimalPlacesContext *_localctx = _tracker.createInstance<DecimalPlacesContext>(_ctx, getState());
  enterRule(_localctx, 146, ADAParser::RuleDecimalPlaces);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(614);
    integerConstant();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GetStatementContext ------------------------------------------------------------------

ADAParser::GetStatementContext::GetStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::GetStatementContext::GET() {
  return getToken(ADAParser::GET, 0);
}

ADAParser::GetArgumentsContext* ADAParser::GetStatementContext::getArguments() {
  return getRuleContext<ADAParser::GetArgumentsContext>(0);
}


size_t ADAParser::GetStatementContext::getRuleIndex() const {
  return ADAParser::RuleGetStatement;
}


antlrcpp::Any ADAParser::GetStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitGetStatement(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::GetStatementContext* ADAParser::getStatement() {
  GetStatementContext *_localctx = _tracker.createInstance<GetStatementContext>(_ctx, getState());
  enterRule(_localctx, 148, ADAParser::RuleGetStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(616);
    match(ADAParser::GET);
    setState(617);
    getArguments();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GetLineStatementContext ------------------------------------------------------------------

ADAParser::GetLineStatementContext::GetLineStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::GetLineStatementContext::GETLINE() {
  return getToken(ADAParser::GETLINE, 0);
}

ADAParser::GetArgumentsContext* ADAParser::GetLineStatementContext::getArguments() {
  return getRuleContext<ADAParser::GetArgumentsContext>(0);
}


size_t ADAParser::GetLineStatementContext::getRuleIndex() const {
  return ADAParser::RuleGetLineStatement;
}


antlrcpp::Any ADAParser::GetLineStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitGetLineStatement(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::GetLineStatementContext* ADAParser::getLineStatement() {
  GetLineStatementContext *_localctx = _tracker.createInstance<GetLineStatementContext>(_ctx, getState());
  enterRule(_localctx, 150, ADAParser::RuleGetLineStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(619);
    match(ADAParser::GETLINE);
    setState(620);
    getArguments();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GetArgumentsContext ------------------------------------------------------------------

ADAParser::GetArgumentsContext::GetArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ADAParser::VariableContext *> ADAParser::GetArgumentsContext::variable() {
  return getRuleContexts<ADAParser::VariableContext>();
}

ADAParser::VariableContext* ADAParser::GetArgumentsContext::variable(size_t i) {
  return getRuleContext<ADAParser::VariableContext>(i);
}


size_t ADAParser::GetArgumentsContext::getRuleIndex() const {
  return ADAParser::RuleGetArguments;
}


antlrcpp::Any ADAParser::GetArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitGetArguments(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::GetArgumentsContext* ADAParser::getArguments() {
  GetArgumentsContext *_localctx = _tracker.createInstance<GetArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 152, ADAParser::RuleGetArguments);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(622);
    match(ADAParser::T__4);
    setState(623);
    variable();
    setState(628);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ADAParser::T__5) {
      setState(624);
      match(ADAParser::T__5);
      setState(625);
      variable();
      setState(630);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(631);
    match(ADAParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

ADAParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ADAParser::SimpleExpressionContext *> ADAParser::ExpressionContext::simpleExpression() {
  return getRuleContexts<ADAParser::SimpleExpressionContext>();
}

ADAParser::SimpleExpressionContext* ADAParser::ExpressionContext::simpleExpression(size_t i) {
  return getRuleContext<ADAParser::SimpleExpressionContext>(i);
}

ADAParser::RelOpContext* ADAParser::ExpressionContext::relOp() {
  return getRuleContext<ADAParser::RelOpContext>(0);
}


size_t ADAParser::ExpressionContext::getRuleIndex() const {
  return ADAParser::RuleExpression;
}


antlrcpp::Any ADAParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ExpressionContext* ADAParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 154, ADAParser::RuleExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(633);
    simpleExpression();
    setState(637);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ADAParser::T__1)
      | (1ULL << ADAParser::T__13)
      | (1ULL << ADAParser::T__14)
      | (1ULL << ADAParser::T__15)
      | (1ULL << ADAParser::T__16)
      | (1ULL << ADAParser::T__17))) != 0)) {
      setState(634);
      relOp();
      setState(635);
      simpleExpression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleExpressionContext ------------------------------------------------------------------

ADAParser::SimpleExpressionContext::SimpleExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ADAParser::TermContext *> ADAParser::SimpleExpressionContext::term() {
  return getRuleContexts<ADAParser::TermContext>();
}

ADAParser::TermContext* ADAParser::SimpleExpressionContext::term(size_t i) {
  return getRuleContext<ADAParser::TermContext>(i);
}

ADAParser::SignContext* ADAParser::SimpleExpressionContext::sign() {
  return getRuleContext<ADAParser::SignContext>(0);
}

std::vector<ADAParser::AddOpContext *> ADAParser::SimpleExpressionContext::addOp() {
  return getRuleContexts<ADAParser::AddOpContext>();
}

ADAParser::AddOpContext* ADAParser::SimpleExpressionContext::addOp(size_t i) {
  return getRuleContext<ADAParser::AddOpContext>(i);
}


size_t ADAParser::SimpleExpressionContext::getRuleIndex() const {
  return ADAParser::RuleSimpleExpression;
}


antlrcpp::Any ADAParser::SimpleExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitSimpleExpression(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::SimpleExpressionContext* ADAParser::simpleExpression() {
  SimpleExpressionContext *_localctx = _tracker.createInstance<SimpleExpressionContext>(_ctx, getState());
  enterRule(_localctx, 156, ADAParser::RuleSimpleExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(640);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
    case 1: {
      setState(639);
      sign();
      break;
    }

    default:
      break;
    }
    setState(642);
    term();
    setState(648);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ADAParser::T__2)
      | (1ULL << ADAParser::T__3)
      | (1ULL << ADAParser::T__11))) != 0)) {
      setState(643);
      addOp();
      setState(644);
      term();
      setState(650);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

ADAParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ADAParser::FactorContext *> ADAParser::TermContext::factor() {
  return getRuleContexts<ADAParser::FactorContext>();
}

ADAParser::FactorContext* ADAParser::TermContext::factor(size_t i) {
  return getRuleContext<ADAParser::FactorContext>(i);
}

std::vector<ADAParser::MulOpContext *> ADAParser::TermContext::mulOp() {
  return getRuleContexts<ADAParser::MulOpContext>();
}

ADAParser::MulOpContext* ADAParser::TermContext::mulOp(size_t i) {
  return getRuleContext<ADAParser::MulOpContext>(i);
}


size_t ADAParser::TermContext::getRuleIndex() const {
  return ADAParser::RuleTerm;
}


antlrcpp::Any ADAParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::TermContext* ADAParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 158, ADAParser::RuleTerm);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(651);
    factor();
    setState(657);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ADAParser::T__18)
      | (1ULL << ADAParser::T__19)
      | (1ULL << ADAParser::T__20)
      | (1ULL << ADAParser::DIV)
      | (1ULL << ADAParser::MOD))) != 0)) {
      setState(652);
      mulOp();
      setState(653);
      factor();
      setState(659);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

ADAParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ADAParser::FactorContext::getRuleIndex() const {
  return ADAParser::RuleFactor;
}

void ADAParser::FactorContext::copyFrom(FactorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- NumberFactorContext ------------------------------------------------------------------

ADAParser::NumberContext* ADAParser::NumberFactorContext::number() {
  return getRuleContext<ADAParser::NumberContext>(0);
}

ADAParser::NumberFactorContext::NumberFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ADAParser::NumberFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitNumberFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringFactorContext ------------------------------------------------------------------

ADAParser::StringConstantContext* ADAParser::StringFactorContext::stringConstant() {
  return getRuleContext<ADAParser::StringConstantContext>(0);
}

ADAParser::StringFactorContext::StringFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ADAParser::StringFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitStringFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CharacterFactorContext ------------------------------------------------------------------

ADAParser::CharacterConstantContext* ADAParser::CharacterFactorContext::characterConstant() {
  return getRuleContext<ADAParser::CharacterConstantContext>(0);
}

ADAParser::CharacterFactorContext::CharacterFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ADAParser::CharacterFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitCharacterFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionCallFactorContext ------------------------------------------------------------------

ADAParser::FunctionCallContext* ADAParser::FunctionCallFactorContext::functionCall() {
  return getRuleContext<ADAParser::FunctionCallContext>(0);
}

ADAParser::FunctionCallFactorContext::FunctionCallFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ADAParser::FunctionCallFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitFunctionCallFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableFactorContext ------------------------------------------------------------------

ADAParser::VariableContext* ADAParser::VariableFactorContext::variable() {
  return getRuleContext<ADAParser::VariableContext>(0);
}

ADAParser::VariableFactorContext::VariableFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ADAParser::VariableFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitVariableFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotFactorContext ------------------------------------------------------------------

tree::TerminalNode* ADAParser::NotFactorContext::NOT() {
  return getToken(ADAParser::NOT, 0);
}

ADAParser::FactorContext* ADAParser::NotFactorContext::factor() {
  return getRuleContext<ADAParser::FactorContext>(0);
}

ADAParser::NotFactorContext::NotFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ADAParser::NotFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitNotFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesizedFactorContext ------------------------------------------------------------------

ADAParser::ExpressionContext* ADAParser::ParenthesizedFactorContext::expression() {
  return getRuleContext<ADAParser::ExpressionContext>(0);
}

ADAParser::ParenthesizedFactorContext::ParenthesizedFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ADAParser::ParenthesizedFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitParenthesizedFactor(this);
  else
    return visitor->visitChildren(this);
}
ADAParser::FactorContext* ADAParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 160, ADAParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(671);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<ADAParser::FunctionCallFactorContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(660);
      functionCall();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<ADAParser::VariableFactorContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(661);
      variable();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<ADAParser::NumberFactorContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(662);
      number();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<ADAParser::CharacterFactorContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(663);
      characterConstant();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<ADAParser::StringFactorContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(664);
      stringConstant();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<ADAParser::NotFactorContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(665);
      match(ADAParser::NOT);
      setState(666);
      factor();
      break;
    }

    case 7: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<ADAParser::ParenthesizedFactorContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(667);
      match(ADAParser::T__4);
      setState(668);
      expression();
      setState(669);
      match(ADAParser::T__6);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

ADAParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::VariableIdentifierContext* ADAParser::VariableContext::variableIdentifier() {
  return getRuleContext<ADAParser::VariableIdentifierContext>(0);
}

std::vector<ADAParser::ModifierContext *> ADAParser::VariableContext::modifier() {
  return getRuleContexts<ADAParser::ModifierContext>();
}

ADAParser::ModifierContext* ADAParser::VariableContext::modifier(size_t i) {
  return getRuleContext<ADAParser::ModifierContext>(i);
}


size_t ADAParser::VariableContext::getRuleIndex() const {
  return ADAParser::RuleVariable;
}


antlrcpp::Any ADAParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::VariableContext* ADAParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 162, ADAParser::RuleVariable);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(673);
    variableIdentifier();
    setState(677);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ADAParser::T__4

    || _la == ADAParser::T__12) {
      setState(674);
      modifier();
      setState(679);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModifierContext ------------------------------------------------------------------

ADAParser::ModifierContext::ModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::IndexListContext* ADAParser::ModifierContext::indexList() {
  return getRuleContext<ADAParser::IndexListContext>(0);
}

ADAParser::FieldContext* ADAParser::ModifierContext::field() {
  return getRuleContext<ADAParser::FieldContext>(0);
}


size_t ADAParser::ModifierContext::getRuleIndex() const {
  return ADAParser::RuleModifier;
}


antlrcpp::Any ADAParser::ModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitModifier(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::ModifierContext* ADAParser::modifier() {
  ModifierContext *_localctx = _tracker.createInstance<ModifierContext>(_ctx, getState());
  enterRule(_localctx, 164, ADAParser::RuleModifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(686);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ADAParser::T__4: {
        enterOuterAlt(_localctx, 1);
        setState(680);
        match(ADAParser::T__4);
        setState(681);
        indexList();
        setState(682);
        match(ADAParser::T__6);
        break;
      }

      case ADAParser::T__12: {
        enterOuterAlt(_localctx, 2);
        setState(684);
        match(ADAParser::T__12);
        setState(685);
        field();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexListContext ------------------------------------------------------------------

ADAParser::IndexListContext::IndexListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ADAParser::IndexContext *> ADAParser::IndexListContext::index() {
  return getRuleContexts<ADAParser::IndexContext>();
}

ADAParser::IndexContext* ADAParser::IndexListContext::index(size_t i) {
  return getRuleContext<ADAParser::IndexContext>(i);
}


size_t ADAParser::IndexListContext::getRuleIndex() const {
  return ADAParser::RuleIndexList;
}


antlrcpp::Any ADAParser::IndexListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitIndexList(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::IndexListContext* ADAParser::indexList() {
  IndexListContext *_localctx = _tracker.createInstance<IndexListContext>(_ctx, getState());
  enterRule(_localctx, 166, ADAParser::RuleIndexList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(688);
    index();
    setState(693);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ADAParser::T__5) {
      setState(689);
      match(ADAParser::T__5);
      setState(690);
      index();
      setState(695);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexContext ------------------------------------------------------------------

ADAParser::IndexContext::IndexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::ExpressionContext* ADAParser::IndexContext::expression() {
  return getRuleContext<ADAParser::ExpressionContext>(0);
}


size_t ADAParser::IndexContext::getRuleIndex() const {
  return ADAParser::RuleIndex;
}


antlrcpp::Any ADAParser::IndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitIndex(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::IndexContext* ADAParser::index() {
  IndexContext *_localctx = _tracker.createInstance<IndexContext>(_ctx, getState());
  enterRule(_localctx, 168, ADAParser::RuleIndex);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(696);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldContext ------------------------------------------------------------------

ADAParser::FieldContext::FieldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::FieldContext::IDENTIFIER() {
  return getToken(ADAParser::IDENTIFIER, 0);
}


size_t ADAParser::FieldContext::getRuleIndex() const {
  return ADAParser::RuleField;
}


antlrcpp::Any ADAParser::FieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitField(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::FieldContext* ADAParser::field() {
  FieldContext *_localctx = _tracker.createInstance<FieldContext>(_ctx, getState());
  enterRule(_localctx, 170, ADAParser::RuleField);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(698);
    match(ADAParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

ADAParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::FunctionNameContext* ADAParser::FunctionCallContext::functionName() {
  return getRuleContext<ADAParser::FunctionNameContext>(0);
}

ADAParser::ArgumentListContext* ADAParser::FunctionCallContext::argumentList() {
  return getRuleContext<ADAParser::ArgumentListContext>(0);
}


size_t ADAParser::FunctionCallContext::getRuleIndex() const {
  return ADAParser::RuleFunctionCall;
}


antlrcpp::Any ADAParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::FunctionCallContext* ADAParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 172, ADAParser::RuleFunctionCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(700);
    functionName();
    setState(701);
    match(ADAParser::T__4);
    setState(703);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ADAParser::T__2)
      | (1ULL << ADAParser::T__3)
      | (1ULL << ADAParser::T__4)
      | (1ULL << ADAParser::NOT))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (ADAParser::IDENTIFIER - 67))
      | (1ULL << (ADAParser::INTEGER - 67))
      | (1ULL << (ADAParser::REAL - 67))
      | (1ULL << (ADAParser::CHARACTER - 67))
      | (1ULL << (ADAParser::STRING - 67)))) != 0)) {
      setState(702);
      argumentList();
    }
    setState(705);
    match(ADAParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionNameContext ------------------------------------------------------------------

ADAParser::FunctionNameContext::FunctionNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::FunctionNameContext::IDENTIFIER() {
  return getToken(ADAParser::IDENTIFIER, 0);
}


size_t ADAParser::FunctionNameContext::getRuleIndex() const {
  return ADAParser::RuleFunctionName;
}


antlrcpp::Any ADAParser::FunctionNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitFunctionName(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::FunctionNameContext* ADAParser::functionName() {
  FunctionNameContext *_localctx = _tracker.createInstance<FunctionNameContext>(_ctx, getState());
  enterRule(_localctx, 174, ADAParser::RuleFunctionName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(707);
    match(ADAParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

ADAParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::UnsignedNumberContext* ADAParser::NumberContext::unsignedNumber() {
  return getRuleContext<ADAParser::UnsignedNumberContext>(0);
}

ADAParser::SignContext* ADAParser::NumberContext::sign() {
  return getRuleContext<ADAParser::SignContext>(0);
}


size_t ADAParser::NumberContext::getRuleIndex() const {
  return ADAParser::RuleNumber;
}


antlrcpp::Any ADAParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::NumberContext* ADAParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 176, ADAParser::RuleNumber);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(710);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ADAParser::T__2

    || _la == ADAParser::T__3) {
      setState(709);
      sign();
    }
    setState(712);
    unsignedNumber();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnsignedNumberContext ------------------------------------------------------------------

ADAParser::UnsignedNumberContext::UnsignedNumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ADAParser::IntegerConstantContext* ADAParser::UnsignedNumberContext::integerConstant() {
  return getRuleContext<ADAParser::IntegerConstantContext>(0);
}

ADAParser::RealConstantContext* ADAParser::UnsignedNumberContext::realConstant() {
  return getRuleContext<ADAParser::RealConstantContext>(0);
}


size_t ADAParser::UnsignedNumberContext::getRuleIndex() const {
  return ADAParser::RuleUnsignedNumber;
}


antlrcpp::Any ADAParser::UnsignedNumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitUnsignedNumber(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::UnsignedNumberContext* ADAParser::unsignedNumber() {
  UnsignedNumberContext *_localctx = _tracker.createInstance<UnsignedNumberContext>(_ctx, getState());
  enterRule(_localctx, 178, ADAParser::RuleUnsignedNumber);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(716);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ADAParser::INTEGER: {
        enterOuterAlt(_localctx, 1);
        setState(714);
        integerConstant();
        break;
      }

      case ADAParser::REAL: {
        enterOuterAlt(_localctx, 2);
        setState(715);
        realConstant();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntegerConstantContext ------------------------------------------------------------------

ADAParser::IntegerConstantContext::IntegerConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::IntegerConstantContext::INTEGER() {
  return getToken(ADAParser::INTEGER, 0);
}


size_t ADAParser::IntegerConstantContext::getRuleIndex() const {
  return ADAParser::RuleIntegerConstant;
}


antlrcpp::Any ADAParser::IntegerConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitIntegerConstant(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::IntegerConstantContext* ADAParser::integerConstant() {
  IntegerConstantContext *_localctx = _tracker.createInstance<IntegerConstantContext>(_ctx, getState());
  enterRule(_localctx, 180, ADAParser::RuleIntegerConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(718);
    match(ADAParser::INTEGER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RealConstantContext ------------------------------------------------------------------

ADAParser::RealConstantContext::RealConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::RealConstantContext::REAL() {
  return getToken(ADAParser::REAL, 0);
}


size_t ADAParser::RealConstantContext::getRuleIndex() const {
  return ADAParser::RuleRealConstant;
}


antlrcpp::Any ADAParser::RealConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitRealConstant(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::RealConstantContext* ADAParser::realConstant() {
  RealConstantContext *_localctx = _tracker.createInstance<RealConstantContext>(_ctx, getState());
  enterRule(_localctx, 182, ADAParser::RuleRealConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(720);
    match(ADAParser::REAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CharacterConstantContext ------------------------------------------------------------------

ADAParser::CharacterConstantContext::CharacterConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::CharacterConstantContext::CHARACTER() {
  return getToken(ADAParser::CHARACTER, 0);
}


size_t ADAParser::CharacterConstantContext::getRuleIndex() const {
  return ADAParser::RuleCharacterConstant;
}


antlrcpp::Any ADAParser::CharacterConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitCharacterConstant(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::CharacterConstantContext* ADAParser::characterConstant() {
  CharacterConstantContext *_localctx = _tracker.createInstance<CharacterConstantContext>(_ctx, getState());
  enterRule(_localctx, 184, ADAParser::RuleCharacterConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(722);
    match(ADAParser::CHARACTER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringConstantContext ------------------------------------------------------------------

ADAParser::StringConstantContext::StringConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::StringConstantContext::STRING() {
  return getToken(ADAParser::STRING, 0);
}


size_t ADAParser::StringConstantContext::getRuleIndex() const {
  return ADAParser::RuleStringConstant;
}


antlrcpp::Any ADAParser::StringConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitStringConstant(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::StringConstantContext* ADAParser::stringConstant() {
  StringConstantContext *_localctx = _tracker.createInstance<StringConstantContext>(_ctx, getState());
  enterRule(_localctx, 186, ADAParser::RuleStringConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(724);
    match(ADAParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelOpContext ------------------------------------------------------------------

ADAParser::RelOpContext::RelOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ADAParser::RelOpContext::getRuleIndex() const {
  return ADAParser::RuleRelOp;
}


antlrcpp::Any ADAParser::RelOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitRelOp(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::RelOpContext* ADAParser::relOp() {
  RelOpContext *_localctx = _tracker.createInstance<RelOpContext>(_ctx, getState());
  enterRule(_localctx, 188, ADAParser::RuleRelOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(726);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ADAParser::T__1)
      | (1ULL << ADAParser::T__13)
      | (1ULL << ADAParser::T__14)
      | (1ULL << ADAParser::T__15)
      | (1ULL << ADAParser::T__16)
      | (1ULL << ADAParser::T__17))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddOpContext ------------------------------------------------------------------

ADAParser::AddOpContext::AddOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ADAParser::AddOpContext::getRuleIndex() const {
  return ADAParser::RuleAddOp;
}


antlrcpp::Any ADAParser::AddOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitAddOp(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::AddOpContext* ADAParser::addOp() {
  AddOpContext *_localctx = _tracker.createInstance<AddOpContext>(_ctx, getState());
  enterRule(_localctx, 190, ADAParser::RuleAddOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(728);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ADAParser::T__2)
      | (1ULL << ADAParser::T__3)
      | (1ULL << ADAParser::T__11))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulOpContext ------------------------------------------------------------------

ADAParser::MulOpContext::MulOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ADAParser::MulOpContext::DIV() {
  return getToken(ADAParser::DIV, 0);
}

tree::TerminalNode* ADAParser::MulOpContext::MOD() {
  return getToken(ADAParser::MOD, 0);
}


size_t ADAParser::MulOpContext::getRuleIndex() const {
  return ADAParser::RuleMulOp;
}


antlrcpp::Any ADAParser::MulOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ADAVisitor*>(visitor))
    return parserVisitor->visitMulOp(this);
  else
    return visitor->visitChildren(this);
}

ADAParser::MulOpContext* ADAParser::mulOp() {
  MulOpContext *_localctx = _tracker.createInstance<MulOpContext>(_ctx, getState());
  enterRule(_localctx, 192, ADAParser::RuleMulOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(730);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ADAParser::T__18)
      | (1ULL << ADAParser::T__19)
      | (1ULL << ADAParser::T__20)
      | (1ULL << ADAParser::DIV)
      | (1ULL << ADAParser::MOD))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> ADAParser::_decisionToDFA;
atn::PredictionContextCache ADAParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ADAParser::_atn;
std::vector<uint16_t> ADAParser::_serializedATN;

std::vector<std::string> ADAParser::_ruleNames = {
  "program", "programHeader", "programIdentifier", "statementIdentifier", 
  "block", "declarations", "constantsPart", "constantDefinitionsList", "constantDefinition", 
  "constantIdentifier", "constant", "sign", "typesPart", "typeDefinitionsList", 
  "typeDefinition", "typeIdentifier", "typeSpecification", "simpleType", 
  "enumerationType", "enumerationConstant", "subrangeType", "arrayType", 
  "arrayDimensionList", "recordType", "recordFields", "variablesPart", "variableDeclarationsList", 
  "variableDeclarations", "variableIdentifierList", "variableIdentifier", 
  "subprogramPart", "subprogramBody", "procedureHead", "functionHead", "routineIdentifier", 
  "parameters", "parameterDeclarationsList", "parameterDeclarations", "parameterIdentifierList", 
  "parameterIdentifier", "statement", "compoundStatement", "emptyStatement", 
  "statementList", "assignmentStatement", "returnStatement", "lhs", "rhs", 
  "newLineStatement", "ifStatement", "trueStatementList", "falseStatementList", 
  "elseStatementList", "ifCondition", "elsifCondition", "exitStatement", 
  "loopStatement", "caseStatement", "caseBranchList", "caseBranch", "caseConstantList", 
  "caseConstant", "whileStatement", "forStatement", "procedureCallStatement", 
  "procedureName", "argumentList", "argument", "putStatement", "putLineStatement", 
  "putArguments", "putArgument", "fieldWidth", "decimalPlaces", "getStatement", 
  "getLineStatement", "getArguments", "expression", "simpleExpression", 
  "term", "factor", "variable", "modifier", "indexList", "index", "field", 
  "functionCall", "functionName", "number", "unsignedNumber", "integerConstant", 
  "realConstant", "characterConstant", "stringConstant", "relOp", "addOp", 
  "mulOp"
};

std::vector<std::string> ADAParser::_literalNames = {
  "", "';'", "'='", "'-'", "'+'", "'('", "','", "')'", "'..'", "':'", "':='", 
  "'=>'", "'|'", "'.'", "'/='", "'<'", "'<='", "'>'", "'>='", "'*'", "'/'", 
  "'&'", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "'''"
};

std::vector<std::string> ADAParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "PROGRAM", "CONST", "TYPE", "ARRAY", "OF", "RECORD", "VAR", 
  "BEGIN", "END", "DIV", "MOD", "AND", "OR", "NOT", "IF", "THEN", "ELSE", 
  "ELSIF", "CASE", "REPEAT", "UNTIL", "WHILE", "DO", "FOR", "TO", "DOWNTO", 
  "WRITE", "WRITELN", "READ", "READLN", "PROCEDURE", "FUNCTION", "EXIT", 
  "WHEN", "IN", "REVERSE", "LOOP", "IS", "PUT", "PUTLINE", "GET", "GETLINE", 
  "OUT", "RETURN", "NEWLINE", "IDENTIFIER", "INTEGER", "REAL", "NEW_LINE", 
  "WS", "QUOTE", "CHARACTER", "STRING", "COMMENT"
};

dfa::Vocabulary ADAParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ADAParser::_tokenNames;

ADAParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x4d, 0x2df, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 
    0x4c, 0x4, 0x4d, 0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 
    0x4, 0x50, 0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 
    0x53, 0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
    0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 0x9, 
    0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 0x9, 0x5c, 
    0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 0x9, 0x5f, 0x4, 
    0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x4, 0x62, 0x9, 0x62, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0xc8, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 
    0x7, 0xda, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xdf, 0xa, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xe4, 0xa, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xe9, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0xf1, 0xa, 0x9, 0xc, 0x9, 
    0xe, 0x9, 0xf4, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xc, 0x5, 0xc, 0xfd, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x5, 0xc, 0x101, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x105, 0xa, 
    0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x7, 0xf, 0x10f, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x112, 
    0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x11d, 0xa, 0x12, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x122, 0xa, 0x13, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0x128, 0xa, 0x14, 0xc, 0x14, 
    0xe, 0x14, 0x12b, 0xb, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x7, 0x18, 0x13f, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x142, 
    0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x147, 0xa, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x152, 0xa, 0x1c, 0xc, 0x1c, 
    0xe, 0x1c, 0x155, 0xb, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x5, 0x1d, 0x15c, 0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x7, 0x1e, 0x161, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x164, 0xb, 0x1e, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x7, 0x20, 0x16b, 
    0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x16e, 0xb, 0x20, 0x3, 0x21, 0x3, 0x21, 
    0x5, 0x21, 0x172, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 
    0x177, 0xa, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x17c, 
    0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x181, 0xa, 0x23, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 
    0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 
    0x18f, 0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 0x192, 0xb, 0x26, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x19a, 
    0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x7, 
    0x28, 0x1a1, 0xa, 0x28, 0xc, 0x28, 0xe, 0x28, 0x1a4, 0xb, 0x28, 0x3, 
    0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 
    0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x1b6, 0xa, 0x2a, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 
    0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x1c1, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 
    0x1c4, 0xb, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 
    0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 
    0x32, 0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x7, 
    0x33, 0x1de, 0xa, 0x33, 0xc, 0x33, 0xe, 0x33, 0x1e1, 0xb, 0x33, 0x5, 
    0x33, 0x1e3, 0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x5, 0x33, 0x1e9, 0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 
    0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 
    0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x5, 0x39, 
    0x1fb, 0xa, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x200, 
    0xa, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x204, 0xa, 0x3a, 0x3, 0x3a, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x20b, 0xa, 0x3a, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 
    0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x7, 0x3c, 0x218, 
    0xa, 0x3c, 0xc, 0x3c, 0xe, 0x3c, 0x21b, 0xb, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 
    0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x7, 
    0x3e, 0x225, 0xa, 0x3e, 0xc, 0x3e, 0xe, 0x3e, 0x228, 0xb, 0x3e, 0x3, 
    0x3f, 0x3, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 0x3, 0x41, 
    0x3, 0x41, 0x3, 0x41, 0x5, 0x41, 0x233, 0xa, 0x41, 0x3, 0x41, 0x3, 0x41, 
    0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x5, 0x42, 0x23a, 0xa, 0x42, 0x3, 0x42, 
    0x3, 0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x7, 
    0x44, 0x243, 0xa, 0x44, 0xc, 0x44, 0xe, 0x44, 0x246, 0xb, 0x44, 0x3, 
    0x45, 0x3, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x47, 0x3, 0x47, 
    0x5, 0x47, 0x24f, 0xa, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 
    0x7, 0x48, 0x255, 0xa, 0x48, 0xc, 0x48, 0xe, 0x48, 0x258, 0xb, 0x48, 
    0x3, 0x48, 0x3, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x5, 0x49, 0x25f, 
    0xa, 0x49, 0x3, 0x4a, 0x5, 0x4a, 0x262, 0xa, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 
    0x3, 0x4a, 0x5, 0x4a, 0x267, 0xa, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4c, 
    0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4e, 0x3, 
    0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x7, 0x4e, 0x275, 0xa, 0x4e, 0xc, 0x4e, 
    0xe, 0x4e, 0x278, 0xb, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 
    0x3, 0x4f, 0x3, 0x4f, 0x5, 0x4f, 0x280, 0xa, 0x4f, 0x3, 0x50, 0x5, 0x50, 
    0x283, 0xa, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x7, 0x50, 
    0x289, 0xa, 0x50, 0xc, 0x50, 0xe, 0x50, 0x28c, 0xb, 0x50, 0x3, 0x51, 
    0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x7, 0x51, 0x292, 0xa, 0x51, 0xc, 0x51, 
    0xe, 0x51, 0x295, 0xb, 0x51, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 
    0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 
    0x52, 0x5, 0x52, 0x2a2, 0xa, 0x52, 0x3, 0x53, 0x3, 0x53, 0x7, 0x53, 
    0x2a6, 0xa, 0x53, 0xc, 0x53, 0xe, 0x53, 0x2a9, 0xb, 0x53, 0x3, 0x54, 
    0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x5, 0x54, 0x2b1, 
    0xa, 0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x7, 0x55, 0x2b6, 0xa, 0x55, 
    0xc, 0x55, 0xe, 0x55, 0x2b9, 0xb, 0x55, 0x3, 0x56, 0x3, 0x56, 0x3, 0x57, 
    0x3, 0x57, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x5, 0x58, 0x2c2, 0xa, 0x58, 
    0x3, 0x58, 0x3, 0x58, 0x3, 0x59, 0x3, 0x59, 0x3, 0x5a, 0x5, 0x5a, 0x2c9, 
    0xa, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5b, 0x3, 0x5b, 0x5, 0x5b, 0x2cf, 
    0xa, 0x5b, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5e, 0x3, 
    0x5e, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x60, 0x3, 0x60, 0x3, 0x61, 0x3, 0x61, 
    0x3, 0x62, 0x3, 0x62, 0x3, 0x62, 0x2, 0x2, 0x63, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 
    0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
    0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 
    0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 
    0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 
    0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 
    0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 
    0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe, 0xc0, 0xc2, 0x2, 0x6, 0x3, 
    0x2, 0x5, 0x6, 0x4, 0x2, 0x4, 0x4, 0x10, 0x14, 0x4, 0x2, 0x5, 0x6, 0xe, 
    0xe, 0x4, 0x2, 0x15, 0x17, 0x21, 0x22, 0x2, 0x2cd, 0x2, 0xc4, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x6, 0xcf, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xa, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd9, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0xea, 0x3, 0x2, 0x2, 0x2, 0x10, 0xed, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x14, 0xf9, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x104, 0x3, 0x2, 0x2, 0x2, 0x18, 0x106, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x108, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x10b, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x113, 0x3, 0x2, 0x2, 0x2, 0x20, 0x117, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x11c, 0x3, 0x2, 0x2, 0x2, 0x24, 0x121, 0x3, 0x2, 0x2, 0x2, 0x26, 0x123, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x130, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x134, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x13b, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x143, 0x3, 0x2, 0x2, 0x2, 0x32, 0x14a, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x36, 0x14e, 0x3, 0x2, 0x2, 0x2, 
    0x38, 0x156, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x3c, 
    0x165, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x167, 0x3, 0x2, 0x2, 0x2, 0x40, 0x171, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x178, 0x3, 0x2, 0x2, 0x2, 0x44, 0x17d, 0x3, 
    0x2, 0x2, 0x2, 0x46, 0x185, 0x3, 0x2, 0x2, 0x2, 0x48, 0x187, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x193, 0x3, 0x2, 0x2, 
    0x2, 0x4e, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x50, 0x1a5, 0x3, 0x2, 0x2, 0x2, 
    0x52, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x54, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x56, 
    0x1bb, 0x3, 0x2, 0x2, 0x2, 0x58, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x1c5, 
    0x3, 0x2, 0x2, 0x2, 0x5c, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x1cc, 0x3, 
    0x2, 0x2, 0x2, 0x60, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x62, 0x1d0, 0x3, 0x2, 
    0x2, 0x2, 0x64, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x66, 0x1ed, 0x3, 0x2, 0x2, 
    0x2, 0x68, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x1f1, 0x3, 0x2, 0x2, 0x2, 
    0x6c, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x70, 
    0x1f7, 0x3, 0x2, 0x2, 0x2, 0x72, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x74, 0x20c, 
    0x3, 0x2, 0x2, 0x2, 0x76, 0x214, 0x3, 0x2, 0x2, 0x2, 0x78, 0x21c, 0x3, 
    0x2, 0x2, 0x2, 0x7a, 0x221, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x229, 0x3, 0x2, 
    0x2, 0x2, 0x7e, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x80, 0x22e, 0x3, 0x2, 0x2, 
    0x2, 0x82, 0x236, 0x3, 0x2, 0x2, 0x2, 0x84, 0x23d, 0x3, 0x2, 0x2, 0x2, 
    0x86, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x88, 0x247, 0x3, 0x2, 0x2, 0x2, 0x8a, 
    0x249, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x250, 
    0x3, 0x2, 0x2, 0x2, 0x90, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x92, 0x261, 0x3, 
    0x2, 0x2, 0x2, 0x94, 0x268, 0x3, 0x2, 0x2, 0x2, 0x96, 0x26a, 0x3, 0x2, 
    0x2, 0x2, 0x98, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x270, 0x3, 0x2, 0x2, 
    0x2, 0x9c, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x282, 0x3, 0x2, 0x2, 0x2, 
    0xa0, 0x28d, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x2a1, 0x3, 0x2, 0x2, 0x2, 0xa4, 
    0x2a3, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x2b0, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x2b2, 
    0x3, 0x2, 0x2, 0x2, 0xaa, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0xac, 0x2bc, 0x3, 
    0x2, 0x2, 0x2, 0xae, 0x2be, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x2c5, 0x3, 0x2, 
    0x2, 0x2, 0xb2, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x2ce, 0x3, 0x2, 0x2, 
    0x2, 0xb6, 0x2d0, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x2d2, 0x3, 0x2, 0x2, 0x2, 
    0xba, 0x2d4, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0xbe, 
    0x2d8, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x2da, 0x3, 0x2, 0x2, 0x2, 0xc2, 0x2dc, 
    0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0x5, 0x4, 0x3, 0x2, 0xc5, 0xc7, 0x5, 
    0xa, 0x6, 0x2, 0xc6, 0xc8, 0x5, 0x6, 0x4, 0x2, 0xc7, 0xc6, 0x3, 0x2, 
    0x2, 0x2, 0xc7, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x3, 0x2, 0x2, 
    0x2, 0xc9, 0xca, 0x7, 0x3, 0x2, 0x2, 0xca, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0xcb, 0xcc, 0x7, 0x36, 0x2, 0x2, 0xcc, 0xcd, 0x5, 0x6, 0x4, 0x2, 0xcd, 
    0xce, 0x7, 0x3d, 0x2, 0x2, 0xce, 0x5, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 
    0x7, 0x45, 0x2, 0x2, 0xd0, 0x7, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x7, 
    0x45, 0x2, 0x2, 0xd2, 0x9, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x5, 0xc, 
    0x7, 0x2, 0xd4, 0xd5, 0x5, 0x54, 0x2b, 0x2, 0xd5, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0xd6, 0xd7, 0x5, 0x3e, 0x20, 0x2, 0xd7, 0xd8, 0x7, 0x3, 0x2, 0x2, 
    0xd8, 0xda, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd9, 
    0xda, 0x3, 0x2, 0x2, 0x2, 0xda, 0xde, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 
    0x5, 0xe, 0x8, 0x2, 0xdc, 0xdd, 0x7, 0x3, 0x2, 0x2, 0xdd, 0xdf, 0x3, 
    0x2, 0x2, 0x2, 0xde, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x3, 0x2, 
    0x2, 0x2, 0xdf, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x5, 0x1a, 0xe, 
    0x2, 0xe1, 0xe2, 0x7, 0x3, 0x2, 0x2, 0xe2, 0xe4, 0x3, 0x2, 0x2, 0x2, 
    0xe3, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe4, 
    0xe8, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x5, 0x34, 0x1b, 0x2, 0xe6, 0xe7, 
    0x7, 0x3, 0x2, 0x2, 0xe7, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe5, 0x3, 
    0x2, 0x2, 0x2, 0xe8, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0xea, 0xeb, 0x7, 0x19, 0x2, 0x2, 0xeb, 0xec, 0x5, 0x10, 0x9, 
    0x2, 0xec, 0xf, 0x3, 0x2, 0x2, 0x2, 0xed, 0xf2, 0x5, 0x12, 0xa, 0x2, 
    0xee, 0xef, 0x7, 0x3, 0x2, 0x2, 0xef, 0xf1, 0x5, 0x12, 0xa, 0x2, 0xf0, 
    0xee, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf0, 
    0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf3, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0xf4, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x5, 0x14, 
    0xb, 0x2, 0xf6, 0xf7, 0x7, 0x4, 0x2, 0x2, 0xf7, 0xf8, 0x5, 0x16, 0xc, 
    0x2, 0xf8, 0x13, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x7, 0x45, 0x2, 0x2, 
    0xfa, 0x15, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfd, 0x5, 0x18, 0xd, 0x2, 0xfc, 
    0xfb, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xfd, 0x100, 
    0x3, 0x2, 0x2, 0x2, 0xfe, 0x101, 0x7, 0x45, 0x2, 0x2, 0xff, 0x101, 0x5, 
    0xb4, 0x5b, 0x2, 0x100, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x100, 0xff, 0x3, 
    0x2, 0x2, 0x2, 0x101, 0x105, 0x3, 0x2, 0x2, 0x2, 0x102, 0x105, 0x5, 
    0xba, 0x5e, 0x2, 0x103, 0x105, 0x5, 0xbc, 0x5f, 0x2, 0x104, 0xfc, 0x3, 
    0x2, 0x2, 0x2, 0x104, 0x102, 0x3, 0x2, 0x2, 0x2, 0x104, 0x103, 0x3, 
    0x2, 0x2, 0x2, 0x105, 0x17, 0x3, 0x2, 0x2, 0x2, 0x106, 0x107, 0x9, 0x2, 
    0x2, 0x2, 0x107, 0x19, 0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 0x7, 0x1a, 
    0x2, 0x2, 0x109, 0x10a, 0x5, 0x1c, 0xf, 0x2, 0x10a, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0x10b, 0x110, 0x5, 0x1e, 0x10, 0x2, 0x10c, 0x10d, 0x7, 0x3, 
    0x2, 0x2, 0x10d, 0x10f, 0x5, 0x1e, 0x10, 0x2, 0x10e, 0x10c, 0x3, 0x2, 
    0x2, 0x2, 0x10f, 0x112, 0x3, 0x2, 0x2, 0x2, 0x110, 0x10e, 0x3, 0x2, 
    0x2, 0x2, 0x110, 0x111, 0x3, 0x2, 0x2, 0x2, 0x111, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0x112, 0x110, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x5, 0x20, 0x11, 
    0x2, 0x114, 0x115, 0x7, 0x4, 0x2, 0x2, 0x115, 0x116, 0x5, 0x22, 0x12, 
    0x2, 0x116, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x7, 0x45, 0x2, 
    0x2, 0x118, 0x21, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11d, 0x5, 0x24, 0x13, 
    0x2, 0x11a, 0x11d, 0x5, 0x2c, 0x17, 0x2, 0x11b, 0x11d, 0x5, 0x30, 0x19, 
    0x2, 0x11c, 0x119, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11a, 0x3, 0x2, 0x2, 
    0x2, 0x11c, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x23, 0x3, 0x2, 0x2, 0x2, 
    0x11e, 0x122, 0x5, 0x20, 0x11, 0x2, 0x11f, 0x122, 0x5, 0x26, 0x14, 0x2, 
    0x120, 0x122, 0x5, 0x2a, 0x16, 0x2, 0x121, 0x11e, 0x3, 0x2, 0x2, 0x2, 
    0x121, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x121, 0x120, 0x3, 0x2, 0x2, 0x2, 
    0x122, 0x25, 0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 0x7, 0x7, 0x2, 0x2, 0x124, 
    0x129, 0x5, 0x28, 0x15, 0x2, 0x125, 0x126, 0x7, 0x8, 0x2, 0x2, 0x126, 
    0x128, 0x5, 0x28, 0x15, 0x2, 0x127, 0x125, 0x3, 0x2, 0x2, 0x2, 0x128, 
    0x12b, 0x3, 0x2, 0x2, 0x2, 0x129, 0x127, 0x3, 0x2, 0x2, 0x2, 0x129, 
    0x12a, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12b, 
    0x129, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0x7, 0x9, 0x2, 0x2, 0x12d, 
    0x27, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12f, 0x5, 0x14, 0xb, 0x2, 0x12f, 
    0x29, 0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 0x5, 0x16, 0xc, 0x2, 0x131, 
    0x132, 0x7, 0xa, 0x2, 0x2, 0x132, 0x133, 0x5, 0x16, 0xc, 0x2, 0x133, 
    0x2b, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x7, 0x1b, 0x2, 0x2, 0x135, 
    0x136, 0x7, 0x7, 0x2, 0x2, 0x136, 0x137, 0x5, 0x2e, 0x18, 0x2, 0x137, 
    0x138, 0x7, 0x9, 0x2, 0x2, 0x138, 0x139, 0x7, 0x1c, 0x2, 0x2, 0x139, 
    0x13a, 0x5, 0x22, 0x12, 0x2, 0x13a, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x13b, 
    0x140, 0x5, 0x24, 0x13, 0x2, 0x13c, 0x13d, 0x7, 0x8, 0x2, 0x2, 0x13d, 
    0x13f, 0x5, 0x24, 0x13, 0x2, 0x13e, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13f, 
    0x142, 0x3, 0x2, 0x2, 0x2, 0x140, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x140, 
    0x141, 0x3, 0x2, 0x2, 0x2, 0x141, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x142, 0x140, 
    0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x7, 0x1d, 0x2, 0x2, 0x144, 0x146, 
    0x5, 0x32, 0x1a, 0x2, 0x145, 0x147, 0x7, 0x3, 0x2, 0x2, 0x146, 0x145, 
    0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 0x3, 0x2, 0x2, 0x2, 0x147, 0x148, 
    0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 0x7, 0x20, 0x2, 0x2, 0x149, 0x31, 
    0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 0x5, 0x36, 0x1c, 0x2, 0x14b, 0x33, 
    0x3, 0x2, 0x2, 0x2, 0x14c, 0x14d, 0x5, 0x36, 0x1c, 0x2, 0x14d, 0x35, 
    0x3, 0x2, 0x2, 0x2, 0x14e, 0x153, 0x5, 0x38, 0x1d, 0x2, 0x14f, 0x150, 
    0x7, 0x3, 0x2, 0x2, 0x150, 0x152, 0x5, 0x38, 0x1d, 0x2, 0x151, 0x14f, 
    0x3, 0x2, 0x2, 0x2, 0x152, 0x155, 0x3, 0x2, 0x2, 0x2, 0x153, 0x151, 
    0x3, 0x2, 0x2, 0x2, 0x153, 0x154, 0x3, 0x2, 0x2, 0x2, 0x154, 0x37, 0x3, 
    0x2, 0x2, 0x2, 0x155, 0x153, 0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0x5, 
    0x3a, 0x1e, 0x2, 0x157, 0x158, 0x7, 0xb, 0x2, 0x2, 0x158, 0x15b, 0x5, 
    0x22, 0x12, 0x2, 0x159, 0x15a, 0x7, 0xc, 0x2, 0x2, 0x15a, 0x15c, 0x5, 
    0x9c, 0x4f, 0x2, 0x15b, 0x159, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15c, 0x3, 
    0x2, 0x2, 0x2, 0x15c, 0x39, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x162, 0x5, 0x3c, 
    0x1f, 0x2, 0x15e, 0x15f, 0x7, 0x8, 0x2, 0x2, 0x15f, 0x161, 0x5, 0x3c, 
    0x1f, 0x2, 0x160, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x161, 0x164, 0x3, 0x2, 
    0x2, 0x2, 0x162, 0x160, 0x3, 0x2, 0x2, 0x2, 0x162, 0x163, 0x3, 0x2, 
    0x2, 0x2, 0x163, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x164, 0x162, 0x3, 0x2, 0x2, 
    0x2, 0x165, 0x166, 0x7, 0x45, 0x2, 0x2, 0x166, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x167, 0x16c, 0x5, 0x40, 0x21, 0x2, 0x168, 0x169, 0x7, 0x3, 0x2, 
    0x2, 0x169, 0x16b, 0x5, 0x40, 0x21, 0x2, 0x16a, 0x168, 0x3, 0x2, 0x2, 
    0x2, 0x16b, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16a, 0x3, 0x2, 0x2, 
    0x2, 0x16c, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x3f, 0x3, 0x2, 0x2, 0x2, 
    0x16e, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x172, 0x5, 0x42, 0x22, 0x2, 
    0x170, 0x172, 0x5, 0x44, 0x23, 0x2, 0x171, 0x16f, 0x3, 0x2, 0x2, 0x2, 
    0x171, 0x170, 0x3, 0x2, 0x2, 0x2, 0x172, 0x173, 0x3, 0x2, 0x2, 0x2, 
    0x173, 0x174, 0x7, 0x3d, 0x2, 0x2, 0x174, 0x176, 0x5, 0xa, 0x6, 0x2, 
    0x175, 0x177, 0x5, 0x46, 0x24, 0x2, 0x176, 0x175, 0x3, 0x2, 0x2, 0x2, 
    0x176, 0x177, 0x3, 0x2, 0x2, 0x2, 0x177, 0x41, 0x3, 0x2, 0x2, 0x2, 0x178, 
    0x179, 0x7, 0x36, 0x2, 0x2, 0x179, 0x17b, 0x5, 0x46, 0x24, 0x2, 0x17a, 
    0x17c, 0x5, 0x48, 0x25, 0x2, 0x17b, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17b, 
    0x17c, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x43, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17e, 
    0x7, 0x37, 0x2, 0x2, 0x17e, 0x180, 0x5, 0x46, 0x24, 0x2, 0x17f, 0x181, 
    0x5, 0x48, 0x25, 0x2, 0x180, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x180, 0x181, 
    0x3, 0x2, 0x2, 0x2, 0x181, 0x182, 0x3, 0x2, 0x2, 0x2, 0x182, 0x183, 
    0x7, 0x43, 0x2, 0x2, 0x183, 0x184, 0x5, 0x20, 0x11, 0x2, 0x184, 0x45, 
    0x3, 0x2, 0x2, 0x2, 0x185, 0x186, 0x7, 0x45, 0x2, 0x2, 0x186, 0x47, 
    0x3, 0x2, 0x2, 0x2, 0x187, 0x188, 0x7, 0x7, 0x2, 0x2, 0x188, 0x189, 
    0x5, 0x4a, 0x26, 0x2, 0x189, 0x18a, 0x7, 0x9, 0x2, 0x2, 0x18a, 0x49, 
    0x3, 0x2, 0x2, 0x2, 0x18b, 0x190, 0x5, 0x4c, 0x27, 0x2, 0x18c, 0x18d, 
    0x7, 0x3, 0x2, 0x2, 0x18d, 0x18f, 0x5, 0x4c, 0x27, 0x2, 0x18e, 0x18c, 
    0x3, 0x2, 0x2, 0x2, 0x18f, 0x192, 0x3, 0x2, 0x2, 0x2, 0x190, 0x18e, 
    0x3, 0x2, 0x2, 0x2, 0x190, 0x191, 0x3, 0x2, 0x2, 0x2, 0x191, 0x4b, 0x3, 
    0x2, 0x2, 0x2, 0x192, 0x190, 0x3, 0x2, 0x2, 0x2, 0x193, 0x194, 0x5, 
    0x4e, 0x28, 0x2, 0x194, 0x199, 0x7, 0xb, 0x2, 0x2, 0x195, 0x19a, 0x7, 
    0x3a, 0x2, 0x2, 0x196, 0x197, 0x7, 0x3a, 0x2, 0x2, 0x197, 0x19a, 0x7, 
    0x42, 0x2, 0x2, 0x198, 0x19a, 0x7, 0x42, 0x2, 0x2, 0x199, 0x195, 0x3, 
    0x2, 0x2, 0x2, 0x199, 0x196, 0x3, 0x2, 0x2, 0x2, 0x199, 0x198, 0x3, 
    0x2, 0x2, 0x2, 0x199, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x19b, 0x3, 
    0x2, 0x2, 0x2, 0x19b, 0x19c, 0x5, 0x20, 0x11, 0x2, 0x19c, 0x4d, 0x3, 
    0x2, 0x2, 0x2, 0x19d, 0x1a2, 0x5, 0x50, 0x29, 0x2, 0x19e, 0x19f, 0x7, 
    0x8, 0x2, 0x2, 0x19f, 0x1a1, 0x5, 0x50, 0x29, 0x2, 0x1a0, 0x19e, 0x3, 
    0x2, 0x2, 0x2, 0x1a1, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a0, 0x3, 
    0x2, 0x2, 0x2, 0x1a2, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x4f, 0x3, 0x2, 
    0x2, 0x2, 0x1a4, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a6, 0x7, 0x45, 
    0x2, 0x2, 0x1a6, 0x51, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1b6, 0x5, 0x54, 
    0x2b, 0x2, 0x1a8, 0x1b6, 0x5, 0x5a, 0x2e, 0x2, 0x1a9, 0x1b6, 0x5, 0x64, 
    0x33, 0x2, 0x1aa, 0x1b6, 0x5, 0x74, 0x3b, 0x2, 0x1ab, 0x1b6, 0x5, 0x72, 
    0x3a, 0x2, 0x1ac, 0x1b6, 0x5, 0x70, 0x39, 0x2, 0x1ad, 0x1b6, 0x5, 0x8a, 
    0x46, 0x2, 0x1ae, 0x1b6, 0x5, 0x8c, 0x47, 0x2, 0x1af, 0x1b6, 0x5, 0x96, 
    0x4c, 0x2, 0x1b0, 0x1b6, 0x5, 0x98, 0x4d, 0x2, 0x1b1, 0x1b6, 0x5, 0x82, 
    0x42, 0x2, 0x1b2, 0x1b6, 0x5, 0x5c, 0x2f, 0x2, 0x1b3, 0x1b6, 0x5, 0x56, 
    0x2c, 0x2, 0x1b4, 0x1b6, 0x5, 0x62, 0x32, 0x2, 0x1b5, 0x1a7, 0x3, 0x2, 
    0x2, 0x2, 0x1b5, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1a9, 0x3, 0x2, 
    0x2, 0x2, 0x1b5, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1ab, 0x3, 0x2, 
    0x2, 0x2, 0x1b5, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1ad, 0x3, 0x2, 
    0x2, 0x2, 0x1b5, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1af, 0x3, 0x2, 
    0x2, 0x2, 0x1b5, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b1, 0x3, 0x2, 
    0x2, 0x2, 0x1b5, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b3, 0x3, 0x2, 
    0x2, 0x2, 0x1b5, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x53, 0x3, 0x2, 0x2, 
    0x2, 0x1b7, 0x1b8, 0x7, 0x1f, 0x2, 0x2, 0x1b8, 0x1b9, 0x5, 0x58, 0x2d, 
    0x2, 0x1b9, 0x1ba, 0x7, 0x20, 0x2, 0x2, 0x1ba, 0x55, 0x3, 0x2, 0x2, 
    0x2, 0x1bb, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x1bd, 0x1c2, 0x5, 0x52, 0x2a, 0x2, 0x1be, 0x1bf, 0x7, 0x3, 0x2, 0x2, 
    0x1bf, 0x1c1, 0x5, 0x52, 0x2a, 0x2, 0x1c0, 0x1be, 0x3, 0x2, 0x2, 0x2, 
    0x1c1, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c0, 0x3, 0x2, 0x2, 0x2, 
    0x1c2, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x59, 0x3, 0x2, 0x2, 0x2, 0x1c4, 
    0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c6, 0x5, 0x5e, 0x30, 0x2, 0x1c6, 
    0x1c7, 0x7, 0xc, 0x2, 0x2, 0x1c7, 0x1c8, 0x5, 0x60, 0x31, 0x2, 0x1c8, 
    0x5b, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1ca, 0x7, 0x43, 0x2, 0x2, 0x1ca, 
    0x1cb, 0x5, 0x9c, 0x4f, 0x2, 0x1cb, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x1cc, 
    0x1cd, 0x5, 0xa4, 0x53, 0x2, 0x1cd, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x1ce, 
    0x1cf, 0x5, 0x9c, 0x4f, 0x2, 0x1cf, 0x61, 0x3, 0x2, 0x2, 0x2, 0x1d0, 
    0x1d1, 0x7, 0x44, 0x2, 0x2, 0x1d1, 0x63, 0x3, 0x2, 0x2, 0x2, 0x1d2, 
    0x1d3, 0x7, 0x26, 0x2, 0x2, 0x1d3, 0x1d4, 0x5, 0x6c, 0x37, 0x2, 0x1d4, 
    0x1d5, 0x7, 0x27, 0x2, 0x2, 0x1d5, 0x1d6, 0x5, 0x66, 0x34, 0x2, 0x1d6, 
    0x1e2, 0x7, 0x3, 0x2, 0x2, 0x1d7, 0x1d8, 0x7, 0x29, 0x2, 0x2, 0x1d8, 
    0x1d9, 0x5, 0x6e, 0x38, 0x2, 0x1d9, 0x1da, 0x7, 0x27, 0x2, 0x2, 0x1da, 
    0x1db, 0x5, 0x6a, 0x36, 0x2, 0x1db, 0x1dc, 0x7, 0x3, 0x2, 0x2, 0x1dc, 
    0x1de, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1de, 
    0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1df, 
    0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e1, 
    0x1df, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1e2, 
    0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1e4, 
    0x1e5, 0x7, 0x28, 0x2, 0x2, 0x1e5, 0x1e6, 0x5, 0x68, 0x35, 0x2, 0x1e6, 
    0x1e7, 0x7, 0x3, 0x2, 0x2, 0x1e7, 0x1e9, 0x3, 0x2, 0x2, 0x2, 0x1e8, 
    0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e9, 0x3, 0x2, 0x2, 0x2, 0x1e9, 
    0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1eb, 0x7, 0x20, 0x2, 0x2, 0x1eb, 
    0x1ec, 0x7, 0x26, 0x2, 0x2, 0x1ec, 0x65, 0x3, 0x2, 0x2, 0x2, 0x1ed, 
    0x1ee, 0x5, 0x58, 0x2d, 0x2, 0x1ee, 0x67, 0x3, 0x2, 0x2, 0x2, 0x1ef, 
    0x1f0, 0x5, 0x58, 0x2d, 0x2, 0x1f0, 0x69, 0x3, 0x2, 0x2, 0x2, 0x1f1, 
    0x1f2, 0x5, 0x58, 0x2d, 0x2, 0x1f2, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x1f3, 
    0x1f4, 0x5, 0x9c, 0x4f, 0x2, 0x1f4, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x1f5, 
    0x1f6, 0x5, 0x9c, 0x4f, 0x2, 0x1f6, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x1f7, 
    0x1fa, 0x7, 0x38, 0x2, 0x2, 0x1f8, 0x1f9, 0x7, 0x39, 0x2, 0x2, 0x1f9, 
    0x1fb, 0x5, 0x9c, 0x4f, 0x2, 0x1fa, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1fa, 
    0x1fb, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x71, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1fd, 
    0x5, 0x8, 0x5, 0x2, 0x1fd, 0x1fe, 0x7, 0xb, 0x2, 0x2, 0x1fe, 0x200, 
    0x3, 0x2, 0x2, 0x2, 0x1ff, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x200, 
    0x3, 0x2, 0x2, 0x2, 0x200, 0x203, 0x3, 0x2, 0x2, 0x2, 0x201, 0x204, 
    0x5, 0x7e, 0x40, 0x2, 0x202, 0x204, 0x5, 0x80, 0x41, 0x2, 0x203, 0x201, 
    0x3, 0x2, 0x2, 0x2, 0x203, 0x202, 0x3, 0x2, 0x2, 0x2, 0x203, 0x204, 
    0x3, 0x2, 0x2, 0x2, 0x204, 0x205, 0x3, 0x2, 0x2, 0x2, 0x205, 0x206, 
    0x7, 0x3c, 0x2, 0x2, 0x206, 0x207, 0x5, 0x58, 0x2d, 0x2, 0x207, 0x208, 
    0x7, 0x20, 0x2, 0x2, 0x208, 0x20a, 0x7, 0x3c, 0x2, 0x2, 0x209, 0x20b, 
    0x5, 0x8, 0x5, 0x2, 0x20a, 0x209, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x20b, 
    0x3, 0x2, 0x2, 0x2, 0x20b, 0x73, 0x3, 0x2, 0x2, 0x2, 0x20c, 0x20d, 0x7, 
    0x2a, 0x2, 0x2, 0x20d, 0x20e, 0x5, 0x9c, 0x4f, 0x2, 0x20e, 0x20f, 0x7, 
    0x3d, 0x2, 0x2, 0x20f, 0x210, 0x5, 0x76, 0x3c, 0x2, 0x210, 0x211, 0x7, 
    0x3, 0x2, 0x2, 0x211, 0x212, 0x7, 0x20, 0x2, 0x2, 0x212, 0x213, 0x7, 
    0x2a, 0x2, 0x2, 0x213, 0x75, 0x3, 0x2, 0x2, 0x2, 0x214, 0x219, 0x5, 
    0x78, 0x3d, 0x2, 0x215, 0x216, 0x7, 0x3, 0x2, 0x2, 0x216, 0x218, 0x5, 
    0x78, 0x3d, 0x2, 0x217, 0x215, 0x3, 0x2, 0x2, 0x2, 0x218, 0x21b, 0x3, 
    0x2, 0x2, 0x2, 0x219, 0x217, 0x3, 0x2, 0x2, 0x2, 0x219, 0x21a, 0x3, 
    0x2, 0x2, 0x2, 0x21a, 0x77, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x219, 0x3, 0x2, 
    0x2, 0x2, 0x21c, 0x21d, 0x7, 0x39, 0x2, 0x2, 0x21d, 0x21e, 0x5, 0x7a, 
    0x3e, 0x2, 0x21e, 0x21f, 0x7, 0xd, 0x2, 0x2, 0x21f, 0x220, 0x5, 0x52, 
    0x2a, 0x2, 0x220, 0x79, 0x3, 0x2, 0x2, 0x2, 0x221, 0x226, 0x5, 0x7c, 
    0x3f, 0x2, 0x222, 0x223, 0x7, 0xe, 0x2, 0x2, 0x223, 0x225, 0x5, 0x7c, 
    0x3f, 0x2, 0x224, 0x222, 0x3, 0x2, 0x2, 0x2, 0x225, 0x228, 0x3, 0x2, 
    0x2, 0x2, 0x226, 0x224, 0x3, 0x2, 0x2, 0x2, 0x226, 0x227, 0x3, 0x2, 
    0x2, 0x2, 0x227, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x228, 0x226, 0x3, 0x2, 0x2, 
    0x2, 0x229, 0x22a, 0x5, 0x16, 0xc, 0x2, 0x22a, 0x7d, 0x3, 0x2, 0x2, 
    0x2, 0x22b, 0x22c, 0x7, 0x2d, 0x2, 0x2, 0x22c, 0x22d, 0x5, 0x9c, 0x4f, 
    0x2, 0x22d, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x22e, 0x22f, 0x7, 0x2f, 0x2, 
    0x2, 0x22f, 0x230, 0x5, 0xa4, 0x53, 0x2, 0x230, 0x232, 0x7, 0x3a, 0x2, 
    0x2, 0x231, 0x233, 0x7, 0x3b, 0x2, 0x2, 0x232, 0x231, 0x3, 0x2, 0x2, 
    0x2, 0x232, 0x233, 0x3, 0x2, 0x2, 0x2, 0x233, 0x234, 0x3, 0x2, 0x2, 
    0x2, 0x234, 0x235, 0x5, 0x2a, 0x16, 0x2, 0x235, 0x81, 0x3, 0x2, 0x2, 
    0x2, 0x236, 0x237, 0x5, 0x84, 0x43, 0x2, 0x237, 0x239, 0x7, 0x7, 0x2, 
    0x2, 0x238, 0x23a, 0x5, 0x86, 0x44, 0x2, 0x239, 0x238, 0x3, 0x2, 0x2, 
    0x2, 0x239, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x23b, 0x3, 0x2, 0x2, 
    0x2, 0x23b, 0x23c, 0x7, 0x9, 0x2, 0x2, 0x23c, 0x83, 0x3, 0x2, 0x2, 0x2, 
    0x23d, 0x23e, 0x7, 0x45, 0x2, 0x2, 0x23e, 0x85, 0x3, 0x2, 0x2, 0x2, 
    0x23f, 0x244, 0x5, 0x88, 0x45, 0x2, 0x240, 0x241, 0x7, 0x8, 0x2, 0x2, 
    0x241, 0x243, 0x5, 0x88, 0x45, 0x2, 0x242, 0x240, 0x3, 0x2, 0x2, 0x2, 
    0x243, 0x246, 0x3, 0x2, 0x2, 0x2, 0x244, 0x242, 0x3, 0x2, 0x2, 0x2, 
    0x244, 0x245, 0x3, 0x2, 0x2, 0x2, 0x245, 0x87, 0x3, 0x2, 0x2, 0x2, 0x246, 
    0x244, 0x3, 0x2, 0x2, 0x2, 0x247, 0x248, 0x5, 0x9c, 0x4f, 0x2, 0x248, 
    0x89, 0x3, 0x2, 0x2, 0x2, 0x249, 0x24a, 0x7, 0x3e, 0x2, 0x2, 0x24a, 
    0x24b, 0x5, 0x8e, 0x48, 0x2, 0x24b, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x24c, 
    0x24e, 0x7, 0x3f, 0x2, 0x2, 0x24d, 0x24f, 0x5, 0x8e, 0x48, 0x2, 0x24e, 
    0x24d, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x24f, 
    0x8d, 0x3, 0x2, 0x2, 0x2, 0x250, 0x251, 0x7, 0x7, 0x2, 0x2, 0x251, 0x256, 
    0x5, 0x90, 0x49, 0x2, 0x252, 0x253, 0x7, 0x8, 0x2, 0x2, 0x253, 0x255, 
    0x5, 0x90, 0x49, 0x2, 0x254, 0x252, 0x3, 0x2, 0x2, 0x2, 0x255, 0x258, 
    0x3, 0x2, 0x2, 0x2, 0x256, 0x254, 0x3, 0x2, 0x2, 0x2, 0x256, 0x257, 
    0x3, 0x2, 0x2, 0x2, 0x257, 0x259, 0x3, 0x2, 0x2, 0x2, 0x258, 0x256, 
    0x3, 0x2, 0x2, 0x2, 0x259, 0x25a, 0x7, 0x9, 0x2, 0x2, 0x25a, 0x8f, 0x3, 
    0x2, 0x2, 0x2, 0x25b, 0x25e, 0x5, 0x9c, 0x4f, 0x2, 0x25c, 0x25d, 0x7, 
    0xb, 0x2, 0x2, 0x25d, 0x25f, 0x5, 0x92, 0x4a, 0x2, 0x25e, 0x25c, 0x3, 
    0x2, 0x2, 0x2, 0x25e, 0x25f, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x91, 0x3, 0x2, 
    0x2, 0x2, 0x260, 0x262, 0x5, 0x18, 0xd, 0x2, 0x261, 0x260, 0x3, 0x2, 
    0x2, 0x2, 0x261, 0x262, 0x3, 0x2, 0x2, 0x2, 0x262, 0x263, 0x3, 0x2, 
    0x2, 0x2, 0x263, 0x266, 0x5, 0xb6, 0x5c, 0x2, 0x264, 0x265, 0x7, 0xb, 
    0x2, 0x2, 0x265, 0x267, 0x5, 0x94, 0x4b, 0x2, 0x266, 0x264, 0x3, 0x2, 
    0x2, 0x2, 0x266, 0x267, 0x3, 0x2, 0x2, 0x2, 0x267, 0x93, 0x3, 0x2, 0x2, 
    0x2, 0x268, 0x269, 0x5, 0xb6, 0x5c, 0x2, 0x269, 0x95, 0x3, 0x2, 0x2, 
    0x2, 0x26a, 0x26b, 0x7, 0x40, 0x2, 0x2, 0x26b, 0x26c, 0x5, 0x9a, 0x4e, 
    0x2, 0x26c, 0x97, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x26e, 0x7, 0x41, 0x2, 
    0x2, 0x26e, 0x26f, 0x5, 0x9a, 0x4e, 0x2, 0x26f, 0x99, 0x3, 0x2, 0x2, 
    0x2, 0x270, 0x271, 0x7, 0x7, 0x2, 0x2, 0x271, 0x276, 0x5, 0xa4, 0x53, 
    0x2, 0x272, 0x273, 0x7, 0x8, 0x2, 0x2, 0x273, 0x275, 0x5, 0xa4, 0x53, 
    0x2, 0x274, 0x272, 0x3, 0x2, 0x2, 0x2, 0x275, 0x278, 0x3, 0x2, 0x2, 
    0x2, 0x276, 0x274, 0x3, 0x2, 0x2, 0x2, 0x276, 0x277, 0x3, 0x2, 0x2, 
    0x2, 0x277, 0x279, 0x3, 0x2, 0x2, 0x2, 0x278, 0x276, 0x3, 0x2, 0x2, 
    0x2, 0x279, 0x27a, 0x7, 0x9, 0x2, 0x2, 0x27a, 0x9b, 0x3, 0x2, 0x2, 0x2, 
    0x27b, 0x27f, 0x5, 0x9e, 0x50, 0x2, 0x27c, 0x27d, 0x5, 0xbe, 0x60, 0x2, 
    0x27d, 0x27e, 0x5, 0x9e, 0x50, 0x2, 0x27e, 0x280, 0x3, 0x2, 0x2, 0x2, 
    0x27f, 0x27c, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x280, 0x3, 0x2, 0x2, 0x2, 
    0x280, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x281, 0x283, 0x5, 0x18, 0xd, 0x2, 
    0x282, 0x281, 0x3, 0x2, 0x2, 0x2, 0x282, 0x283, 0x3, 0x2, 0x2, 0x2, 
    0x283, 0x284, 0x3, 0x2, 0x2, 0x2, 0x284, 0x28a, 0x5, 0xa0, 0x51, 0x2, 
    0x285, 0x286, 0x5, 0xc0, 0x61, 0x2, 0x286, 0x287, 0x5, 0xa0, 0x51, 0x2, 
    0x287, 0x289, 0x3, 0x2, 0x2, 0x2, 0x288, 0x285, 0x3, 0x2, 0x2, 0x2, 
    0x289, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x28a, 0x288, 0x3, 0x2, 0x2, 0x2, 
    0x28a, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x28b, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x28c, 
    0x28a, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x293, 0x5, 0xa2, 0x52, 0x2, 0x28e, 
    0x28f, 0x5, 0xc2, 0x62, 0x2, 0x28f, 0x290, 0x5, 0xa2, 0x52, 0x2, 0x290, 
    0x292, 0x3, 0x2, 0x2, 0x2, 0x291, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x292, 
    0x295, 0x3, 0x2, 0x2, 0x2, 0x293, 0x291, 0x3, 0x2, 0x2, 0x2, 0x293, 
    0x294, 0x3, 0x2, 0x2, 0x2, 0x294, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x295, 0x293, 
    0x3, 0x2, 0x2, 0x2, 0x296, 0x2a2, 0x5, 0xae, 0x58, 0x2, 0x297, 0x2a2, 
    0x5, 0xa4, 0x53, 0x2, 0x298, 0x2a2, 0x5, 0xb2, 0x5a, 0x2, 0x299, 0x2a2, 
    0x5, 0xba, 0x5e, 0x2, 0x29a, 0x2a2, 0x5, 0xbc, 0x5f, 0x2, 0x29b, 0x29c, 
    0x7, 0x25, 0x2, 0x2, 0x29c, 0x2a2, 0x5, 0xa2, 0x52, 0x2, 0x29d, 0x29e, 
    0x7, 0x7, 0x2, 0x2, 0x29e, 0x29f, 0x5, 0x9c, 0x4f, 0x2, 0x29f, 0x2a0, 
    0x7, 0x9, 0x2, 0x2, 0x2a0, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x296, 
    0x3, 0x2, 0x2, 0x2, 0x2a1, 0x297, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x298, 
    0x3, 0x2, 0x2, 0x2, 0x2a1, 0x299, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x29a, 
    0x3, 0x2, 0x2, 0x2, 0x2a1, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x29d, 
    0x3, 0x2, 0x2, 0x2, 0x2a2, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x2a3, 0x2a7, 0x5, 
    0x3c, 0x1f, 0x2, 0x2a4, 0x2a6, 0x5, 0xa6, 0x54, 0x2, 0x2a5, 0x2a4, 0x3, 
    0x2, 0x2, 0x2, 0x2a6, 0x2a9, 0x3, 0x2, 0x2, 0x2, 0x2a7, 0x2a5, 0x3, 
    0x2, 0x2, 0x2, 0x2a7, 0x2a8, 0x3, 0x2, 0x2, 0x2, 0x2a8, 0xa5, 0x3, 0x2, 
    0x2, 0x2, 0x2a9, 0x2a7, 0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2ab, 0x7, 0x7, 
    0x2, 0x2, 0x2ab, 0x2ac, 0x5, 0xa8, 0x55, 0x2, 0x2ac, 0x2ad, 0x7, 0x9, 
    0x2, 0x2, 0x2ad, 0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2af, 0x7, 0xf, 
    0x2, 0x2, 0x2af, 0x2b1, 0x5, 0xac, 0x57, 0x2, 0x2b0, 0x2aa, 0x3, 0x2, 
    0x2, 0x2, 0x2b0, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0xa7, 0x3, 0x2, 0x2, 
    0x2, 0x2b2, 0x2b7, 0x5, 0xaa, 0x56, 0x2, 0x2b3, 0x2b4, 0x7, 0x8, 0x2, 
    0x2, 0x2b4, 0x2b6, 0x5, 0xaa, 0x56, 0x2, 0x2b5, 0x2b3, 0x3, 0x2, 0x2, 
    0x2, 0x2b6, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2b5, 0x3, 0x2, 0x2, 
    0x2, 0x2b7, 0x2b8, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0xa9, 0x3, 0x2, 0x2, 0x2, 
    0x2b9, 0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2bb, 0x5, 0x9c, 0x4f, 0x2, 
    0x2bb, 0xab, 0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2bd, 0x7, 0x45, 0x2, 0x2, 
    0x2bd, 0xad, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2bf, 0x5, 0xb0, 0x59, 0x2, 
    0x2bf, 0x2c1, 0x7, 0x7, 0x2, 0x2, 0x2c0, 0x2c2, 0x5, 0x86, 0x44, 0x2, 
    0x2c1, 0x2c0, 0x3, 0x2, 0x2, 0x2, 0x2c1, 0x2c2, 0x3, 0x2, 0x2, 0x2, 
    0x2c2, 0x2c3, 0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2c4, 0x7, 0x9, 0x2, 0x2, 
    0x2c4, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c6, 0x7, 0x45, 0x2, 0x2, 
    0x2c6, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x2c7, 0x2c9, 0x5, 0x18, 0xd, 0x2, 
    0x2c8, 0x2c7, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2c9, 0x3, 0x2, 0x2, 0x2, 
    0x2c9, 0x2ca, 0x3, 0x2, 0x2, 0x2, 0x2ca, 0x2cb, 0x5, 0xb4, 0x5b, 0x2, 
    0x2cb, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x2cc, 0x2cf, 0x5, 0xb6, 0x5c, 0x2, 
    0x2cd, 0x2cf, 0x5, 0xb8, 0x5d, 0x2, 0x2ce, 0x2cc, 0x3, 0x2, 0x2, 0x2, 
    0x2ce, 0x2cd, 0x3, 0x2, 0x2, 0x2, 0x2cf, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x2d0, 
    0x2d1, 0x7, 0x46, 0x2, 0x2, 0x2d1, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x2d2, 
    0x2d3, 0x7, 0x47, 0x2, 0x2, 0x2d3, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x2d4, 
    0x2d5, 0x7, 0x4b, 0x2, 0x2, 0x2d5, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x2d6, 
    0x2d7, 0x7, 0x4c, 0x2, 0x2, 0x2d7, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x2d8, 
    0x2d9, 0x9, 0x3, 0x2, 0x2, 0x2d9, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x2da, 0x2db, 
    0x9, 0x4, 0x2, 0x2, 0x2db, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x2dc, 0x2dd, 0x9, 
    0x5, 0x2, 0x2, 0x2dd, 0xc3, 0x3, 0x2, 0x2, 0x2, 0x3b, 0xc7, 0xd9, 0xde, 
    0xe3, 0xe8, 0xf2, 0xfc, 0x100, 0x104, 0x110, 0x11c, 0x121, 0x129, 0x140, 
    0x146, 0x153, 0x15b, 0x162, 0x16c, 0x171, 0x176, 0x17b, 0x180, 0x190, 
    0x199, 0x1a2, 0x1b5, 0x1c2, 0x1df, 0x1e2, 0x1e8, 0x1fa, 0x1ff, 0x203, 
    0x20a, 0x219, 0x226, 0x232, 0x239, 0x244, 0x24e, 0x256, 0x25e, 0x261, 
    0x266, 0x276, 0x27f, 0x282, 0x28a, 0x293, 0x2a1, 0x2a7, 0x2b0, 0x2b7, 
    0x2c1, 0x2c8, 0x2ce, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ADAParser::Initializer ADAParser::_init;
