#ifndef AED_SCHEDULE_UC_H
#define AED_SCHEDULE_UC_H

#include <string>
#include <utility>
#include <iostream>

using namespace std;

/**
 * Classe UC
 * @details Esta classe define a relação entre turmas e UCs
 */

class UC {
    int const static cap = 30;
    string codeUC;
    string Class;
public:
    int NumStudents;
    /**
     * Complexity: O(1)
     * Construtor personalizado da classe.
     * @param codeUC string relativa ao código da UC
     * @param Class string relativa ao código da turma
     * @param NumStudents int relativo ao número de estudantes
     */
    UC(string codeUC, string Class, int NumStudents);
    /**
     * Complexity: O(1)
     * Construtor personalizado da classe UC para Student.
     * @param codeUC string relativa ao código da UC
     * @param Class string relativa ao código da turma
     */
    UC(string codeUC, string Class);
    /**
     * Complexity: O(1)
     * Copy Construtor da classe.
     * @param C membro da classe UC que se pretende copiar
     */
    UC(const UC& C);
    /**
     * Complexity: O(1)
     * Método normal que devolve o atributo codeUC
     * @return string relativa ao código da UC
     */
    string getcodeUC() const;
    /**
     * Complexity: O(1)
     * Método normal que devolve o atributo Class
     * @return string relativa ao código da turma
     */
    string getClass() const;
    /**
     * Complexity: O(1)
     * Método normal que devolve o atributo cap
     * @return int que representa o número máximo de alunos numa turma
     */
    static int getcap() ;
    /**
     * Complexity: O(1)
     * Método normal que devolve o atributo NumStudents
     * @return int que representa o número de alunos numa turma
     */
    int getNumStudents() const;
    /**
     * Complexity: O(1)
     * Método void que modifica o atributo codeUC segundo o parâmetro utilizado
     * @param newcodeUC string relativa ao código da UC
     */
    void setcodeUC(string newcodeUC);
    /**
     * Complexity: O(1)
     * Método void que modifica o atributo Class segundo o parâmetro utilizado
     * @param newClass string relativa ao código da turma
     */
    void setClass(string newClass);
    /**
     * Complexity: O(1)
     * Método void que incrementa o atributo NumStudents
     */
    void addStudent();
    /**
     * Complexity: O(1)
     * Método void que decrementa o atributo NumStudents
     */
    void removeStudent();
    /**
     * Complexity: O(1)
     * Operador de igualdade para dois membros da classe Student.
     * @param UC membro da classe UC
     * @return true caso os dois membros sejam relativos à mesma turma, false caso contrário
     */
    bool operator==(UC& UC) const;
};

#endif //AED_SCHEDULE_UC_H
