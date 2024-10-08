#include <iostream>
#include <set>

struct Estudiante {
  std::string Nombre;
  std::string Identificacion;
};

void menu();
void eliminarEstudiante(std::set<Estudiante>& Inscripcion_Alumnos);

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

void eliminarEstudiante(std::set<Estudiante>& Inscripcion_Alumnos) {

}
