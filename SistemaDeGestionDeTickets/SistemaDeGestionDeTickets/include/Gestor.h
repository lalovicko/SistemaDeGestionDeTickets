#pragma once
#include "Prerequisites.h"
#include "Ticket.h"
class Gestor {
public:
    void Agregar(const Ticket& t) { // Agrega un ticket al vector
        tickets.push_back(t); 
    }

    void MostrarLista()const {
        if (tickets.empty()) {
            std::cout << "No hay ningun ticket generado aun" << std::endl;
        }
        else {
            for (const auto& t:tickets) {
                t.mostrar();
            }
        }
    }

    void Eliminar(int id) { // Elimina un ticket por ID
        for (auto it = tickets.begin(); it != tickets.end(); ++it) {
            if (it->GetID() == id) {
                tickets.erase(it);
                std::cout << "Ticket eliminado con exito" << std::endl;
                return;
            }
        }
        std::cout << "No se encontro ticket con ese ID" << std::endl;
    }


    void Editar(int id) { 
        for (auto& t : tickets) {
            if (t.GetID() == id) {
                std::cout << "Que desea editar? 1-Titulo 2-Descripcion 3-Estado: " << std::endl;
                int editar;
                std::cin >> editar;
                std::cin.ignore();

                switch (editar) {
                case 1: {
                    std::string nuevoTitulo;
                    std::cout << "Nuevo titulo: " << std::endl;
                    std::getline(std::cin, nuevoTitulo);
                    t.GetTitulo(nuevoTitulo);
                    break;
                }
                case 2: {
                    std::string nuevaDesc;
                    std::cout << "Nueva descripcion: " << std::endl;
                    std::getline(std::cin, nuevaDesc);
                    t.GetDescripcion(nuevaDesc);
                    break;
                }
                case 3: {
                    t.GetEstado();
                    break;
                }
                default:
                    std::cout << "Opcion invalida." << std::endl;
                    return;
                }

                std::cout << "Ticket editado con exito." << std::endl;
                return;
            }
        }
        std::cout << "No se encontro ticket con ese ID." << std::endl;
    }
private:
	std::vector <Ticket> tickets;
};