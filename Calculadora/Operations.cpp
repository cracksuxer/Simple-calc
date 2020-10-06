
#include <iostream>
#include <list>

class OperationsClass
{
    // params

    std::list <float> numlist;
    std::list <float>::iterator iterator;
    int option;

    // methods

    int operator++() { return 0; }
    int operator+() { return 0; }

    void operaciones(std::list<float> numlist, std::list <float>::iterator ok, int option) {

        float resultado = 0.0;

        switch (option)
        {
        case 1:

            resultado = 0;

            for (ok = numlist.begin(); ok != numlist.end(); ok++)
            {
                resultado += *ok;
            }

            break;

        case 2:

            resultado = 0;
            ok = numlist.begin();
            *ok *= -1;

            for (ok = numlist.begin(); ok != numlist.end(); ok++)
            {
                resultado -= *ok;
            }
            break;

        case 3:
            resultado = 1;

            for (ok = numlist.begin(); ok != numlist.end(); ok++)
            {
                resultado *= *ok;
            }
            break;

        case 4:
            resultado = 1;

            for (ok = numlist.begin(); ok != numlist.end(); ok++)
            {
                resultado /= *ok;
            }
            break;

        default:
            std::cout << "Error";
            break;
        }

        std::cout << "El resultado es : " << resultado;

    }

};


