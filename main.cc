#include <iostream>
#include <set>

// Estructura estudiante
struct Estudiante {
  std::string Nombre;
  std::string Identificacion;
};

void menu();
void buscar(const std::set<Estudiante>& Inscripcion_Alumnos);

int main() {
  std::set<Estudiante> Inscripcion_Alumnos;
  // aqui van las funciones a llamar

  return 0;
}

void menu() {
  int Opcion;

  std::cout << "\n------ Inscripcion Universitaria ------- \n\n";
  std::cout
      << "1. Registrar Informacion || 2.  Modificar Informacion || "
         "3. Mostrar Informacion || 4. Eliminar informacion || 5. Salir\n\n";
  std::cout << "Digitar una opcion: ";
  std::cin >> Opcion;

  do {
    switch (Opcion) {
      case 3:
        buscar(Inscripcion_Alumnos);
        break;

      default:
        break;
    }

  } while (Opcion != 4);

    std::cin.ignore(); // Limpiar el buffer
    std::cin.get(); // Esperar entrada del usuario
}

void buscar(const std::set<Estudiante>& Inscripcion_Alumnos) {
    std::string identificacion;
    std::cout << "Ingrese el id del estudiante a buscar: ";
    std::cin >> identificacion;

    Estudiante estudiante_buscado;
    estudiante_buscado.Identificacion = identificacion;

    std::set<Estudiante>::const_iterator iterador = Inscripcion_Alumnos.find(estudiante_buscado);
    if (iterador != Inscripcion_Alumnos.end()) {
        std::cout << "Estudiante encontrado:\n";
        std::cout << "Nombre: " << iterador->Nombre << "\nIdentificacion: " << iterador->Identificacion << std::endl;
    } else {
        std::cout << "Estudiante no encontrado.\n";
    }
}