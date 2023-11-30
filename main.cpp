#include <iostream> // cout
#include <fstream>  // ifstream
#include <sstream>  // istringstream
#include <map>      // map :-)

#include "departamento.h"
#include "empresa.h"

void leDepartamentos(Empresa &e)
{
    ifstream inputStream;
    string codigoDepStr;
    int i = 0;
    inputStream.exceptions(ifstream::badbit | ifstream::failbit);
    try
    {
        inputStream.open("departamentos.csv");
        string linha;
        getline(inputStream, linha); // cabeçalho
        while (getline(inputStream, linha))
        {
            istringstream linhaStream(linha);
            getline(linhaStream, codigoDepStr, ';');
            int codigoDep = stoi(codigoDepStr);
            string nomeDepartamento;
            getline(linhaStream, nomeDepartamento, ';');
            e.createDepartamento(codigoDep, nomeDepartamento);
            i++;
        }
    }
    catch (invalid_argument &e)
    {
        cerr << "Exception: "
             << "Não foi possível converter \"" << codigoDepStr << "\" em int na linha " << i << endl;
        exit(1);
    }
    catch (ifstream::failure &e)
    {
        if (!inputStream.eof())
        {
            cerr << "Exception: Problema na abertura/leitura do arquivo " << endl;
            exit(1);
        }
        inputStream.close();
    }
}

void leFuncionarios(Empresa &e)
{
    ifstream inputStream;
    inputStream.exceptions(ifstream::badbit | ifstream::failbit);
    int i = 0;
    string codigoDepStr;
    string codigoFunStr;
    try
    {
        inputStream.open("funcionarios.csv");
        string linha;
        getline(inputStream, linha); // cabeçalho
        while (getline(inputStream, linha))
        {
            istringstream linhaStream(linha);
            getline(linhaStream, codigoFunStr, ';');
            int codigoFun = stoi(codigoFunStr);
            string nomeFuncionario;
            getline(linhaStream, nomeFuncionario, ';');
            getline(linhaStream, codigoDepStr, ';');
            int codigoDep = stoi(codigoDepStr);
            // inv: tenho dados para criar funcionario
            e.findDepartamento(codigoDep).createFuncionario(codigoFun, nomeFuncionario);
            i++;
        }
    }

    catch (const Empresa::CodigoInvalidoExeption &e)
    {
        cerr << "Exception: "
             << "Não foi possível achar o departamento com o código especificado" << endl;
        exit(1);
    }
    catch (out_of_range &e)
    {
        cerr << "Exception: "
             << "Não foi possível achar o departamento com o código especificado" << endl;
        exit(1);
    }
    catch (invalid_argument &e)
    {
        cerr << "Exception: "
             << "Não foi possível converter a string em int na linha " << i << endl;
        exit(1);
    }
    catch (ifstream::failure &e)
    {
        if (!inputStream.eof())
        {
            cerr << "Exception: Problema na abertura/leitura do arquivo " << endl;
            exit(1);
        }
        inputStream.close();
    }
}

int main()
{
    Empresa e;
    // leDepartamentos(e);
    leFuncionarios(e);
    // inv: departamentos.csv e funcionarios.csv lidos
    for (auto &[codigoDep, departamento] : e.getDepartamentos())
    {
        cout << departamento.getNome() << ", código [" << codigoDep << "], funcionários:" << endl;
        for (auto &[codigoFun, funcionario] : departamento.getFuncionarios())
        {
            cout << "\t" << funcionario.getNome() << ", código [" << codigoFun << "]";
            // para demonstrar a navegabilidade Funcionario->Departamento
            cout << ", departamento " << funcionario.getDepartamento()->getNome() << endl;
        }
    }
}
