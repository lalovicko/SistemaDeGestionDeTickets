#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

// Estructura Fecha para almacenar la fecha de creación del ticket
struct Fecha {
    int dia;
    int mes;
    int anio;

    // Obtiene la fecha actual del sistema y la guarda
    std::string GetFecha() {
        time_t t = time(0);       // Hora actual
        tm* now = localtime(&t);  // Convierte a estructura tm

        dia = now->tm_mday;       // Día actual
        mes = now->tm_mon + 1;    // Mes actual (0-11)
        anio = now->tm_year + 1900; // Año actual

        return toString();        // Devuelve como string
    }

    // Convierte la fecha a string en formato dd/mm/aaaa
    std::string toString() const {
        return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio);
    }
};

};