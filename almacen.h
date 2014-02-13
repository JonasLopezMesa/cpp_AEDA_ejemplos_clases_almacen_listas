#include <string> 
#include <iostream>
using namespace std;

typedef struct
{
	string p_name;			//nombre del producto 
	int p_code;				//código del producto 
	int p_units;			//número de unidades del producto
	int pos;
} box;

class CAlmacen
{
	
private:
	int size;				//tamaño del almacen, número de compartimentos 
	box *cajas;				//array de compartimentos 
	int nCajasOcupadas;		//número de compartimentos ocupados
public: 
	CAlmacen(int s); 
	~CAlmacen();
	int buscarProducto (int cod);
	void infoProducto (string name); 
	void anadirProducto(string name, int cod, int unidades); 
	void retirarProducto(string name1, int cod, int unidades); 
	void listar();
	bool comprobar();
};

