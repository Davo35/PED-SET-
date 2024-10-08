#include <iostream>
#include <set>

struct Estudiante {
  std::string Nombre;
  std::string Identificacion;
  std::string Carrera;

  // Sobrecargar el operador < para poder almacenar en un set
  bool operator<(const Estudiante &temp) const {
    return Nombre < temp.Nombre;  // Ordenar por nombre
  }
  /*Compara elementos que almacena, si ya existe en el set, no lo almacena */
};

void menu(std::set<Estudiante> &alumno);
void IngresarDatos(std::set<Estudiante> &alumno, const std::string &nombre,
                   const std::string &identificacion,
                   const std::string &carrera);

int main() {
  std::set<Estudiante> Inscripcion_Alumnos;
  menu(Inscripcion_Alumnos); //Pasamos el set al menu para distribuirse por todo el codigo
  return 0;
}

void menu(std::set<Estudiante> &alumno) {
  int Opcion;
  std::string nombre, identificacion, carrera;

  do {
    std::cout << "\n------ Inscripcion Universitaria ------- \n\n";
    std::cout
        << "1. Registrar Informacion || 2. Modificar Informacion || "
        << "3. Mostrar Informacion || 4. Eliminar informacion || 5. Salir\n\n";
    std::cout << "Digitar una opcion: ";
    std::cin >> Opcion;

    switch (Opcion) {
      case 1:
        // Ingresar
        std::cin.ignore();  // Para evitar problemas con getline
        std::cout << "\nIngresar Nombre: ";
        std::getline(std::cin, nombre);

        std::cout << "\nIngresar NIE o DUI: ";
        std::cin >> identificacion;

        std::cout << "\nCarrera a cursar: ";
        std::cin.ignore();
        std::getline(std::cin, carrera);

        IngresarDatos(alumno, nombre, identificacion, carrera);
        break;

      default:
        break;
    }

  } while (Opcion != 5);

  std::cout << "\nSaliendo....\n";
}

void IngresarDatos(std::set<Estudiante> &alumno, const std::string &nombre,
                   const std::string &identificacion,
                   const std::string &carrera) {
  // Parametros como referencia ya que va cambiar constantemente
  Estudiante AlumnoIngresar = {nombre, identificacion, carrera};

  // Agregando alumno y comprobando que ha sido agregado
  if (alumno.insert(AlumnoIngresar).second) { //Second
    std::cout << "\nAgregaste la informacion correctamente\n\n";
    std::cout << "Nombre: " << nombre << "  Dui/Nit: " << identificacion
              << "   Carrera: " << carrera << std::endl;
    system("pause");
  } else {
    std::cout << "\nYa existe una persona con esos datos\n";
  }
}

