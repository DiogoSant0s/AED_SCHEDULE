#ifndef AED_SCHEDULE_REQUEST_H
#define AED_SCHEDULE_REQUEST_H

#include <string>
#include <utility>
#include "Student.h"
#include "Schedule.h"

using namespace std;

/**
 * @brief Classe que representa um pedido de alteração de horário
 * Esta classe é usada para representar um pedido de alteração de horário e guarda o número do aluno,
 * o código da turma, a unidade curricular, o tipo de pedido e o estado do pedido.
 */

class Request {
private:
    int StudentId;
    string codeUC;
    string Class;
    string requestType;
    string requestStatus;
public:
    /**
     * Complexity: O(1)
     * @brief Construtor da classe Request
     * @param StudentId Numero de estudante
     * @param codeUC Código da unidade curricular
     * @param Class Código da turma
     * @param requestType Tipo de pedido
     */
    Request(int StudentId, string codeUC, string Class, string requestType);
    /**
     * Complexity: O(1)
     * @brief Método normal que devolve o atributo StudentId
     * @return int relativo ao número de estudante
     */
    int getStudentId() const;
    /**
     * Complexity: O(1)
     * @brief Método normal que devolve o atributo codeUC
     * @return string relativa ao código da unidade curricular
     */
    string getcodeUC() const;
    /**
     * Complexity: O(1)
     * @brief Método normal que devolve o atributo Class
     * @return string relativa ao código da turma
     */
    string getClass() const;
    /**
     * Complexity: O(1)
     * @brief Método normal que devolve o atributo requestType
     * @return string relativa ao tipo de pedido
     */
    string getRequestType() const;
    /**
     * Complexity: O(1)
     * @brief Método normal que devolve o atributo requestStatus
     * @return string relativa ao estado do pedido
     */
    string getRequestStatus() const;
    /**
     * Complexity: O(1)
     * @brief Método void que modifica o atributo requestStatus segundo o parâmetro utilizado
     * @param requestStatus string relativa ao estado do pedido
     */
    void setRequestStatus(string requestStatus);
    /**
     * Complexity: O(n^2)
     * @brief Processa o pedido, se possível
     * Processa o pedido, se possível.\n
     * Este metodo consgue adicionar ou remover uma turma a um estudante, ou trocar uma turma por outra, para isto,
     * primeiro remove o estudante da turma de origem e adiciona-o à turma de destino.
     * @return true se o pedido for aceite, false caso contrario
     */
    bool handleRequest(vector<Student> Students, const vector<UC*>& UCs, const vector<Schedule>& Schedules);
};

#endif //AED_SCHEDULE_REQUEST_H
