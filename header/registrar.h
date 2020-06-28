#ifndef __registrar_h_
#define __registrar_h_
#endif

#include <string>
#include <map>
#include "student.h"

using namespace std;

class Registrar {
  private:
    map<int, Student> registrarMap;
  public:
    void addStudent(int idIn, string nameIn, string emailIn);
    void searchStudent(string name);
    void modifyStudent(int id, string nameIn, string emailIn);
    void updateStudent(int id, Student student);
    void viewStudent(int id);
    void deleteStudent(int id);
    Student getStudent(int id);
};