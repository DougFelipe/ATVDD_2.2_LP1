/**
 * @file Q3.cpp
 * @brief Questão 3 da lista de exercícios 2 da disciplina de LP1
 * @author Douglas Felipe de Lima Silva (20220054131)
 * @since 02/06/2023
 * @date 04/06/2023
*/

//Cabeçalho (INCLUIR AS BIBLIOTECAS)
#include <iostream> //incluir já por padrão
using namespace std; // P/ evitar repetições do std
#include <fstream>
#include <string>
#include <vector>

//Linhas de lógica e códigos comentados 

//Cria o struct Aluno
struct Aluno 
{
    string nome;
    vector<double> notas;
};

//Iniciando funções utilizadas no código (Se necessário)
bool lerInput(const string& Arquivo, vector<Aluno>& alunos);
bool escreverOutput(const string& Arquivo, const vector<Aluno>& alunos);
double Media(const vector<double>& notas);
string aprovadoOUreprovado(double media);

 /**
     * @brief Função principal do programa que lê um arquivo de entrada, calcula a média, o status de aprovação e escreve em um arquivo de saída
    * @return lê de um arquivo as notas dos alunos de uma
turma e escreve em outro arquivo o nome e a média de cada aluno, bem como a sua situação
(aprovado (média >= 7.0) ou reprovado).
     */

//Função principal que executa as funções
int main() 
{
    const string arquivoInput = "entrada_q3.txt";
    const string arquivoOutput = "saida_q3.txt";

    vector<Aluno> alunos;

    if (!lerInput(arquivoInput, alunos)) 
    {
        return 1;
    }

    if (!escreverOutput(arquivoOutput, alunos))
    {
        return 1;
    }

    return 0;
}


/**
     * @brief Função que lê os dados do arquivo de entrada
    * @param Arquivo nome do arquivo de entrada
    * @param alunos vetor de alunos 
     */
bool lerInput(const string& Arquivo, vector<Aluno>& alunos) 
{
    ifstream arquivoEntrada(Arquivo);
    if (!arquivoEntrada.is_open()) 
    {
        cerr << "Erro ao  tentar abrir o arquivo" << endl;
        return false;
    }

    string linha;
    while (getline(arquivoEntrada, linha)) 
    {
        Aluno aluno;
        size_t pos = linha.find('\t');
        aluno.nome = linha.substr(0, pos);

        while (pos != string::npos) 
        {
            size_t nextPos = linha.find('\t', pos + 1);
            string stringNota = linha.substr(pos + 1, nextPos - pos - 1);
            double nota = stod(stringNota);
            aluno.notas.push_back(nota);
            pos = nextPos;
        }

        alunos.push_back(aluno);
    }

    arquivoEntrada.close();
    return true;
}

/**
     * @brief   Função que calcula a média das notas
    * @param    notas vetor de notas
    * @return retorna a média das notas
     */
double Media(const vector<double>& notas) 
{
    double soma = 0;
    for (double nota : notas)
    {
        soma += nota;
    }
    return soma / notas.size();
}

/**
     * @brief  determina se o aluno foi aprovado ou reprovado
    * @param    media média das notas
    * @return   retorna aprovado ou reprovado
     */ 
string aprovadoOUreprovado(double media) 
{
    return (media >= 7.0) ? "Aprovado" : "Reprovado";
}

/**
     * @brief   escreve no arquivo de saída o nome, a média e o status do aluno
    * @param    Arquivo nome do arquivo de saída
    * @param    alunos vetor de alunos
    * @return   retorna true se o arquivo foi escrito com sucesso
     */ 
bool escreverOutput(const string& Arquivo, const vector<Aluno>& alunos) 
{
    ofstream arquivoSaida(Arquivo);
    if (!arquivoSaida.is_open()) 
    {
        cerr << "Erro ao tentar abrir o arquivo de saída" << endl;
        return false;
    }

    arquivoSaida.precision(2); 

    for (const Aluno& aluno : alunos) 
    {
        double media = Media(aluno.notas);
        string status = aprovadoOUreprovado(media);

        arquivoSaida << aluno.nome << "\t";
        arquivoSaida << media << "\t";
        arquivoSaida << status << endl;
    }

    arquivoSaida.close();
    return true;
}