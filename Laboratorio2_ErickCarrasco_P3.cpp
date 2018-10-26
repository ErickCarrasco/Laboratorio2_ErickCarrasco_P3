#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#include <cstdlib>

#include <string>
//using std::to_string;
//using std::stoi;

#include <ctime>

int* createArray(int);

void freeArray(int*);

void initArray(int*, int);

void printArray(int*, int);

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
				//printArray(arreglo, size);
				while(chances>0){
					cout<<endl;	
					cout<<...<<endl<<endl<<"DATA GENERATED"<<endl;
					string cadenauser;
					cout<<"Ingrese una cadena de 4 numeros (0-9)"<<endl;
					cin>>cadenauser;
					int validador2=0;
					while(validador2==0){
						
					}
					
				}
				freeArray(arreglo);	
			}
			break;
			
			case 2:
			{
				
			}
			break;

			case 3:
			{
			
			}
			break;

			default: 
			
			break;

		}
	}
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
}
