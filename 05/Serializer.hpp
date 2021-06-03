#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

#ifndef serializer_hpp
#define serializer_hpp

enum class Error {
	NoError,
	CorruptedArchive
};

class Serializer {

	static constexpr char Separator = ' ';
	std::ostream& out_;

public:

	explicit Serializer(std::ostream& out): out_(out) {}

	template <class T>
	Error save(T& object) {
		return object.serialize(*this);
	}
	
	template <class... ArgsT>
	Error operator()(ArgsT&... args) {
		return process(args...);
	}

	template <class T>
	Error process(T& t) {
		return one_to_stream(t);
	}

	template <class T, class... ArgsT>
	Error process(T& t, ArgsT&... args) {
		if(one_to_stream(t) == Error::CorruptedArchive)
			return Error::CorruptedArchive;
		return process(args...);
	}

	Error one_to_stream(bool& var) const {
		if(var)
			out_ << "true" << Separator;
		else
			out_ << "false" << Separator;

		return Error::NoError;
	}

	Error one_to_stream(uint64_t& var) const {
		out_ << var << Separator;
		return Error::NoError;
	}

	template<class T>
	Error one_to_stream(T& t) const {
		return Error::CorruptedArchive;
	}
};


class Deserializer {

	std::istream& in_;

public:

	explicit Deserializer(std::istream& in): in_(in) {}

	template <class T>
	Error load(T& object) {
		return object.deserialize(*this);
	}

	template <class... ArgsT>
	Error operator()(ArgsT&... args) {
		return process(args...);
	}

	template <class T>
	Error process(T& t) {
		return one_from_stream(t);
	}

	template <class T, class... ArgsT>
	Error process(T& t, ArgsT&... args) {
		if(one_from_stream(t) == Error::CorruptedArchive)
			return Error::CorruptedArchive;
		return process(args...);
	}

	Error one_from_stream(bool& var) {
		std::string text;
		in_ >> text;

		if(text == "true") {
			var = true;
			return Error::NoError;
		}
		else if(text == "false") {
			var = false;
			return Error::NoError;
		}

		return Error::CorruptedArchive;
	}

	Error one_from_stream(uint64_t& var) {     
		std::string text;
		in_ >> text;

		if(!isdigit(text[0])) {
			return Error::CorruptedArchive;
		}
		
		try {        
			var = std::stoull(text);
			return Error::NoError;
		} 
		catch (std::exception &x) {
			return Error::CorruptedArchive;
		}
	}

	template<class T>
	Error one_from_stream(T& t) const {
		return Error::CorruptedArchive;
	}
};

#endif
