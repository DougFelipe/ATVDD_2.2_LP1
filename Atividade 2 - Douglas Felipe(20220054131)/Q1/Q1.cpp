/**
 * @file Q1.cpp
 * @brief Questão 1 da lista de exercícios 2 da disciplina de LP1
 * @author Douglas Felipe de Lima Silva (20220054131)
 * @since 02/06/2023
 * @date 04/06/2023
*/

//Cabeçalho (INCLUIR AS BIBLIOTECAS)
#include <iostream> //incluir já por padrão
#include <fstream>
#include <string>

using namespace std;


  /**
     * @brief Função principal do programa que lê um arquivo de entrada e imprime na saída padrão
    * @return preenche um vetor de 4 cadeias de caracteres
(strings) com informações vindas de um arquivo de entrada e imprime cada elemento do vetor
na saída padrão.
     */
int main() 
{
    const int sizeVetor = 4;
    string Nomes[sizeVetor];

    // Abrir o arquivo de entrada
    ifstream arquivo("entrada_q1.txt");
    if (!arquivo.is_open()) 
    {
        cerr << "Erro ao tentar abrir o arquivo" << endl;
        return 1;
    }

    // completa o vetor com as informações do arquivo de entrada
    for (int i = 0; i < sizeVetor; i++) 
    {
        getline(arquivo, Nomes[i]);
    }

    // fecha o arquivi de entrada
    arquivo.close();

    // imprime os elementos do vetor
    for (int i = 0; i < sizeVetor; i++) 
    {
        cout << Nomes[i] << endl;
    }

    return 0;
}
