#include "Parser.hpp"
#include <cassert>

//set callbacks for digits and strings as counters
void unittest_1() {
    Parser parser;
    size_t n_digits = 0;
    size_t n_strings = 0;
    std::string text = "string 12345 123 123nodigit 987654321 no123digit456 54321";
    
    parser.set_digit_callback([&n_digits](const std::string & token){ n_digits++; });
    parser.set_string_callback([&n_strings](const std::string & token){ n_strings++; });
    parser.parse(text);
    
    assert(n_digits == 4 and n_strings == 3);
}

//multiple delimiters
void unittest_2() {
    Parser parser;
    size_t n_digits = 0;
    size_t n_strings = 0;
    std::string text = "string \t\n \n 12345 123 123nodigit \n \t\t\t 987654321 123456n 54321";
    
    parser.set_digit_callback([&n_digits](const std::string & token){ n_digits++; });
    parser.set_string_callback([&n_strings](const std::string & token){ n_strings++; });
    parser.parse(text);
    
    assert(n_digits == 4 and n_strings == 3);
}

//delimeters at the end
void unittest_3() {
    Parser parser;
    size_t n_digits = 0;
    size_t n_strings = 0;
    std::string text = "string 12345 123nodigit\n";
    
    parser.set_digit_callback([&n_digits](const std::string & token){ n_digits++; });
    parser.set_string_callback([&n_strings](const std::string & token){ n_strings++; });
    parser.parse(text);
    
    assert(n_digits == 1 and n_strings == 2);
}

//multiple delimeters at the end
void unittest_4() {
    Parser parser;
    size_t n_digits = 0;
    size_t n_strings = 0;
    std::string text = "string 12345 123nodigit\n\t\n \n \n \n";
    
    parser.set_digit_callback([&n_digits](const std::string & token){ n_digits++; });
    parser.set_string_callback([&n_strings](const std::string & token){ n_strings++; });
    parser.parse(text);
    assert(n_digits == 1 and n_strings == 2);
}

//change start and end callbacks
void unittest_5() {
    Parser parser;
    bool started = false;
    bool ended = false;
    size_t n_digits = 0;
    size_t n_strings = 0;
    std::string text = "string 12345 123nodigit\n\t\n \n \n \n";
    
    parser.set_start_callback([&started](){ started = true; });
    parser.set_digit_callback([&n_digits](const std::string & token){ n_digits++; });
    parser.set_string_callback([&n_strings](const std::string & token){ n_strings++; });
    parser.set_end_callback([&ended](){ ended = true; });
    parser.parse(text);
    
    assert(n_digits == 1 and n_strings == 2 and started and ended);
}

//change digit and string callbacks
//digit - '1'
//string - '0'
void unittest_6() {
    Parser parser;
    bool started = false;
    bool ended = false;
    std::string check;
    std::string text = "string 12345 123nodigit\n\t\n 1234\n \n123456789 \n";
    
    parser.set_start_callback([&started](){ started = true; });
    parser.set_digit_callback([&check](const std::string & token){ check.push_back('1'); });
    parser.set_string_callback([&check](const std::string & token){ check.push_back('0'); });
    parser.set_end_callback([&ended](){ ended = true; });
    parser.parse(text);
    
    assert(check == std::string("01011") and started and ended);
}

//change digit and string callbacks
void unittest_7() {
    Parser parser;
    bool started = false;
    bool ended = false;
    std::string check;
    std::string text = "string 12345 123nodigit\n\t\n 1234\n \n123456789 \n";
    
    parser.set_start_callback([&started](){ started = true; });
    parser.set_digit_callback([&check](const std::string & token){ check+=token; });
    parser.set_string_callback([&check](const std::string & token){ check+=token; });
    parser.set_end_callback([&ended](){ ended = true; });
    parser.parse(text);
    
    assert(check == std::string("string12345123nodigit1234123456789") and started and ended);
}

int main() {
    std::cout<<"Unittest_1 ";
    unittest_1();
    std::cout<<"OK"<<std::endl;
    std::cout<<"Unittest_2 ";
    unittest_2();
    std::cout<<"OK"<<std::endl;
    std::cout<<"Unittest_3 ";
    unittest_3();
    std::cout<<"OK"<<std::endl;
    std::cout<<"Unittest_4 ";
    unittest_4();
    std::cout<<"OK"<<std::endl;
    std::cout<<"Unittest_5 ";
    unittest_5();
    std::cout<<"OK"<<std::endl;
    std::cout<<"Unittest_6 ";
    unittest_6();
    std::cout<<"OK"<<std::endl;
    std::cout<<"Unittest_7 ";
    unittest_7();
    std::cout<<"OK"<<std::endl;
    return 0;
}
