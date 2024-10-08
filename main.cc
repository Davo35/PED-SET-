#include <iostream>
#include <set>
#include <string>

struct Estudiante {
    std::string Nombre;
    std::string Identificacion;
    std::string Carrera;

    // Comparador que primero considera la Identificacion y luego el Nombre
    bool operator<(const Estudiante &temp) const {
        return Identificacion < temp.Identificacion;
    }
};

void menu(std::set<Estudiante>& Inscripcion_Alumnos);
void IngresarDatos(std::set<Estudiante> &alumno, const std::string &nombre, const std::string &identificacion, const std::string &carrera);
void eliminarEstudiante(std::set<Estudiante> &Inscripcion_Alumnos);
void buscar(const std::set<Estudiante>& Inscripcion_Alumnos);
void mostrar(const std::set<Estudiante>& Inscripcion_Alumnos);

int main() {
    std::set<Estudiante> Inscripcion_Alumnos;
    menu(Inscripcion_Alumnos);
    return 0;
}

void menu(std::set<Estudiante> &Inscripcion_Alumnos) {
    int Opcion;
    std::string nombre, identificacion, carrera;
    do {
        std::cout << "\n------ Inscripcion Universitaria ------- \n\n";
        std::cout << "1. Registrar Informacion || 2. BUscar Informacion || "
                  << "3. Mostrar Informacion || 4. Eliminar informacion || 5. Salir\n\n";
        std::cout << "Digitar una opcion: ";
        std::cin >> Opcion;
        std::cin.ignore();  // Limpiar el bufer

        switch (Opcion) {
            case 1:
                std::cout << "\nIngresar Nombre: ";
                std::getline(std::cin, nombre);

                std::cout << "\nIngresar NIE o DUI: ";
                std::getline(std::cin, identificacion);  // Cambie a getline

                std::cout << "\nCarrera a cursar: ";
                std::getline(std::cin, carrera);

                IngresarDatos(Inscripcion_Alumnos, nombre, identificacion, carrera);
                break;
            case 2:
                buscar(Inscripcion_Alumnos);
                break;
            case 3:
                mostrar(Inscripcion_Alumnos);
                break;
            case 4:
                eliminarEstudiante(Inscripcion_Alumnos);
                break;
            default:
                break;
        }
    } while (Opcion != 5);
}

void buscar(const std::set<Estudiante>& Inscripcion_Alumnos) {
    std::string identificacion;
    std::cout << "Ingrese el id del estudiante a buscar: ";
    std::cin >> identificacion;
    std::cin.ignore();  // Limpiar el bufer

    Estudiante estudiante_buscado;
    estudiante_buscado.Identificacion = identificacion;

    // Busqueda por identificacion
    auto iterador = Inscripcion_Alumnos.find(estudiante_buscado);
    if (iterador != Inscripcion_Alumnos.end()) {
        std::cout << "Estudiante encontrado:\n";
        std::cout << "Nombre: " << iterador->Nombre << "\nIdentificacion: " << iterador->Identificacion << std::endl;
        std::cout << "Carrera: " << iterador->Carrera <<std::endl;
    } else {
        std::cout << "Estudiante no encontrado.\n";
    }
}

void IngresarDatos(std::set<Estudiante> &alumno, const std::string &nombre, const std::string &identificacion, const std::string &carrera) {
    Estudiante AlumnoIngresar = {nombre, identificacion, carrera};

    if (alumno.insert(AlumnoIngresar).second) {
        std::cout << "\nAgregaste la informacion correctamente\n\n";
        std::cout << "Nombre: " << nombre << "  Dui/Nit: " << identificacion
                  << "   Carrera: " << carrera << std::endl;
    } else {
        std::cout << "\nYa existe una persona con esos datos\n";
    }
}

void eliminarEstudiante(std::set<Estudiante> &Inscripcion_Alumnos) {
    std::string Identificacion;
    std::cout << "Ingrese el NIE o DUI del estudiante a eliminar: ";
    std::getline(std::cin, Identificacion);

    Estudiante estudiante_buscado;
    estudiante_buscado.Identificacion = Identificacion;

    // Buscamos y eliminamos el estudiante
    auto it = Inscripcion_Alumnos.find(estudiante_buscado);
    if (it != Inscripcion_Alumnos.end()) {
        Inscripcion_Alumnos.erase(it);
        std::cout << "El estudiante ha sido eliminado con exito." << std::endl;
    } else {
        std::cout << "No se encontro ningun estudiante con ese NIE o DUI." << std::endl;
    }
}

void mostrar(const std::set<Estudiante>& Inscripcion_Alumnos) {
    if (Inscripcion_Alumnos.empty()) {
        std::cout << "No hay estudiantes registrados.\n";
    } else {
        std::cout << "Lista de estudiantes registrados:\n";
        for (const auto& estudiante : Inscripcion_Alumnos) {
            std::cout << "Nombre: " << estudiante.Nombre << "\n";
            std::cout << "Identificacion: " << estudiante.Identificacion << "\n";
            std::cout << "Carrera: " << estudiante.Carrera << "\n";
            std::cout << "----------------------------\n";
        }
    }
}

