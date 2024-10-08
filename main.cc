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
  };

void menu(std::set<Estudiante>& Inscripcion_Alumnos);
void IngresarDatos(std::set<Estudiante> &alumno, const std::string &nombre, const std::string &identificacion, const std::string &carrera);
void eliminarEstudiante(std::set<Estudiante> &Inscripcion_Alumnos);
void buscar(const std::set<Estudiante>& Inscripcion_Alumnos);

int main(){
  std::set<Estudiante> Inscripcion_Alumnos;
  // aqui van las funciones a llamar
  menu(Inscripcion_Alumnos);
  return 0;
}

void menu(std::set<Estudiante> &Inscripcion_Alumnos)
{
  int Opcion;
  std::string nombre, identificacion, carrera;
  do {
    std::cout << "\n------ Inscripcion Universitaria ------- \n\n";
    std::cout
        << "1. Registrar Informacion || 2. Modificar Informacion || "
        << "3. Mostrar Informacion || 4. Eliminar informacion || 5. Salir\n\n";
    std::cout << "Digitar una opcion: ";
    std::cin >> Opcion;
    switch (Opcion){
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
    case 2:
      /* code */
      break;
      case 3:
        buscar(Inscripcion_Alumnos);

        break;
    case 4:
        eliminarEstudiante(Inscripcion_Alumnos);
      break;

    default:
      break;
    }
  } while (Opcion != 5);

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
  std::cout << "\nSaliendo....\n";

}

void IngresarDatos(std::set<Estudiante> &alumno, const std::string &nombre, const std::string &identificacion, const std::string &carrera) {
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

  system("pause");
}

void eliminarEstudiante(std::set<Estudiante> &Inscripcion_Alumnos){
  std::string Identificacion;
  std::cout << "Ingrese el carnet del estudiante a eliminar: ";
  std::getline(std::cin, Identificacion);

  // hace la busqueda solamente por la identificacion del estudiante
  std::set<Estudiante>::iterator it = Inscripcion_Alumnos.find(Estudiante{"", Identificacion});
  if (it != Inscripcion_Alumnos.end()){
    Inscripcion_Alumnos.erase(it); // el erase() es de la libreria set y elimina lo que este igualado en el iterador "it"
    std::cout << "El estudiante ha sido eliminado con exito." << std::endl;
  }else{
    std::cout << "No se encontro ningun estudiante con ese carnet." << std::endl;
  }
}

