/**
 * @file Q2.cpp
 * @brief Questão 2 da lista de exercícios 2 da disciplina de LP1
 * @author Douglas Felipe de Lima Silva (20220054131)
 * @since 02/06/2023
 * @date 04/06/2023
*/
//Cabeçalho (INCLUIR AS BIBLIOTECAS)
#include <iostream> //incluir já por padrão
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

  /**
     * @brief Função principal do programa que lê um arquivo de entrada, calcula a média, o maior e o menor elemento e escreve em um arquivo de saída
    * @return preenche um vetor de 10 inteiros com
informações vindas de um arquivo e escreve em outro arquivo
     */

int main() 
{
    const int sizeVetor = 10;
    vector<int> Numeros(sizeVetor);

    // Abrir o arquivo de entrada
    ifstream Entrada("entrada_q2.txt");

    if (!Entrada.is_open()) 
    {
        cerr << "Erro ao tentar abrir arquivo de entrada." << endl;
        return 1;
    }

    // Preencher o vetor com as informações do arquivo
    for (int i = 0; i < sizeVetor; i++) 
    {
        Entrada >> Numeros[i];
    }

    // Fechar o arquivo de entrada
    Entrada.close();

    // Encontrar o menor e o maior elemento do vetor
    int menor = *min_element(Numeros.begin(), Numeros.end());
    int maior = *max_element(Numeros.begin(), Numeros.end());

    // Calcular a média dos elementos do vetor
    int soma = 0;
    for (int numero : Numeros) 
    {
        soma += numero;
    }
    double media = static_cast<double>(soma) / sizeVetor;

    // Abrir o arquivo de saída
    ofstream Saida("saida_q2.txt");
    
    if (!Saida.is_open())
    {
        cerr << "Erro ao  tentar abrir arquivo de saída" << endl;
        return 1;
    }

    // Escrever no arquivo de saída
    Saida << "Menor : " << menor << endl;
    Saida << "Maior : " << maior << endl;
    Saida << "Média : " << media << endl;

    // Fechar o arquivo de saída
    Saida.close();

    return 0;
}
