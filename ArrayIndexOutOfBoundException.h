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