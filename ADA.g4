grammar ADA;

@header {
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;
}

program           : programHeader block (programIdentifier)? ';';
programHeader     : PROCEDURE programIdentifier IS ; 

programIdentifier   locals [ SymtabEntry *entry = nullptr ]
    : IDENTIFIER ;
    
statementIdentifier   locals [ SymtabEntry *entry = nullptr ]
    : IDENTIFIER ;
    
block         : declarations compoundStatement ;
declarations  : ( subprogramPart ';')? ( constantsPart ';' )? 
                ( typesPart ';' )? ( variablesPart ';' )?  ;

constantsPart           : CONST constantDefinitionsList ;
constantDefinitionsList : constantDefinition ( ';' constantDefinition )* ;
constantDefinition      : constantIdentifier '=' constant ;

constantIdentifier  locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ]
    : IDENTIFIER ;

constant            locals [ Typespec *type = nullptr, Object value = nullptr ]  
    : sign? ( IDENTIFIER | unsignedNumber )
    | characterConstant
    | stringConstant
    ;

sign : '-' | '+' ;

typesPart           : TYPE typeDefinitionsList ;
typeDefinitionsList : typeDefinition ( ';' typeDefinition )* ;
typeDefinition      : typeIdentifier '=' typeSpecification ;

typeIdentifier      locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ]
    : IDENTIFIER ;

typeSpecification   locals [ Typespec *type = nullptr ]
    : simpleType        # simpleTypespec
    | arrayType         # arrayTypespec 
    | recordType        # recordTypespec
    ;

simpleType          locals [ Typespec *type = nullptr ] 
    : typeIdentifier    # typeIdentifierTypespec 
    | enumerationType   # enumerationTypespec
    | subrangeType      # subrangeTypespec
    ;
           
enumerationType     : '(' enumerationConstant ( ',' enumerationConstant )* ')' ;
enumerationConstant : constantIdentifier ;
subrangeType        : constant '..' constant ;

arrayType
    : ARRAY '(' arrayDimensionList ')' OF typeSpecification ;
arrayDimensionList : simpleType ( ',' simpleType )* ;

recordType          locals [ SymtabEntry *entry = nullptr ]   
    : RECORD recordFields ';'? END ;
recordFields : variableDeclarationsList ;
           
variablesPart            : variableDeclarationsList ;
variableDeclarationsList : variableDeclarations ( ';' variableDeclarations )* ;
variableDeclarations     : variableIdentifierList ':' typeSpecification (':=' expression)? ;
variableIdentifierList   : variableIdentifier ( ',' variableIdentifier )* ;

variableIdentifier  locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ] 
    : IDENTIFIER ;

subprogramPart    : subprogramBody ( ';' subprogramBody)* ;
subprogramBody 	  : (procedureHead | functionHead ) IS block (routineIdentifier)? ;
procedureHead     : PROCEDURE routineIdentifier parameters? ;
functionHead      : FUNCTION  routineIdentifier parameters? RETURN typeIdentifier;

routineIdentifier   locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ]
    : IDENTIFIER ;

parameters                : '(' parameterDeclarationsList ')' ;
parameterDeclarationsList : parameterDeclarations ( ';' parameterDeclarations )* ;
parameterDeclarations     :  parameterIdentifierList ':'(IN | IN OUT | OUT)? typeIdentifier ;
parameterIdentifierList   : parameterIdentifier ( ',' parameterIdentifier )* ;

parameterIdentifier   locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ]
    : IDENTIFIER ;
    


statement : compoundStatement
          | assignmentStatement
          | ifStatement
          | caseStatement
          | loopStatement
          | exitStatement
          | putStatement
          | putLineStatement
          | getStatement
          | getLineStatement
          | procedureCallStatement
          | returnStatement
          | emptyStatement
          | newLineStatement
          ;

compoundStatement : BEGIN statementList END ;
emptyStatement : ;
     
statementList       : statement ( ';' statement )* ;
assignmentStatement : lhs ':=' rhs ;
returnStatement     : RETURN expression;
lhs                 locals [ Typespec *type = nullptr ] 
    : variable ;
rhs : expression ;
newLineStatement    :  NEWLINE;

ifStatement    : IF ifCondition THEN trueStatementList ';' 
				((ELSIF elsifCondition THEN elseStatementList ';')*)?
				( ELSE falseStatementList ';')? END IF;
trueStatementList  : statementList ;
falseStatementList : statementList ;
elseStatementList  : statementList;
ifCondition : expression;
elsifCondition: expression;

exitStatement : EXIT (WHEN expression)?;
loopStatement : (statementIdentifier ':')? (whileStatement | forStatement)? 
				LOOP statementList  END LOOP (statementIdentifier)? ;

caseStatement
        locals [ map<int, ADAParser::StatementContext*> *jumpTable = nullptr ]
    : CASE expression IS caseBranchList ';'END CASE ;
    
caseBranchList   : caseBranch (';' caseBranch )* ;
caseBranch       : WHEN caseConstantList '=>' statement ;
caseConstantList : caseConstant ( '|' caseConstant )* ;

caseConstant        locals [ Typespec *type = nullptr, int value = 0 ]
    : constant ;

whileStatement  : WHILE expression;

forStatement : FOR variable IN (REVERSE)? subrangeType;
                   

procedureCallStatement : procedureName '(' argumentList? ')' ;

procedureName   locals [ SymtabEntry *entry = nullptr ] 
    : IDENTIFIER ;

argumentList : argument ( ',' argument )* ;
argument     : expression ;

putStatement   : PUT putArguments ;
putLineStatement : PUTLINE putArguments? ;
putArguments   : '(' putArgument (',' putArgument)* ')' ;
putArgument    : expression (':' fieldWidth)? ;
fieldWidth       : sign? integerConstant (':' decimalPlaces)? ;
decimalPlaces    : integerConstant ;

getStatement   : GET getArguments ;
getLineStatement : GETLINE getArguments ;
getArguments   : '(' variable ( ',' variable )* ')' ;

expression          locals [ Typespec *type = nullptr ] 
    : simpleExpression (relOp simpleExpression)? ;
    
simpleExpression    locals [ Typespec *type = nullptr ] 
    : sign? term (addOp term)* ;
    
term                locals [ Typespec *type = nullptr ]
    : factor (mulOp factor)* ;

factor              locals [ Typespec *type = nullptr ] 
    : functionCall         # functionCallFactor
    |variable             # variableFactor
    | number               # numberFactor
    | characterConstant    # characterFactor
    | stringConstant       # stringFactor
    | NOT factor           # notFactor
    | '(' expression ')'   # parenthesizedFactor
    ;

variable        locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ] 
    : variableIdentifier modifier* ;

modifier  : '(' indexList ')' | '.' field ;
indexList : index ( ',' index )* ;
index     : expression ; 

field           locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ]     
    : IDENTIFIER ;

functionCall : functionName '(' argumentList? ')' ;
functionName    locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ] 
    : IDENTIFIER ;
     
number          : sign? unsignedNumber ;
unsignedNumber  : integerConstant | realConstant ;
integerConstant : INTEGER ;
realConstant    : REAL;

characterConstant : CHARACTER ;
stringConstant    : STRING ;
       
relOp : '=' | '/=' | '<' | '<=' | '>' | '>=' ;
addOp : '+' | '-' | '|' ;
mulOp : '*' | '/' | DIV | MOD | '&' ;

fragment A : ('a' | 'A') ;
fragment B : ('b' | 'B') ;
fragment C : ('c' | 'C') ;
fragment D : ('d' | 'D') ;
fragment E : ('e' | 'E') ;
fragment F : ('f' | 'F') ;
fragment G : ('g' | 'G') ;
fragment H : ('h' | 'H') ;
fragment I : ('i' | 'I') ;
fragment J : ('j' | 'J') ;
fragment K : ('k' | 'K') ;
fragment L : ('l' | 'L') ;
fragment M : ('m' | 'M') ;
fragment N : ('n' | 'N') ;
fragment O : ('o' | 'O') ;
fragment P : ('p' | 'P') ;
fragment Q : ('q' | 'Q') ;
fragment R : ('r' | 'R') ;
fragment S : ('s' | 'S') ;
fragment T : ('t' | 'T') ;
fragment U : ('u' | 'U') ;
fragment V : ('v' | 'V') ;
fragment W : ('w' | 'W') ;
fragment X : ('x' | 'X') ;
fragment Y : ('y' | 'Y') ;
fragment Z : ('z' | 'Z') ;

PROGRAM   : P R O G R A M ;
CONST     : C O N S T ;
TYPE      : T Y P E ;
ARRAY     : A R R A Y ;
OF        : O F ;
RECORD    : R E C O R D ;
VAR       : V A R ;
BEGIN     : B E G I N ;
END       : E N D ;
DIV       : D I V ;
MOD       : M O D ;
AND       : A N D ;
OR        : O R ;
NOT       : N O T ;
IF        : I F ;
THEN      : T H E N ;
ELSE      : E L S E ;
ELSIF	  : E L S I F ;
CASE      : C A S E ;
REPEAT    : R E P E A T ;
UNTIL     : U N T I L ;
WHILE     : W H I L E ;
DO        : D O ;
FOR       : F O R ;
TO        : T O ;
DOWNTO    : D O W N T O ;
WRITE     : W R I T E ;
WRITELN   : W R I T E L N ;
READ      : R E A D ;
READLN    : R E A D L N ;
PROCEDURE : P R O C E D U R E ;
FUNCTION  : F U N C T I O N ;
EXIT 	  : E X I T;
WHEN 	  : W H E N;
IN		  : I N;
REVERSE   : R E V E R S E;
LOOP	  : L O O P;
IS 		  : I S;
PUT 	  : P U T;
PUTLINE  : P U T L I N E;
GET 	  : G E T;
GETLINE  : G E T L I N E;
OUT 	  : O U T;
RETURN    : R E T U R N;
NEWLINE   : N E W L I N E;

IDENTIFIER : [a-zA-Z][a-zA-Z0-9]* ;
INTEGER    : [0-9]+ ;

REAL       : INTEGER '.' INTEGER
           | INTEGER ('e' | 'E') ('+' | '-')? INTEGER
           | INTEGER '.' INTEGER ('e' | 'E') ('+' | '-')? INTEGER
           ;

NEW_LINE : '\r'? '\n' -> skip  ;
WS      : [ \t]+ -> skip ; 

QUOTE     : '\'' ;
CHARACTER : QUOTE CHARACTER_CHAR QUOTE ;
STRING    : '"' STRING_CHAR* '"' ;

fragment CHARACTER_CHAR : ~('\'')   // any non-quote character
                        ;

fragment STRING_CHAR : QUOTE QUOTE  // two consecutive quotes
                     | ~('"')      // any non-quote character
                     ;

COMMENT : '--' COMMENT_CHARACTER* -> skip ;

fragment COMMENT_CHARACTER : ~('}') ;
                     
                     