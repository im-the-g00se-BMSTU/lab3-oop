```mermaid

classDiagram

&#x20;   QMainWindow <|-- MainWindow



&#x20;   MainWindow \*-- Facade

&#x20;   MainWindow ..> InputCommandType



&#x20;   Facade \*-- ExpressionEditor

&#x20;   Facade \*-- ExpressionCalculator

&#x20;   Facade --> InputCommandType



&#x20;   ExpressionEditor \*-- LexemeFactory

&#x20;   ExpressionEditor o-- Lexeme



&#x20;   ExpressionCalculator ..> Lexeme



&#x20;   LexemeFactory ..> Lexeme

&#x20;   LexemeFactory ..> NumberLexeme

&#x20;   LexemeFactory ..> BinaryOperator

&#x20;   LexemeFactory ..> UnaryOperator

&#x20;   LexemeFactory ..> LeftParenLexeme

&#x20;   LexemeFactory ..> RightParenLexeme



&#x20;   Lexeme <|-- NumberLexeme

&#x20;   Lexeme <|-- MathOperator

&#x20;   Lexeme <|-- LeftParenLexeme

&#x20;   Lexeme <|-- RightParenLexeme



&#x20;   MathOperator <|-- BinaryOperator

&#x20;   MathOperator <|-- UnaryOperator



&#x20;   Lexeme --> LexemeType

&#x20;   MathOperator --> OperatorPriority



&#x20;   LexemeException --|> std\_exception

&#x20;   MathException --|> std\_exception



&#x20;   class MainWindow {

&#x20;       -Ui::MainWindow\* ui

&#x20;       -Facade facade

&#x20;       -QMovie\* monkeyMovie

&#x20;       -connectButtons()

&#x20;       -updateUi()

&#x20;       -onDigitButtonClicked()

&#x20;       -onOperatorButtonClicked()

&#x20;   }



&#x20;   class Facade {

&#x20;       -ExpressionEditor editor

&#x20;       -ExpressionCalculator calculator

&#x20;       -string errorText

&#x20;       -map commandHandlers

&#x20;       +handleDigitInput(string text)

&#x20;       +handleOperatorInput(string text)

&#x20;       +handleCommandInput(InputCommandType type)

&#x20;       +evaluateExpression()

&#x20;       +getDisplayText() string

&#x20;       +getErrorText() string

&#x20;   }



&#x20;   class ExpressionEditor {

&#x20;       -vector\~shared\_ptr\~Lexeme\~\~ lexemes

&#x20;       -LexemeFactory lexemeFactory

&#x20;       -EditorMode mode

&#x20;       +appendDigit(char digit)

&#x20;       +appendDot()

&#x20;       +appendOperator(string text)

&#x20;       +appendLeftParen()

&#x20;       +appendRightParen()

&#x20;       +setResult(string value)

&#x20;       +canEvaluate() bool

&#x20;       +getLexemes() vector

&#x20;   }



&#x20;   class ExpressionCalculator {

&#x20;       +translateToRpn(vector lexemes) vector

&#x20;       +evaluate(vector rpn) double

&#x20;       -appendRemainingOperators()

&#x20;       -handleRightParen()

&#x20;       -handleOperator()

&#x20;   }



&#x20;   class LexemeFactory {

&#x20;       -map lexemeCreators

&#x20;       +create(LexemeType kind, string text) shared\_ptr\~Lexeme\~

&#x20;   }



&#x20;   class Lexeme {

&#x20;       <<abstract>>

&#x20;       +type()\* LexemeType

&#x20;       +text()\* string

&#x20;       +canBePlacedAfter(Lexeme\*)\* bool

&#x20;       +evaluate(stack\~double\~\&)

&#x20;       +priority() OperatorPriority

&#x20;   }



&#x20;   class NumberLexeme {

&#x20;       -string numberText

&#x20;       +type() LexemeType

&#x20;       +text() string

&#x20;       +appendDigit(char digit)

&#x20;       +appendDot()

&#x20;       +removeLastChar() bool

&#x20;       +evaluate(stack\~double\~\&)

&#x20;   }



&#x20;   class MathOperator {

&#x20;       -string operatorText

&#x20;       -Type operatorType

&#x20;       -map binaryOperations

&#x20;       -map unaryOperations

&#x20;       -map priorities

&#x20;       +type() LexemeType

&#x20;       +text() string

&#x20;       +priority() OperatorPriority

&#x20;   }



&#x20;   class BinaryOperator {

&#x20;       +canBePlacedAfter(Lexeme\*) bool

&#x20;       +evaluate(stack\~double\~\&)

&#x20;   }



&#x20;   class UnaryOperator {

&#x20;       +canBePlacedAfter(Lexeme\*) bool

&#x20;       +evaluate(stack\~double\~\&)

&#x20;   }



&#x20;   class LeftParenLexeme {

&#x20;       +type() LexemeType

&#x20;       +text() string

&#x20;       +canBePlacedAfter(Lexeme\*) bool

&#x20;   }



&#x20;   class RightParenLexeme {

&#x20;       +type() LexemeType

&#x20;       +text() string

&#x20;       +canBePlacedAfter(Lexeme\*) bool

&#x20;   }

```

