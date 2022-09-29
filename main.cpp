#include <iostream>
#include <string> //must add to use strings
#include <sstream> //must add to use stringstream command
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

#define PI2 3.141592
#define NEWLINE2 '\n'

//use #define to determine preprocessor definitions. Everytime you call the identifier, it's value will already be defined.

/* that's my first program.
 * trying to learn new functionalities and commands.
 * that's a comment with more than 1 line. */

//That's a comment with only one line.
//I need to add another pair of slashes to go to the other line.


/*
 * using namespace std;  //Possible, but not recommended. IT MAY CAUSE NAME COLLISION!
 *                       //It's better to use the usual std::cout every time you set a new statement.
int main ()
{
  cout << "Hello World! ";
  cout << "I'm a C++ program";
}
*/

int variables() {
    //operating with variables
    //declaring variables
    int a, b;
    int result;

    //process
    a = 5;
    b = 2;
    a = a + 1;
    result = a - b;

    //print out the result
    //std::cout << result;  --> Can't do that here. It needs to be called in the main function

    //terminate the program
    return result;
}

void variables2() {
    int v1 = 5;
    int v2(3);
    int v3{2};
    int result2;

    v1 = v1 + v2;
    result2 = v1 - v3;
    std::cout << result2 << "\n"; //don't use std::cout inside the function. Better use it in the main function
}

void constant() {
    int sufixo1 = 75;
    int sufixo2 = 75u; //unsigned int
    int sufixo3 = 75l; //long
    int sufixo4 = 75ul; //unsigned long
    int sufixo5 = 75lu; //unsigned long

    std::cout << "You can use 'l' or 'u' to specify an integer. You can use Lower or Uppercase letters to do it. \n";
    std::cout << sufixo1 << "\n" << sufixo2 << "\n" << sufixo3 << "\n" << sufixo4 << "\n" << sufixo5 << "\n";
    std::cout << "It doesn't change the number, but will change its type and consequently its binary. \n";

    float numero1 = 3.141592654;
    auto numero2 = 6.02e5;
    auto numero3 = 3.0f; //"f" to declare a float
    auto numero4 = 9.99l; //"l" to declare a long double/float

    std::cout << "The difference between a float and a double is the size in the memory" << "\n";
    std::cout << numero1 << "\n" << numero2 << "\n" << numero3 << '\n' << numero4 << '\n';
    //You can use the \n command with a single string, like the example above.
    //The '\n' character is a special character called "Escape Code".
}


void phrase() {
    std::string mystring;
    mystring = "This is a string!";
    std::cout << mystring << "\n"; //you can create a new line with std:endl but is leads to poor buffering performance.
    std::string mystring2 = "This is another string";
    std::cout << mystring2 << "\n";
    mystring = "Now, it's a new string";
    std::cout << mystring << "\n";
    mystring2 = "this is " "a new string." "Yeah, you can use multiple" " double commas to write";
    std::cout << mystring2 << '\n';
    std::string mystring3;
    mystring3 = "you can also use more than one line to "
                "write all this";
    std::cout << mystring3 << "\n";
}

void phrase2() {
    std::string frase1;
    frase1 = u'a';
    std::string frase2;
    frase2 = U'b';
    std::string frase3;
    frase3 = L'c'; //you won't use this because it can lead to incompatibility issues.

    std::cout << frase1;
    std::cout << frase2;
    std::cout << frase3 << '\n';
}

const double pi = 3.141592;
const char newline = '\n';

void constant2() {
    double r = 5.0;  //radius
    double circle;

    circle = 2 * pi * r;
    std::cout << circle;
    std::cout << newline;
}

void preprocessordefinition() {
    double r = 10.0;
    double circle;

    circle = 2 * PI2 * r;
    std::cout << circle;
    std::cout << NEWLINE2;
}

void Operators() {
    //assignment operator (=)
    int val1, val2;        // a:?,  b:?
    val1 = 10;             // a:10, b:?
    val2 = 12;             // a:10, b:4
    val1 = val2;           // a:4,  b:4
    val2 = 7;              // a:4,  b:7

    std::cout << "val1:";
    std::cout << val1;
    std::cout << " val2:";
    std::cout << val2 << '\n';

    //modulo operator
    auto resto = val1 % val2;
    std::cout << "the remain of the division is: " << resto << '\n'; //modulo operator is most used in arrays

    //compound assignments
    //they modify the current value of a variable by performing an operation on it.
    //those are all the compounds assignments +=, -=, *=, /=, %=, >>=, <<=, &=, ^=, |=;

    std::cout << "val1: " << val1 << '\n';
    std::cout << "val2: " << val2 << '\n';
    val1 += val2; //val1 = val1 + val2
    std::cout << "val1 + val2: " << val1 << '\n';
    val1 -= 5; //val1 = val1 - 5
    std::cout << "val1 - 5: " << val1 << '\n';
    val1 *= 2; //val1 = val1 * 2
    std::cout << "val1 * 2: " << val1 << '\n';
    val1 /= 2; //val1 = val1 / 2
    std::cout << "val1 / 2: " << val1 << '\n';
    val1 *= val2 + 1; // val1 = val1 * (val2 + 1)
    std::cout << "val1 * (val2 + 1): " << val1 << '\n';

    //Increment and Decrement Operators
    int val3 = 3;
    std::cout << "val3: " << val3 << '\n';
    ++val3; //val3 = val3 + 1 OR val3 += 1
    std::cout << "val3: " << val3 << '\n';
    std::cout << "val3: " << ++val3 << '\n';
    std::cout << "val3: " << --val3 << '\n';

    /*
     * you can add '++' and '--' before or after the variable, and either way will have the same meaning.
     * however, it will have different meanings depending on the expression.
     * In the case that the increase operator is used as a prefix (++x) of the value,
     * the expression evaluates to the final value of x, once it is already increased.
     * On the other hand, in case that it is used as a suffix (x++), the value is also increased,
     * but the expression evaluates to the value that x had before being increased. Notice the difference:
     * x = 3 / y = ++x;
     * x contains 4, y contains 4
     *
     * x = 3 / y = x++;
     * x contains 4, y contains 3x
     */

}

bool comparison(int x) {
    //relational and comparison operators
    int comp1, comp3;
    comp1 = 5;
    comp3 = 7;

    if (comp1 == x) {
        std::cout << "both numbers are equal." << '\n';
        //return true;
        // you use 'return' when you want your function to stop. If I put this return here, the program won't read the rest of the function
        std::cout << true;
    } else {
        std::cout << "both numbers are different." << '\n';
    }

    if (comp1 != comp3) {
        std::cout << "both numbers are different." << '\n';
    } else {
        std::cout << "both numbers are equal." << '\n';
    }
    //you can also use '<' for "less than", '>' for "greater than", '<=' for "less than or equal to" and '>=' for "greater than or equal to"
    //you can also use '!' for the boolean operation "NOT", '&&' for "AND" and '||' for "OR"
}

bool comparison2(int x) {
    for (x; x < 18; x++) { //it's better to put the ++ inside the 'for' function instead of the 'if' function.
        if ((x <= 10) || (x < 15)) { //if put '++x<15', after 10 it will increase 'x' by 2.
            //pay attention when using '&&' and '||'. C++ only evaluates what is necessary from left to right.
            //this is important when the right side has side effects. see the example below.
            std::cout << x << " is smaller than 10 OR 15." << '\n';
        }
    }
}

bool comparison3(int y) {
    std::cout << '\n' << "trying the '&&' now: " << '\n';

    for (y; y < 18; y++) {
        if ((y <= 10) && (y < 15)) {
            std::cout << y << " is smaller than 10 AND 15." << '\n';
        }
    }
}

bool conditional() {
    //the conditional ternary operator returns one value if the operation is TRUE and another value if the operation is FALSE.
    //it follows the syntax: conditional?result1:result2.

    int cond1, cond2, cond3;
    cond1 = 2;
    cond2 = 7;
    cond3 = (cond1 > cond2) ? cond1 : cond2;

    std::cout << cond3 << '\n';
}

int comma() {
    //comma operator
    //used to separate two or more expressions where only one was expected.
    int com1, com2;
    com1 = (com2 = 3, com2 + 2);

    std::cout << "com1 = " << com1 << '\n';
    std::cout << "com2 = " << com2 << '\n';
}

int mudartipo() {
    //type casting operator
    //allows to convert a value of a given type to another type.
    int i, ii;
    float f = 3.14;
    i = (int) f;
    ii = int(f);
    //the remainder (.14) is lost

    std::cout << "valor de 'i' = " << i << '\n';
    std::cout << "valor de 'ii' = " << ii << '\n';
}

int definirtamanho() {
    //it returns the size in bytes of the type or object.

    int def;
    def = sizeof(char);
    //here, x is assigned the value '1', because 'char' type has the size of one byte.
    //The value returned by sizeof is a compile-time constant, so it is always determined before program execution.

    std::cout << def << '\n';
}

int readingpriority(){
    //A single expression may have multiple operators
    int read1;
    read1 = 5 + 7 % 2;
    /*
     * The above expression always assigns 6 to variable x, because the % operator has a higher precedence than the + operator,
     * and is always evaluated before. Parts of the expressions can be enclosed in parenthesis to override this precedence order,
     * or to make explicitly clear the intended effect.
     * x = 5 + (7 % 2);    // x = 6 (same as without parenthesis)
     * x = (5 + 7) % 2;    // x = 0
     * Enclosing all sub-statements in parentheses (even those unnecessary because of their precedence) improves code readability.
     */

    return read1;
}

int standardinput(){
    int age;
    std::cout << "Enter your age" << '\n';
    std::cin >> age;
    std::cout << "your age is " << age << '\n';
}

void standardinput2(){
    std::string yourname;
    std::cout << "Enter your name: " << '\n';
    std::cin >> yourname;
    std::cout << yourname << std::endl;
    //the cin command only considers the first word. Spaces, tabs and newlines are considered as terminating the value being extracted.
    //to have a full sentence, you need the command 'getline' that appears in the next function.
}

void standardinput3(){
    std::string mystr;
    std::cout << "What's your name?" << '\n';
    std::cin.ignore();

    getline (std::cin, mystr);
    std::cout << "Hello " << mystr << '\n';

    std::cout << "What's your favorite food?" << '\n';
    getline (std::cin, mystr);
    std::cout << "I like " << mystr << " too!!" << '\n';
}

void learningstringstream(){
    std::string mystr ("1204");
    int myint;
    std::stringstream (mystr) >> myint;
    std::cout << mystr << '\n';
    std::cout << myint << '\n';
}

void learningstringstream2(){
    std::string mystr;
    float price = 0;
    int quantity = 0;

    std::cout << "Enter price: " << '\n';
    getline (std::cin,mystr);
    std::stringstream (mystr) >> price;
    std::cout << "Enter quantity: " << '\n';
    getline (std::cin, mystr);
    std::stringstream (mystr) >> quantity;
    std::cout << "Total price: " << price*quantity << '\n' << std::endl;
}

void selectionstatement(){
    std::string mystr;
    int number;
    std::cout << "Enter a number: " << '\n';
    getline(std::cin, mystr);
    std::stringstream (mystr) >> number;
    std::cout << "You chose the number " << number << '\n';
    if(number > 0){
        std::cout << "The number " << number << " is positive." << '\n';
    }
    else if (number <0){
        std::cout << "The number " << number << " is negative." << '\n';
    }
    else{
        std::cout << "You chose zero as your number." << '\n';
    }
}

void iterationstatements(){
    //loops --> 'while', 'do' and 'for

    //WHILE
    int n = 10;
    while (n >0){
        std::cout << n << ", ";
        --n;
    }
    std::cout << "LIFTOFF!!" << '\n';

    //DO WHILE
    //Similar to 'while', but the condition is evaluated after the execution of the statement, guaranteeing at least one execution of the statement.
    std::string str;
    do{
        std::cout << "Enter text: " << '\n';
        getline (std::cin, str);
        std::cout << "You entered: " << str << '\n';
    }
    while (str != "goodbye");

    //FOR
    //Its syntax is: for (initialization; condition; increase) statement;
    //You don't need to enter the three fields, but in all cases the semicolon signs between them are required.
    /*
     * Because each of the fields is executed in a particular time in the life cycle of a loop,
     * it may be useful to execute more than a single expression as any of initialization, condition, or statement.
     * Unfortunately, these are not statements, but rather, simple expressions, and thus cannot be replaced by a block.
     * As expressions, they can, however, make use of the comma operator (,)
     * This operator is an expression separator, and can separate multiple expressions where only one is generally expected.
     * For example, using it, it would be possible for a for loop to handle two counter variables, initializing and increasing both:
     * for ( n=0, i=100 ; n!=i ; ++n, --i ){
          // whatever here...
        }
     * this loop will execute 50 times if neither 'n' or 'i' are modified within the loop.
     */
    for(int x=10; x>0; --x){
        std::cout << x << ", ";
    }
    std::cout << "Liftoff!" << '\n';
}

void iterationstatements2(){  //This one has a countdown!
    std::cout << "countdown:\n";
    for (int i=10; i>0; --i){
        std::cout << i << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
    std::cout << "Lift off!\n";
}

void iterationstatements3(){
    //Range-based for loop
    //used exclusively with ranges
    //for ( declaration : range ) statement;
    std::string str {"Hello!"};
    for(char c : str){
        std::cout << "[" << c << "]";
    }
    std::cout << '\n';

    /*
     * Range based loops usually also make use of type deduction for the type of the elements with auto.
     * Typically, the range-based loop above can also be written as:
     * for (auto c : str){
     *      cout << "[" << c << "]";
     * }
     * Here, the type of c is automatically deduced as the type of the elements in str.
     */
}

void jumpstatement(){
    //allow altering the flow of a program by performing jumps to specific locations;
    //BREAK STATEMENT
    //leaves a loop, even if the condition for its end is not fulfilled.
    //can be used to end an infinite loop or to force it to end before its natural end.
    for (int n=10; n>0; --n){
        std::cout << n << ", ";
        if(n==3){
            std::cout << "countdown aborted!" << '\n';
            break;
        }
    }

    //CONTINUE STATEMENT
    //causes the program to skip the rest of the loop in the current iteration,
    //as if the end of the statement block had been reached, causing it to jump to the start of the following iteration.
    for(int num=10; num>0; num--){
        if(num==5) continue; //skip number 5
        std::cout << num << ", ";
    }
    std::cout << "liftoff!" << '\n';

    //GOTO STATEMENT
    //usado mais em assembling
    //allows to make an absolute jump to another point in the program.
    // This unconditional jump ignores nesting levels, and does not cause any automatic stack unwinding.
    // Therefore, it is a feature to use with care, and preferably within the same block of statements, especially in the presence of local variables.
    // The destination point is identified by a label, which is then used as an argument for the goto statement.
    // A label is made of a valid identifier followed by a colon (:)

    int numnum=10;
    mylabel:
    std::cout << numnum << ", ";
    numnum--;
    if (numnum>0){
        goto mylabel;
    }
    std::cout << "liftoff!\n";
}

void anotherselectionstatement(){
    //SWITCH STATEMENT
    //it's equivalent to ann if-else statement
    //Its purpose is to check for a value among a number of possible constant expressions.
    //It is something similar to concatenating if-else statements, but limited to constant expressions.
    //It works in the following way: switch evaluates expression and checks if it is equivalent to constant1;
    //if it is, it executes group-of-statements-1 until it finds the break statement.
    //When it finds this break statement, the program jumps to the end of the entire switch statement (the closing brace).
    //If expression was not equal to constant1, it is then checked against constant2.
    //If it is equal to this, it executes group-of-statements-2 until a break is found, when it jumps to the end of the switch.
    //Finally, if the value of expression did not match any of the previously specified constants (there may be any number of these),
    //the program executes the statements included after the default: label, if it exists (since it is optional).
    int x;
    std::string str;

    std::cout << "Choose a number between 1 and 2." << '\n';
    getline (std::cin, str);
    std::stringstream (str) >> x;

    switch (x) {
        case 1:
            std::cout << "You chose the number 1." << '\n';
            break;

        case 2:
            std::cout << "You chose the number 2." << '\n';
            break;

        default:
            std::cout << "value unknown!";
    }

    //Notice that switch is limited to compare its evaluated expression against labels that are constant expressions.
    // It is not possible to use variables as labels or ranges, because they are not valid C++ constant expressions.
    //To check for ranges or values that are not constant, it is better to use concatenations of if and else if statements.
}

int main() {
    //std::cout << "Hello, World!" << std::endl;
    //std::cout << "I'm a c++ program!" << std::endl;
    //std::cout << variables() << "\n";
    //variables2();
    //phrase();
    //constant();
    //phrase2();
    //constant2();
    //preprocessordefinition();
    //Operators();
    //comparison(5);
    //comparison2(8);
    //comparison3(8);
    //conditional();
    //comma();
    //mudartipo();
    //definirtamanho();
    //std::cout << readingpriority() << '\n';
    //standardinput();
    //standardinput2();
    //standardinput3();
    //learningstringstream();
    //learningstringstream2();
    //selectionstatement();
    //iterationstatements();
    //iterationstatements2();
    //iterationstatements3();
    //jumpstatement();
    //anotherselectionstatement();

    return 0;
}

//pq eu to criando um bool ai em cima? pq eu nao crio um int, ou void, ou static, etc.
//como imprimir 'true' ou 'false' no booleano.