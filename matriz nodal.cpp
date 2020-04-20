//Feliciano Morales Juan Daniel 10/04/20.
//Copyright © 2020 Feliciano Morales Juan Daniel. Todos los derechos reservados
#include <iostream>
using namespace std;
class Nodo
{
	private:
    	float dato;
    	int x,y;
    	Nodo *sig;
    	Nodo *ant;
	public:
    	Nodo()
    	{  	dato=0.0;
        	x=0;
        	y=0;
        	sig=NULL;
        	ant=NULL;
    	}
    	Nodo(float a)
    	{  	dato=a;
        	x=0;
        	y=0;
        	sig=NULL;
        	ant=NULL;
    	}
    	Nodo(float a,int b, int c)
    	{	dato=a;
        	x=b;
        	y=c;
        	sig=NULL;
        	ant=NULL;
    	}
    	void Asignasig(Nodo*);
    	void Asignaant(Nodo*);
    	void Leer(float);
    	void Imprimir();
    	Nodo *Obtienesig();
    	Nodo *Obtieneant();
    	float Obtienedato();
    	float Obtienefila();
    	float Obtienecolumna();
};
void Nodo::Asignasig(Nodo *x)
{  this->sig=x;
}
void Nodo::Asignaant(Nodo *x)
{  this->ant=x;
}
void Nodo::Leer(float a)
{  this->dato=a;
}
void Nodo::Imprimir()
{  cout<<"["<<this->dato<<"]";
}
Nodo* Nodo::Obtienesig()
{  return(this->sig);
}
Nodo* Nodo::Obtieneant()
{  return(this->ant);
}
float Nodo::Obtienedato()
{  return(this->dato);
}
float Nodo::Obtienefila()
{  return(this->x);
}
float Nodo::Obtienecolumna()
{  return(this->y);
}
class LDE
{   private:
    	Nodo *Inicio,*Fin;
	public:
    	void InsertarI(int);
    	void InsertarF(float,int,int);
    	void BorrarI();
    	void BorrarF();
   		void Imprimir();
    	void ImprimirR();
    	int Contar();
    	Nodo *Buscar(int);
    	Nodo *Buscar(int,int);
		void Borrar(int);
    	void Inicializar();
    	void Leer();
    	LDE operator + (LDE);
    	LDE operator - (LDE);
    	LDE operator * (LDE);
    	LDE()
    	{
        	Inicio=NULL;
        	Fin=NULL;
    	}
    	LDE(int,int,float);
    	LDE(int,float);  
};
void LDE::InsertarF(float d,int f,int c)
{	if(!Inicio)
	{	Inicio=new Nodo(d,f,c);
		Fin=Inicio;
	}
	else
	{	Nodo *Aux=new Nodo(d,f,c);
		Fin->Asignasig(Aux);
		Aux->Asignaant(Fin);
		Fin=Aux;
	}
}
void LDE::Imprimir()
{	Nodo *Aux=Inicio;
	if(!Inicio) cout<<"Matriz vacia"<<endl;
	else
	{	for(int i=1;i<=Fin->Obtienefila();i++)
		{	for(int j=1;j<=Fin->Obtienecolumna();j++)
			{	Aux->Imprimir();
				Aux=Aux->Obtienesig();
			}
			cout<<endl;
		}	
	} 
}
void LDE::ImprimirR()
{	Nodo *Aux=Fin;
	for(int i=1;i<=Fin->Obtienefila();i++)
	{	for(int j=1;j<=Fin->Obtienecolumna();j++)
		{	Aux->Imprimir();
			Aux=Aux->Obtieneant();
		}
		cout<<endl;
	} 
}
int LDE::Contar()
{	Nodo *Aux=Inicio;
	int c=0;
	while(Aux!=NULL)
	{	Aux=Aux->Obtienesig(); c++;
	}
	return c;
}
void LDE::Leer()
{	int f,c;
	float d;
	cout<<"Ingrese numero de filas: ";	cin>>f;
	cout<<"Ingrese numero de columnas: ";	cin>>c;
	for(int i=1;i<=f;i++)
		for(int j=1;j<=c;j++)
		{	cout<<"Ingresa ["<<i<<"]["<<j<<"] :"; cin>>d;
			InsertarF(d,i,j);
		}
}
Nodo* LDE::Buscar(int x,int y)
{	Nodo *Aux=Inicio,*F;
	while(Aux!=NULL)
	{	if( (Aux->Obtienefila()==x) && (Aux->Obtienecolumna()==y) ) 
		{	F=Aux;
			Aux=NULL;
		}
		else	Aux=Aux->Obtienesig();
	}
	return F;
}
LDE LDE::operator +(LDE B)
{	LDE F;
	Nodo *A=Inicio,*D=B.Inicio;
 //La condición esta mal, imaginate que tienes una matriz de 3X4 y otra de 2X6, segun tu programa si se podrian sumar.
	if(B.Contar()==Contar())
		
	{	for(int i=1;i<=Fin->Obtienefila();i++)
		//no utilices ciclos for, para una lista utilizamos ciclos while
			for(int j=1,v;j<=Fin->Obtienecolumna();j++)
			{ 	v=A->Obtienedato()+D->Obtienedato();
				A=A->Obtienesig();
				D=D->Obtienesig();
				F.InsertarF(v,i,j);
			}
		return F;
	}
	else cout<<"Para sumar matrices deben de ser del mismo numero de filas y columnas"<<endl;
}
LDE LDE::operator -(LDE B)
{	LDE F;
	Nodo *A=Inicio,*D=B.Inicio;
 //La condición esta mal, imaginate que tienes una matriz de 3X4 y otra de 2X6, segun tu programa si se podrian restar.
	if(B.Contar()==Contar())
	{	for(int i=1;i<=Fin->Obtienefila();i++)
			for(int j=1;j<=Fin->Obtienecolumna();j++)
			{ 	int v=A->Obtienedato()-D->Obtienedato();
				A=A->Obtienesig();
				D=D->Obtienesig();
				F.InsertarF(v,i,j);
			}
		return F;
	}
	else cout<<"Para restar matrices deben de ser del mismo numero de filas y columnas"<<endl;
}
LDE LDE::operator *(LDE B)
{	LDE F;
	Nodo *uno,*dos;
	if(Fin->Obtienecolumna()==B.Fin->Obtienefila())
	{	for(int i=1;i<=Fin->Obtienefila();i++)
			for(int j=1,v;j<=B.Fin->Obtienecolumna();j++)
			{	v=0;
				for(int k=1;k<=Fin->Obtienecolumna();k++)
				{	uno=Buscar(i,k); dos=B.Buscar(k,j);
					v=v+uno->Obtienedato()*dos->Obtienedato();
				}
				F.InsertarF(v,i,j);
			}
		return F;
	}
	else
	{	cout<<"Como el numero de columnas de la primer matriz es diferente al numero de filas de la segunda"<<endl
		<<"No es posible hacer la operacion solicitada"<<endl;
	}
	
}
int main(int argc, const char * argv[])
{	LDE A,B,C;
	int opc,c=0;
	do
	{
		cout<<"1.-LLenar matrices\n2.-Imprimir\n3.-Sumar\n4.-Restar"<<endl;
        cout<<"5.- Multiplicar\n6- Salir\nSeleccionaste: ";   cin>>opc;
        switch(opc)
        {	case 1: if(c==0) 
					{	A.Leer(); B.Leer(); c++;
					}
					else cout<<"Solo puedes usar esta opcion 1 vez"<<endl; break;	
        	case 2:	A.Imprimir(); cout<<endl; B.Imprimir(); cout<<endl; C.Imprimir(); break;
        	case 3: C=A+B; break;
        	case 4: C=A-B; break;
        	case 5:	if(c==1)	C=A*B; 
					else cout<<"Primero insertar datos en tus matrices para poder realizar la operacion"<<endl;	break;
        	case 6: cout<<"acabas de salir"<<endl; break;
        	default: cout<<"Opcion invalida verifica"<<endl; break;
		}
		system("pause"); system("cls");
	}while(opc!=6);
    return 0;
}
