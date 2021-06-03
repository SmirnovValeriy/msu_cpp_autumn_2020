#include "Serializer.hpp"

/* Structure with one element with type uint64_t */
struct DataOneElem {

    uint64_t a;

    Error serialize(Serializer& source) {
        return source(a);
    }

    Error deserialize(Deserializer& source) {
        return source(a);
    }

};

/* Structure with multiple elements with types uint64_t and bool */
struct DataMultipleElems {

    uint64_t a;
    bool b;
    uint64_t c;
    
    Error serialize(Serializer& source) {
        return source(a, b, c);
    }

    Error deserialize(Deserializer& source) {
        return source(a, b, c);
    }

};

/* Structure with multiple elements with type char */
struct DataWrongTypesElems {

    char a;
    char b;
    
    Error serialize(Serializer& source) {
        return source(a, b);
    }

    Error deserialize(Deserializer& source) {
        return source(a, b);
    }

};

/* Serialize & deserialize structure with one element with correct type */ 
bool one_elem() {
    try {
        DataOneElem x { 100 };
        std::stringstream stream;
        Serializer serializer(stream);

        const Error err_ser = serializer.save(x);
        if(err_ser == Error::CorruptedArchive) return false;

        Deserializer deserializer(stream);
        DataOneElem y { 0 };

        const Error err_deser = deserializer.load(y);
        return (err_deser == Error::NoError) and (x.a == y.a);
    }
    /* any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Serialize & deserialize structure with multiple elements with correct types */ 
bool multiple_elems() {
    try {
        DataMultipleElems x { 1, true, 2 };
        std::stringstream stream;
        Serializer serializer(stream);

        const Error err_ser = serializer.save(x);
        if(err_ser == Error::CorruptedArchive) 
            return false;

        Deserializer deserializer(stream);
        DataMultipleElems y { 0, false, 1 };

        const Error err_deser = deserializer.load(y);
        return (err_deser == Error::NoError) and (x.a == y.a) and (x.b == y.b) and (x.c == y.c);
    }
    /* any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Serialize structure with multiple elements with incorrect types */ 
bool wrong_types_serialize() {
    try {
        DataWrongTypesElems x { 'a', 'b' };
        std::stringstream stream;
        Serializer serializer(stream);

        const Error err = serializer.save(x);
        return(err == Error::CorruptedArchive);
    }
    /* any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Deserialize structure with multiple elements with incorrect types */
bool wrong_types_deserialize() {
    try {
        DataOneElem x { 0 };
        std::stringstream stream;
        stream << "zero";
        Deserializer deserializer(stream);

        const Error err = deserializer.load(x);
        return(err == Error::CorruptedArchive);
    }
    /* any unknown exception is error */
    catch(...) {
        return false;
    }
}


int main() {
    std::cout.width(44);
    std::cout<<std::left<<"Unittest one_elem "<<(one_elem() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest multiple_elems "<<(multiple_elems() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest wrong_types_serialize "<<(wrong_types_serialize() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest wrong_types_deserialize "<<(wrong_types_deserialize() ? "OK" : "ERROR")<<std::endl;
}
