#pragma once
#include"Prerequisites.h"

class Ticket {
public:
	Ticket() = default;
	Ticket(int id, std::string titulo, std::string descripcion, std::string estado) :  // Constructor con parámetros
		ID(id), m_titulo(titulo), m_descripcion(descripcion), m_estado(estado) {
		m_fecha.GetFecha(); // Guarda la fecha de creación
	} 
	~Ticket() = default;

	void mostrar() const {	// Muestra los datos del ticket en consola
		std::cout << "Ticket no: " << ID << std::endl;
		std::cout << "Titulo: " << m_titulo<< std::endl;
		std::cout << "Detalles: " << m_descripcion << std::endl;
		std::cout << "Estado actual es: " << m_estado << std::endl;
		std::cout << "Fecha de generacion: " << m_fecha.toString() << std::endl;
	}


	int GetID() const { return ID; }     // Devuelve el ID del ticket
	void GetEstado() {   // Cambia el estado automáticamente siguiendo la secuencia valida
		if (m_estado == "Pendiente") {
			m_estado = "En Progreso";
			std::cout << "El ticket ahora está en 'En Progreso'." << std::endl;
		}
		else if (m_estado == "En Progreso") {
			m_estado = "Completado";
			std::cout << "El ticket ahora está 'Completado'." << std::endl;
		}
		else if (m_estado == "Completado") {
			std::cout << "El ticket ya está completado, no se puede avanzar." << std::endl;
		}
	}
	void GetDescripcion(const std::string& desc) { m_descripcion = desc; }
	void GetTitulo(const std::string& titulo) { m_titulo = titulo; }
	// modifican el título y la descripción
private:
	int ID;
	std::string m_titulo;
	std::string m_descripcion;
	std::string m_estado;
	Fecha m_fecha;
};