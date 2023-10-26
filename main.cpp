/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
//#include <basic_string.h>

using namespace std;

void Despedida(){
	std::cout << "================" << std::endl;
    std::cout << "| HASTA LUEGO  |" << std::endl;
    std::cout << "================" << std::endl;
}

int Leer_archivo(){
    
    string saldo_banco = "Saldo.bat";
    string contenido="";
    int modificar =0;
    
    ifstream leer_archivo(saldo_banco.c_str());
    getline(leer_archivo,contenido);
    istringstream(contenido) >> modificar;
	//modificar = std::stoi(contenido.c_str());
    leer_archivo.close();
    
    return modificar;
}

void Escribir_archivo(int saldo){
    
    string saldo_banco = "Saldo.bat";
    ofstream escribir_archivo(saldo_banco.c_str());
    escribir_archivo<<saldo;
    escribir_archivo.close();
}

int ObtenerDato(){
    
    int monto =0;    
    std::cout << "| Ingrese el monto:                    |" << std::endl;
    std::cout << "| Monto:";
	std::cin >> monto;    
    
    system("cls");
    return monto;
}

void SacarDinero(){
    int restar=0;
    std::cout << "=========================================" << std::endl;
    std::cout << "| Cuanto Dinero quiere Sacar:           |" << std::endl;
    restar= Leer_archivo() - ObtenerDato();
    
    Escribir_archivo(restar);
    
}

void IngresarDinero(){
    int sumar=0;
    std::cout << "=========================================" << std::endl;
    std::cout << "| Cuanto Dinero quiere Ingresar:       |" << std::endl;
    sumar= Leer_archivo() + ObtenerDato(); 
    
    Escribir_archivo(sumar);
}

void ConsultarSaldo(){
    std::cout << "=========================================" << std::endl;
    std::cout << "| Tu saldo es:"<<Leer_archivo()<<"BS.   |" << std::endl;
    std::cout << "=========================================" << std::endl;
	system("PAUSE");
	system("CLS");
}

void Proceso(int opc){
    switch (opc){
        case 1:ConsultarSaldo();break;
        case 2:IngresarDinero();break;
        case 3:SacarDinero();break;
        case 4:Despedida();break;
    }
}

void Menu(){
    
    unsigned int opcion=0;
    do{
    	std::cout << "=========================================" << std::endl;
        std::cout << "|      Banco de Venezuela Gabriel       |" <<endl;
        std::cout << "| Digite numero de opcion a realizar:   |" << std::endl;
        std::cout << "| 1- Consultar Saldo                    |" << std::endl;
        std::cout << "| 2- Ingresar dinero                    |" << std::endl;
        std::cout << "| 3- Sacar dinero                       |" << std::endl;
        std::cout << "| 4- Salir                              |"<< std::endl;
        std::cout << "| Opcion:";
        std::cin >> opcion;
    	
    	system("cls");
        if(opcion<1 || opcion>4){
        	std::cout << "============================================================" << std::endl;				
            std::cout << "| La opcion Ingresada no esta dentro del rango establecido |" << std::endl;
            std::cout << "============================================================" << std::endl;
            system("pause");
            system("cls");
        }else{
            Proceso(opcion);   
        }
    
    }while(opcion!=4);
}

int main()
{

    Menu();

    return 0;
}
