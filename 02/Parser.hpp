#include <iostream>
#include <functional>
#include <string>

#ifndef allocator_hpp
#define allocator_hpp

using TokenCallback = std::function<void(std::string token)>;
using StartEndCallback = std::function<void()>;

class Parser {
private:
    StartEndCallback start_callback;
    TokenCallback digit_callback;
    TokenCallback string_callback;
    StartEndCallback end_callback;
    
public:
    Parser();
    void set_start_callback(StartEndCallback start_cb);
    void set_digit_callback(TokenCallback digit_cb);
    void set_string_callback(TokenCallback string_cb);
    void set_end_callback(StartEndCallback end_cb);
    void parse(std::string text);
};

#endif
