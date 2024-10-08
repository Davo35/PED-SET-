#include <iostream>
#include <set>

struct Estudiante {
  std::string Nombre;
  std::string Identificacion;
};

void menu();

int main() { 

std::set<Estudiante> Inscripcion_Alumnos;
//aqui van las funciones a llamar    
    
    
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
      case 1:
        /* code */
        break;

      default:
        break;
    }

  } while (Opcion != 4);

  std::cout << "\nSaliendo....\n";
  system("pause");
}

// Función para mostrar todos los estudiantes
void mostrar(const std::set<Estudiante>& Inscripcion_Alumnos) {
  if (Inscripcion_Alumnos.empty()) {
    std::cout << "No hay estudiantes registrados.\n";
  } else {
    std::cout << "Lista de estudiantes registrados:\n";
    for (const auto& estudiante : Inscripcion_Alumnos) {
      std::cout << "Nombre: " << estudiante.Nombre << "\n";
      std::cout << "Identificacion: " << estudiante.Identificacion << "\n";
      std::cout << "----------------------------\n";
    }
  }
}