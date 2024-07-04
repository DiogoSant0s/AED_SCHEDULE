#ifndef AED_SCHEDULE_SCHEDULE_H
#define AED_SCHEDULE_SCHEDULE_H

#include <string>
#include <vector>
#include <utility>
#include "Interval.h"
#include "UC.h"

using namespace std;

/**
 * Classe Schedule
 * @details Esta classe define o horário de cada turma relativo a cada cadeira.
 */

class Schedule {
    UC UCClass;
    vector<Interval> intervals;
public:
    /**
     * Complexity: O(1)
     * Construtor personalizado da classe.
     * @param UCClass UC relativa à turma e cadeira
     * @param intervals vector que representa a duração das aulas de uma turma
     */
    Schedule(UC& UCClass, vector<Interval> intervals);
    /**
     * Complexity: O(1)
     * Copy Construtor da classe.
     * @param S membro da classe Schedule que se pretende copiar
     */
    Schedule(const Schedule &S, const UC& ucClass);
    /**
     * Complexity: O(1)
     * Método normal que devolve o atributo codeUC
     * @return string relativa ao código da UC
     */
    string getCodeUC() const;
    /**
     * Complexity: O(1)
     * Método normal que devolve o atributo Class
     * @return string relativa ao código da turma
     */
    string getClass() const;
    /**
     * Complexity: O(1)
     * Método normal que devolve o atributo intervals
     * @return vector que representa a duração das aulas de uma turma
     */
    vector<Interval> getIntervals();
    /**
     * Complexity: O(1)
     * Método void que modifica o atributo codeUC segundo o parâmetro utilizado
     * @param newCodeUC string relativa ao código da UC
     */
    void setCodeUC(string newCodeUC) const;
    /**
     * Complexity: O(1)
     * Método void que modifica o atributo Class segundo o parâmetro utilizado
     * @param newClass string relativa ao código da turma
     */
    void setClass(string newClass) const;
    /**
     * Complexity: O(1)
     * Método void que modifica o atributo intervals segundo o parâmetro utilizado
     * @param newIntervals vector que representa a duração das aulas de uma turma
     */
    void setInterval(const vector<Interval> &newIntervals);
    /**
     * Complexity: O(1)
     * Método void que modifica o atributo intervals segundo o parâmetro utilizado
     * @param I membro da classe Interval
     */
    void addInterval(Interval& I);
    /**
     * Complexity: O(1)
     * Operador de igualdade para dois membros da classe Schedule.
     * @param S membro da classe Schedule
     * @return true caso os dois membros sejam relativos à mesma cadeira e turma, false caso contrário
     */
    bool operator==(Schedule& S) const;
};

#endif //AED_SCHEDULE_SCHEDULE_H
