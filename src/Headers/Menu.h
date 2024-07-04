#ifndef AED_SCHEDULE_MENU_H
#define AED_SCHEDULE_MENU_H

#include "LoadData.h"
#include "iostream"
#include "algorithm"
#include <iomanip>

using namespace std;

/**
 * Classe Menu
 * @details A classe AdminMenu relaciona-se diretamente com a classe LoadData,
 * por meio do atributo data. Esta classe configura a UI do programa, toda a lógica
 * do menu e certas operações de sorting/filtragem.
 */

class Menu {
    LoadData data;
public:
    /**
     * Complexity: O(n)
     * Construtor da classe.
     * @param data membro da classe LoadData
     * @see LoadData
     */
    explicit Menu(LoadData& data);
    /**
     * Complexity: O(1)
     * Método void que apresenta o título do menu
     */
    static void printTitle();
    /**
     * Complexity: O(1)
     * Método void que formata uma string segundo um tamanho definido para apresentar no ecrã nas listagens.
     * @param s string
     * @param linelength inteiro
     */
    static void Print(const string &s, int linelength);
    /**
     * Complexity: O(n)
     * Método normal que verifica se o input do utilizador é válido.
     * @param inputs vetor de inteiros
     * @return inteiro input do utilizador
     */
    static int getUserInput(vector<int> inputs);
    /**
     * Complexity: O(n)
     * Método normal que verifica se o input do utilizador é válido,
     * para um número indefinido de inputs possíveis.
     * @return string input do utilizador
     */
    static string getUserTextInput();
    /**
     * Complexity: O(n)
     * Método void que "limpa" o ecrã
     */
    static void clearScreen();
    /**
     * Complexity: O(n)
     * Método void utilizado para apresentar no ecrã as opções, relativas
     * a um conjunto de data definido por um membro LoadData, do menu inicial ao utilizador.
     * @param List_Size inteiro que determina o tamanho das listas
     */
    void MainMenu(int List_Size);
    /**
     * Complexity: O(n)
     * Método void que inicializa a interação do utilizador com o menu das UCs
     * @param List_Size inteiro que determina o tamanho das listas
     */
    void UCsMenu(int List_Size);
    /**
     * Complexity: O(n)
     * Método void que inicializa a interação do utilizador com o menu dos Students
     * @param List_Size inteiro que determina o tamanho das listas
     */
    void StudentsMenu(int List_Size);
    /**
     * Complexity: O(n)
     * Método void que inicializa a interação do utilizador com o menu dos Schedules
     * @param List_Size inteiro que determina o tamanho das listas
     */
    void SchedulesMenu(int List_Size);
    /**
     * Complexity: O(n)
     * Método void que inicializa a interação do utilizador com o menu dos Requests
     * @param List_Size inteiro que determina o tamanho das listas
     */
    void RequestMenu(int List_Size);
    /**
     * Complexity: O(n)
     * Método void que imita o MainMenu só que sem o PrintTitle
     */
    void wait(int List_Size);
    /**
     * Complexity: O(n)
     * Método void que inicializa a interação do utilizador com o menu do ListUCCode,
     * e aplica as diferentes funcionalidades do mesmo
     * @param List_Size inteiro que determina o tamanho das listas
     */
    void ListUCcodeMenu(int List_Size);
    /**
     * Complexity: O(n)
     * Método void que inicializa a interação do utilizador com o menu do ListClasscode,
     * e aplica as diferentes funcionalidades do mesmo
     * @param List_Size inteiro que determina o tamanho das listas
     */
    void ListClasscodeMenu(int List_Size);
    /**
     * Complexity: O(n)
     * Método void que inicializa a interação do utilizador com o menu do ListNumberStudents,
     * e aplica as diferentes funcionalidades do mesmo
     * @param List_Size inteiro que determina o tamanho das listas
     */
    void ListNumberStudentsMenu(int List_Size);
    /**
     * Complexity: O(n)
     * Método void que inicializa a interação do utilizador com o menu do ListStudentCodeMenu,
     * e aplica as diferentes funcionalidades do mesmo
     * @param List_Size inteiro que determina o tamanho das listas
     */
    void ListStudentCodeMenu(int List_Size);
    /**
     * Complexity: O(n)
     * Método void que inicializa a interação do utilizador com o menu do ListStudentNameMenu,
     * e aplica as diferentes funcionalidades do mesmo
     * @param List_Size inteiro que determina o tamanho das listas
     */
    void ListStudentNameMenu(int List_Size);
    /**
     * Complexity: O(n)
     * Método void que inicializa a interação do utilizador com o menu do ListNumUCs,
     * e aplica as diferentes funcionalidades do mesmo
     * @param List_Size inteiro que determina o tamanho das listas
     */
    void ListNumUCsMenu(int List_Size);
    /**
     * Complexity: O(n)
     * Método void que inicializa a interação do utilizador com o menu do ListScheduleUCcode,
     * e aplica as diferentes funcionalidades do mesmo
     * @param List_Size inteiro que determina o tamanho das listas
     */
    void ListScheduleUCcodeMenu(int List_Size);
    /**
     * Complexity: O(n)
     * Método void que inicializa a interação do utilizador com o menu do ListScheduleClasscode,
     * e aplica as diferentes funcionalidades do mesmo
     * @param List_Size inteiro que determina o tamanho das listas
     */
    void ListScheduleClasscodeMenu(int List_Size);
    /**
     * Complexity: O(n)
     * Método void que inicializa a interação do utilizador com o menu do ListSchedule,
     * e aplica as diferentes funcionalidades do mesmo
     * @param List_Size inteiro que determina o tamanho das listas
     */
    void ListScheduleMenu(int List_Size);
    /**
     * Complexity: O(n)
     * Método void que inicializa a interação do utilizador com o menu do AddRequest,
     * e aplica as diferentes funcionalidades do mesmo
     * @param List_Size inteiro que determina o tamanho das listas
     */
    void AddRequestMenu(int List_Size);
};

#endif //AED_SCHEDULE_MENU_H
