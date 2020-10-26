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

void Parser::parse(const std::string & text) const {
	start_callback();

	std::string token;
	char c;
	auto begin_iterator = text.begin();
	bool digit = true;

	while(begin_iterator != text.end()) {
		c = *begin_iterator;
		if((c != '\t') and (!isspace(c)) and (c != '\n')) {
			token.push_back(c);
			if(!isdigit(c)) digit = false;
		}
		else
			if(token.size() != 0) {
				if(digit) digit_callback(token);
				else string_callback(token);
				digit = true;
				token.clear();
			}
		begin_iterator++;
	}
	//last token callback
	if(token.size() != 0) {
		if(digit) digit_callback(token);
		else string_callback(token);
		token.clear();
	}
	end_callback();
}

