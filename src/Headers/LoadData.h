#ifndef AED_SCHEDULE_LOADDATA_H
#define AED_SCHEDULE_LOADDATA_H

#include <iostream>
#include <sstream>
#include <fstream>
#include "vector"
#include <algorithm>
#include <queue>
#include "Request.h"

using namespace std;

/**
 * Classe LoadData
 * @details A classe é responsável pelo carregamento, armazenamento de dados e sorting de dados.
 */

class LoadData {
    vector<UC*> UCs;
    vector<Schedule> Schedules;
    vector<Student> Students;
    queue<Request> Requests;
public:
    /**
     * Complexity: O(n)
     * Método void responsável por ler o ficheiro classes.csv que contêm as informações sobre o horário de cada turma relativo a cada cadeira.
     */
    void loadData_Classes();
    /**
     * Complexity: O(n)
     * Método void responsável por ler o ficheiro classes_per_uc.csv que contêm as informações sobre a relação entre turmas e UCs
     */
    void loadData_Classes_per_UC();
    /**
     * Complexity: O(n)
     * Método void responsável por ler o ficheiro students_classes.csv que contêm as informações sobre as aulas de um estudante
     */
    void loadData_Students_Classes();
    /**
     * Complexity: O(1)
     * Método normal que devolve o atributo UCs
     * @return vector que representa as UCs
     */
    vector<UC*> getUCs();
    /**
     * Complexity: O(1)
     * Método normal que devolve o atributo Schedules
     * @return vector que representa os Schedules
     */
    vector<Schedule> getSchedules();
    /**
     * Complexity: O(1)
     * Método normal que devolve o atributo Students
     * @return vector que representa os Students
     */
    vector<Student> getStudents();
    /**
     * Complexity: O(1)
     * Método normal que devolve o atributo Requests
     * @return queue que representa os Requests
     */
    queue<Request> &getRequests();
    /**
     * Complexity: O(nlog(n)) with n being UCs
     * Método normal que devolve o atributo UCs depois do sort() pelo atributo codeUC
     * @return vector que representa os UCs sortidos pelo atributo codeUC
     */
    vector<UC*> sortUCs_CodeUC();
    /**
     * Complexity: O(nlog(n)) with n being UCs
     * Método normal que devolve o atributo UCs depois do sort() pelo atributo Class
     * @return vector que representa os UCs sortidos pelo atributo Class
     */
    vector<UC*> sortUCs_ClassCode();
    /**
     * Complexity: O(nlog(n)) with n being Students
     * Método normal que devolve o atributo UCs depois do sort() pelo atributo NumStudents
     * @return vector que representa os UCs sortidos pelo atributo NumStudents
     */
    vector<UC*> sortUCs_NumStudents();
    /**
     * Complexity: O(nlog(n)) with n being Students
     * Método normal que devolve o atributo Students depois do sort() pelo atributo StudentId
     * @return vector que representa os Students sortidos pelo atributo StudentId
     */
    vector<Student> sortStudents_StudentCode();
    /**
     * Complexity: O(nlog(n)) with n being Students
     * Método normal que devolve o atributo Students depois do sort() pelo atributo name
     * @return vector que representa os Students sortidos pelo atributo name
     */
    vector<Student> sortStudents_StudentName();
    /**
     * Complexity: O(nlog(n)) with n being Schedules
     * Método normal que devolve o atributo Schedules depois do sort() pelo atributo codeUC
     * @return vector que representa os Schedules sortidos pelo atributo name
     */
    vector<Schedule> sortSchedules_CodeUC();
    /**
     * Complexity: O(nlog(n)) with n being Schedules
     * Método normal que devolve o atributo Schedules depois do sort() pelo atributo Class
     * @return vector que representa os Schedules sortidos pelo atributo name
     */
    vector<Schedule> sortSchedules_ClassCode();
    /**
     * Complexity: O(S + c + C) = O(n) with S being the StudentId, c being codeUC and C being Class
     * Método responsável por acrescentar um pedido de remoção de um estudante de uma turma aos Requests
     * @param StudentId int relativa ao número de estudante do estudante
     * @param codeUC string relativa ao código da UC
     * @param Class string relativa ao código da turma
     */
    void removeStudent(int StudentId, const string& codeUC, const string& Class);
    /**
     * Complexity: O(S + c + C) = O(n) with S being the StudentId, c being codeUC and C being Class
     * Método responsável por acrescentar um pedido de adição de um estudante a uma turma aos Requests
     * @param StudentId int relativa ao número de estudante do estudante
     * @param codeUC string relativa ao código da UC
     * @param Class string relativa ao código da turma
     */
    void addStudent(int StudentId, const string& codeUC, const string& Class);
    /**
     * Complexity: O(log(n))
     * Método responsável por processar os Requests
     * @param Students vector que representa os Students
     * @param UCs vector que representa as UCs
     * @param Schedules vector que representa os Schedules
     * @param Requests queue que representa os Requests
     */
    static void processAllRequests(const vector<Student>& Students, const vector<UC*>& UCs, const vector<Schedule>& Schedules, queue<Request>& Requests);
    /**
     * Complexity: O(n)
     * @brief Arquiva os requests fornecidos
     * @param r queue que contém os requests fornecidos
     */
    static void archiveRequest(queue<Request>& r);
    /**
     * Complexity: O(n^2)
     * @brief Arquiva os Students fornecidos
     * @param S vector que contém os Students fornecidos
     */
    static void archiveStudents(const vector<Student>& S);
};

#endif //AED_SCHEDULE_LOADDATA_H
