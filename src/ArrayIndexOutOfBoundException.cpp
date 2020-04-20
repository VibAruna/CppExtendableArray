/*
 * ArrayIndexOutOfBoundException.cpp
 *
 *  Created on: Apr 20, 2020
 *      Author: vibhath
 */

#include "ArrayIndexOutOfBoundException.h"

ArrayIndexOutOfBoundException::ArrayIndexOutOfBoundException(unsigned int req_index, unsigned int length)
{
    this->req_index = req_index;
    this->length = length;
}

const char* ArrayIndexOutOfBoundException::what() const throw()
{
    char* err_msg = new char[80];
    sprintf(err_msg, "ArrayIndexOutOfBoundException : Requested Index : %d Length : %d", req_index, length);
    return err_msg;
}


