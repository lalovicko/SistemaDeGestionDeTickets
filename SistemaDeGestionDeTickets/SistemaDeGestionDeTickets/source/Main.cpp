#include "Prerequisites.h"
#include "Ticket.h"
#include "Gestor.h"
int
main(){
	int eleccion;
	Gestor g;
	do {
		std::cout << "Bienvenido al gestor de reporte de bugs en videojuegos, ";
		std::cout << "que desea hacer? 1-Generar Reporte 2-Editar Reporte 3-Mostrar Reportes Generados  4-Eliminar 5-Salir" << std::endl;
		std::cin >> eleccion;
		switch (eleccion) {
		case 1:{
				int id;
				std::string problema;
				std::string descripcion;
				std::string estado;
				std::cout << "Por favor asigne un ID para identificar el problema? " << std::endl;
				std::cin >> id;
				std::cin.ignore();
				std::cout << "Cual es el problema?" << std::endl;
				std::getline(std::cin, problema);
				std::cout << "Como se genero este bug?" << std::endl;
				std::getline(std::cin, descripcion);
				estado = "pendiente";
				Ticket nuevo(id, problema, descripcion, estado);
				g.Agregar(nuevo);
				std::cout << "Reporte generado correctamente" << std::endl;
				break;
			}
		case 2: {
			int id;
			std::cout << "Cual es el numero de ID del ticket que desea editar?" << std::endl;
			std::cin >> id;
			g.Editar(id);
			break;
		}
		case 3: {
			g.MostrarLista();
			break;
		}
		case 4: {
			int id;
			std::cout << "Cual es el numero de ID del ticket que desea borrar?" << std::endl;
			std::cin >> id;
			g.Eliminar(id);
		}
		}
	} while (eleccion != 5);
}