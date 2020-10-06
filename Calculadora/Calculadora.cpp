#include <iostream>
#include <list>

/*void sumar(int x, int y){

    int resultado = x + y;
    std::cout << "El resultado es " << resultado << std::endl;
}

void restar(int x, int y) {

    int resultado =  x - y;
    std::cout << "El resultado es " << resultado << std::endl;

}

void dividir(int x, int y) {

    int resultado = x / y;
    std::cout << "El resultado es " << resultado << std::endl;

}

void multiplicar(int x, int y) {

    int resultado = x * y;
    std::cout << "El resultado es " << resultado << std::endl;

}*/

/*void operaciones(float num1, float num2, int option) {


    float resultado = 0;

    switch (option) {
    case 1:
        resultado = num1 + num2;
        break;
    case 2:
        resultado = num1 - num2;
        break;
    case 3:
        resultado = num1 * num2;
        break;
    case 4:
        resultado = num1 / num2;
        break;
    default:
        break;
    }

    std::cout << "El resultado es: " << resultado << std::endl;
};*/


int errorHandling(int& num, int error)
{
    switch (error)
    {
        //Error handler 1
        case 1:
            if (num <= 0 || num >=  5)
            {
                std::cout << "Elija un numero entre 1 y 4." << std::endl;
                std::cout << "->: ";
                std::cin >> num;
                errorHandling(num, 1);
            }
            return num;
        //Error handler 2
        case 2:
            if (num <= 0)
            {
                std::cout << "Elija un numero mayor que 0." << std::endl;
                std::cout << "Cuantos numeros: ";
                std::cin >> num;
                errorHandling(num, 2);
            }
            return num;
        /*Error handler 3
        case 3:
            std::cin >> num;
            if (!std::cin)
            {
                std::cout << "EROOR: Enter a number." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            return num;*/
        case 3:
            std::cout << "Error: ErrorHandlder option out of range" << std::endl;
            break;
    }
}

void operaciones(std::list<float> numlist, int option ) {

    std::list <float>::iterator iterator;
    float resultado = 0.0;

    switch (option)
    {
    //Sum
    case 1:

        resultado = 0;

        for (iterator = numlist.begin(); iterator != numlist.end(); iterator++) 
        {
            resultado += *iterator;
        }
        std::cout << "El resultado es : " << resultado << std::endl;
        break;
    //Subs
    case 2:

        resultado = 0;
        iterator = numlist.begin();
        *iterator *= -1;

        for (iterator = numlist.begin(); iterator != numlist.end(); iterator++) 
        {
            resultado -= *iterator;
        }
        std::cout << "El resultado es : " << resultado << std::endl;
        break;
    //Multi
    case 3:
        resultado = 1;

        for (iterator = numlist.begin(); iterator != numlist.end(); iterator++) 
        {
            resultado *= *iterator;
        }
        std::cout << "El resultado es : " << resultado << std::endl;
        break;
    //Divis
    case 4:
        iterator = numlist.begin();
        resultado = *iterator * *iterator;

        for (iterator = numlist.begin(); iterator != numlist.end(); iterator++) 
        {
            resultado /= *iterator;
        }
        std::cout << "El resultado es : " << resultado << std::endl;
        break;

    default:
        std::cout << "Error : Operation option out of range";
        break;
    }
}

void list(int list_size, std::list <float> &numlist)
{
    int i = 0;
    std::list <float>::iterator iterator;
    iterator = numlist.begin();

    while (i != list_size)
    {
        float number;
        std::cout << "Numero : ";
        std::cin >> number;
        numlist.insert(iterator, number);
        i++;
    }
}

int main()
{
    while (true) {
        int options;
        int* optionsPtr = &options;
        int list_size;
        int* list_sizePtr = &list_size;
        std::cout << "---Calculadora----" << std::endl;
        std::cout << ". . . . . . . . . . ." << std::endl;
        std::cout << "1)Sumar\n2)Restar\n3)Multiplicar\n4)Dividir\n: ";
        std::cout << ". . . . . . . . . . ." << std::endl;
        std::cin >> options;
        while (true)
        {
            std::cin >> options;
            if (!std::cin)
            {
                std::cout << "ERROR: Elija un numero." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else break;
        }
        errorHandling(*optionsPtr, 1);  // Error handler 1
        std::cout << "Cuantos numeros: ";
        std::cin >> list_size;
        while (true)
        {
            std::cin >> list_size;
            if (!std::cin)
            {
                std::cout << "ERROR: Elija un numero." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else break;
        }
        errorHandling(*list_sizePtr, 2); // Error handler 2
        std::list <float> numlist;
        std::list <float>* numlistPtr = &numlist;
        std::list <float>::iterator iterator;
        iterator = numlist.begin();
        list(list_size, *numlistPtr);   //List maker
        operaciones(numlist, options);  //Operations
        system("pause");                //OS dependant and slow = bad
    }
    return 0;
}