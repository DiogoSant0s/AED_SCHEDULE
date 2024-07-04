#ifndef AED_SCHEDULE_INTERVAL_H
#define AED_SCHEDULE_INTERVAL_H

#include <string>
#include <sstream>
#include <utility>

using namespace std;

/**
 * Classe Interval
 * @details Esta classe define o dia, o tipo e as horas de início e de fim de uma aula
 */

class Interval {
    int weekday;
    float start;
    float end;
    string type;
public:
    /**
     * Complexity: O(1)
     * Construtor personalizado da classe.
     * @param weekday int relativo ao dia da aula
     * @param start float relativa à hora de início da aula
     * @param end float relativa à hora de fim da aula
     * @param type string relativa ao tipo de aula
     */
    Interval(int weekday, float start, float end, string type);
    /**
     * Complexity: O(1)
     * Copy Construtor da classe.
     * @param I membro da classe Interval que se pretende copiar
     */
    Interval(const Interval& I);
    /**
     * Complexity: O(1)
     * Método normal que devolve o atributo weekday
     * @return int relativo ao dia da aula
     */
    int getWeekDay() const;
    /**
     * Complexity: O(1)
     * Método normal que devolve o atributo start
     * @return float relativa à hora de início da aula
     */
    float getStart() const;
    /**
     * Complexity: O(1)
     * Método normal que devolve o atributo end
     * @return float relativa à hora de fim da aula
     */
    float getEnd() const;
    /**
     * Complexity: O(1)
     * Método normal que devolve o atributo type
     * @return string relativa ao tipo de aula
     */
    string getType() const;
    /**
     * Complexity: O(1)
     * Método void que modifica o atributo weekday segundo o parâmetro utilizado
     * @param newWeekDay int relativo ao dia da aula
     */
    void setWeekDay(int newWeekDay);
    /**
     * Complexity: O(n1)
     * Método void que modifica o atributo start segundo o parâmetro utilizado
     * @param newStart float relativa à hora de início da aula
     */
    void setStart(float newStart);
    /**
     * Complexity: O(1)
     * Método void que modifica o atributo end segundo o parâmetro utilizado
     * @param newEnd float relativa à hora de fim da aula
     */
    void setEnd(float newEnd);
    /**
     * Complexity: O(1)
     * Método void que modifica o atributo type segundo o parâmetro utilizado
     * @param newType string relativa ao tipo de aula
     */
    void setType(string newType);
    /**
     * Complexity: O(n)
     * Operador de igualdade para dois membros da classe Interval.
     * @param I membro da classe Interval
     * @return true caso os dois membros sejam relativos a datas iguais com types sobreponíveis, false caso contrário
     */
    bool operator==(const Interval& I) const;
};

#endif //AED_SCHEDULE_INTERVAL_H
