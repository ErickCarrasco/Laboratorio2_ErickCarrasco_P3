#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#include <cstdlib>

#include <string>
//using std::to_string;
//using std::stoi;
using std::string;
#include <ctime>

#include <sstream>
using std::stringstream;

//FUNCIONES PARA EJERCICIO 1
int* createArray(int);

void freeArray(int*);

void initArray(int*, int);

void printArray(int*, int);

//FUNCIONES PARA EJERCICIO 2

char* createCharArray(int);

void initCharArray(char*, int);

void printCharArray(char*, int);

void freeCharArray(char*);

int main(){
	
	int respuesta=1;
	while(respuesta==1){
		cout<<"Bienvenido al programa"<<endl;
		cout<<"----------------------"<<endl;
		cout<<endl;
		cout<<"1/ Ejercicio 1" << endl;
		cout<<"2/ Ejercicio 2" << endl;
		cout<<"3/ EJercicio 3" << endl;
		cout<<endl;
		int seleccion=0;
		cout<<"Ingrese su seleccion: " << endl;
		cin>>seleccion;
		int chances=5;

		switch(seleccion){
			case 1:
			{
				cout<<"Generando numero"<<endl;
				srand(time(NULL));
				int size=4;
				int* arreglo = NULL;
				arreglo = createArray(size);
				initArray(arreglo, size);
				printArray(arreglo, size);
				int pos1=-1;
				int pos2=-1;
				int pos3=-1;
				int pos4=-1;
				int valuegen=0;
				int result=0;
				//Empiezo de intentos
				while(chances>0){
					cout<<endl;	
					cout<<"..."<<endl<<endl<<"DATA GENERATED"<<endl;
					string cadenauser;
					cout<<"Ingrese una cadena de 4 numeros (0-9)"<<endl;
					cin>>cadenauser;
					int validador2=0;
					while(validador2==0){
						int tams= cadenauser.size();
						if(tams==4){
							cout<<tams<<" characters.."<<endl<<"Accepted"<<endl;
							validador2=1;
						}
						if(tams>4 || tams<4){
							cout<<"Out of bounds"<<endl;	
							cout<<"Ingrese la cadena de nuevo"<<endl;
							cin>>cadenauser;
							validador2=0;
						}					
					}

					//COMPARACION DE NUMEROS
					result =0;
					if(validador2=1){
						for(int i=0; i<size; i++){
							valuegen=0;
							int compare= arreglo[i];
							for(int j =0; j<4; j++){
								char number= cadenauser[j];
								int numberg = number - '0';
								cout<< numberg<<endl;

								if(numberg == compare && i == j){
									result=result +1;
									cout<<"El numero: " << numberg<< " esta en la posicion correcta"<<
									endl;

									valuegen=1;
									if(i==0){
										pos1=1;
									}
									if(i==1){
										pos2=1;
									}

									if(i==2){
										pos3=1;
									}
									if(i==3){
										pos4=1;
									}
												
								}
								if(numberg == compare && valuegen==0){
									cout<<"El numero: "<<"se ha encontrado el numero dentro del codigo"
									<<endl;
								}
							}//FIN DEL FOR DE LA CADENA DE USUARIO	
						}//FIN DEL FOR PRINCIPAL
					}//FIN VALIDADOR
					chances= chances-1;
					if(result==4 && pos1==1 && pos2 ==1 && pos3 == 1 && pos4 ==1){
						cout<<"Ha acertado el codigo"<<endl;
						for(int i = 0; i<size ; i++){
							cout<<arreglo[i];
						}
						cout<<endl;
						chances=-1000;
					}
					if(chances==0){
						cout<<"Objective failed"<<endl;
					}
				}//FIN WHILE DE TURNOS
				freeArray(arreglo);
				arreglo=NULL;	
			}
			break;
			
			case 2:
			{
				cout<<"Iniciando el programa 2"<<endl;
				int numDecimal=0;
				cout<<"Ingrese un numero: "<<endl;
				cin>>numDecimal;
				int a2;
				int tab=0;
				int maxtab=0;
				int table[0];

				if(numDecimal>=0){
					a2=numDecimal;
					int remainder;
						
					while(numDecimal!=0){
						remainder = numDecimal%2;
						numDecimal = numDecimal/2;
						maxtab++;
					}//FIN Numero del size del array
				
					maxtab--;
					numDecimal = a2;
					table[0]=table[maxtab];
					
					while(numDecimal!=0){
						remainder = numDecimal%2;
						numDecimal = numDecimal/2;
						table[tab]=remainder;
						tab++;
					}//Asignacion de numeros

					tab--;
					cout<<"The binary is: ";
					/*
					int table2[7];
					int inserter = 7-maxtab;
					for(int i =0; i<7; i++){
						if(i<inserter){
							table2[i]=0;
						}
						if(i>=inserter){
							table2[i]=table[i-inserter];
						}
					
					} 
					*/
					while(tab>=0){
						cout<<table[tab]<<" ";
						tab--;
					}//FIN IMPRESION DE BINARY
					/*
					int iterator=7;
					while(tab>=0){
						cout<<"The data is: "<<endl;
						cout<<table2[iterator]<<" ";
						iterator--;
					}
					*/
					cout<<endl;
				}//FIN IF NUMEROS POSITIVOS

				if(numDecimal<0){

				}//FIN IF NUMEROS NEGATIVOS
			}
			break;

			case 3:
			{
				cout<<"Ingresando al nuevo dato"<<endl;
				string palabra;
				cout<<"Ingrese un verbo regular"<<endl;
				cin>>palabra;
				int validador=palabra.size();
				char value1 = palabra[validador-1];
				char value2 = palabra[validador-2];
				
				stringstream comparador;
				comparador << value2<<value1;
				string terminal = comparador.str();
				cout<<terminal<<endl;
				if(terminal == "er" || terminal == "ar" || terminal == "ir"){
					cout<<"Palabra aceptada"<<endl;
					
					if(terminal=="er"){
						stringstream concatenado;
						for(int i = 0; i<validador-2;i++){
							char valor= palabra[i];
							concatenado<<valor;
						}
						string palabraconc=concatenado.str();
						//cout<<palabraconc<<endl;
						string pasado="i";

						//PASADO
						stringstream concatenadop;
						concatenadop<<palabraconc<<pasado;
						string palabrapas=concatenadop.str();
						cout<<"Pasado: " << palabrapas<<endl;
						
						//Presente	
						stringstream concatenadopres;
						concatenadopres<<palabraconc<<"o";
						string palabrapres=concatenadopres.str();
						cout<< "Presente: " << palabrapres<<endl;
	
						//Futuro
						stringstream concatenadofu;
						concatenadofu<<palabraconc<<"ere";
						string palabrafu=concatenadofu.str();
						cout<< "Futuro: " << palabrafu<<endl;
					
					}//FIN DE ER
					
					if(terminal=="ar"){
						stringstream concatenado;
						for(int i = 0; i<validador-2;i++){
							char valor = palabra[i];
							concatenado<<valor;
						}
						
						string palabraconc = concatenado.str();
						
						//Pasado
						stringstream concatenadop;
						concatenadop<<palabraconc<<"uve";
						string palabrapas=concatenadop.str();
						cout<<"Pasado: "<< palabrapas<<endl;

						//Presente
						stringstream concatenadopres;
						concatenadopres<<palabraconc<<"o";
						string palabrapres=concatenadopres.str();
						cout<<"Presente: " << palabrapres<<endl;

						//Futuro
						stringstream concatenadofu;
						concatenadofu<<palabraconc<<"are";
						string palabrafu=concatenadofu.str();
						cout<<"Futuro: " << palabrafu<<endl;
					}//FIN AR

					if(terminal=="ir"){
						stringstream concatenado;
						for(int i =0 ; i<validador-2; i++){
							char valor = palabra[i];
							concatenado<<valor;
						}
						string palabraconc = concatenado.str();

						//Pasado
						stringstream concatenadop;
						concatenadop<<palabraconc<<"ido";
						string palabrapas=concatenadop.str();
						cout<<"Pasado: " << palabrapas<<endl;
						
						//Presente
						stringstream concatenadopres;
						//concatenadopres<<palabraconc<<;

						//Futuro
						stringstream concatenadofu;
						concatenadofu<<palabraconc<<"ire";
						string palabrafu=concatenadofu.str();
						cout<<"Futuro: " <<palabrafu<<endl;
						
					}
				}
				else{
					cout<<"Palabra no aceptada!"<<endl;
				}
			}
			break;

			default: 
				cout<<"OUT OF BOUNDS"<<endl;
			break;

		}
		cout<<"Desea continuar? 1/ SI 2/NEIN!"<<endl;
	cin>>respuesta;
	}
	cout<<"Thanks for participating!"<<endl;
	return 0;
}

void printArray(int* array, int size){
	cout<<"Entering.."<<endl;
	if(array!= NULL){
		for(int i =0; i<size; i++){
			cout<< "["<<array[i]<<"]";
		}
		cout<<endl;
	}
}

int* createArray(int size){
	cout<< "Initializing..";
	cout<<endl;
	return new int[size];
}

void initArray(int* array, int size){
	int n1 =-1;
	int n2 =-1;
	int n3 =-1;
	int n4 =-1;
	if(array!=NULL){
		cout<<"Adding data.." << endl;
		
		for(int i=0; i<size; i++){
			int value=1;
			while(value==1){
				int random = rand()%9;
				if(random != n1 && random != n2 && random != n3 && random != n4){
					if(i==0){
						n1 = random;
						array[i]=random;
					}
					if(i==1){
						n2 = random;
						array[i] = random;
					}
					if(i==2){
						n3 = random;
						array[i] = random;
					}
					
					if(i==3){
						n4 = random;
						array[i] = random;
					}
					value=0;
				}
			}
		}
	}
}

void freeArray(int* array){
	if(array!=NULL){
		delete[] array;
	}
	cout<<endl;
	cout<<"DATA EXPUNGED"<<endl;
}
