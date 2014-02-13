
#include "almacen.h"

CAlmacen::CAlmacen(int s) : size(s){ //constructor Crea el array de compartimentos ‘cajas’, del tamaño indicado s. Inicializa a 0 el numero de cajas ocupadas y el numero de unidades en cada caja.
	
	int i = 0;
	
	cajas = new box[size];
	nCajasOcupadas = 0;
	
	for (i = 0; i < size; i++) {
		cajas[i].p_units = 0;
		
		
	}
	
	
}

CAlmacen::~CAlmacen(){ //Destructor Libera la memoria ocupada por el array ‘cajas’.
	
	delete[] cajas;
	
}

int CAlmacen::buscarProducto(int cod){ //Recibe el código de un producto y devuelve la posicion de la caja donde está, ó -1 si no lo encuentra.
	
	int posicion;
	int r = 0;
	int i = 0;
	while ((i < nCajasOcupadas) && (r == 0)) {
		if (cod == cajas[i].p_code) {
			posicion = i;
			r = 1;
		}
		else {
			posicion = -1;
			r = 1;
		}
		i++;
	}
	
	return posicion;
}

void CAlmacen::infoProducto(string name){ //Recibe el nombre de un producto y devuelve toda la información sobre él, es decir, la caja donde se encuentra, su código y el número de unidades disponibles.
	
	int h = 0;
	int p = 0;
	int i = 0;
	while ((i < nCajasOcupadas) && (h == 0)) {
		if (name == cajas[i].p_name) {
			cout << "Nombre del Producto:             " << cajas[i].p_name << endl;
			cout << "Código del Producto:             " << cajas[i].p_code << endl;
			cout << "Caja donde se encuentra:         " << "caja nº:" << i << endl;
			cout << "Número de Unidades disponibles:  " << cajas[i].p_units << endl;
			p = 1;
			h = 1;
		}
		i++;
	}
	
	if (p = 0) {
		cout << "Ese producto no existe" << endl;
		
	}
	
	
}

void CAlmacen::anadirProducto(string name, int cod, int unidades){ //Recibe los datos de un producto a meter en el almacen (nombre, código y número de unidades). Si el producto ya está en algún compartimento del almacén, simplemente actualiza el número de unidades disponibles. Si no, lo mete en el primer compartimento vacío que encuentre, si el almacén no está lleno, e incrementa nCajasOcupadas.
	

	int i = 0;
	int ver = 0;
	
	while(i <= nCajasOcupadas) {
		if (cod == cajas[i].p_code) {
			cajas[i].p_units = unidades;
			ver = 1;
			
		}
		i++;
		
	}
	i--;
	if (ver == 0) {
		if (nCajasOcupadas < size) {
			
			cajas[i].p_name = name;
			cajas[i].p_code = cod;
			cajas[i].p_units = unidades;
			nCajasOcupadas++;
		}
		cout << "Producto agregado con éxito en la caja nº:" << i << endl;
	}
	
	
}

void CAlmacen::retirarProducto(string name1, int cod, int unidades){ //Recibe el nombre y código de un producto y el número de unidades a retirar. Busca el compartimento donde está y resta las unidades pedidas, siempre y cuando sea posible (pedido menor que unidades disponibles). Si el compartimento queda vacío, decrementa nCajasOcupadas.
	
	int w;
	int rec = 0;
	int i = 0;
	while ((i < nCajasOcupadas) && (rec == 0)) {
		if ((name1 == cajas[i].p_name) && (cod == cajas[i].p_code)) {
			if (cajas[i].p_units > unidades){
				w = cajas[i].p_units;
				
				cajas[i].p_units = (w - unidades);
				cout << w << " menos " << unidades << " es igual a:" << cajas[i].p_units << endl;
				cout << "Por tanto quedan en el almacén " << cajas[i].p_units << " unidades." << endl;
				rec = 1;
			}
			if ((cajas[i].p_units < unidades) && (rec == 0)) {
				cout << "no hay suficientes unidades de ese producto" << endl;
				rec = 1;
				
			}
			if ((cajas[i].p_units = unidades) && (rec == 0)) {
				nCajasOcupadas--;
				rec = 1;
				
			}
		
			i++;
		}
	}
	
}

void CAlmacen::listar(){ //Lista todos los productos que hay en el almacén, mostrando la caja donde están, el nombre, código y número de unidades.
	
	int i = 0;
	
	
	cout << "*************ALMACÉN**************" << endl;
	for (i = 0; i < nCajasOcupadas; i++) {
		cout << "----------------------------------" << endl;
		cout << "Caja donde está situada:.........." << i << endl;
		cout << "Nombre:..........................." << cajas[i].p_name << endl;
		cout << "Código:..........................." << cajas[i].p_code << endl;
		cout << "Número de Unidades:..............." << cajas[i].p_units << endl;
		cout << "----------------------------------" << endl;
		
	}
	
}

bool CAlmacen::comprobar(){

	if (nCajasOcupadas < size) {
		return true;
	}
	if (nCajasOcupadas == size) {
		return false;
	}

}

