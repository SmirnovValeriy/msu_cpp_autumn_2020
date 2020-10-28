#include "Parser.hpp"


Parser::Parser() {
	start_callback = [](){};
	digit_callback = [](const std::string & token) {};
	string_callback = [](const std::string & token) {};
	end_callback = [](){};
}

void Parser::set_start_callback(StartEndCallback start_cb) {
	start_callback = start_cb;
}

void Parser::set_digit_callback(TokenCallback digit_cb) {
	digit_callback = digit_cb;
}

void Parser::set_string_callback(TokenCallback string_cb) {
	string_callback = string_cb;
}

void Parser::set_end_callback(StartEndCallback end_cb) {
	end_callback = end_cb;
}

void Parser::parse(const std::string & text) {
	start_callback();

	std::string token;
	char c;
	auto begin_iterator = text.begin();
	bool digit = true;

	while(begin_iterator != text.end()) {
		c = *begin_iterator;
		if(!isspace(c)) {
			token.push_back(c);
			if(!isdigit(c)) digit = false;
		}
		else
			token_processing(token, digit);
		begin_iterator++;
	}
	//last token callback
	token_processing(token, digit);
	end_callback();
}

void Parser::token_processing(std::string & token, bool & digit) {
    if(token.size() != 0) {
		digit ? digit_callback(token) : string_callback(token);
		token.clear();
		digit = true;
    }
}

