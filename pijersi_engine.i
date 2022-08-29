%module PijersiCore

%{
    #include <board.h>
    #include <piece.h>
    using namespace PijersiEngine;
%}

%include "carrays.i"
%include "std_vector.i"
%include "std_array.i"
%include "stdint.i"
%array_class(int, intArray);
%array_class(uint8_t, byteArray);
namespace std {
   %template(IntVector) vector<int>;
}
%include "std_string.i"

%include <board.h>
%include <piece.h>