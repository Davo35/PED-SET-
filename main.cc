#include <iostream>
#include <set>

struct Estudiante
{
  std::string Nombre;
  std::string Identificacion;
};

void menu(std::set<Estudiante>& Inscripcion_Alumnos);
void eliminarEstudiante(std::set<Estudiante> &Inscripcion_Alumnos);

int main()
{

  std::set<Estudiante> Inscripcion_Alumnos;
  // aqui van las funciones a llamar
  menu(Inscripcion_Alumnos);

  return 0;
}

void menu(std::set<Estudiante> &Inscripcion_Alumnos)
{
  int Opcion;

  std::cout << "\n------ Inscripcion Universitaria ------- \n\n";
  std::cout
      << "1. Registrar Informacion || 2.  Modificar Informacion || "
         "3. Mostrar Informacion || 4. Eliminar informacion || 5. Salir\n\n";
  std::cout << "Digitar una opcion: ";
  std::cin >> Opcion;

  do{
    switch (Opcion){
    case 1:
      /* code */
      break;
    case 2:
      /* code */
      break;
    case 3:
      /* code */
      break;
    case 4:
    eliminarEstudiante(Inscripcion_Alumnos);
      break;

    default:
      break;
    }

  }while (Opcion != 4);

  std::cout << "\nSaliendo....\n";
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
