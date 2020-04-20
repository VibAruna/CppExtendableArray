/*
 * ArrayIndexOutOfBoundException.h
 *
 *  Created on: Apr 20, 2020
 *      Author: vibhath
 */

#ifndef ARRAYINDEXOUTOFBOUNDEXCEPTION_H_
#define ARRAYINDEXOUTOFBOUNDEXCEPTION_H_

#include <exception>
#include <string>

class ArrayIndexOutOfBoundException: public std::exception
{
    public:
        ArrayIndexOutOfBoundException(unsigned int req_index, unsigned int length);

    private:
        unsigned int req_index;
        unsigned int length;

        virtual const char* what() const throw();
};



#endif /* ARRAYINDEXOUTOFBOUNDEXCEPTION_H_ */
