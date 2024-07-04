#ifndef AED_SCHEDULE_STUDENT_H
#define AED_SCHEDULE_STUDENT_H

#include <string>
#include <vector>
#include <utility>
#include "UC.h"

using namespace std;

/**
 * Classe Student
 * @details Esta classe define as aulas de um estudante
 */

class Student {
    string name;
    int StudentId;
    vector<UC> classes;
public:
    /**
     * Complexity: O(1)
     * Construtor personalizado da classe.
     * @param name string relativa ao nome do estudante
     * @param StudentId int relativa ao número de estudante do estudante
     * @param classes vector que representa as aulas do estudante
     */
    Student(string name, int StudentId, vector<UC> classes);
    /**
     * Complexity: O(1)
     * Copy Construtor da classe.
     * @param S membro da classe Student que se pretende copiar
     */
    Student(const Student& S);
    /**
     * Complexity: O(1)
     * Método normal que devolve o atributo name
     * @return string relativa ao nome do estudante
     */
    string getName();
    /**
     * Complexity: O(1)
     * Método normal que devolve o atributo StudentId
     * @return int relativa ao número de estudante do estudante
     */
    int getId() const;
    /**
     * Complexity: O(1)
     * Método normal que devolve o atributo classes
     * @return vector que representa as aulas do estudante
     */
    vector<UC> getClasses();
    /**
     * Complexity: O(1)
     * Método void que modifica o atributo name segundo o parâmetro utilizado
     * @param newName string relativa ao nome do estudante
     */
    void setName(string newName);
    /**
     * Complexity: O(1)
     * Método void que modifica o atributo StudentId segundo o parâmetro utilizado
     * @param newStudentId int relativa ao número de estudante do estudante
     */
    void setId(int newStudentId);
    /**
     * Complexity: O(1)
     * Método void que modifica o atributo classes segundo o parâmetro utilizado
     * @param newClasses int relativa ao número de estudante do estudante
     */
    void setClasses(vector<UC> newClasses);
    /**
     * Complexity: O(1)
     * Operador de igualdade para dois membros da classe Student.
     * @param S membro da classe Student
     * @return true caso os dois membros sejam relativos ao mesmo aluno, false caso contrário
     */
    bool operator==(Student& S) const;
    /**
     * Complexity: O(1)
     * Método void que modifica o atributo classes segundo o parâmetro utilizado
     * @param UC membro da classe UC
     */
    void addUC(const UC& UC);
};

#endif //AED_SCHEDULE_STUDENT_H
